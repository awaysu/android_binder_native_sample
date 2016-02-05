#include "ArcHmbPlayerBinder.h"

#define LOG_TAG "ARCADYAN:Server"

int main(int argc, char **argv) 
{

	ALOGE("built : [%s %s]\n", __DATE__, __TIME__);

    ALOGE("We're the service");
    
    defaultServiceManager()->addService(String16("ArcHmbPlayerServer"),
            new ArcHmbPlayerBinder());
    ProcessState::self()->startThreadPool();
    ALOGE("ArcHmbPlayer server is running now");
    IPCThreadState::self()->joinThreadPool();
    ALOGE("ArcHmbPlayer server thread joined");

    return 0;
}


