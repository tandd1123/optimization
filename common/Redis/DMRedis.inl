#pragma once
#include <ace/Log_Msg.h>
#include "DMRedis.h"
#include "hiredis/hiredis.h"
#include <sstream>

template <typename T1, typename T2> 
std::string DMRedis::pack_domain(T1 key_field, T2 value_field)
{
    std::ostringstream strStream;
    std::string key,value;
    
    strStream << key_field;
    key = strStream.str();

    strStream.str("");
    strStream << value_field;
    value = strStream.str();
    return key + ":" + value;
}

template<typename T>
bool DMRedis::write_redis_string(std::string keys, T value)
{
    std::ostringstream strStream;
    std::string strValue;
    
    strStream << value;
    strValue = strStream.str();
    
    if (NULL == redisCommand(_redis_ctx, "SET %s %s", keys.c_str(),strValue.c_str()))
    {
        ACE_DEBUG((LM_ERROR,"redis write %s failure!\n", keys.c_str()));
        return false;
    }
    return true;
}

template<typename T>
bool DMRedis::write_redis_hash(std::string keys, std::string domain, T value)
{
    std::stringstream ostrStream;
    std::string strValue;
    
    ostrStream << value;
    strValue = ostrStream.str();

    if (NULL == redisCommand(_redis_ctx, "HSET %s %s %s", keys.c_str(), domain.c_str(), strValue.c_str()))
    {
        ACE_DEBUG((LM_ERROR,"redis write %s failure!\n", keys.c_str()));
        return false;
    }
    return true;
}
