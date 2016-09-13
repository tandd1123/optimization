//=============================================================================
/* 
*  File: DMServiceMap.h
*
*  Author: bing
*
*  Date: 2016-09-01
*
*  Version: v2.0
*
*  Github/Mail: https://github.com/binchen-china    <563853086@qq.com>
*
*  Note:
*/
//=============================================================================

#pragma once

#include "DMaker.h"

#define SERVICE_MAP_PATH "DMaker.json"

typedef struct msg_range
{
    msg_range():msg_start(0),msg_end(0){};
    DM_UINT msg_start;
    DM_UINT msg_end;
}MsgRange;

class DMServiceMap
{
public:
    static DMServiceMap* instance();
    
    DMServiceMap();
    
    //<server_name,server_id>
    map<string, DM_INT> service_map;
 
    //<server_name,msg_range>
    map<DM_INT, MsgRange> message_map;  

    //rabbit_queue
    map<DM_INT, vector<string>> queue_map;
private: 
    void load_cfg();

	static DMServiceMap* _instance;
    static ACE_Thread_Mutex _mutex_lock;
};

