#include "DMServerImpl.h"

void DMServerImpl::init_process(DM_INT process_num, DM_INT argc, DM_CHAR *argv[])
{
    DM_INT ret = create_process(process_num, argc, argv);
    if (0 == ret)
    {
        run_master_process();
    }
    
    else
    {
        run_subprogram_process();
    }
}

void DMServerImpl::run_master_process()
{
    wait_all_process();
}

void DMServerImpl::run_subprogram_process()
{
    ACE_Reactor::instance()->run_event_loop();
}
