/**
 *
 *  ArticleTags.h
 *  DO NOT EDIT. This file is generated by drogon_ctl
 *
 */

#pragma once
#include <drogon/orm/Result.h>
#include <drogon/orm/Row.h>
#include <drogon/orm/Field.h>
#include <drogon/orm/SqlBinder.h>
#include <drogon/orm/Mapper.h>
#include <trantor/utils/Date.h>
#include <trantor/utils/Logger.h>
#include <json/json.h>
#include <string>
#include <memory>
#include <vector>
#include <tuple>
#include <stdint.h>
#include <iostream>

using namespace drogon::orm;
namespace drogon
{
namespace orm
{
class DbClient;
using DbClientPtr = std::shared_ptr<DbClient>;
}
}
namespace drogon_model
{
namespace realworld 
{

class ArticleTags
{
  public:
    struct Cols
    {
        static const std::string _article_id;
        static const std::string _tag_id;
    };

    const static int primaryKeyNumber;
    const static std::string tableName;
    const static bool hasPrimaryKey;
    const static std::string primaryKeyName;
    using PrimaryKeyType = void;
    int getPrimaryKey() const { assert(false); return 0; }

    /**
     * @brief constructor
     * @param r One row of records in the SQL query result.
     * @param indexOffset Set the offset to -1 to access all columns by column names, 
     * otherwise access all columns by offsets.
     * @note If the SQL is not a style of 'select * from table_name ...' (select all 
     * columns by an asterisk), please set the offset to -1.
     */
    explicit ArticleTags(const Row &r, const ssize_t indexOffset = 0) noexcept;

    /**
     * @brief constructor
     * @param pJson The json object to construct a new instance.
     */
    explicit ArticleTags(const Json::Value &pJson) noexcept(false);

    /**
     * @brief constructor
     * @param pJson The json object to construct a new instance.
     * @param pMasqueradingVector The aliases of table columns.
     */
    ArticleTags(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false);

    ArticleTags() = default;
    
    void updateByJson(const Json::Value &pJson) noexcept(false);
    void updateByMasqueradedJson(const Json::Value &pJson,
                                 const std::vector<std::string> &pMasqueradingVector) noexcept(false);
    static bool validateJsonForCreation(const Json::Value &pJson, std::string &err);
    static bool validateMasqueradedJsonForCreation(const Json::Value &,
                                                const std::vector<std::string> &pMasqueradingVector,
                                                    std::string &err);
    static bool validateJsonForUpdate(const Json::Value &pJson, std::string &err);
    static bool validateMasqueradedJsonForUpdate(const Json::Value &,
                                          const std::vector<std::string> &pMasqueradingVector,
                                          std::string &err);
    static bool validJsonOfField(size_t index,
                          const std::string &fieldName,
                          const Json::Value &pJson, 
                          std::string &err, 
                          bool isForCreation);

    /**  For column article_id  */
    ///Get the value of the column article_id, returns the default value if the column is null
    const std::string &getValueOfArticleId() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getArticleId() const noexcept;
    ///Set the value of the column article_id
    void setArticleId(const std::string &pArticleId) noexcept;
    void setArticleId(std::string &&pArticleId) noexcept;

    /**  For column tag_id  */
    ///Get the value of the column tag_id, returns the default value if the column is null
    const std::string &getValueOfTagId() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getTagId() const noexcept;
    ///Set the value of the column tag_id
    void setTagId(const std::string &pTagId) noexcept;
    void setTagId(std::string &&pTagId) noexcept;


    static size_t getColumnNumber() noexcept {  return 2;  }
    static const std::string &getColumnName(size_t index) noexcept(false);

    Json::Value toJson() const;
    Json::Value toMasqueradedJson(const std::vector<std::string> &pMasqueradingVector) const;
    /// Relationship interfaces
  private:
    friend Mapper<ArticleTags>;
    static const std::vector<std::string> &insertColumns() noexcept;
    void outputArgs(drogon::orm::internal::SqlBinder &binder) const;
    const std::vector<std::string> updateColumns() const;
    void updateArgs(drogon::orm::internal::SqlBinder &binder) const;
    ///For mysql or sqlite3
    void updateId(const uint64_t id);
    std::shared_ptr<std::string> articleId_;
    std::shared_ptr<std::string> tagId_;
    struct MetaData
    {
        const std::string colName_;
        const std::string colType_;
        const std::string colDatabaseType_;
        const ssize_t colLength_;
        const bool isAutoVal_;
        const bool isPrimaryKey_;
        const bool notNull_;
    };
    static const std::vector<MetaData> metaData_;
    bool dirtyFlag_[2]={ false };
  public:
    static const std::string &sqlForFindingByPrimaryKey()
    {
        static const std::string sql="";
        return sql;                   
    }

    static const std::string &sqlForDeletingByPrimaryKey()
    {
        static const std::string sql="";
        return sql;                   
    }
    std::string sqlForInserting(bool &needSelection) const
    {
        std::string sql="insert into " + tableName + " (";
        size_t parametersCount = 0;
        needSelection = false;
        if(dirtyFlag_[0])
        {
            sql += "article_id,";
            ++parametersCount;
        }
        if(dirtyFlag_[1])
        {
            sql += "tag_id,";
            ++parametersCount;
        }
        if(parametersCount > 0)
        {
            sql[sql.length()-1]=')';
            sql += " values (";
        }
        else
            sql += ") values (";
        
        int placeholder=1;
        char placeholderStr[64];
        size_t n=0;
        if(dirtyFlag_[0])
        {
            n = sprintf(placeholderStr,"$%d,",placeholder++);
            sql.append(placeholderStr, n);
        } 
        if(dirtyFlag_[1])
        {
            n = sprintf(placeholderStr,"$%d,",placeholder++);
            sql.append(placeholderStr, n);
        } 
        if(parametersCount > 0)
        {
            sql.resize(sql.length() - 1);
        }
        if(needSelection)
        {
            sql.append(") returning *");
        }
        else
        {
            sql.append(1, ')');
        }
        LOG_TRACE << sql;
        return sql;   
    }
};
} // namespace realworld
} // namespace drogon_model
