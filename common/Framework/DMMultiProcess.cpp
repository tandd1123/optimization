#include "DMMultiProcess.h"

DMMultiProcess::DMMultiProcess():_process_num(0),_pids(nullptr)
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

    for (DM_INT i = 0; i < _process_num; ++i)
    {
       /* ACE_Process* process;
        DM_NEW(process ,sizeof(ACE_Process));
        DM_TRACE("process = %d\n",process);
        process->spawn(_options);
        _child_process.push_back(process);  */    
    }
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