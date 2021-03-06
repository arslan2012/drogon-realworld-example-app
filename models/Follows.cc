/**
 *
 *  Follows.cc
 *  DO NOT EDIT. This file is generated by drogon_ctl
 *
 */

#include "Follows.h"
#include <drogon/utils/Utilities.h>
#include <string>

using namespace drogon;
using namespace drogon_model::realworld;

const std::string Follows::Cols::_user_id = "user_id";
const std::string Follows::Cols::_follow_id = "follow_id";
const std::string Follows::primaryKeyName = "";
const bool Follows::hasPrimaryKey = false;
const std::string Follows::tableName = "follows";

const std::vector<typename Follows::MetaData> Follows::metaData_={
{"user_id","int32_t","integer",4,0,0,1},
{"follow_id","int32_t","integer",4,0,0,1}
};
const std::string &Follows::getColumnName(size_t index) noexcept(false)
{
    assert(index < metaData_.size());
    return metaData_[index].colName_;
}
Follows::Follows(const Row &r, const ssize_t indexOffset) noexcept
{
    if(indexOffset < 0)
    {
        if(!r["user_id"].isNull())
        {
            userId_=std::make_shared<int32_t>(r["user_id"].as<int32_t>());
        }
        if(!r["follow_id"].isNull())
        {
            followId_=std::make_shared<int32_t>(r["follow_id"].as<int32_t>());
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
            userId_=std::make_shared<int32_t>(r[index].as<int32_t>());
        }
        index = offset + 1;
        if(!r[index].isNull())
        {
            followId_=std::make_shared<int32_t>(r[index].as<int32_t>());
        }
    }

}

Follows::Follows(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false)
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
            userId_=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[0]].asInt64());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            followId_=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[1]].asInt64());
        }
    }
}

Follows::Follows(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("user_id"))
    {
        dirtyFlag_[0]=true;
        if(!pJson["user_id"].isNull())
        {
            userId_=std::make_shared<int32_t>((int32_t)pJson["user_id"].asInt64());
        }
    }
    if(pJson.isMember("follow_id"))
    {
        dirtyFlag_[1]=true;
        if(!pJson["follow_id"].isNull())
        {
            followId_=std::make_shared<int32_t>((int32_t)pJson["follow_id"].asInt64());
        }
    }
}

void Follows::updateByMasqueradedJson(const Json::Value &pJson,
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
            userId_=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[0]].asInt64());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            followId_=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[1]].asInt64());
        }
    }
}
                                                                    
void Follows::updateByJson(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("user_id"))
    {
        dirtyFlag_[0] = true;
        if(!pJson["user_id"].isNull())
        {
            userId_=std::make_shared<int32_t>((int32_t)pJson["user_id"].asInt64());
        }
    }
    if(pJson.isMember("follow_id"))
    {
        dirtyFlag_[1] = true;
        if(!pJson["follow_id"].isNull())
        {
            followId_=std::make_shared<int32_t>((int32_t)pJson["follow_id"].asInt64());
        }
    }
}

const int32_t &Follows::getValueOfUserId() const noexcept
{
    const static int32_t defaultValue = int32_t();
    if(userId_)
        return *userId_;
    return defaultValue;
}
const std::shared_ptr<int32_t> &Follows::getUserId() const noexcept
{
    return userId_;
}
void Follows::setUserId(const int32_t &pUserId) noexcept
{
    userId_ = std::make_shared<int32_t>(pUserId);
    dirtyFlag_[0] = true;
}



const int32_t &Follows::getValueOfFollowId() const noexcept
{
    const static int32_t defaultValue = int32_t();
    if(followId_)
        return *followId_;
    return defaultValue;
}
const std::shared_ptr<int32_t> &Follows::getFollowId() const noexcept
{
    return followId_;
}
void Follows::setFollowId(const int32_t &pFollowId) noexcept
{
    followId_ = std::make_shared<int32_t>(pFollowId);
    dirtyFlag_[1] = true;
}



void Follows::updateId(const uint64_t id)
{
}

const std::vector<std::string> &Follows::insertColumns() noexcept
{
    static const std::vector<std::string> inCols={
        "user_id",
        "follow_id"
    };
    return inCols;
}

void Follows::outputArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[0])
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
    if(dirtyFlag_[1])
    {
        if(getFollowId())
        {
            binder << getValueOfFollowId();
        }
        else
        {
            binder << nullptr;
        }
    }
}

const std::vector<std::string> Follows::updateColumns() const
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

void Follows::updateArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[0])
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
    if(dirtyFlag_[1])
    {
        if(getFollowId())
        {
            binder << getValueOfFollowId();
        }
        else
        {
            binder << nullptr;
        }
    }
}
Json::Value Follows::toJson() const
{
    Json::Value ret;
    if(getUserId())
    {
        ret["user_id"]=getValueOfUserId();
    }
    else
    {
        ret["user_id"]=Json::Value();
    }
    if(getFollowId())
    {
        ret["follow_id"]=getValueOfFollowId();
    }
    else
    {
        ret["follow_id"]=Json::Value();
    }
    return ret;
}

Json::Value Follows::toMasqueradedJson(
    const std::vector<std::string> &pMasqueradingVector) const
{
    Json::Value ret;
    if(pMasqueradingVector.size() == 2)
    {
        if(!pMasqueradingVector[0].empty())
        {
            if(getUserId())
            {
                ret[pMasqueradingVector[0]]=getValueOfUserId();
            }
            else
            {
                ret[pMasqueradingVector[0]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[1].empty())
        {
            if(getFollowId())
            {
                ret[pMasqueradingVector[1]]=getValueOfFollowId();
            }
            else
            {
                ret[pMasqueradingVector[1]]=Json::Value();
            }
        }
        return ret;
    }
    LOG_ERROR << "Masquerade failed";
    if(getUserId())
    {
        ret["user_id"]=getValueOfUserId();
    }
    else
    {
        ret["user_id"]=Json::Value();
    }
    if(getFollowId())
    {
        ret["follow_id"]=getValueOfFollowId();
    }
    else
    {
        ret["follow_id"]=Json::Value();
    }
    return ret;
}

bool Follows::validateJsonForCreation(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("user_id"))
    {
        if(!validJsonOfField(0, "user_id", pJson["user_id"], err, true))
            return false;
    }
    else
    {
        err="The user_id column cannot be null";
        return false;
    }
    if(pJson.isMember("follow_id"))
    {
        if(!validJsonOfField(1, "follow_id", pJson["follow_id"], err, true))
            return false;
    }
    else
    {
        err="The follow_id column cannot be null";
        return false;
    }
    return true;
}
bool Follows::validateMasqueradedJsonForCreation(const Json::Value &pJson,
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
bool Follows::validateJsonForUpdate(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("user_id"))
    {
        if(!validJsonOfField(0, "user_id", pJson["user_id"], err, false))
            return false;
    }
    if(pJson.isMember("follow_id"))
    {
        if(!validJsonOfField(1, "follow_id", pJson["follow_id"], err, false))
            return false;
    }
    return true;
}
bool Follows::validateMasqueradedJsonForUpdate(const Json::Value &pJson,
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
bool Follows::validJsonOfField(size_t index,
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
            if(!pJson.isInt())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 1:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(!pJson.isInt())
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
