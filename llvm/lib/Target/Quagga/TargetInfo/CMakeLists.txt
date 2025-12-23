add_llvm_component_library(LLVMQuaggaInfo
  QuaggaTargetInfo.cpp

  LINK_COMPONENTS
  MC
  Support

  ADD_TO_COMPONENT
  Quagga
  )
