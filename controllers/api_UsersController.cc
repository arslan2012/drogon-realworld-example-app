#include <external/libbcrypt/include/bcrypt/BCrypt.hpp>
#include "api_UsersController.h"
#include <utils/jwtService.h>

using namespace api;
using namespace std;
namespace drogon {
    template<>
    inline Users fromRequest(const HttpRequest &req) {
        auto json = req.getJsonObject();
        auto userJson = (*json)["user"];
        auto user = Users(userJson);
        auto encryptedPass = BCrypt::generateHash(user.getValueOfPassword());
        user.setPassword(encryptedPass);
        return user;
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
