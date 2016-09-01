#pragma once

#include "DMaker.h"

#define SERVICE_MAP_PATH "..//..//common//Framework//MsgRoute.json"

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
    map<string, DM_UINT> service_map;
 
    //<server_name,msg_range>
    map<DM_UINT, MsgRange> message_map;  

    //rabbit_queue
    map<DM_UINT, vector<string>> queue_map;
private: 
    void load_cfg();

	static DMServiceMap* _instance;
    static ACE_Thread_Mutex _mutex_lock;
};

