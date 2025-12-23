//===-- QuaggaMCCodeEmitter.cpp - Convert Quagga code to machine code -----===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "QuaggaMCTargetDesc.h"
#include "llvm/MC/MCCodeEmitter.h"
#include "llvm/MC/MCContext.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"

using namespace llvm;

#define DEBUG_TYPE "mccodeemitter"

namespace {
class QuaggaMCCodeEmitter : public MCCodeEmitter {
  const MCInstrInfo &MCII;
  MCContext &Ctx;

public:
  QuaggaMCCodeEmitter(const MCInstrInfo &MCII, MCContext &Ctx)
      : MCII(MCII), Ctx(Ctx) {}

  ~QuaggaMCCodeEmitter() override = default;

  void encodeInstruction(const MCInst &MI, SmallVectorImpl<char> &CB,
                         SmallVectorImpl<MCFixup> &Fixups,
                         const MCSubtargetInfo &STI) const override {
    // Minimal implementation - just emit zeros
    CB.push_back(0);
    CB.push_back(0);
    CB.push_back(0);
    CB.push_back(0);
  }
};
} // end anonymous namespace

MCCodeEmitter *llvm::createQuaggaMCCodeEmitter(const MCInstrInfo &MCII,
                                               MCContext &Ctx) {
  return new QuaggaMCCodeEmitter(MCII, Ctx);
}
