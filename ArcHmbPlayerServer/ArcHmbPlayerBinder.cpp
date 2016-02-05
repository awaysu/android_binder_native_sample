#include "ArcHmbPlayerBinder.h"

#define LOG_TAG "ARCADYAN:ArcHmbPlayerBinder"

status_t ArcHmbPlayerBinder::onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags) {
    ALOGE("ArcHmbPlayerBinder::onTransact(%i) %i", code, flags);
    /*
     * Before executing actual method, check whether the RPC are from expected client.
     * Client will write interface token, to identify interface to which those methods
     * belong.
     */
    if (!data.enforceInterface(ArcHmbPlayerInterface::DESCRIPTOR)) {
        ALOGE("failed to check Interface, you might call wrong service, this is for '%s'",
                String8(ArcHmbPlayerInterface::DESCRIPTOR).string());
        return BAD_TYPE;
    }
    data.print(aout);
    endl(aout);

    switch(code) {
    case ArcHmbPlayerInterface::PRINT: {
        String16 msg = data.readString16();
        print(String8(msg).string());
        return NO_ERROR;
    }
    case ArcHmbPlayerInterface::ADD: {
        int32_t a = data.readInt32();
        int32_t b = data.readInt32();
        int32_t sum = add(a, b);
        ALOGE("ArcHmbPlayerBinder:onTransact add(%i, %i) = %i", a, b, sum);
        reply->print(aout); endl(aout);
        reply->writeInt32(sum);
        return NO_ERROR;
    }
    default:
        ALOGE("ArcHmbPlayerBinder, bad requesting code, no match found");
    }
    return BBinder::onTransact(code, data, reply, flags);
}

void ArcHmbPlayerBinder::print(const char *msg) {
    ALOGE("ArcHmbPlayerBinder::print, msg is '%s'", msg);
}

int32_t ArcHmbPlayerBinder::add(int32_t a, int32_t b) {
    return a + b;
}