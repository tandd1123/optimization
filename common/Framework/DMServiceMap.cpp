#include "DMServiceMap.h"

DMServiceMap* DMServiceMap::_instance = nullptr;
ACE_Thread_Mutex DMServiceMap::_mutex_lock;

DMServiceMap* DMServiceMap::instance()
{
	_mutex_lock.acquire();
	if (nullptr == _instance)
	{
		_instance = DM_NEW() DMServiceMap();
	}
	_mutex_lock.release();
	return _instance;
}

DMServiceMap::DMServiceMap()
{
    load_cfg();
}

void DMServiceMap::load_cfg()
{
    std::ifstream cfg_file;
    cfg_file.open(SERVICE_MAP_PATH, std::ios::binary);

    if (!cfg_file.is_open())
    {   
        ACE_DEBUG((LM_INFO,"open DMaker.json config failure!\n"));
        return;
    }

    Json::Reader Reader;
    Json::Value Root;

    if (Reader.parse(cfg_file,Root))
    {
        Json::Value service_id = Root["service_id"];
        Json::Value::Members members = service_id.getMemberNames();
        Json::Value::Members::iterator it = members.begin();
        for (; it != members.end(); ++it)
        {
            string service_name = *it;
            DM_INT32 svr_id = service_id[service_name].asDM_INT32();
            service_map.insert(make_pair(service_name,svr_id));
        }

        Json::Value rabbit_queue = Root["rabbit_queue"];
        map<string, DM_INT32>::iterator svr_it = service_map.begin();
        for (; svr_it != service_map.end(); ++svr_it)
        {
            string svr_name = svr_it->first;
            DM_INT32 svr_id = svr_it->second;
            DM_INT32 mq_size = rabbit_queue[svr_name].size();
            vector<string> mq_number;
            for (DM_INT32 i = 0; i < mq_size; ++i)
            {
                mq_number.push_back(rabbit_queue[svr_name][i].asString());
            }
            queue_map.insert(make_pair(svr_id,mq_number));
        }

        Json::Value message_route = Root["message_route"];
        for (svr_it = service_map.begin(); svr_it != service_map.end(); ++svr_it)
        {
            DM_INT32 svr_id = svr_it->second;
            MsgRange msg_range;
            msg_range.msg_start = message_route[svr_it->first][0].asDM_INT32();
            msg_range.msg_end = message_route[svr_it->first][1].asDM_INT32();
            message_map.insert(make_pair(svr_id,msg_range));
        }
    }
}

