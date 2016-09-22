#include "DMSession.h"

DMSession::DMSession(ACE_HANDLE fd, DM_BOOL enable):_fd(fd),_enable(enable)
{

};

DMSession::~DMSession()
{

};

void DMSession::init()
{
    _service->init(_msg_factory);
}

MESSAGE_CALLBACK_HANDLE DMSession::get_service_callback()
{
    return _service->message_task_callback;
}

