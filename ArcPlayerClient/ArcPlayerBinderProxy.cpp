#include "ArcPlayerBinderProxy.h"

#define LOG_TAG "ARCADYAN:ArcPlayerBinderProxy"

ArcPlayerBinderProxy::ArcPlayerBinderProxy(const sp<IBinder>& impl) {
    ALOGE("ArcPlayerBinderProxy::ArcPlayerBinderProxy()");
    remote = impl;
}

void ArcPlayerBinderProxy::print(const char *msg) {
    Parcel data, reply;
    data.writeInterfaceToken(ArcPlayerInterface::DESCRIPTOR);
    data.writeString16(String16(msg));

    aout << "ArcPlayerBinderProxy::print parcel to be sent:n";
    data.print(aout);
    endl(aout);
    remote->transact(ArcPlayerInterface::PRINT, data, &reply, IBinder::FLAG_ONEWAY);
    ALOGE("ArcPlayerBinderProxy::print() is returned");
}

int32_t ArcPlayerBinderProxy::add(int32_t a, int32_t b) {
    Parcel data, reply;
    data.writeInterfaceToken(ArcPlayerInterface::DESCRIPTOR);
    data.writeInt32(a);
    data.writeInt32(b);

    aout << "ArcPlayerBinderProxy::add parcel to be sent:n";
    data.print(aout);
    endl(aout);

    remote->transact(ArcPlayerInterface::ADD, data, &reply);
    ALOGE("ArcPlayerBinderProxy::add transact reply");
    reply.print(aout);
    endl(aout);
    int32_t res;
    status_t status = reply.readInt32(&res);
    ALOGE("ArcPlayerBinderProxy::add(%i, %i) = %i(status: %i)",
            a, b, res, status);
    return res;
}



