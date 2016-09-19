#include "DMServer.h"

int DM_MAIN(int argc, ACE_TCHAR *argv[])
{
    DMService service;
    DMMessageFactory factory;
    DMServer server(&service, &factory);
    
    server.init("main.json",argc,argv);
    server.run();
    return 0;
}

