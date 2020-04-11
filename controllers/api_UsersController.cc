#include "api_UsersController.h"

using namespace api;

using namespace drogon_model::realworld;
namespace drogon {
    template<>
    inline Users fromRequest(const HttpRequest &req) {
        auto json = req.getJsonObject();
        auto userJson = (*json)["user"];
        auto user = Users(userJson);
        return user;
    }

}

void UsersController::newUser(Users &&pNewUser,
                              std::function<void(const HttpResponsePtr &)> &&callback) const {
    LOG_DEBUG << pNewUser.toJson().toStyledString();
    auto resp = HttpResponse::newHttpJsonResponse(pNewUser.toJson());
    callback(resp);
}
