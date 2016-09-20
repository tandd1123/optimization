#include "DMServiceImpl.h"
#include "DMMultiTask.h"
#include "DMSessionManager.h"
#include "DMMessageParser.h"
#include "DMMessageRouter.h"

DMMessageFactory* DMServiceImpl::_factory = nullptr;

void DMServiceImpl::init()
{
    DMTask::instance()->init();
    DMTask::instance()->register_message_callback(message_task_callback);

    _factory->init_cmd();
}
    
void DMServiceImpl::register_message_factory(DMMessageFactory* msg_factory)
{
    _factory = msg_factory;   
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
    MESSAGE_CALLBACK_HANDLE func_handle = _factory->find_callback_handle(msg.head.msg_cmd);
    if (nullptr != func_handle)
    {
        func_handle(msg);
    }
}

void DMServiceImpl::send_app_message(ACE_HANDLE fd, DMMessage& msg)
{
    ACE_SOCK_Stream stream(fd);
    DM_CHAR* buf;
    buf = new DM_CHAR[sizeof(DMMessageHead) + msg.head.length];
    
    DMMessageParser parser;
    parser.pack(msg, buf);
    
    stream.send_n(buf, sizeof(DMMessageHead) + msg.head.length);
    
    delete[] buf;
}

void DMServiceImpl::send_mq_message(DMMessage& msg)
{
    DMMessageRouter router;
    router.send(msg);
}

