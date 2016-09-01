#include "json/json.h"
#include <fstream>
#include <ace/Log_Msg.h>
#include "DMRedis.h"

DMRedis::DMRedis():_redis_ctx(NULL)
{
    init();
}

DMRedis::~DMRedis()
{
    if (NULL != _redis_ctx)
    {
        disconnect_redis();
    }
}

bool DMRedis::load_redis_config()
{
    std::ifstream cfg_file;
    cfg_file.open(REDIS_CFG_FILE, std::ios::binary);

    if (!cfg_file.is_open())
    { 
        return 0;
    }

    Json::Reader Reader;
    Json::Value Root;

    if (Reader.parse(cfg_file,Root))
    {
        _redis_cfg.ip = Root["redis_ip"].asString();
        _redis_cfg.port= Root["redis_port"].asInt();
    }
    else
    {
        ACE_DEBUG((LM_ERROR,"parse redis config file failure!\n"));    
        return false;
    }
    
    return true;
}

void DMRedis::init()
{
    if (load_redis_config())
    {
        conncet_redis(_redis_cfg.ip, _redis_cfg.port);
    }
}

bool DMRedis::conncet_redis(std::string ip, int port)
{
    _redis_ctx = redisConnect(ip.c_str(), port);
    
    if (_redis_ctx == NULL || _redis_ctx->err) 
    {
        if (_redis_ctx) 
        {
            // handle error
            ACE_DEBUG((LM_ERROR,"connect redis error: %s\n", _redis_ctx->errstr));
        } 
        else 
        {
            ACE_DEBUG((LM_ERROR,"Can't allocate redis context\n"));
        }
        
        return false;
    }

    return true;
}

void DMRedis::disconnect_redis()
{
    redisFree(_redis_ctx);
    _redis_ctx = NULL;
}

bool DMRedis::write_redis_cmd(std::string cmd)
{
    if (NULL == redisCommand(_redis_ctx, cmd.c_str()))
    {
        ACE_DEBUG((LM_ERROR,"redis write %s failure!\n", cmd));
        return false;
    }
    return true;
}

std::string DMRedis::read_redis_cmd(std::string cmd)
{
    redisReply *reply;
    reply = (redisReply*)redisCommand(_redis_ctx, cmd.c_str());
    freeReplyObject(reply);
    return reply->str;
}

std::string DMRedis::read_redis_string(std::string keys)
{
    redisReply *reply;
    reply = (redisReply*)redisCommand(_redis_ctx, "GET %s", keys.c_str());
    freeReplyObject(reply);
    return reply->str;
}

std::string DMRedis::read_redis_hash(std::string keys, std::string domain)
{
    redisReply *reply;
    reply = (redisReply*)redisCommand(_redis_ctx, "HGET %s %s", keys.c_str(), domain.c_str());
    freeReplyObject(reply);
    return reply->str;    
}

bool DMRedis::ping_redis()
{
    redisReply *reply;
    reply = (redisReply*)redisCommand(_redis_ctx, "PING");

    std::string result = reply->str;
    if ("PONG" == result)
    {
        return true;
    }
    
    ACE_DEBUG((LM_ERROR,"redis disconnected!\n"));
    return false;
}

