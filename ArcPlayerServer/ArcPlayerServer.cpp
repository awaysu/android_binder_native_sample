#include "ArcPlayerBinder.h"

#define LOG_TAG "ARCADYAN:Server"

int main(int argc, char **argv) {
    ALOGE("We're the service");
    
    defaultServiceManager()->addService(String16("ArcPlayerServer"),
            new ArcPlayerBinder());
    ProcessState::self()->startThreadPool();
    ALOGE("ArcPlayer server is running now");
    IPCThreadState::self()->joinThreadPool();
    ALOGE("ArcPlayer server thread joined");

    return 0;
}


