add_llvm_component_group(Quagga)

set(LLVM_TARGET_DEFINITIONS Quagga.td)

tablegen(LLVM QuaggaGenAsmWriter.inc -gen-asm-writer)
tablegen(LLVM QuaggaGenCallingConv.inc -gen-callingconv)
tablegen(LLVM QuaggaGenInstrInfo.inc -gen-instr-info)
tablegen(LLVM QuaggaGenMCCodeEmitter.inc -gen-emitter)
tablegen(LLVM QuaggaGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM QuaggaGenSubtargetInfo.inc -gen-subtarget)

add_public_tablegen_target(QuaggaCommonTableGen)

add_llvm_target(QuaggaCodeGen
  QuaggaSubtarget.cpp
  QuaggaTargetMachine.cpp

  LINK_COMPONENTS
  AsmPrinter
  CodeGen
  Core
  MC
  QuaggaDesc
  QuaggaInfo
  SelectionDAG
  Support
  Target
  TargetParser

  ADD_TO_COMPONENT
  Quagga
  )

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)
