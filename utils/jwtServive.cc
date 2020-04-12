#include "jwtService.h"

const string jwtService::secret = drogon::app().getCustomConfig()["jwt-secret"].asString();
const int jwtService::duration = drogon::app().getCustomConfig()["jwt-sessionTime"].asInt();
const verifier<default_clock> jwtService::_verifier = verify()
        .allow_algorithm(algorithm::hs256{jwtService::secret})
        .with_issuer("auth0");

auto jwtService::generateFromUser(Users user) -> string {
    return jwt::create()
            .set_issuer("auth0")
            .set_type("JWS")
            .set_issued_at(std::chrono::system_clock::now())
            .set_expires_at(std::chrono::system_clock::now() + std::chrono::seconds{duration})
            .set_payload_claim("user", jwt::claim(to_string(user.getValueOfId())))
            .sign(jwt::algorithm::hs256{secret});
}

auto jwtService::getUserIdFromJwt(string token) -> optional<int> {
    auto decoded = jwt::decode(token);
    try {
        _verifier.verify(decoded);
    } catch (runtime_error e) {
        LOG_ERROR << e.what();
        return nullopt;
    }
    return decoded.get_payload_claim("user").as_int();
}