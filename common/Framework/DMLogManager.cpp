#include "DMLogManager.h"

DMLogManager::DMLogManager():_log_mask(0)
{
    init();
}

DMLogManager::~DMLogManager()
{
    
}

void DMLogManager::init()
{
    get_log_config(); 
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

void DMLogManager::print_log(const DM_CHAR* fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
               
    string log_info = fmt;     
    ACE_OS::vfprintf(stdout, fmt, ap);  

    va_end (ap);
}

void DMLogManager::trace_log(string file, string func, DM_INT line, const DM_CHAR* fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
               
    ACE_OS::printf("[DM_TRACE][%s][%s][%d]:",file.c_str(), func.c_str(), line);               
    string log_info = fmt;     
    ACE_OS::vfprintf(stdout, fmt, ap);  

    va_end (ap);
}

void DMLogManager::write_log(DM_INT log_level, string file, string func, DM_INT line, const DM_CHAR* fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    
    open_log_file();
    
    switch (log_level)
    {
        case DM_DEBUG:
        {
            if (DM_DEBUG & _log_mask)
            {               
                ACE_OS::fprintf(_log_file, "[DM_DEBUG][%s][%s][%d]:",file.c_str(), func.c_str(), line);                 
                ACE_OS::vfprintf(_log_file, fmt, ap);  
            }            
            break;
        }
        case DM_INFO:
        {
            if (DM_INFO & _log_mask)
            {
                ACE_OS::fprintf(_log_file, "[DM_INFO][%s][%s][%d]:",file.c_str(), func.c_str(), line);                  
                ACE_OS::vfprintf(_log_file, fmt, ap);  
            }
            break;
        }
        case DM_WARNING:
        {
            if (DM_WARNING & _log_mask)
            {
                ACE_OS::fprintf(_log_file, "[DM_WARNING][%s][%s][%d]:",file.c_str(), func.c_str(), line);                 
                ACE_OS::vfprintf(_log_file, fmt, ap);  
            }
            break;
        }
        case DM_ERROR:
        {
            if (DM_ERROR & _log_mask)
            {
                ACE_OS::fprintf(_log_file, "[DM_ERROR][%s][%s][%d]:",file.c_str(), func.c_str(), line);                 
                ACE_OS::vfprintf(_log_file, fmt, ap);       
            }
            break;
        }
    }
    
    close_log_file();
    va_end (ap);
}
