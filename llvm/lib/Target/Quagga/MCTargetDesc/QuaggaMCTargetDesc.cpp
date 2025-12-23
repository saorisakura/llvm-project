//===-- QuaggaMCTargetDesc.cpp - Quagga Target Descriptions ---------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "QuaggaMCTargetDesc.h"
#include "QuaggaInstPrinter.h"
#include "TargetInfo/QuaggaTargetInfo.h"
#include "llvm/MC/MCAsmInfoELF.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

#define GET_INSTRINFO_MC_DESC
#define GET_INSTRINFO_MC_HELPERS
#include "QuaggaGenInstrInfo.inc"

#define GET_REGINFO_MC_DESC
#include "QuaggaGenRegisterInfo.inc"

#define GET_SUBTARGETINFO_MC_DESC
#include "QuaggaGenSubtargetInfo.inc"

static MCInstrInfo *createQuaggaMCInstrInfo() {
  MCInstrInfo *X = new MCInstrInfo();
  InitQuaggaMCInstrInfo(X);
  return X;
}

static MCRegisterInfo *createQuaggaMCRegisterInfo(const Triple &TT) {
  MCRegisterInfo *X = new MCRegisterInfo();
  InitQuaggaMCRegisterInfo(X, 0);
  return X;
}

static MCSubtargetInfo *createQuaggaMCSubtargetInfo(const Triple &TT,
                                                    StringRef CPU,
                                                    StringRef FS) {
  return createQuaggaMCSubtargetInfoImpl(TT, CPU, /*TuneCPU*/ CPU, FS);
}

static MCAsmInfo *createQuaggaMCAsmInfo(const MCRegisterInfo &MRI,
                                        const Triple &TT,
                                        const MCTargetOptions &Options) {
  return nullptr;
}

static MCInstPrinter *createQuaggaMCInstPrinter(const Triple &T,
                                                unsigned SyntaxVariant,
                                                const MCAsmInfo &MAI,
                                                const MCInstrInfo &MII,
                                                const MCRegisterInfo &MRI) {
  return new QuaggaInstPrinter(MAI, MII, MRI);
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeQuaggaTargetMC() {
  Target &T = getTheQuaggaTarget();

  TargetRegistry::RegisterMCAsmInfo(T, createQuaggaMCAsmInfo);
  TargetRegistry::RegisterMCInstrInfo(T, createQuaggaMCInstrInfo);
  TargetRegistry::RegisterMCRegInfo(T, createQuaggaMCRegisterInfo);
  TargetRegistry::RegisterMCSubtargetInfo(T, createQuaggaMCSubtargetInfo);
  TargetRegistry::RegisterMCInstPrinter(T, createQuaggaMCInstPrinter);
  TargetRegistry::RegisterMCCodeEmitter(T, createQuaggaMCCodeEmitter);
  TargetRegistry::RegisterMCAsmBackend(T, createQuaggaAsmBackend);
}
