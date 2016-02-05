/**
 * Demonstrate how to us Binder in Native C++ codes.
 *
 * The interface describes the RPC calls.
 *
 * Based on BinderDemo: https://github.com/gburca/BinderDemo/blob/master/binder.cpp
 */
#ifndef _ARCPLAYER_INTERFACE_H
#define _ARCPLAYER_INTERFACE_H

#include <stdlib.h>
#include <binder/IBinder.h>
#include <utils/Log.h>
#include <binder/TextOutput.h>

using namespace android;

/**
 * The interface describing the RPC methods.
 *
 * RefBase is the base class for smart pointer.
 */
class ArcPlayerInterface : public RefBase {
public:
    enum {
        PRINT = IBinder::FIRST_CALL_TRANSACTION,
        ADD
    };

    virtual void print(const char *msg) = 0;

    virtual int32_t add(int32_t a, int32_t b) = 0;

    static const String16 DESCRIPTOR;

    ArcPlayerInterface();

    virtual ~ArcPlayerInterface();
};

#endif

