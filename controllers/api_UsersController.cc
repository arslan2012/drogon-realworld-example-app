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

    template<>
    inline int fromRequest(const HttpRequest &req) {
        auto token = req.getHeader("Authorization").substr(6);
        LOG_DEBUG << token;
        return jwtService::getUserIdFromJwt(token).value_or(0);
    }

}

auto UsersController::newUser(Users &&pNewUser,
                              function<void(const HttpResponsePtr &)> &&callback) -> void {
    checkInputUser(pNewUser, [=](const bool ifValid) {
        if (!ifValid) {
            auto resp = HttpResponse::newHttpResponse();
            resp->setStatusCode(HttpStatusCode::k400BadRequest);
            callback(resp);
            return;
        }
        auto newUser = pNewUser;
        auto encryptedPass = BCrypt::generateHash(newUser.getValueOfPassword());
        newUser.setPassword(encryptedPass);
        newUser.setImage(app().getCustomConfig()["image-default"].asString());
        LOG_DEBUG << newUser.toJson().toStyledString();
        userMapper.insert(
                newUser,
                [callback](const Users &user) {
                    auto userWithToken = UsersController::UserWithToken(user);
                    auto json = Json::Value();
                    json["user"] = userWithToken.toJson();
                    auto resp = HttpResponse::newHttpJsonResponse(json);
                    resp->setStatusCode(HttpStatusCode::k201Created);
                    callback(resp);
                },
                [callback](const DrogonDbException &e) {
                    LOG_ERROR << e.base().what();
                    auto resp = HttpResponse::newHttpResponse();
                    resp->setStatusCode(HttpStatusCode::k400BadRequest);
                    callback(resp);
                }
        );
    });
}

auto UsersController::checkInputUser(const Users &user, const function<void(const bool)> &callback) -> void {
    // check if missing field
    if (user.getEmail() == nullptr || user.getPassword() == nullptr || user.getUsername() == nullptr) {
        callback(false);
    }
    // check if duplicate
    userMapper.findBy(
            Criteria(Users::Cols::_username, CompareOperator::EQ, user.getValueOfUsername()) ||
            Criteria(Users::Cols::_email, CompareOperator::EQ, user.getValueOfEmail()),
            [callback](const vector<Users> &users) {
                callback(users.empty());
            },
            [callback](const DrogonDbException &e) {
                LOG_ERROR << e.base().what();
                callback(false);
            }
    );
}

auto UsersController::login(Users &&pNewUser, std::function<void(const HttpResponsePtr &)> &&callback) -> void {
    userMapper.findOne(
            Criteria(Users::Cols::_email, CompareOperator::EQ, pNewUser.getValueOfEmail()),
            [=](const Users &user) {
                if (BCrypt::validatePassword(pNewUser.getValueOfPassword(), user.getValueOfPassword())) {
                    auto userWithToken = UsersController::UserWithToken(user);
                    auto json = Json::Value();
                    json["user"] = userWithToken.toJson();
                    auto resp = HttpResponse::newHttpJsonResponse(json);
                    callback(resp);
                } else {
                    auto resp = HttpResponse::newHttpResponse();
                    resp->setStatusCode(HttpStatusCode::k401Unauthorized);
                    callback(resp);
                }
            },
            [callback](const DrogonDbException &e) {
                LOG_ERROR << e.base().what();
                auto resp = HttpResponse::newHttpResponse();
                resp->setStatusCode(HttpStatusCode::k400BadRequest);
                callback(resp);
            }
    );
}

auto
UsersController::currentUser(int &&userId, std::function<void(const HttpResponsePtr &)> &&callback) -> void {
    if (userId !=0 ) {
        userMapper.findOne(
                Criteria(Users::Cols::_id, CompareOperator::EQ, userId),
                [=](const Users &user) {
                    auto userWithToken = UsersController::UserWithToken(user);
                    auto json = Json::Value();
                    json["user"] = userWithToken.toJson();
                    auto resp = HttpResponse::newHttpJsonResponse(json);
                    callback(resp);
                },
                [callback](const DrogonDbException &e) {
                    LOG_ERROR << e.base().what();
                    auto resp = HttpResponse::newHttpResponse();
                    resp->setStatusCode(HttpStatusCode::k400BadRequest);
                    callback(resp);
                }
        );
    } else {
        auto resp = HttpResponse::newHttpResponse();
        resp->setStatusCode(HttpStatusCode::k401Unauthorized);
        callback(resp);
    }

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
