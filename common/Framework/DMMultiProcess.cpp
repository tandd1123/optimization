#include "DMMultiProcess.h"

DMMultiProcess::DMMultiProcess()
{
    
}

void DMMultiProcess::set_process_options()
{
    if (_argc == 1)
    {
        _options.command_line("%s %d",_argv[0],_process_num - 1);
    }
    else if (atoi(_argv[1]) == 1)
    {
        return;
    }
    else
    {
       // _process_num = atoi(_argv[1]);
       // _options.command_line("%s %d",_argv[0],_process_num - 1);
    }
}

void DMMultiProcess::create_process(DM_INT process_num, int argc, char *argv[])
{   
    _process_num = process_num;
    _argc = argc;
    _argv = argv;
    
    set_process_options();
    _child_process = DM_NEW(_child_process, _process_num * sizeof(_child_process));
    DM_LOG(DM_DEBUG,"hello %d", __DM_LOG__, _process_num);
    DM_LOG(DM_INFO,"hello %d", __DM_LOG__, _process_num);
    DM_LOG(DM_WARNING,"hello %d", __DM_LOG__, _process_num);
    DM_LOG(DM_ERROR,"hello %d", __DM_LOG__, _process_num);
    DM_TRACE();
    /*for (DM_INT i = 0; i < _process_num; ++i)
    {
        _child_process[i].spawn(_options);
    }*/
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
    /*for (DM_INT i = 0; i < _process_num; ++i)
    {
        _child_process[i].wait();
    }*/
}