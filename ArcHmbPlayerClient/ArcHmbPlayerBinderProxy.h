#ifndef _ARCPLAYER_BINDERPROXY_H
#define _ARCPLAYER_BINDERPROXY_H


#include <stdlib.h>
#include <binder/IBinder.h>
#include <binder/IServiceManager.h>
#include <binder/Parcel.h>
#include <binder/TextOutput.h>
#include "../ArcHmbPlayerInterface/ArcHmbPlayerInterface.h"

using namespace android;

/**
 * The proxy used for client side.
 */
class ArcHmbPlayerBinderProxy : public ArcHmbPlayerInterface {
private:
    sp<IBinder> remote;
public:
    ArcHmbPlayerBinderProxy(const sp<IBinder>& impl);

    void print(const char *msg);

    int32_t add(int32_t a, int32_t b);
};

static sp<ArcHmbPlayerInterface> getArcHmbPlayerServer(const char *msg) 
{
    sp<IServiceManager> sm = defaultServiceManager();
    sp<IBinder> binder = sm->getService(String16(msg));
    if (binder == NULL) {
        ALOGE("Cannot find server '%s'", msg);
        return NULL;
    }
    sp<ArcHmbPlayerInterface> svr = new ArcHmbPlayerBinderProxy(binder);
    return svr;
}

#endif