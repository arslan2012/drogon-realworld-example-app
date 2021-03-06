/**
 *
 *  Comments.cc
 *  DO NOT EDIT. This file is generated by drogon_ctl
 *
 */

#include "Comments.h"
#include <drogon/utils/Utilities.h>
#include <string>

using namespace drogon;
using namespace drogon_model::realworld;

const std::string Comments::Cols::_id = "id";
const std::string Comments::Cols::_body = "body";
const std::string Comments::Cols::_article_id = "article_id";
const std::string Comments::Cols::_user_id = "user_id";
const std::string Comments::Cols::_created_at = "created_at";
const std::string Comments::Cols::_updated_at = "updated_at";
const std::string Comments::primaryKeyName = "id";
const bool Comments::hasPrimaryKey = true;
const std::string Comments::tableName = "comments";

const std::vector<typename Comments::MetaData> Comments::metaData_={
{"id","int32_t","integer",4,1,1,1},
{"body","std::string","text",0,0,0,0},
{"article_id","int32_t","integer",4,0,0,0},
{"user_id","int32_t","integer",4,0,0,0},
{"created_at","::trantor::Date","timestamp without time zone",0,0,0,1},
{"updated_at","::trantor::Date","timestamp without time zone",0,0,0,1}
};
const std::string &Comments::getColumnName(size_t index) noexcept(false)
{
    assert(index < metaData_.size());
    return metaData_[index].colName_;
}
Comments::Comments(const Row &r, const ssize_t indexOffset) noexcept
{
    if(indexOffset < 0)
    {
        if(!r["id"].isNull())
        {
            id_=std::make_shared<int32_t>(r["id"].as<int32_t>());
        }
        if(!r["body"].isNull())
        {
            body_=std::make_shared<std::string>(r["body"].as<std::string>());
        }
        if(!r["article_id"].isNull())
        {
            articleId_=std::make_shared<int32_t>(r["article_id"].as<int32_t>());
        }
        if(!r["user_id"].isNull())
        {
            userId_=std::make_shared<int32_t>(r["user_id"].as<int32_t>());
        }
        if(!r["created_at"].isNull())
        {
            auto timeStr = r["created_at"].as<std::string>();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            auto p = strptime(timeStr.c_str(),"%Y-%m-%d %H:%M:%S",&stm);
            size_t t = mktime(&stm);
            size_t decimalNum = 0;
            if(*p=='.')
            {
                std::string decimals(p+1,&timeStr[timeStr.length()]);
                while(decimals.length()<6)
                {
                    decimals += "0";
                }
                decimalNum = (size_t)atol(decimals.c_str());
            }
            createdAt_=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
        }
        if(!r["updated_at"].isNull())
        {
            auto timeStr = r["updated_at"].as<std::string>();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            auto p = strptime(timeStr.c_str(),"%Y-%m-%d %H:%M:%S",&stm);
            size_t t = mktime(&stm);
            size_t decimalNum = 0;
            if(*p=='.')
            {
                std::string decimals(p+1,&timeStr[timeStr.length()]);
                while(decimals.length()<6)
                {
                    decimals += "0";
                }
                decimalNum = (size_t)atol(decimals.c_str());
            }
            updatedAt_=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
        }
    }
    else
    {
        size_t offset = (size_t)indexOffset;
        if(offset + 6 > r.size())
        {
            LOG_FATAL << "Invalid SQL result for this model";
            return;
        }
        size_t index;
        index = offset + 0;
        if(!r[index].isNull())
        {
            id_=std::make_shared<int32_t>(r[index].as<int32_t>());
        }
        index = offset + 1;
        if(!r[index].isNull())
        {
            body_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 2;
        if(!r[index].isNull())
        {
            articleId_=std::make_shared<int32_t>(r[index].as<int32_t>());
        }
        index = offset + 3;
        if(!r[index].isNull())
        {
            userId_=std::make_shared<int32_t>(r[index].as<int32_t>());
        }
        index = offset + 4;
        if(!r[index].isNull())
        {
            auto timeStr = r[index].as<std::string>();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            auto p = strptime(timeStr.c_str(),"%Y-%m-%d %H:%M:%S",&stm);
            size_t t = mktime(&stm);
            size_t decimalNum = 0;
            if(*p=='.')
            {
                std::string decimals(p+1,&timeStr[timeStr.length()]);
                while(decimals.length()<6)
                {
                    decimals += "0";
                }
                decimalNum = (size_t)atol(decimals.c_str());
            }
            createdAt_=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
        }
        index = offset + 5;
        if(!r[index].isNull())
        {
            auto timeStr = r[index].as<std::string>();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            auto p = strptime(timeStr.c_str(),"%Y-%m-%d %H:%M:%S",&stm);
            size_t t = mktime(&stm);
            size_t decimalNum = 0;
            if(*p=='.')
            {
                std::string decimals(p+1,&timeStr[timeStr.length()]);
                while(decimals.length()<6)
                {
                    decimals += "0";
                }
                decimalNum = (size_t)atol(decimals.c_str());
            }
            updatedAt_=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
        }
    }

}

Comments::Comments(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 6)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        dirtyFlag_[0] = true;
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            id_=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[0]].asInt64());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            body_=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        dirtyFlag_[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            articleId_=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[2]].asInt64());
        }
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        dirtyFlag_[3] = true;
        if(!pJson[pMasqueradingVector[3]].isNull())
        {
            userId_=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[3]].asInt64());
        }
    }
    if(!pMasqueradingVector[4].empty() && pJson.isMember(pMasqueradingVector[4]))
    {
        dirtyFlag_[4] = true;
        if(!pJson[pMasqueradingVector[4]].isNull())
        {
            auto timeStr = pJson[pMasqueradingVector[4]].asString();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            auto p = strptime(timeStr.c_str(),"%Y-%m-%d %H:%M:%S",&stm);
            size_t t = mktime(&stm);
            size_t decimalNum = 0;
            if(*p=='.')
            {
                std::string decimals(p+1,&timeStr[timeStr.length()]);
                while(decimals.length()<6)
                {
                    decimals += "0";
                }
                decimalNum = (size_t)atol(decimals.c_str());
            }
            createdAt_=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
        }
    }
    if(!pMasqueradingVector[5].empty() && pJson.isMember(pMasqueradingVector[5]))
    {
        dirtyFlag_[5] = true;
        if(!pJson[pMasqueradingVector[5]].isNull())
        {
            auto timeStr = pJson[pMasqueradingVector[5]].asString();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            auto p = strptime(timeStr.c_str(),"%Y-%m-%d %H:%M:%S",&stm);
            size_t t = mktime(&stm);
            size_t decimalNum = 0;
            if(*p=='.')
            {
                std::string decimals(p+1,&timeStr[timeStr.length()]);
                while(decimals.length()<6)
                {
                    decimals += "0";
                }
                decimalNum = (size_t)atol(decimals.c_str());
            }
            updatedAt_=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
        }
    }
}

Comments::Comments(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("id"))
    {
        dirtyFlag_[0]=true;
        if(!pJson["id"].isNull())
        {
            id_=std::make_shared<int32_t>((int32_t)pJson["id"].asInt64());
        }
    }
    if(pJson.isMember("body"))
    {
        dirtyFlag_[1]=true;
        if(!pJson["body"].isNull())
        {
            body_=std::make_shared<std::string>(pJson["body"].asString());
        }
    }
    if(pJson.isMember("article_id"))
    {
        dirtyFlag_[2]=true;
        if(!pJson["article_id"].isNull())
        {
            articleId_=std::make_shared<int32_t>((int32_t)pJson["article_id"].asInt64());
        }
    }
    if(pJson.isMember("user_id"))
    {
        dirtyFlag_[3]=true;
        if(!pJson["user_id"].isNull())
        {
            userId_=std::make_shared<int32_t>((int32_t)pJson["user_id"].asInt64());
        }
    }
    if(pJson.isMember("created_at"))
    {
        dirtyFlag_[4]=true;
        if(!pJson["created_at"].isNull())
        {
            auto timeStr = pJson["created_at"].asString();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            auto p = strptime(timeStr.c_str(),"%Y-%m-%d %H:%M:%S",&stm);
            size_t t = mktime(&stm);
            size_t decimalNum = 0;
            if(*p=='.')
            {
                std::string decimals(p+1,&timeStr[timeStr.length()]);
                while(decimals.length()<6)
                {
                    decimals += "0";
                }
                decimalNum = (size_t)atol(decimals.c_str());
            }
            createdAt_=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
        }
    }
    if(pJson.isMember("updated_at"))
    {
        dirtyFlag_[5]=true;
        if(!pJson["updated_at"].isNull())
        {
            auto timeStr = pJson["updated_at"].asString();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            auto p = strptime(timeStr.c_str(),"%Y-%m-%d %H:%M:%S",&stm);
            size_t t = mktime(&stm);
            size_t decimalNum = 0;
            if(*p=='.')
            {
                std::string decimals(p+1,&timeStr[timeStr.length()]);
                while(decimals.length()<6)
                {
                    decimals += "0";
                }
                decimalNum = (size_t)atol(decimals.c_str());
            }
            updatedAt_=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
        }
    }
}

void Comments::updateByMasqueradedJson(const Json::Value &pJson,
                                            const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 6)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            id_=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[0]].asInt64());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            body_=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        dirtyFlag_[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            articleId_=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[2]].asInt64());
        }
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        dirtyFlag_[3] = true;
        if(!pJson[pMasqueradingVector[3]].isNull())
        {
            userId_=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[3]].asInt64());
        }
    }
    if(!pMasqueradingVector[4].empty() && pJson.isMember(pMasqueradingVector[4]))
    {
        dirtyFlag_[4] = true;
        if(!pJson[pMasqueradingVector[4]].isNull())
        {
            auto timeStr = pJson[pMasqueradingVector[4]].asString();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            auto p = strptime(timeStr.c_str(),"%Y-%m-%d %H:%M:%S",&stm);
            size_t t = mktime(&stm);
            size_t decimalNum = 0;
            if(*p=='.')
            {
                std::string decimals(p+1,&timeStr[timeStr.length()]);
                while(decimals.length()<6)
                {
                    decimals += "0";
                }
                decimalNum = (size_t)atol(decimals.c_str());
            }
            createdAt_=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
        }
    }
    if(!pMasqueradingVector[5].empty() && pJson.isMember(pMasqueradingVector[5]))
    {
        dirtyFlag_[5] = true;
        if(!pJson[pMasqueradingVector[5]].isNull())
        {
            auto timeStr = pJson[pMasqueradingVector[5]].asString();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            auto p = strptime(timeStr.c_str(),"%Y-%m-%d %H:%M:%S",&stm);
            size_t t = mktime(&stm);
            size_t decimalNum = 0;
            if(*p=='.')
            {
                std::string decimals(p+1,&timeStr[timeStr.length()]);
                while(decimals.length()<6)
                {
                    decimals += "0";
                }
                decimalNum = (size_t)atol(decimals.c_str());
            }
            updatedAt_=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
        }
    }
}
                                                                    
void Comments::updateByJson(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("id"))
    {
        if(!pJson["id"].isNull())
        {
            id_=std::make_shared<int32_t>((int32_t)pJson["id"].asInt64());
        }
    }
    if(pJson.isMember("body"))
    {
        dirtyFlag_[1] = true;
        if(!pJson["body"].isNull())
        {
            body_=std::make_shared<std::string>(pJson["body"].asString());
        }
    }
    if(pJson.isMember("article_id"))
    {
        dirtyFlag_[2] = true;
        if(!pJson["article_id"].isNull())
        {
            articleId_=std::make_shared<int32_t>((int32_t)pJson["article_id"].asInt64());
        }
    }
    if(pJson.isMember("user_id"))
    {
        dirtyFlag_[3] = true;
        if(!pJson["user_id"].isNull())
        {
            userId_=std::make_shared<int32_t>((int32_t)pJson["user_id"].asInt64());
        }
    }
    if(pJson.isMember("created_at"))
    {
        dirtyFlag_[4] = true;
        if(!pJson["created_at"].isNull())
        {
            auto timeStr = pJson["created_at"].asString();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            auto p = strptime(timeStr.c_str(),"%Y-%m-%d %H:%M:%S",&stm);
            size_t t = mktime(&stm);
            size_t decimalNum = 0;
            if(*p=='.')
            {
                std::string decimals(p+1,&timeStr[timeStr.length()]);
                while(decimals.length()<6)
                {
                    decimals += "0";
                }
                decimalNum = (size_t)atol(decimals.c_str());
            }
            createdAt_=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
        }
    }
    if(pJson.isMember("updated_at"))
    {
        dirtyFlag_[5] = true;
        if(!pJson["updated_at"].isNull())
        {
            auto timeStr = pJson["updated_at"].asString();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            auto p = strptime(timeStr.c_str(),"%Y-%m-%d %H:%M:%S",&stm);
            size_t t = mktime(&stm);
            size_t decimalNum = 0;
            if(*p=='.')
            {
                std::string decimals(p+1,&timeStr[timeStr.length()]);
                while(decimals.length()<6)
                {
                    decimals += "0";
                }
                decimalNum = (size_t)atol(decimals.c_str());
            }
            updatedAt_=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
        }
    }
}

const int32_t &Comments::getValueOfId() const noexcept
{
    const static int32_t defaultValue = int32_t();
    if(id_)
        return *id_;
    return defaultValue;
}
const std::shared_ptr<int32_t> &Comments::getId() const noexcept
{
    return id_;
}
const typename Comments::PrimaryKeyType & Comments::getPrimaryKey() const
{
    assert(id_);
    return *id_;
}

const std::string &Comments::getValueOfBody() const noexcept
{
    const static std::string defaultValue = std::string();
    if(body_)
        return *body_;
    return defaultValue;
}
const std::shared_ptr<std::string> &Comments::getBody() const noexcept
{
    return body_;
}
void Comments::setBody(const std::string &pBody) noexcept
{
    body_ = std::make_shared<std::string>(pBody);
    dirtyFlag_[1] = true;
}
void Comments::setBody(std::string &&pBody) noexcept
{
    body_ = std::make_shared<std::string>(std::move(pBody));
    dirtyFlag_[1] = true;
}


void Comments::setBodyToNull() noexcept
{
    body_.reset();
    dirtyFlag_[1] = true;
}

const int32_t &Comments::getValueOfArticleId() const noexcept
{
    const static int32_t defaultValue = int32_t();
    if(articleId_)
        return *articleId_;
    return defaultValue;
}
const std::shared_ptr<int32_t> &Comments::getArticleId() const noexcept
{
    return articleId_;
}
void Comments::setArticleId(const int32_t &pArticleId) noexcept
{
    articleId_ = std::make_shared<int32_t>(pArticleId);
    dirtyFlag_[2] = true;
}


void Comments::setArticleIdToNull() noexcept
{
    articleId_.reset();
    dirtyFlag_[2] = true;
}

const int32_t &Comments::getValueOfUserId() const noexcept
{
    const static int32_t defaultValue = int32_t();
    if(userId_)
        return *userId_;
    return defaultValue;
}
const std::shared_ptr<int32_t> &Comments::getUserId() const noexcept
{
    return userId_;
}
void Comments::setUserId(const int32_t &pUserId) noexcept
{
    userId_ = std::make_shared<int32_t>(pUserId);
    dirtyFlag_[3] = true;
}


void Comments::setUserIdToNull() noexcept
{
    userId_.reset();
    dirtyFlag_[3] = true;
}

const ::trantor::Date &Comments::getValueOfCreatedAt() const noexcept
{
    const static ::trantor::Date defaultValue = ::trantor::Date();
    if(createdAt_)
        return *createdAt_;
    return defaultValue;
}
const std::shared_ptr<::trantor::Date> &Comments::getCreatedAt() const noexcept
{
    return createdAt_;
}
void Comments::setCreatedAt(const ::trantor::Date &pCreatedAt) noexcept
{
    createdAt_ = std::make_shared<::trantor::Date>(pCreatedAt);
    dirtyFlag_[4] = true;
}



const ::trantor::Date &Comments::getValueOfUpdatedAt() const noexcept
{
    const static ::trantor::Date defaultValue = ::trantor::Date();
    if(updatedAt_)
        return *updatedAt_;
    return defaultValue;
}
const std::shared_ptr<::trantor::Date> &Comments::getUpdatedAt() const noexcept
{
    return updatedAt_;
}
void Comments::setUpdatedAt(const ::trantor::Date &pUpdatedAt) noexcept
{
    updatedAt_ = std::make_shared<::trantor::Date>(pUpdatedAt);
    dirtyFlag_[5] = true;
}



void Comments::updateId(const uint64_t id)
{
}

const std::vector<std::string> &Comments::insertColumns() noexcept
{
    static const std::vector<std::string> inCols={
        "body",
        "article_id",
        "user_id",
        "created_at",
        "updated_at"
    };
    return inCols;
}

void Comments::outputArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[1])
    {
        if(getBody())
        {
            binder << getValueOfBody();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[2])
    {
        if(getArticleId())
        {
            binder << getValueOfArticleId();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[3])
    {
        if(getUserId())
        {
            binder << getValueOfUserId();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[4])
    {
        if(getCreatedAt())
        {
            binder << getValueOfCreatedAt();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[5])
    {
        if(getUpdatedAt())
        {
            binder << getValueOfUpdatedAt();
        }
        else
        {
            binder << nullptr;
        }
    }
}

const std::vector<std::string> Comments::updateColumns() const
{
    std::vector<std::string> ret;
    for(size_t i=0;i<sizeof(dirtyFlag_);i++)
    {
        if(dirtyFlag_[i])
        {
            ret.push_back(getColumnName(i));
        }
    }
    return ret;
}

void Comments::updateArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[1])
    {
        if(getBody())
        {
            binder << getValueOfBody();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[2])
    {
        if(getArticleId())
        {
            binder << getValueOfArticleId();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[3])
    {
        if(getUserId())
        {
            binder << getValueOfUserId();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[4])
    {
        if(getCreatedAt())
        {
            binder << getValueOfCreatedAt();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[5])
    {
        if(getUpdatedAt())
        {
            binder << getValueOfUpdatedAt();
        }
        else
        {
            binder << nullptr;
        }
    }
}
Json::Value Comments::toJson() const
{
    Json::Value ret;
    if(getId())
    {
        ret["id"]=getValueOfId();
    }
    else
    {
        ret["id"]=Json::Value();
    }
    if(getBody())
    {
        ret["body"]=getValueOfBody();
    }
    else
    {
        ret["body"]=Json::Value();
    }
    if(getArticleId())
    {
        ret["article_id"]=getValueOfArticleId();
    }
    else
    {
        ret["article_id"]=Json::Value();
    }
    if(getUserId())
    {
        ret["user_id"]=getValueOfUserId();
    }
    else
    {
        ret["user_id"]=Json::Value();
    }
    if(getCreatedAt())
    {
        ret["created_at"]=getCreatedAt()->toDbStringLocal();
    }
    else
    {
        ret["created_at"]=Json::Value();
    }
    if(getUpdatedAt())
    {
        ret["updated_at"]=getUpdatedAt()->toDbStringLocal();
    }
    else
    {
        ret["updated_at"]=Json::Value();
    }
    return ret;
}

Json::Value Comments::toMasqueradedJson(
    const std::vector<std::string> &pMasqueradingVector) const
{
    Json::Value ret;
    if(pMasqueradingVector.size() == 6)
    {
        if(!pMasqueradingVector[0].empty())
        {
            if(getId())
            {
                ret[pMasqueradingVector[0]]=getValueOfId();
            }
            else
            {
                ret[pMasqueradingVector[0]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[1].empty())
        {
            if(getBody())
            {
                ret[pMasqueradingVector[1]]=getValueOfBody();
            }
            else
            {
                ret[pMasqueradingVector[1]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[2].empty())
        {
            if(getArticleId())
            {
                ret[pMasqueradingVector[2]]=getValueOfArticleId();
            }
            else
            {
                ret[pMasqueradingVector[2]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[3].empty())
        {
            if(getUserId())
            {
                ret[pMasqueradingVector[3]]=getValueOfUserId();
            }
            else
            {
                ret[pMasqueradingVector[3]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[4].empty())
        {
            if(getCreatedAt())
            {
                ret[pMasqueradingVector[4]]=getCreatedAt()->toDbStringLocal();
            }
            else
            {
                ret[pMasqueradingVector[4]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[5].empty())
        {
            if(getUpdatedAt())
            {
                ret[pMasqueradingVector[5]]=getUpdatedAt()->toDbStringLocal();
            }
            else
            {
                ret[pMasqueradingVector[5]]=Json::Value();
            }
        }
        return ret;
    }
    LOG_ERROR << "Masquerade failed";
    if(getId())
    {
        ret["id"]=getValueOfId();
    }
    else
    {
        ret["id"]=Json::Value();
    }
    if(getBody())
    {
        ret["body"]=getValueOfBody();
    }
    else
    {
        ret["body"]=Json::Value();
    }
    if(getArticleId())
    {
        ret["article_id"]=getValueOfArticleId();
    }
    else
    {
        ret["article_id"]=Json::Value();
    }
    if(getUserId())
    {
        ret["user_id"]=getValueOfUserId();
    }
    else
    {
        ret["user_id"]=Json::Value();
    }
    if(getCreatedAt())
    {
        ret["created_at"]=getCreatedAt()->toDbStringLocal();
    }
    else
    {
        ret["created_at"]=Json::Value();
    }
    if(getUpdatedAt())
    {
        ret["updated_at"]=getUpdatedAt()->toDbStringLocal();
    }
    else
    {
        ret["updated_at"]=Json::Value();
    }
    return ret;
}

bool Comments::validateJsonForCreation(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("id"))
    {
        if(!validJsonOfField(0, "id", pJson["id"], err, true))
            return false;
    }
    if(pJson.isMember("body"))
    {
        if(!validJsonOfField(1, "body", pJson["body"], err, true))
            return false;
    }
    if(pJson.isMember("article_id"))
    {
        if(!validJsonOfField(2, "article_id", pJson["article_id"], err, true))
            return false;
    }
    if(pJson.isMember("user_id"))
    {
        if(!validJsonOfField(3, "user_id", pJson["user_id"], err, true))
            return false;
    }
    if(pJson.isMember("created_at"))
    {
        if(!validJsonOfField(4, "created_at", pJson["created_at"], err, true))
            return false;
    }
    else
    {
        err="The created_at column cannot be null";
        return false;
    }
    if(pJson.isMember("updated_at"))
    {
        if(!validJsonOfField(5, "updated_at", pJson["updated_at"], err, true))
            return false;
    }
    return true;
}
bool Comments::validateMasqueradedJsonForCreation(const Json::Value &pJson,
                                                  const std::vector<std::string> &pMasqueradingVector,
                                                  std::string &err)
{
    if(pMasqueradingVector.size() != 6)
    {
        err = "Bad masquerading vector";
        return false;
    }
    if(!pMasqueradingVector[0].empty())
    {
        if(pJson.isMember(pMasqueradingVector[0]))
        {
            if(!validJsonOfField(0, pMasqueradingVector[0], pJson[pMasqueradingVector[0]], err, true))
                return false;
        }
    }
    if(!pMasqueradingVector[1].empty())
    {
        if(pJson.isMember(pMasqueradingVector[1]))
        {
            if(!validJsonOfField(1, pMasqueradingVector[1], pJson[pMasqueradingVector[1]], err, true))
                return false;
        }
    }
    if(!pMasqueradingVector[2].empty())
    {
        if(pJson.isMember(pMasqueradingVector[2]))
        {
            if(!validJsonOfField(2, pMasqueradingVector[2], pJson[pMasqueradingVector[2]], err, true))
                return false;
        }
    }
    if(!pMasqueradingVector[3].empty())
    {
        if(pJson.isMember(pMasqueradingVector[3]))
        {
            if(!validJsonOfField(3, pMasqueradingVector[3], pJson[pMasqueradingVector[3]], err, true))
                return false;
        }
    }
    if(!pMasqueradingVector[4].empty())
    {
        if(pJson.isMember(pMasqueradingVector[4]))
        {
            if(!validJsonOfField(4, pMasqueradingVector[4], pJson[pMasqueradingVector[4]], err, true))
                return false;
        }
        else
        {
            err="The " + pMasqueradingVector[4] + " column cannot be null";
            return false;
        }
    }
    if(!pMasqueradingVector[5].empty())
    {
        if(pJson.isMember(pMasqueradingVector[5]))
        {
            if(!validJsonOfField(5, pMasqueradingVector[5], pJson[pMasqueradingVector[5]], err, true))
                return false;
        }
    }
    return true;
}
bool Comments::validateJsonForUpdate(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("id"))
    {
        if(!validJsonOfField(0, "id", pJson["id"], err, false))
            return false;
    }
    else
    {
        err = "The value of primary key must be set in the json object for update";
        return false;
    }
    if(pJson.isMember("body"))
    {
        if(!validJsonOfField(1, "body", pJson["body"], err, false))
            return false;
    }
    if(pJson.isMember("article_id"))
    {
        if(!validJsonOfField(2, "article_id", pJson["article_id"], err, false))
            return false;
    }
    if(pJson.isMember("user_id"))
    {
        if(!validJsonOfField(3, "user_id", pJson["user_id"], err, false))
            return false;
    }
    if(pJson.isMember("created_at"))
    {
        if(!validJsonOfField(4, "created_at", pJson["created_at"], err, false))
            return false;
    }
    if(pJson.isMember("updated_at"))
    {
        if(!validJsonOfField(5, "updated_at", pJson["updated_at"], err, false))
            return false;
    }
    return true;
}
bool Comments::validateMasqueradedJsonForUpdate(const Json::Value &pJson,
                                                const std::vector<std::string> &pMasqueradingVector,
                                                std::string &err)
{
    if(pMasqueradingVector.size() != 6)
    {
        err = "Bad masquerading vector";
        return false;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        if(!validJsonOfField(0, pMasqueradingVector[0], pJson[pMasqueradingVector[0]], err, false))
            return false;
    }
    else
    {
        err = "The value of primary key must be set in the json object for update";
        return false;
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        if(!validJsonOfField(1, pMasqueradingVector[1], pJson[pMasqueradingVector[1]], err, false))
            return false;
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        if(!validJsonOfField(2, pMasqueradingVector[2], pJson[pMasqueradingVector[2]], err, false))
            return false;
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        if(!validJsonOfField(3, pMasqueradingVector[3], pJson[pMasqueradingVector[3]], err, false))
            return false;
    }
    if(!pMasqueradingVector[4].empty() && pJson.isMember(pMasqueradingVector[4]))
    {
        if(!validJsonOfField(4, pMasqueradingVector[4], pJson[pMasqueradingVector[4]], err, false))
            return false;
    }
    if(!pMasqueradingVector[5].empty() && pJson.isMember(pMasqueradingVector[5]))
    {
        if(!validJsonOfField(5, pMasqueradingVector[5], pJson[pMasqueradingVector[5]], err, false))
            return false;
    }
    return true;
}
bool Comments::validJsonOfField(size_t index,
                                const std::string &fieldName,
                                const Json::Value &pJson, 
                                std::string &err, 
                                bool isForCreation)
{
    switch(index)
    {
        case 0:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(isForCreation)
            {
                err="The automatic primary key cannot be set";
                return false;
            }        
            if(!pJson.isInt())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 1:
            if(pJson.isNull())
            {
                return true;
            }
            if(!pJson.isString())
            {
                err="Type error in the "+fieldName+" field";
                return false;                
            }
            break;
        case 2:
            if(pJson.isNull())
            {
                return true;
            }
            if(!pJson.isInt())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 3:
            if(pJson.isNull())
            {
                return true;
            }
            if(!pJson.isInt())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 4:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(!pJson.isString())
            {
                err="Type error in the "+fieldName+" field";
                return false;                
            }
            break;
        case 5:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(!pJson.isString())
            {
                err="Type error in the "+fieldName+" field";
                return false;                
            }
            break;
     
        default:
            err="Internal error in the server";
            return false;
            break;
    }
    return true;
}
