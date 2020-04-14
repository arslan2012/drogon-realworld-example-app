#pragma once

#include <drogon/HttpController.h>
#include <models/Articles.h>

using namespace drogon;
using namespace drogon_model::realworld;
using namespace std;
namespace api {
    class ArticlesController : public drogon::HttpController<ArticlesController> {
    public:
        METHOD_LIST_BEGIN
            ADD_METHOD_TO(ArticlesController::newArticle, "/articles", Post, "LoginFilter");
            ADD_METHOD_TO(ArticlesController::getAllArticles,
                          "/articles?tag={}&favorited={}&author={}&offset={}&limit={}", Get);
        METHOD_LIST_END

        auto newArticle(Articles &&pNewArticle,
                        function<void(const HttpResponsePtr &)> &&callback) -> void;

        auto getAllArticles(const HttpRequestPtr &req,
                            function<void(const HttpResponsePtr &)> &&callback, const string &tag,
                            const string &favorited,
                            const string &author, int offset = 0, int limit = 0) -> void;

    private:
        Mapper<Articles> articleMapper = Mapper<Articles>(app().getFastDbClient());
    };
}
