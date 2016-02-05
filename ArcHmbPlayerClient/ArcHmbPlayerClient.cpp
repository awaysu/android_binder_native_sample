#include "ArcHmbPlayerBinderProxy.h"

#define LOG_TAG "ARCADYAN:Client"

int main(int argc, char **argv) 
{
	ALOGE("built : [%s %s]\n", __DATE__, __TIME__);
	
	
    ALOGE("we are the client");
    const char *native = "ArcHmbPlayerServer";
	
	ALOGE("======================================");
    sp<ArcHmbPlayerInterface> svc = getArcHmbPlayerServer(native);
    if (svc == NULL) {
        ALOGE("failed to find service");
        return -1;
    }
		
    svc->print("Hello, welcome to the world of native binder");
	
	ALOGE("======================================");
	sleep(10);
    int32_t s = svc->add(2013, 3102);
    ALOGE("Addition result: %i + %i = %i", 2013, 3102, s);

    return 0;
}


