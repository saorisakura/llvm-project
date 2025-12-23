//===-- QuaggaSubtarget.cpp - Quagga Subtarget Information ----------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "QuaggaSubtarget.h"

using namespace llvm;

#define DEBUG_TYPE "quagga-subtarget"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "QuaggaGenSubtargetInfo.inc"

QuaggaSubtarget::QuaggaSubtarget(const Triple &TT, StringRef CPU,
                                 StringRef FS, const TargetMachine &TM)
    : QuaggaGenSubtargetInfo(TT, CPU, /*TuneCPU*/ CPU, FS) {}
