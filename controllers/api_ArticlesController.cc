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
    auto callbackPtr = make_shared<function<void(const HttpResponsePtr &)>>(move(callback));
    articleMapper.insert(
            pNewArticle,
            [callbackPtr](const Articles &article) {
                auto json = Json::Value();
                json["article"] = article.toJson();
                auto resp = HttpResponse::newHttpJsonResponse(json);
                resp->setStatusCode(HttpStatusCode::k201Created);
                (*callbackPtr)(resp);
            },
            [callbackPtr](const DrogonDbException &e) {
                LOG_ERROR << e.base().what();
                auto resp = HttpResponse::newHttpResponse();
                resp->setStatusCode(HttpStatusCode::k400BadRequest);
                (*callbackPtr)(resp);
            }
    );
}

auto ArticlesController::getAllArticles(const HttpRequestPtr &req, function<void(const HttpResponsePtr &)> &&callback,
                                        const string &tag, const string &favorited, const string &author, int offset,
                                        int limit) -> void {
    auto callbackPtr = make_shared<function<void(const HttpResponsePtr &)>>(move(callback));
    auto dbClient = app().getFastDbClient();
    if (!tag.empty()) {
        *dbClient << "select * from articles "
                     "where $1 = any(taglist)"
                  << tag
                  >> [callbackPtr](const Result &r) {
                      std::cout << r.size() << " rows selected!" << std::endl;
                      Json::Value ret;
                      ret.resize(0);
                      for (const auto &row : r) {
                          auto article = Articles(row);
                          ret.append(article.toJson());
                      }
                      auto resp = HttpResponse::newHttpJsonResponse(ret);
                      resp->setStatusCode(HttpStatusCode::k201Created);
                      (*callbackPtr)(resp);
                  }
                  >> [callbackPtr](const DrogonDbException &e) {
                      LOG_ERROR << e.base().what();
                      auto resp = HttpResponse::newHttpResponse();
                      resp->setStatusCode(HttpStatusCode::k500InternalServerError);
                      (*callbackPtr)(resp);
                  };
        return;
    }
    if (!favorited.empty()) {
        *dbClient << "select "
                     "    a.id, "
                     "    a.user_id, "
                     "    a.slug, "
                     "    a.title, "
                     "    a.description, "
                     "    a.body, "
                     "    a.created_at, "
                     "    a.updated_at "
                     "from "
                     "    articles a "
                     "inner join article_favorites af on "
                     "    a.id = af.article_id "
                     "inner join users u on "
                     "    af.user_id = u.id "
                     "where u.username = $1"
                  << favorited
                  >> [callbackPtr](const Result &r) {
                      std::cout << r.size() << " rows selected!" << std::endl;
                      Json::Value ret;
                      ret.resize(0);
                      for (const auto &row : r) {
                          auto article = Articles(row, -1);
                          ret.append(article.toJson());
                      }
                      auto resp = HttpResponse::newHttpJsonResponse(ret);
                      resp->setStatusCode(HttpStatusCode::k201Created);
                      (*callbackPtr)(resp);
                  }
                  >> [callbackPtr](const DrogonDbException &e) {
                      LOG_ERROR << e.base().what();
                      auto resp = HttpResponse::newHttpResponse();
                      resp->setStatusCode(HttpStatusCode::k500InternalServerError);
                      (*callbackPtr)(resp);
                  };
        return;
    }
    if (!author.empty()) {
        *dbClient << "select "
                     "    a.id, "
                     "    a.user_id, "
                     "    a.slug, "
                     "    a.title, "
                     "    a.description, "
                     "    a.body, "
                     "    a.created_at, "
                     "    a.updated_at "
                     "from "
                     "    articles a "
                     "inner join users u on "
                     "    a.user_id = u.id "
                     "where u.username = $1"
                  << author
                  >> [callbackPtr](const Result &r) {
                      std::cout << r.size() << " rows selected!" << std::endl;
                      Json::Value ret;
                      ret.resize(0);
                      for (const auto &row : r) {
                          auto article = Articles(row, -1);
                          ret.append(article.toJson());
                      }
                      auto resp = HttpResponse::newHttpJsonResponse(ret);
                      resp->setStatusCode(HttpStatusCode::k201Created);
                      (*callbackPtr)(resp);
                  }
                  >> [callbackPtr](const DrogonDbException &e) {
                      LOG_ERROR << e.base().what();
                      auto resp = HttpResponse::newHttpResponse();
                      resp->setStatusCode(HttpStatusCode::k500InternalServerError);
                      (*callbackPtr)(resp);
                  };
        return;
    }
    articleMapper.offset(offset).limit(limit).findAll(
            [callbackPtr](const vector<Articles> &articles) {
                Json::Value ret;
                ret.resize(0);
                for (auto &obj : articles) {
                    ret.append(obj.toJson());
                }
                auto resp = HttpResponse::newHttpJsonResponse(ret);
                resp->setStatusCode(HttpStatusCode::k201Created);
                (*callbackPtr)(resp);
            },
            [callbackPtr](const DrogonDbException &e) {
                LOG_ERROR << e.base().what();
                auto resp = HttpResponse::newHttpResponse();
                resp->setStatusCode(HttpStatusCode::k400BadRequest);
                (*callbackPtr)(resp);
            }
    );
}

