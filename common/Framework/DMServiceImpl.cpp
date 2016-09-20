#include "DMServiceImpl.h"
#include "DMMultiTask.h"
#include "DMSessionManager.h"
#include "DMMessageParser.h"
#include "DMMessageRouter.h"

map<DM_INT, MESSAGE_CALLBACK_HANDLE>  DMServiceImpl::_cmd_map;

void DMServiceImpl::init()
{
    DMTask::instance()->init();
    DMTask::instance()->register_message_callback(message_task_callback);
    init_cmd();
}
    
void DMServiceImpl::register_message_factory(DMMessageFactory* msg_factory)
{
    _factory = msg_factory;   
}

void DMServiceImpl::register_cmd(DM_INT message_cmd, MESSAGE_CALLBACK_HANDLE func)
{
    _cmd_map[message_cmd] = func;
}

void DMServiceImpl::send_message(DM_INT uid, DMMessage& msg, DM_INT dest)
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

void DMServiceImpl::publish_message(vector<DM_INT> uid, DMMessage& msg, DM_INT dest)
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

void DMServiceImpl::message_task_callback(DMMessage& msg)
{
    map<DM_INT, MESSAGE_CALLBACK_HANDLE>::iterator it = _cmd_map.find(msg.head.msg_cmd);
    if (it != _cmd_map.end())
    {
        (it->second)(msg);
    }
}

void DMServiceImpl::send_app_message(ACE_HANDLE fd, DMMessage& msg)
{
    ACE_SOCK_Stream stream(fd);
    DM_CHAR* buf;
    DM_NEW(buf,sizeof(DMMessageHead) + msg.head.length);
    DMMessageParser parser;
    
    parser.pack(msg, buf);
    DM_TRACE("data=%s",msg.body);
    stream.send_n(buf, sizeof(DMMessageHead) + msg.head.length);
    
    DM_DELETE(buf,sizeof(DMMessageHead) + msg.head.length);
}

void DMServiceImpl::send_mq_message(DMMessage& msg)
{
    DMMessageRouter router;
    router.send(msg);
}

