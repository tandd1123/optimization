#include "DMMultiProcess.h"

DMMultiProcess::DMMultiProcess()
{
    _process_manager = ACE_Process_Manager::instance();
}

void DMMultiProcess::create_process(DM_INT process_num)
{
    _process_num = process_num;
    ACE_Process_Options options;
    options.avoid_zombies (1);
    //options.process_name("test");
    options.command_line (ACE_TEXT ("./DMFramework"));
    _pids = DM_NEW(_process_num, _process_num * sizeof(DM_INT));
    _process_manager->spawn_n(_process_num, options, _pids);
}

DM_BOOL DMMultiProcess::is_master_process()
{
    pid_t pid = getpid();
    for (DM_INT i = 0; i < _process_num; ++i)
    {
        if (_pids[i] == pid)
        {
            return false;
        }
    }
    return true;
}

void DMMultiProcess::wait_all_process()
{
    _process_manager->wait();
}