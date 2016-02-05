#ifndef _ARCPLAYER_BINDERPROXY_H
#define _ARCPLAYER_BINDERPROXY_H


#include <stdlib.h>
#include <binder/IBinder.h>
#include <binder/IServiceManager.h>
#include <binder/Parcel.h>
#include <binder/TextOutput.h>
#include "../ArcPlayerInterface/ArcPlayerInterface.h"

using namespace android;

/**
 * The proxy used for client side.
 */
class ArcPlayerBinderProxy : public ArcPlayerInterface {
private:
    sp<IBinder> remote;
public:
    ArcPlayerBinderProxy(const sp<IBinder>& impl);

    void print(const char *msg);

    int32_t add(int32_t a, int32_t b);
};

static sp<ArcPlayerInterface> getArcPlayerServer(const char *msg) 
{
    sp<IServiceManager> sm = defaultServiceManager();
    sp<IBinder> binder = sm->getService(String16(msg));
    if (binder == NULL) {
        ALOGE("Cannot find server '%s'", msg);
        return NULL;
    }
    sp<ArcPlayerInterface> svr = new ArcPlayerBinderProxy(binder);
    return svr;
}

#endif