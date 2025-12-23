//===-- QuaggaCallingConv.td - Calling Conventions --------*- tablegen -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
// Quagga calling convention
//===----------------------------------------------------------------------===//

def CC_Quagga : CallingConv<[
  CCIfType<[i32], CCAssignToReg<[R0, R1, R2, R3]>>,
  CCIfType<[i32], CCAssignToStack<4, 4>>
]>;

def RetCC_Quagga : CallingConv<[
  CCIfType<[i32], CCAssignToReg<[R0, R1]>>
]>;
