#include "GateService.h"
#include "GateMessageFactory.h"

void get_proxy_message(DMMessage& message)
{
    DM_TRACE("message test!data=%s,addr=%d",message.body,&message.body);
    GateSrv::instance()->send_message(message.head.msg_uid,message,DM_APP);
}
