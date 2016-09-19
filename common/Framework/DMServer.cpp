#include "DMServer.h"

DMServer::DMServer(DMService* service,DMMessageFactory* factory)
{
    _service = service;
    _service->register_message_factory(factory);
}

DM_BOOL DMServer::init(const string& config_path, DM_INT argc, DM_CHAR *argv[])
{
    //load config file
    DMJsonCfg::instance()->load_config_file(config_path); 
    
    //init multi process
    init_process(argc, argv);  
    
    //init acceptor
    _acceptor = DMAcceptor::instance();
    _acceptor->init(argc, argv);
    
    //init dispatcher
    _dispatcher.init();

    //init service
    _service->init();
    
    return true;
}

void DMServer::run()
{        
    run_event_loop();
}

