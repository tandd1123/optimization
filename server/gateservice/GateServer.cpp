#include "GateServer.h"

int DM_MAIN(int argc, ACE_TCHAR *argv[])
{   
    GateServer server;
    
    server.init("GateServer.json",argc,argv);
    server.run();
    return 0;
}
