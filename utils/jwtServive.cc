#include "jwtService.h"

const string jwtService::secret = drogon::app().getCustomConfig()["jwt-secret"].asString();
const int jwtService::duration = drogon::app().getCustomConfig()["jwt-sessionTime"].asInt();
const verifier<default_clock> jwtService::_verifier = verify()
        .allow_algorithm(algorithm::hs256{jwtService::secret})
        .with_issuer("auth0");

auto jwtService::generateFromUser(const Users& user) -> string {
    return jwt::create()
            .set_issuer("auth0")
            .set_type("JWS")
//            .set_issued_at(std::chrono::system_clock::now())
//            .set_expires_at(std::chrono::system_clock::now() + std::chrono::seconds{duration})
            .set_payload_claim("user", jwt::claim(to_string(user.getValueOfId())))
            .sign(jwt::algorithm::hs256{secret});
}

auto jwtService::getUserIdFromJwt(const string& token) -> optional<int> {
    auto decoded = jwt::decode(token);
    try {
        _verifier.verify(decoded);
    } catch (const runtime_error &e) {
        LOG_ERROR << e.what();
        return nullopt;
    }
    return stoi(decoded.get_payload_claim("user").as_string());
}

auto jwtService::getCurrentUserIdFromRequest(const HttpRequestPtr &req) -> optional<int> {
    auto token = req->getHeader("Authorization").substr(6);
    return getUserIdFromJwt(token);
}

auto jwtService::getCurrentUserFromRequest(const HttpRequestPtr &req, const function<void(optional<Users>)>& callback) -> void {
    Mapper<Users> userMapper = Mapper<Users>(app().getFastDbClient());
    auto id = getCurrentUserIdFromRequest(req);
    if (!id.has_value()) {
        callback(nullopt);
        return;
    }
    userMapper.findByPrimaryKey(id.value(), [callback](const Users &user) {
        callback(user);
    },[callback](const DrogonDbException &e) {
        callback(nullopt);
    });
}
