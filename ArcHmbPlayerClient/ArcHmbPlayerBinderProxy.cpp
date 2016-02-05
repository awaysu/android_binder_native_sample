#include "ArcHmbPlayerBinderProxy.h"

#define LOG_TAG "ARCADYAN:ArcHmbPlayerBinderProxy"

ArcHmbPlayerBinderProxy::ArcHmbPlayerBinderProxy(const sp<IBinder>& impl) {
    ALOGE("ArcHmbPlayerBinderProxy::ArcHmbPlayerBinderProxy()");
    remote = impl;
}

void ArcHmbPlayerBinderProxy::print(const char *msg) {
    Parcel data, reply;
    data.writeInterfaceToken(ArcHmbPlayerInterface::DESCRIPTOR);
    data.writeString16(String16(msg));

    aout << "ArcHmbPlayerBinderProxy::print parcel to be sent:n";
    data.print(aout);
    endl(aout);
    remote->transact(ArcHmbPlayerInterface::PRINT, data, &reply, IBinder::FLAG_ONEWAY);
    ALOGE("ArcHmbPlayerBinderProxy::print() is returned");
}

int32_t ArcHmbPlayerBinderProxy::add(int32_t a, int32_t b) {
    Parcel data, reply;
    data.writeInterfaceToken(ArcHmbPlayerInterface::DESCRIPTOR);
    data.writeInt32(a);
    data.writeInt32(b);

    aout << "ArcHmbPlayerBinderProxy::add parcel to be sent:n";
    data.print(aout);
    endl(aout);

    remote->transact(ArcHmbPlayerInterface::ADD, data, &reply);
    ALOGE("ArcHmbPlayerBinderProxy::add transact reply");
    reply.print(aout);
    endl(aout);
    int32_t res;
    status_t status = reply.readInt32(&res);
    ALOGE("ArcHmbPlayerBinderProxy::add(%i, %i) = %i(status: %i)",
            a, b, res, status);
    return res;
}



