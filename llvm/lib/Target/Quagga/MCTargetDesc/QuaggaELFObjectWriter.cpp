//===-- QuaggaELFObjectWriter.cpp - Quagga ELF Writer --------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "QuaggaMCTargetDesc.h"
#include "llvm/MC/MCELFObjectWriter.h"
#include "llvm/MC/MCObjectWriter.h"
#include "llvm/Support/ErrorHandling.h"

using namespace llvm;

namespace {
class QuaggaELFObjectWriter : public MCELFObjectTargetWriter {
public:
  QuaggaELFObjectWriter(uint8_t OSABI)
      : MCELFObjectTargetWriter(false, OSABI, ELF::EM_QUAGGA,
                                /*HasRelocationAddend*/ true) {}

  ~QuaggaELFObjectWriter() override = default;

protected:
  unsigned getRelocType(const MCFixup &Fixup, const MCValue &Target,
                        bool IsPCRel) const override {
    return 0;
  }
};
} // end anonymous namespace

std::unique_ptr<MCObjectTargetWriter>
llvm::createQuaggaELFObjectWriter(uint8_t OSABI) {
  return std::make_unique<QuaggaELFObjectWriter>(OSABI);
}
