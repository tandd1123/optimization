#include "DMServerImpl.h"
#include "DMAcceptor.h"
#include "ace/Thread_Manager.h"

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

void* run_event(void *arg)
{
	ACE_Reactor *reactor = static_cast<ACE_Reactor *> (arg);
	reactor->owner(ACE_OS::thr_self());
	reactor->run_reactor_event_loop();
	return 0;
}

void DMServerImpl::run_event_loop()
{
    ACE_Thread_Manager::instance()->spawn(run_event, DMAcceptor::instance()->get_reactor());
    ACE_Thread_Manager::instance()->spawn(run_event, ACE_Reactor::instance());
	ACE_Thread_Manager::instance()->wait();
}

