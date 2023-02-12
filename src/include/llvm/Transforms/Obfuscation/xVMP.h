
#ifndef _OBFUSCATION_VMPROTECT_H_
#define _OBFUSCATION_VMPROTECT_H_

#include "llvm/ADT/Statistic.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/Module.h"
#include "llvm/Pass.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Transforms/IPO.h"
// #include "llvm/Transforms/Obfuscation/CryptoUtils.h"

namespace llvm {
Pass *createVMProtect(bool flag);
} // namespace llvm

extern bool is_interpreter_function(llvm::Function *targetFunction);
extern std::string get_vm_function_name(llvm::Function *targetFunction);

#endif

