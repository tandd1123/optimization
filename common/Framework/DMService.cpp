#include "DMService.h"
#include "DMMultiTask.h"
#include "DMSessionManager.h"
#include "DMMessageParser.h"

DMMessageFactory* DMService::_factory = nullptr;

void DMService::init()
{
    DMTask::instance()->init();
    DMTask::instance()->register_message_callback(message_task_callback);

    _factory->init_cmd();
}
    
void DMService::register_message_factory(DMMessageFactory* msg_factory)
{
    _factory = msg_factory;   
}

void DMService::send_message(DM_INT uid, DMMessage& msg, DM_INT dest)
{
    if (DM_APP == dest)//session
    {
        ACE_HANDLE fd = DMSessionMgr::instance()->find_fd(uid);
        if (-1 != fd)
        {
            send_app_message(fd, msg);  
        }
    }
    else if (DM_MQ == dest)//route
    {
        send_mq_message(msg);
    }
}

void DMService::publish_message(vector<DM_INT> uid, DMMessage& msg, DM_INT dest)
{
    if (DM_APP == dest)//session
    {
        vector<DM_INT>::iterator it = uid.begin();
        for (; it != uid.end(); ++it)
        {
            ACE_HANDLE fd = DMSessionMgr::instance()->find_fd((*it));
            send_app_message(fd, msg);   
        }
    }
    else if (DM_MQ == dest)//route
    {
        DMMessageRouter router;
        router.publish(msg);
    }
}

void DMService::message_task_callback(DMMessage& msg)
{
    MESSAGE_CALLBACK_HANDLE func_handle = _factory->find_callback_handle(msg.head.msg_cmd);
    if (nullptr != func_handle)
    {
        func_handle(msg);
    }
}

void DMService::send_app_message(ACE_HANDLE fd, DMMessage& msg)
{
    _router.send(fd, msg);
}

void DMService::send_mq_message(DMMessage& msg)
{   
    _router.send(msg);
}

