#include "api_ArticlesController.h"

using namespace api;
namespace drogon {
    template<>
    inline Articles fromRequest(const HttpRequest &req) {
        auto json = req.getJsonObject();
        auto articleJson = (*json)["article"];
        auto article = Articles(articleJson);
        return article;
    }
}

auto
ArticlesController::newArticle(Articles &&pNewArticle, function<void(const HttpResponsePtr &)> &&callback) -> void {
    articleMapper.insert(
            pNewArticle,
            [callback](const Articles &article) {
                auto json = Json::Value();
                json["article"] = article.toJson();
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
}

auto ArticlesController::getAllArticles(const HttpRequestPtr &req, function<void(const HttpResponsePtr &)> &&callback,
                                        const string& tag, const string& favorited, const string& author, int offset, int limit) -> void {
    if (!tag.empty()) {
    }
    if (!favorited.empty()) {
    }
    if (!author.empty()) {
    }
//    articleMapper.offset(offset).limit(limit).findBy(criteria);
}

