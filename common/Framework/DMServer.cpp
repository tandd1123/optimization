#include "DMServer.h"

DM_BOOL DMServer::init(const string& config_path, DM_INT argc, DM_CHAR *argv[])
{
    //load config file
    DMJsonCfg::instance()->load_config_file(config_path); 
    
    //init multi process
    init_process(argc, argv);  
    
    //init acceptor
    _acceptor = DMAcceptor::instance();
    _acceptor->init();
    
    //init dispatcher
    _dispatcher.init(_service);
    
    return true;
}

void DMServer::run(DMService* pService)
{        
    run_event_loop();
}
