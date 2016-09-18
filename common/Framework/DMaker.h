//=============================================================================
/* 
*  File: DMaker.h
*
*  Author: bing
*
*  Date: 2016-09-01
*
*  Version: v2.0
*
*  Github/Mail: https://github.com/binchen-china    <563853086@qq.com>
*
*  Note:
*/
//=============================================================================

//#pragma once

//DM include
#include "DMTypes.h"
#include "DMJsonConfig.h"
#include "DMMultiProcess.h"
#include "DMLogManager.h"
#include "DMServiceMap.h"
#include "DMSessionManager.h"
#include "DMSession.h"

//ACE include
#include "ace/Acceptor.h"
#include "ace/SOCK_Acceptor.h"
#include "ace/Reactor.h"
#include "ace/Log_Msg.h"
#include "ace/Dev_Poll_Reactor.h"
#include "ace/INET_Addr.h"
#include "ace/Thread_Mutex.h"
#include "ace/Task.h"
#include "ace/Task_T.h"
#include "ace/Synch_Traits.h"
#include "ace/Svc_Handler.h"
#include "ace/SOCK_Stream.h"
#include "ace/Event_Handler.h"
#include "ace/Process_Manager.h"
#include "ace/Process.h"
#include "ace/OS_NS_unistd.h"
#include "ace/Singleton.h"

//AMQP include
#include "amqpcpp.h"
#include "amqpcpp/include/message.h"

//common include
#include "json/json.h"

//other include
#include <fstream>
#include <stdio.h> 
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
