/**
 *
 * Based on BinderDemo: https://github.com/gburca/BinderDemo/blob/master/binder.cpp
 */
#include <stdlib.h>
#include <binder/IPCThreadState.h>
#include <binder/IServiceManager.h>
#include <utils/Log.h>
#include <binder/TextOutput.h>

#include "mathinterface.h"

using namespace android;

/**
 * The remote binder or the server.
 */
class MathBinder : public BBinder {
protected:
    virtual status_t onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags = 0);
public:
    virtual void print(const char *msg);
    virtual int32_t add(int32_t a, int32_t b);
};

status_t MathBinder::onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags) {
    INFO("MathBinder::onTransact(%i) %i", code, flags);
    /*
     * Before executing actual method, check whether the RPC are from expected client.
     * Client will write interface token, to identify interface to which those methods
     * belong.
     */
    if (!data.enforceInterface(MathInterface::DESCRIPTOR)) {
        INFO("failed to check Interface, you might call wrong service, this is for '%s'",
                String8(MathInterface::DESCRIPTOR).string());
        return BAD_TYPE;
    }
    data.print(aout);
    endl(aout);

    switch(code) {
    case MathInterface::PRINT: {
        String16 msg = data.readString16();
        print(String8(msg).string());
        return NO_ERROR;
    }
    case MathInterface::ADD: {
        int32_t a = data.readInt32();
        int32_t b = data.readInt32();
        int32_t sum = add(a, b);
        INFO("MathBinder:onTransact add(%i, %i) = %i", a, b, sum);
        reply->print(aout); endl(aout);
        reply->writeInt32(sum);
        return NO_ERROR;
    }
    default:
        INFO("MathBinder, bad requesting code, no match found");
    }
    return BBinder::onTransact(code, data, reply, flags);
}

void MathBinder::print(const char *msg) {
    INFO("MathBinder::print, msg is '%s'", msg);
}

int32_t MathBinder::add(int32_t a, int32_t b) {
    return a + b;
}

int main(int argc, char **argv) {
    INFO("We're the service");
    
    defaultServiceManager()->addService(String16("MathServer"),
            new MathBinder());
    ProcessState::self()->startThreadPool();
    INFO("Math server is running now");
    IPCThreadState::self()->joinThreadPool();
    INFO("Math server thread joined");

    return 0;
}


