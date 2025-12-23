//===-- QuaggaInstrInfo.td - Quagga Instruction defs ------*- tablegen -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
// Instruction format superclass
//===----------------------------------------------------------------------===//

class QuaggaInst<dag outs, dag ins, string asmstr, list<dag> pattern>
    : Instruction {
  let Namespace = "Quagga";
  
  dag OutOperandList = outs;
  dag InOperandList = ins;
  let AsmString = asmstr;
  let Pattern = pattern;
  
  field bits<32> Inst;
  field bits<32> SoftFail = 0;
}

// Pseudo Instructions
class Pseudo<dag outs, dag ins, list<dag> pattern>
    : QuaggaInst<outs, ins, "", pattern> {
  let isPseudo = 1;
  let isCodeGenOnly = 1;
}

// Define a simple NOP instruction
def NOP : QuaggaInst<(outs), (ins), "nop", []> {
  let Inst{31-0} = 0;
}
