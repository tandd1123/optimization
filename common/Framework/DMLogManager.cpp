#include "DMLogManager.h"

DMLogManager::DMLogManager():_log_mask(0)
{
    init();
}

DMLogManager::~DMLogManager()
{
    close_log_file();
}

void DMLogManager::init()
{
    get_log_config();
    open_log_file();
    set_log_level();
}

void DMLogManager::get_log_config()
{
    _log_name = DMJsonCfg::instance()->GetItemString("service_info", "service_name");
    _log_level = DMJsonCfg::instance()->GetItemString("service_info", "log_level");
    _log_name.append(".log");
}

inline  void DMLogManager::open_log_file()
{
    _log_file = fopen(_log_name.c_str(), "a");
    if (nullptr == _log_file)
    {    
        return;
    }    
}

inline  void DMLogManager::close_log_file()
{
    fclose(_log_file);
}

void DMLogManager::set_log_level()
{
    if ("DEBUG" == _log_level)
    {
        _log_mask = 0x1111;
    }
    else if ("INFO" == _log_level)
    {
        _log_mask = 0x0111;
    }
    else if ("WARNING" == _log_level)
    {
        _log_mask = 0x0011;
    }
    else if ("ERROR" == _log_level)
    {
        _log_mask = 0x0001;
    }
}

void DMLogManager::write_function_trace(string file, string func, DM_INT line)
{
    ACE_DEBUG((LM_DEBUG,"FILE:[%s]\tFUNCTION_NAME:[%s]\tLINE:[%d]\n",file.c_str(), func.c_str(), line));
}

void DMLogManager::write_log(DM_INT log_level, const DM_CHAR* fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    
    switch (log_level)
    {
        case DM_DEBUG:
        {
            if (DM_DEBUG & _log_mask)
            {
                string log_info = "[DM_DEBUG][%s][%s][%d]:";
                log_info.append(fmt);     
                log_info.append("\n");
                ACE_OS::vfprintf(_log_file, log_info.c_str(), ap);  
            }            
            break;
        }
        case DM_INFO:
        {
            if (DM_INFO & _log_mask)
            {
                string log_info = "[DM_INFO][%s][%s][%d]:";
                log_info.append(fmt);     
                log_info.append("\n");
                ACE_OS::vfprintf(_log_file, log_info.c_str(), ap);
            }
            break;
        }
        case DM_WARNING:
        {
            if (DM_WARNING & _log_mask)
            {
                string log_info = "[DM_WARNING][%s][%s][%d]:";
                log_info.append(fmt);     
                log_info.append("\n");
                ACE_OS::vfprintf(_log_file, log_info.c_str(), ap); 
            }
            break;
        }
        case DM_ERROR:
        {
            if (DM_ERROR & _log_mask)
            {
                string log_info = "[DM_ERROR][%s][%s][%d]:";
                log_info.append(fmt);     
                log_info.append("\n");
                ACE_OS::vfprintf(_log_file, log_info.c_str(), ap);            
            }
            break;
        }
    }
    
    va_end (ap);
}
