/**
 *
 *  ArticleTags.cc
 *  DO NOT EDIT. This file is generated by drogon_ctl
 *
 */

#include "ArticleTags.h"
#include <drogon/utils/Utilities.h>
#include <string>

using namespace drogon;
using namespace drogon_model::realworld;

const std::string ArticleTags::Cols::_article_id = "article_id";
const std::string ArticleTags::Cols::_tag_id = "tag_id";
const std::string ArticleTags::primaryKeyName = "";
const bool ArticleTags::hasPrimaryKey = false;
const std::string ArticleTags::tableName = "article_tags";

const std::vector<typename ArticleTags::MetaData> ArticleTags::metaData_={
{"article_id","std::string","character varying",255,0,0,1},
{"tag_id","std::string","character varying",255,0,0,1}
};
const std::string &ArticleTags::getColumnName(size_t index) noexcept(false)
{
    assert(index < metaData_.size());
    return metaData_[index].colName_;
}
ArticleTags::ArticleTags(const Row &r, const ssize_t indexOffset) noexcept
{
    if(indexOffset < 0)
    {
        if(!r["article_id"].isNull())
        {
            articleId_=std::make_shared<std::string>(r["article_id"].as<std::string>());
        }
        if(!r["tag_id"].isNull())
        {
            tagId_=std::make_shared<std::string>(r["tag_id"].as<std::string>());
        }
    }
    else
    {
        size_t offset = (size_t)indexOffset;
        if(offset + 2 > r.size())
        {
            LOG_FATAL << "Invalid SQL result for this model";
            return;
        }
        size_t index;
        index = offset + 0;
        if(!r[index].isNull())
        {
            articleId_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 1;
        if(!r[index].isNull())
        {
            tagId_=std::make_shared<std::string>(r[index].as<std::string>());
        }
    }

}

ArticleTags::ArticleTags(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 2)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        dirtyFlag_[0] = true;
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            articleId_=std::make_shared<std::string>(pJson[pMasqueradingVector[0]].asString());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            tagId_=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
        }
    }
}

ArticleTags::ArticleTags(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("article_id"))
    {
        dirtyFlag_[0]=true;
        if(!pJson["article_id"].isNull())
        {
            articleId_=std::make_shared<std::string>(pJson["article_id"].asString());
        }
    }
    if(pJson.isMember("tag_id"))
    {
        dirtyFlag_[1]=true;
        if(!pJson["tag_id"].isNull())
        {
            tagId_=std::make_shared<std::string>(pJson["tag_id"].asString());
        }
    }
}

void ArticleTags::updateByMasqueradedJson(const Json::Value &pJson,
                                            const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 2)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        dirtyFlag_[0] = true;
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            articleId_=std::make_shared<std::string>(pJson[pMasqueradingVector[0]].asString());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            tagId_=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
        }
    }
}
                                                                    
void ArticleTags::updateByJson(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("article_id"))
    {
        dirtyFlag_[0] = true;
        if(!pJson["article_id"].isNull())
        {
            articleId_=std::make_shared<std::string>(pJson["article_id"].asString());
        }
    }
    if(pJson.isMember("tag_id"))
    {
        dirtyFlag_[1] = true;
        if(!pJson["tag_id"].isNull())
        {
            tagId_=std::make_shared<std::string>(pJson["tag_id"].asString());
        }
    }
}

const std::string &ArticleTags::getValueOfArticleId() const noexcept
{
    const static std::string defaultValue = std::string();
    if(articleId_)
        return *articleId_;
    return defaultValue;
}
const std::shared_ptr<std::string> &ArticleTags::getArticleId() const noexcept
{
    return articleId_;
}
void ArticleTags::setArticleId(const std::string &pArticleId) noexcept
{
    articleId_ = std::make_shared<std::string>(pArticleId);
    dirtyFlag_[0] = true;
}
void ArticleTags::setArticleId(std::string &&pArticleId) noexcept
{
    articleId_ = std::make_shared<std::string>(std::move(pArticleId));
    dirtyFlag_[0] = true;
}



const std::string &ArticleTags::getValueOfTagId() const noexcept
{
    const static std::string defaultValue = std::string();
    if(tagId_)
        return *tagId_;
    return defaultValue;
}
const std::shared_ptr<std::string> &ArticleTags::getTagId() const noexcept
{
    return tagId_;
}
void ArticleTags::setTagId(const std::string &pTagId) noexcept
{
    tagId_ = std::make_shared<std::string>(pTagId);
    dirtyFlag_[1] = true;
}
void ArticleTags::setTagId(std::string &&pTagId) noexcept
{
    tagId_ = std::make_shared<std::string>(std::move(pTagId));
    dirtyFlag_[1] = true;
}



void ArticleTags::updateId(const uint64_t id)
{
}

const std::vector<std::string> &ArticleTags::insertColumns() noexcept
{
    static const std::vector<std::string> inCols={
        "article_id",
        "tag_id"
    };
    return inCols;
}

void ArticleTags::outputArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[0])
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
    if(dirtyFlag_[1])
    {
        if(getTagId())
        {
            binder << getValueOfTagId();
        }
        else
        {
            binder << nullptr;
        }
    }
}

const std::vector<std::string> ArticleTags::updateColumns() const
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

void ArticleTags::updateArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[0])
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
    if(dirtyFlag_[1])
    {
        if(getTagId())
        {
            binder << getValueOfTagId();
        }
        else
        {
            binder << nullptr;
        }
    }
}
Json::Value ArticleTags::toJson() const
{
    Json::Value ret;
    if(getArticleId())
    {
        ret["article_id"]=getValueOfArticleId();
    }
    else
    {
        ret["article_id"]=Json::Value();
    }
    if(getTagId())
    {
        ret["tag_id"]=getValueOfTagId();
    }
    else
    {
        ret["tag_id"]=Json::Value();
    }
    return ret;
}

Json::Value ArticleTags::toMasqueradedJson(
    const std::vector<std::string> &pMasqueradingVector) const
{
    Json::Value ret;
    if(pMasqueradingVector.size() == 2)
    {
        if(!pMasqueradingVector[0].empty())
        {
            if(getArticleId())
            {
                ret[pMasqueradingVector[0]]=getValueOfArticleId();
            }
            else
            {
                ret[pMasqueradingVector[0]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[1].empty())
        {
            if(getTagId())
            {
                ret[pMasqueradingVector[1]]=getValueOfTagId();
            }
            else
            {
                ret[pMasqueradingVector[1]]=Json::Value();
            }
        }
        return ret;
    }
    LOG_ERROR << "Masquerade failed";
    if(getArticleId())
    {
        ret["article_id"]=getValueOfArticleId();
    }
    else
    {
        ret["article_id"]=Json::Value();
    }
    if(getTagId())
    {
        ret["tag_id"]=getValueOfTagId();
    }
    else
    {
        ret["tag_id"]=Json::Value();
    }
    return ret;
}

bool ArticleTags::validateJsonForCreation(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("article_id"))
    {
        if(!validJsonOfField(0, "article_id", pJson["article_id"], err, true))
            return false;
    }
    else
    {
        err="The article_id column cannot be null";
        return false;
    }
    if(pJson.isMember("tag_id"))
    {
        if(!validJsonOfField(1, "tag_id", pJson["tag_id"], err, true))
            return false;
    }
    else
    {
        err="The tag_id column cannot be null";
        return false;
    }
    return true;
}
bool ArticleTags::validateMasqueradedJsonForCreation(const Json::Value &pJson,
                                                     const std::vector<std::string> &pMasqueradingVector,
                                                     std::string &err)
{
    if(pMasqueradingVector.size() != 2)
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
        else
        {
            err="The " + pMasqueradingVector[0] + " column cannot be null";
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
        else
        {
            err="The " + pMasqueradingVector[1] + " column cannot be null";
            return false;
        }
    }
    return true;
}
bool ArticleTags::validateJsonForUpdate(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("article_id"))
    {
        if(!validJsonOfField(0, "article_id", pJson["article_id"], err, false))
            return false;
    }
    if(pJson.isMember("tag_id"))
    {
        if(!validJsonOfField(1, "tag_id", pJson["tag_id"], err, false))
            return false;
    }
    return true;
}
bool ArticleTags::validateMasqueradedJsonForUpdate(const Json::Value &pJson,
                                                   const std::vector<std::string> &pMasqueradingVector,
                                                   std::string &err)
{
    if(pMasqueradingVector.size() != 2)
    {
        err = "Bad masquerading vector";
        return false;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        if(!validJsonOfField(0, pMasqueradingVector[0], pJson[pMasqueradingVector[0]], err, false))
            return false;
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        if(!validJsonOfField(1, pMasqueradingVector[1], pJson[pMasqueradingVector[1]], err, false))
            return false;
    }
    return true;
}
bool ArticleTags::validJsonOfField(size_t index,
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
            if(!pJson.isString())
            {
                err="Type error in the "+fieldName+" field";
                return false;                
            }
            // asString().length() creates a string object, is there any better way to validate the length?
            if(pJson.isString() && pJson.asString().length() > 255)
            {
                err="String length exceeds limit for the " +
                    fieldName +
                    " field (the maximum value is 255)";
                return false;               
            }

            break;
        case 1:
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
            // asString().length() creates a string object, is there any better way to validate the length?
            if(pJson.isString() && pJson.asString().length() > 255)
            {
                err="String length exceeds limit for the " +
                    fieldName +
                    " field (the maximum value is 255)";
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
