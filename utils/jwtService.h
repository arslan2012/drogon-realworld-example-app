//
// Created by arslan on 4/12/20.
//

#ifndef ARSLANTECH_JWTSERVICE_H
#define ARSLANTECH_JWTSERVICE_H

#include <models/Users.h>
#include <drogon/drogon.h>
#include <jwt-cpp/jwt.h>

using namespace std;
using namespace drogon;
using namespace drogon_model::realworld;
using namespace jwt;

class jwtService {
public:
    static auto generateFromUser(const Users& user) -> string;

    static auto getUserIdFromJwt(const string& token) -> optional<int>;

    static auto getCurrentUserIdFromRequest(const HttpRequestPtr &req) -> optional<int>;

    static auto getCurrentUserFromRequest(const HttpRequestPtr &req, const function<void(optional<Users>)>& callback) -> void;

private:
    static const string secret;
    static const int duration;
    static const verifier<default_clock> _verifier;
};

#endif //ARSLANTECH_JWTSERVICE_H
