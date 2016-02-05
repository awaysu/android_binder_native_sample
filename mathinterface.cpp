/**
 * Demonstrate how to us Binder in Native C++ codes.
 *
 * The interface describes the RPC calls.
 *
 * Based on BinderDemo: https://github.com/gburca/BinderDemo/blob/master/binder.cpp
 */
#include "mathinterface.h"

const String16 MathInterface::DESCRIPTOR("MathInterface");

MathInterface::MathInterface() {
    INFO("MathInterface::MathInterface()");
}

MathInterface::~MathInterface() {
    INFO("MathInterface::~MathInterface()");
}
