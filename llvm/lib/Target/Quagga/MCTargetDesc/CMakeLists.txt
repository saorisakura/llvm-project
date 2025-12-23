add_llvm_component_library(LLVMQuaggaDesc
  QuaggaAsmBackend.cpp
  QuaggaELFObjectWriter.cpp
  QuaggaInstPrinter.cpp
  QuaggaMCCodeEmitter.cpp
  QuaggaMCTargetDesc.cpp

  LINK_COMPONENTS
  MC
  QuaggaInfo
  Support

  ADD_TO_COMPONENT
  Quagga
  )
