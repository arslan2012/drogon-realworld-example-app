#pragma once

#include <drogon/HttpController.h>
#include <models/Users.h>

using namespace drogon;
using namespace drogon_model::realworld;
namespace api {
    class UsersController : public drogon::HttpController<UsersController> {
    public:
        METHOD_LIST_BEGIN
            ADD_METHOD_TO(UsersController::newUser, "/users", Post);
        METHOD_LIST_END

        auto newUser(Users &&pNewUser,
                     std::function<void(const HttpResponsePtr &)> &&callback) -> void;

    private:
        Mapper<Users> userMapper = Mapper<Users>(app().getFastDbClient());

        auto checkInputUser(const Users &user, const std::function<void(const bool)> &callback) -> void;

        struct UserWithToken {
            std::string email;
            std::string username;
            std::string bio;
            std::string image;
            std::string token;

            explicit UserWithToken(const Users& user);
            auto toJson() -> Json::Value;
        };
    };
}
