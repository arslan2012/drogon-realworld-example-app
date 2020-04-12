#pragma once

#include <drogon/HttpController.h>
#include <models/Users.h>

using namespace drogon;
using namespace drogon_model::realworld;
using namespace std;
namespace api {
    class UsersController : public drogon::HttpController<UsersController> {
    public:
        METHOD_LIST_BEGIN
            ADD_METHOD_TO(UsersController::newUser, "/users", Post);
            ADD_METHOD_TO(UsersController::login, "/users/login", Post);
            ADD_METHOD_TO(UsersController::currentUser, "/user", Get);
        METHOD_LIST_END

        auto newUser(Users &&pNewUser,
                     function<void(const HttpResponsePtr &)> &&callback) -> void;

        auto login(Users &&pNewUser,
                   function<void(const HttpResponsePtr &)> &&callback) -> void;

        auto currentUser(int &&userId,
                         function<void(const HttpResponsePtr &)> &&callback) -> void;
    private:
        Mapper<Users> userMapper = Mapper<Users>(app().getFastDbClient());
        struct UserWithToken {
            string email;
            string username;
            string bio;
            string image;
            string token;

            explicit UserWithToken(const Users &user);

            auto toJson() -> Json::Value;
        };

        auto checkInputUser(const Users &user, const function<void(const bool)> &callback) -> void;

    };
}
