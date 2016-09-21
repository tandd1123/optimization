#include "GateService.h"
#include "GateMessageFactory.h"
#include "ProxyMapManager.h"

void get_proxy_message(DMMessage& message)
{
    DM_TRACE("message test!data=%s,addr=%d",message.body,&message.body);
    string proxy;
    GateSrv::instance()->get_proxy_info(message.head.msg_uid, proxy);

    DMMessage resp = message;
    resp.head.length = proxy.length();
    resp.require_body_size(proxy.length());
   
    memcpy(resp.body, proxy.c_str(), proxy.length());
    GateSrv::instance()->send_message(resp.head.msg_uid,resp,DM_APP);
}

void GateService::get_proxy_info(int seed, string& proxy)
{
    proxy = ProxyMapManager::instance()->hash(seed);
}
