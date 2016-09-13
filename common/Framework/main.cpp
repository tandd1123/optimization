#include "DMServer.h"

int DM_MAIN(int argc, ACE_TCHAR *argv[])
{
    DMServer server;
    DMService service;
    server.init("main.json",argc,argv);
    server.run(&service);
    return 0;
}
