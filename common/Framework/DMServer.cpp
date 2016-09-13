#include "DMServer.h"

DM_BOOL DMServer::init(const string& config_path, DM_INT argc, DM_CHAR *argv[])
{
    DMJsonCfg::instance()->load_config_file(config_path);  
    init_process(argc, argv);  
    _acceptor.init();
    _dispatcher.init(_service);
    return true;
}

void DMServer::run(DMService* pService)
{        
    run_event_loop();
}
