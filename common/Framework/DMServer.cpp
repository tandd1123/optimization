#include "DMServer.h"
#include "DMSessionManager.h"

template<class SERVICE, class MESSAGE_FACTORY>
DM_BOOL DMServer<SERVICE, MESSAGE_FACTORY>::init(const string& config_path, DM_INT argc, DM_CHAR *argv[])
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

    SERVICE* service = new SERVICE;
    MESSAGE_FACTORY* factory = new MESSAGE_FACTORY;
    DMSessionMgr::instance()->init(service, factory);

    DMTask::instance()->init();

    return true;
}

template<class SERVICE, class MESSAGE_FACTORY>
void DMServer<SERVICE, MESSAGE_FACTORY>::run()
{        
    run_event_loop();
}

