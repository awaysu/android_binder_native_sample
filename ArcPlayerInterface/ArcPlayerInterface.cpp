/**
 * Demonstrate how to us Binder in Native C++ codes.
 *
 * The interface describes the RPC calls.
 *
 * Based on BinderDemo: https://github.com/gburca/BinderDemo/blob/master/binder.cpp
 */
#include "ArcPlayerInterface.h"

const String16 ArcPlayerInterface::DESCRIPTOR("ArcPlayerInterface");

ArcPlayerInterface::ArcPlayerInterface() {
    ALOGE("ArcPlayerInterface::ArcPlayerInterface()");
}

ArcPlayerInterface::~ArcPlayerInterface() {
    ALOGE("ArcPlayerInterface::~ArcPlayerInterface()");
}
