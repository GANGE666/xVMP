# xVMP

xVMP is an LLVM IR-based code virtualization tool, which fulfilled a scalable and virtualized instruction-hardened obfuscation. It supports multiple programming languages, and architectures. It is also compatible with existing LLVM IR-based obfuscation schemes (such as Obfuscator-LLVM).

xVMP is developer friendly. You only need to add annotations to the to-be-protected function in the source code, and xVMP can perform virtualization protection on the function during compilation.

The website http://xvmp.homes/ which contains the detailed usage document and video is also available.



## Table of Contents

- [Background](#background)
- [Install](#install)
- [Usage](#usage)
- [Examples](#examples)
- [Precautions](#Precautions)
- [Maintainers](#maintainers)
- [Contributing](#contributing)



## Background

Virtualization-based software protection schemes protect the logic and data in the program by converting the original code into a new bytecode based on the custom instruction set architecture (ISA). The new bytecode is emulated via an embedded virtual machine (i.e. interpreter) at runtime. Since a lot of reverse engineering is required for attackers to learn the custom ISA, virtualization obfuscation could hide valuable assets in software.

To meet the requirements in real-world software development, the virtualization obfuscator should achieve the following three goals: 

- i) Strong protection, which means that virtualized code should resist various de-virtualization techniques such as symbolic execution, frequency analysis, etc. 
- ii) Compatibility, which means the virtualization obfuscator should support different source code types, platforms, instruction sets, and various code obfuscation schemes. 
- iii) Ease of use, i.e., developers only need to make simple marks to complete the obfuscation.

Unfortunately, the state-of-the-art virtualization obfuscators cannot fulfill the above requirements. On the one hand, they lack effective protection for virtualization instructions (Tigress only xors a constant for all instructions) and many works in recent years have broken through them by using frequency analysis and symbolic execution. On the other hand, VMProtect and Themida only support virtualize executables on X86 and X64 architectures, and they are not open source. The most advanced academic virtualization scheme Tigress can only support C language source code, and since its input must be a single file containing the full program source code, it is difficult to blend in the software development cycle.

Therefore, we present xVMP, an LLVM-based code virtualization obfuscator fulfills these goals. It incorporates the obfuscation process of code virtualization into the compilation to mask the effects of different architectures and program languages. xVMP generates virtualized code based on LLVM IR and embeds the interpreter of virtualized code into the IR and compiles to an executable. To enhance the security, xVMP encrypts virtualized instructions in each basic block and decrypts them at runtime to enhance the security of obfuscation. In addition, it supports specified function obfuscation. xVMP identifies the function annotations marked by the developer in the source code to locate the function to protect.



## Install

### Prebuilt Binaries

Please download the latest prebuilt binaries from [Release](https://github.com/GANGE666/xVMP/releases).

### Building from source with Obfuscator-LLVM

The code in the master branch is xVMP mixed with obfuscator-llvm based on LLLVM 8.0.

1. Use the building script. It will build xVMP and compatible obfuscator-llvm in the `build` directory.

```bash
$ bash ./build.sh
```

### Building as a plugin for LLVM

TBD

### Docker

TBD



## Usage

You only need to add the annotation before the definition of the to-be-protected function. As shown in the following code.

```c
__attribute((__annotate__("vmp"))) 	// add this annotation
void gen_deckey (unsigned char *decrypt_key, char *passwd) {
  // generate decrypt key from the password
}
```

Then compile the source code using the LLVM toolchain with xVMP. 

But please heed these [precautions](#Precautions).



## Examples



## Precautions

- Code optimization. Virtualization is unsound because code optimization may introduces instructions that xVMP cannot handle. So please compile with the `-O0` option, or optimize after xVMP virtualization is complete.



## Maintainers

[@G6](https://github.com/GANGE666).

## Contributing

Feel free to dive in! [Open an issue](https://github.com/GANGE666/xVMP/issues/new) or submit PRs.