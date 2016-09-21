#include "GateService.h"
#include "GateMessageFactory.h"
#include "ProxyMapManager.h"

void get_proxy_message(DMMessage& message)
{
    GateSrv::instance()->get_proxy_info(message);
}

void GateService::get_proxy_info(DMMessage& message)
{   
    string proxy = ProxyMapManager::instance()->hash(message.head.msg_uid);
    
    DMMessage resp = message;
    resp.head.length = proxy.length();
    resp.require_body_size(proxy.length());
   
    memcpy(resp.body, proxy.c_str(), proxy.length());
    send_message(resp.head.msg_uid,resp,DM_APP);
}
