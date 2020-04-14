#include <external/libbcrypt/include/bcrypt/BCrypt.hpp>
#include "api_UsersController.h"
#include <utils/jwtService.h>

using namespace api;
namespace drogon {
    template<>
    inline Users fromRequest(const HttpRequest &req) {
        auto json = req.getJsonObject();
        auto userJson = (*json)["user"];
        auto user = Users(userJson);
        return user;
    }
}

auto UsersController::newUser(Users &&pNewUser,
                              function<void(const HttpResponsePtr &)> &&callback) -> void {
    auto callbackPtr = make_shared<function<void(const HttpResponsePtr &)>>(move(callback));
    checkInputUser(pNewUser, [=](const bool ifValid) {
        if (!ifValid) {
            auto resp = HttpResponse::newHttpResponse();
            resp->setStatusCode(HttpStatusCode::k400BadRequest);
            (*callbackPtr)(resp);
            return;
        }
        auto newUser = pNewUser;
        auto encryptedPass = BCrypt::generateHash(newUser.getValueOfPassword());
        newUser.setPassword(encryptedPass);
        newUser.setImage(app().getCustomConfig()["image-default"].asString());
        LOG_DEBUG << newUser.toJson().toStyledString();
        userMapper.insert(
                newUser,
                [callbackPtr](const Users &user) {
                    auto userWithToken = UsersController::UserWithToken(user);
                    auto json = Json::Value();
                    json["user"] = userWithToken.toJson();
                    auto resp = HttpResponse::newHttpJsonResponse(json);
                    resp->setStatusCode(HttpStatusCode::k201Created);
                    (*callbackPtr)(resp);
                },
                [callbackPtr](const DrogonDbException &e) {
                    LOG_ERROR << e.base().what();
                    auto resp = HttpResponse::newHttpResponse();
                    resp->setStatusCode(HttpStatusCode::k400BadRequest);
                    (*callbackPtr)(resp);
                }
        );
    });
}

auto UsersController::checkInputUser(const Users &user, const function<void(const bool)> &callback) -> void {
    // check if missing field
    if (user.getEmail() == nullptr || user.getPassword() == nullptr || user.getUsername() == nullptr) {
        callback(false);
        return;
    }
    // check if duplicate
    auto callbackPtr = make_shared<function<void(const bool &)>>(callback);
    userMapper.findBy(
            Criteria(Users::Cols::_username, CompareOperator::EQ, user.getValueOfUsername()) ||
            Criteria(Users::Cols::_email, CompareOperator::EQ, user.getValueOfEmail()),
            [callbackPtr](const vector<Users> &users) {
                (*callbackPtr)(users.empty());
            },
            [callbackPtr](const DrogonDbException &e) {
                LOG_ERROR << e.base().what();
                (*callbackPtr)(false);
            }
    );
}

auto UsersController::login(Users &&pNewUser, std::function<void(const HttpResponsePtr &)> &&callback) -> void {
    auto callbackPtr = make_shared<function<void(const HttpResponsePtr &)>>(move(callback));
    userMapper.findOne(
            Criteria(Users::Cols::_email, CompareOperator::EQ, pNewUser.getValueOfEmail()),
            [=](const Users &user) {
                if (BCrypt::validatePassword(pNewUser.getValueOfPassword(), user.getValueOfPassword())) {
                    auto userWithToken = UsersController::UserWithToken(user);
                    auto json = Json::Value();
                    json["user"] = userWithToken.toJson();
                    auto resp = HttpResponse::newHttpJsonResponse(json);
                    (*callbackPtr)(resp);
                } else {
                    auto resp = HttpResponse::newHttpResponse();
                    resp->setStatusCode(HttpStatusCode::k401Unauthorized);
                    (*callbackPtr)(resp);
                }
            },
            [callbackPtr](const DrogonDbException &e) {
                LOG_ERROR << e.base().what();
                auto resp = HttpResponse::newHttpResponse();
                resp->setStatusCode(HttpStatusCode::k400BadRequest);
                (*callbackPtr)(resp);
            }
    );
}

auto
UsersController::currentUser(const HttpRequestPtr &req,
                             std::function<void(const HttpResponsePtr &)> &&callback) -> void {
    auto callbackPtr = make_shared<function<void(const HttpResponsePtr &)>>(move(callback));
    jwtService::getCurrentUserFromRequest(req, [callbackPtr](optional<Users> user) {
        if (user.has_value()) {
            auto userWithToken = UsersController::UserWithToken(user.value());
            auto json = Json::Value();
            json["user"] = userWithToken.toJson();
            auto resp = HttpResponse::newHttpJsonResponse(json);
            (*callbackPtr)(resp);
        } else {
            auto resp = HttpResponse::newHttpResponse();
            resp->setStatusCode(HttpStatusCode::k400BadRequest);
            (*callbackPtr)(resp);
        }
    });
}

auto UsersController::update(const HttpRequestPtr &req, function<void(const HttpResponsePtr &)> &&callback,
                             Users &&pNewUser) -> void {
    auto callbackPtr = make_shared<function<void(const HttpResponsePtr &)>>(move(callback));
    jwtService::getCurrentUserFromRequest(req, [=](optional<Users> user) {
        if (user.has_value()) {
            if (pNewUser.getEmail() != nullptr) {
                user->setEmail(pNewUser.getValueOfEmail());
            }
            if (pNewUser.getUsername() != nullptr) {
                user->setEmail(pNewUser.getValueOfUsername());
            }
            if (pNewUser.getPassword() != nullptr) {
                user->setEmail(pNewUser.getValueOfPassword());
            }
            if (pNewUser.getBio() != nullptr) {
                user->setEmail(pNewUser.getValueOfBio());
            }
            if (pNewUser.getImage() != nullptr) {
                user->setEmail(pNewUser.getValueOfImage());
            }
            userMapper.update(user.value(), [callbackPtr, user](const size_t size) {
                auto userWithToken = UsersController::UserWithToken(user.value());
                auto json = Json::Value();
                json["user"] = userWithToken.toJson();
                auto resp = HttpResponse::newHttpJsonResponse(json);
                (*callbackPtr)(resp);
            }, [callbackPtr](const DrogonDbException &e) {
                LOG_ERROR << e.base().what();
                auto resp = HttpResponse::newHttpResponse();
                resp->setStatusCode(HttpStatusCode::k400BadRequest);
                (*callbackPtr)(resp);
            });
        } else {
            auto resp = HttpResponse::newHttpResponse();
            resp->setStatusCode(HttpStatusCode::k400BadRequest);
            (*callbackPtr)(resp);
        }
    });
}

UsersController::UserWithToken::UserWithToken(const Users &user) {
    token = jwtService::generateFromUser(user);
    email = user.getValueOfEmail();
    username = user.getValueOfUsername();
    bio = user.getValueOfBio();
    image = user.getValueOfImage();
}

auto UsersController::UserWithToken::toJson() -> Json::Value {
    Json::Value ret;
    ret["username"] = username;
    ret["email"] = email;
    ret["bio"] = bio;
    ret["image"] = image;
    ret["token"] = token;
    return ret;
}
