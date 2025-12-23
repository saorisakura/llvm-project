//===-- QuaggaRegisterInfo.td - Quagga Register defs ------*- tablegen -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
//  Declarations that describe the Quagga register file
//===----------------------------------------------------------------------===//

class QuaggaReg<bits<16> Enc, string n> : Register<n> {
  let HWEncoding = Enc;
  let Namespace = "Quagga";
}

// General Purpose Registers
def R0  : QuaggaReg<0,  "r0">;
def R1  : QuaggaReg<1,  "r1">;
def R2  : QuaggaReg<2,  "r2">;
def R3  : QuaggaReg<3,  "r3">;
def R4  : QuaggaReg<4,  "r4">;
def R5  : QuaggaReg<5,  "r5">;
def R6  : QuaggaReg<6,  "r6">;
def R7  : QuaggaReg<7,  "r7">;
def R8  : QuaggaReg<8,  "r8">;
def R9  : QuaggaReg<9,  "r9">;
def R10 : QuaggaReg<10, "r10">;
def R11 : QuaggaReg<11, "r11">;
def R12 : QuaggaReg<12, "r12">;
def R13 : QuaggaReg<13, "r13">;
def R14 : QuaggaReg<14, "r14">;
def R15 : QuaggaReg<15, "r15">;

// Register Classes
def GRRegs : RegisterClass<"Quagga", [i32], 32,
  (add R0, R1, R2, R3, R4, R5, R6, R7,
       R8, R9, R10, R11, R12, R13, R14, R15)>;
