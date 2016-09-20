#include "GateServer.h"
#include "GateService.h"
#include "GateMessageFactory.h"

int DM_MAIN(int argc, ACE_TCHAR *argv[])
{
    GateService service;
    GateMessageFactory factory;
    GateServer server(&service, &factory);
    
    server.init("GateServer.json",argc,argv);
    server.run();
    return 0;
}
