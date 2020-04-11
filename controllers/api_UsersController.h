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

        void newUser(Users &&pNewUser,
                      std::function<void(const HttpResponsePtr &)> &&callback) const;
    };
}
