#include "DMMultiProcess.h"

DMMultiProcess::DMMultiProcess():_process_num(0),_pids(nullptr)
{
    _process_manager = ACE_Process_Manager::instance();
}

DM_INT DMMultiProcess::set_process_options(ACE_Process_Options& options)
{
    if (_argc == 1) //parent
    {
        options.command_line("%s %d",_argv[0], _process_num);
        return 0;
    }
    else
    {
        DM_INT process_tag = ACE_OS::atoi(_argv[1]) - 1;
        if (0 == process_tag)
        {
            return -1;//the last
        }
        options.command_line("%s %d",_argv[0], process_tag);
    }
    return 1;
}

DM_INT DMMultiProcess::create_process(DM_INT process_num, DM_INT argc, DM_CHAR *argv[])
{     
    _argc = argc;
    _argv = argv;
    ACE_Process_Options options;
    _process_num = process_num;

    if (0 == set_process_options(options))
    {
        _process_manager->spawn(options);
        return 1;
    }
    else if (-1 == set_process_options(options))
    {
        return -1;
    }
    
    _process_manager->spawn(options);  
    return 0;
}

void DMMultiProcess::wait_all_process()
{
    _process_manager->wait(); 
}
