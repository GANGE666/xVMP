add_llvm_library(LLVMObfuscation
  CryptoUtils.cpp
  Substitution.cpp
  StringObfuscation.cpp
  BogusControlFlow.cpp
  Utils.cpp
  SplitBasicBlocks.cpp
  Flattening.cpp
  xVMP.cpp

  ADDITIONAL_HEADER_DIRS
  ${LLVM_MAIN_INCLUDE_DIR}/llvm/Transforms/Obfuscation
)

set(LLVM_LINK_COMPONENTS
  ${LLVM_TARGETS_TO_BUILD}
  ScalarOpts
)

add_dependencies(LLVMObfuscation intrinsics_gen)

