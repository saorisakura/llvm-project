//===-- QuaggaSubtarget.h - Define Subtarget for the Quagga ----*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_QUAGGA_QUAGGASUBTARGET_H
#define LLVM_LIB_TARGET_QUAGGA_QUAGGASUBTARGET_H

#include "llvm/CodeGen/TargetSubtargetInfo.h"
#include <string>

#define GET_SUBTARGETINFO_HEADER
#include "QuaggaGenSubtargetInfo.inc"

namespace llvm {
class StringRef;

class QuaggaSubtarget : public QuaggaGenSubtargetInfo {
public:
  QuaggaSubtarget(const Triple &TT, StringRef CPU, StringRef FS,
                  const TargetMachine &TM);

  void ParseSubtargetFeatures(StringRef CPU, StringRef TuneCPU, StringRef FS);
};

} // end namespace llvm

#endif
