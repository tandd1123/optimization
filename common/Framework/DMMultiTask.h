//=============================================================================
/* 
*  File: DMMultiTask.h
*
*  Author: bing
*
*  Date: 2016-09-18
*
*  Version: v2.0
*
*  Github/Mail: https://github.com/binchen-china    <563853086@qq.com>
*
*  Note:
*/
//=============================================================================

#pragma once
#include "DMaker.h"
#include "DMMessage.h"
 
class DMMultiTask : public ACE_Task<ACE_MT_SYNCH>
{
public:
    
    void init();

    void put_msg(DMMessage* msg);
    
    virtual DM_INT svc(void);

private:
    
    DM_INT _task_num;   
    
    MESSAGE_CALLBACK_HANDLE _func_callback;
};

typedef ACE_Singleton<DMMultiTask, ACE_Thread_Mutex> DMTask; 

