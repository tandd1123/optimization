#include "DMServer.h"

int DM_MAIN(int argc, ACE_TCHAR *argv[])
{
    DMServer server;
    server.init("main.json",argc,argv);
    server.run();
    return 0;
}
