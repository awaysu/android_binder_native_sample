#ifndef _ARCPLAYER_BINDER_H
#define _ARCPLAYER_BINDER_H

#include <stdlib.h>
#include <binder/IPCThreadState.h>
#include <binder/IServiceManager.h>
#include <utils/Log.h>
#include <binder/TextOutput.h>
#include "../ArcPlayerInterface/ArcPlayerInterface.h"

using namespace android;

/**
 * The remote binder or the server.
 */
class ArcPlayerBinder : public BBinder {
protected:
    virtual status_t onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags = 0);
public:
    virtual void print(const char *msg);
    virtual int32_t add(int32_t a, int32_t b);
};

#endif /* _ARCPLAYER_BINDER_H */
