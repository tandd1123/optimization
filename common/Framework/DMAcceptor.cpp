#include "DMAcceptor.h"

DMAcceptor* DMAcceptor::_instance = nullptr;

DM_INT DMAcceptor::init(DM_INT argc, DM_CHAR *argv[])
{   
    DM_INT fd_num = DMJsonCfg::instance()->GetItemInt("service_config", "FD_NUM");

    _reactor = new ACE_Reactor(new ACE_Dev_Poll_Reactor(fd_num));
    
    string svr_ip = DMJsonCfg::instance()->GetItemString("service_info", "service_ip");
    DM_INT svr_port = DMJsonCfg::instance()->GetItemInt("service_info", "service_port");
    
    if (1 != argc)
    {
        svr_port += ACE_OS::atoi(argv[1]) - 1;
    }
    
    ACE_INET_Addr addr(svr_port, svr_ip.c_str());  
    if (-1 == open(addr, _reactor))
    {
        DM_TRACE("open listen port failure!");
        return -1;
    }
    return 0;
}

ACE_Reactor* DMAcceptor::get_reactor()
{
    return _reactor;
}
