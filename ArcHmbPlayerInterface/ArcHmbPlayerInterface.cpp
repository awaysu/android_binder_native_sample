/**
 * Demonstrate how to us Binder in Native C++ codes.
 *
 * The interface describes the RPC calls.
 *
 * Based on BinderDemo: https://github.com/gburca/BinderDemo/blob/master/binder.cpp
 */
#include "ArcHmbPlayerInterface.h"

const String16 ArcHmbPlayerInterface::DESCRIPTOR("ArcHmbPlayerInterface");

ArcHmbPlayerInterface::ArcHmbPlayerInterface() {
    ALOGE("ArcHmbPlayerInterface::ArcHmbPlayerInterface()");
}

ArcHmbPlayerInterface::~ArcHmbPlayerInterface() {
    ALOGE("ArcHmbPlayerInterface::~ArcHmbPlayerInterface()");
}
