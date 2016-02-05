/**
 * Demonstrate how to us Binder in Native C++ codes.
 *
 * The interface describes the RPC calls.
 *
 * Based on BinderDemo: https://github.com/gburca/BinderDemo/blob/master/binder.cpp
 */
#ifndef _MATH_INTERFACE_H
#define _MATH_INTERFACE_H

#define LOG_TAG "native_binder"

#include <stdlib.h>
#include <binder/IBinder.h>
#include <utils/Log.h>
#include <binder/TextOutput.h>

using namespace android;

#define INFO(...) \
    do { \
        printf(__VA_ARGS__); \
        printf("\n"); \
        ALOGD(__VA_ARGS__); \
    } while(0)

/**
 * The interface describing the RPC methods.
 *
 * RefBase is the base class for smart pointer.
 */
class MathInterface : public RefBase {
public:
    enum {
        PRINT = IBinder::FIRST_CALL_TRANSACTION,
        ADD
    };

    virtual void print(const char *msg) = 0;

    virtual int32_t add(int32_t a, int32_t b) = 0;

    static const String16 DESCRIPTOR;

    MathInterface();

    virtual ~MathInterface();
};

#endif

