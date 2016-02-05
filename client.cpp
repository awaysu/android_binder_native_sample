/**
 *
 * Based on BinderDemo: https://github.com/gburca/BinderDemo/blob/master/binder.cpp
 */

#include <stdlib.h>
#include <binder/IBinder.h>
#include <binder/IServiceManager.h>
#include <binder/Parcel.h>
#include <binder/TextOutput.h>

#include "mathinterface.h"

using namespace android;

/**
 * The proxy used for client side.
 */
class MathBinderProxy : public MathInterface {
private:
    sp<IBinder> remote;
public:
    MathBinderProxy(const sp<IBinder>& impl);

    void print(const char *msg);

    int32_t add(int32_t a, int32_t b);
};

MathBinderProxy::MathBinderProxy(const sp<IBinder>& impl) {
    INFO("MathBinderProxy::MathBinderProxy()");
    remote = impl;
}

void MathBinderProxy::print(const char *msg) {
    Parcel data, reply;
    data.writeInterfaceToken(MathInterface::DESCRIPTOR);
    data.writeString16(String16(msg));

    aout << "MathBinderProxy::print parcel to be sent:n";
    data.print(aout);
    endl(aout);
    remote->transact(MathInterface::PRINT, data, &reply, IBinder::FLAG_ONEWAY);
    INFO("MathBinderProxy::print() is returned");
}

int32_t MathBinderProxy::add(int32_t a, int32_t b) {
    Parcel data, reply;
    data.writeInterfaceToken(MathInterface::DESCRIPTOR);
    data.writeInt32(a);
    data.writeInt32(b);

    aout << "MathBinderProxy::add parcel to be sent:n";
    data.print(aout);
    endl(aout);

    remote->transact(MathInterface::ADD, data, &reply);
    INFO("MathBinderProxy::add transact reply");
    reply.print(aout);
    endl(aout);
    int32_t res;
    status_t status = reply.readInt32(&res);
    INFO("MathBinderProxy::add(%i, %i) = %i(status: %i)",
            a, b, res, status);
    return res;
}

static sp<MathInterface> getMathServer(const char *msg) {
    sp<IServiceManager> sm = defaultServiceManager();
    sp<IBinder> binder = sm->getService(String16(msg));
    if (binder == NULL) {
        INFO("getmath server, cannot find server '%s'", msg);
        return NULL;
    }
    sp<MathInterface> svr = new MathBinderProxy(binder);
    return svr;
}

int main(int argc, char **argv) 
{
    INFO("we are the client");
    const char *native = "MathServer";
	
	INFO("======================================");
    sp<MathInterface> svc = getMathServer(native);
    if (svc == NULL) {
        INFO("failed to find service");
        return -1;
    }
		
    svc->print("Hello, welcome to the world of native binder");
	
	INFO("======================================");
	sleep(10);
    int32_t s = svc->add(2013, 3102);
    INFO("Addition result: %i + %i = %i", 2013, 3102, s);

    return 0;
}


