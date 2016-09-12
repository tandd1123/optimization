#include "DMServerImpl.h"

void DMServerImpl::init_process(DM_INT argc, DM_CHAR *argv[])
{
    DM_INT ret = create_process(argc, argv);
    if (0 == ret)
    {
        run_master_process();
    }
}

void DMServerImpl::run_master_process()
{
    wait_all_process();
}

void DMServerImpl::run_event_loop()
{
    ACE_Reactor::instance()->run_event_loop();
}
