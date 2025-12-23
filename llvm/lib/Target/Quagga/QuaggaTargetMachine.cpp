//===-- QuaggaTargetMachine.cpp - Define TargetMachine for Quagga ---------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "QuaggaTargetMachine.h"
#include "Quagga.h"
#include "TargetInfo/QuaggaTargetInfo.h"
#include "llvm/CodeGen/TargetLoweringObjectFileImpl.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include "llvm/MC/TargetRegistry.h"
#include <optional>

using namespace llvm;

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeQuaggaTarget() {
  RegisterTargetMachine<QuaggaTargetMachine> X(getTheQuaggaTarget());
}

static std::string computeDataLayout(const Triple &TT) {
  return "e-m:e-p:32:32-i8:8:32-i16:16:32-i64:64-n32";
}

static Reloc::Model getEffectiveRelocModel(std::optional<Reloc::Model> RM) {
  return RM.value_or(Reloc::Static);
}

QuaggaTargetMachine::QuaggaTargetMachine(const Target &T, const Triple &TT,
                                         StringRef CPU, StringRef FS,
                                         const TargetOptions &Options,
                                         std::optional<Reloc::Model> RM,
                                         std::optional<CodeModel::Model> CM,
                                         CodeGenOptLevel OL, bool JIT)
    : CodeGenTargetMachineImpl(T, computeDataLayout(TT), TT, CPU, FS, Options,
                               getEffectiveRelocModel(RM),
                               getEffectiveCodeModel(CM, CodeModel::Small), OL),
      TLOF(std::make_unique<TargetLoweringObjectFileELF>()),
      Subtarget(TT, std::string(CPU), std::string(FS), *this) {
  initAsmInfo();
}

namespace {
class QuaggaPassConfig : public TargetPassConfig {
public:
  QuaggaPassConfig(QuaggaTargetMachine &TM, PassManagerBase &PM)
      : TargetPassConfig(TM, PM) {}

  QuaggaTargetMachine &getQuaggaTargetMachine() const {
    return getTM<QuaggaTargetMachine>();
  }

  bool addInstSelector() override {
    return false;
  }
};
} // namespace

TargetPassConfig *QuaggaTargetMachine::createPassConfig(PassManagerBase &PM) {
  return new QuaggaPassConfig(*this, PM);
}
