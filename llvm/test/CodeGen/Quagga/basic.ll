; RUN: llc -mtriple=quagga < %s | FileCheck %s
; RUN: llc -mtriple=quagga -filetype=obj < %s

; Basic test to verify Quagga target is registered and functional

define i32 @test_simple() {
; CHECK-LABEL: test_simple:
  ret i32 42
}
