#include "DMMultiTask.h"

void DMMultiTask::init()
{
    _task_num = DMJsonCfg::instance()->GetItemInt("service_config", "task_num");
    activate(THR_NEW_LWP | THR_JOINABLE |THR_INHERIT_SCHED , _task_num);//创建线程
}

int DMMultiTask::svc(void)
{
    ACE_Message_Block *msg_block;// = new ACE_Message_Block();
    while(True)
    {
        getq(msg_block);            //空闲线程阻塞
        
        ACE_Data_Block *Data_Block = msg_block->data_block();
        DMMessage *pData = reinterpret_cast <DMMessage*>(Data_Block->base());
        _func_callback(*pData);
        msg_block->release();        //release
    }
}

void DMMultiTask::register_message_callback(MESSAGE_CALLBACK_HANDLE func)
{
    _func_callback = func;
}

