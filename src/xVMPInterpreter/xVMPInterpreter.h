//#include <string>
//#include <cstdint>
#include <stdint.h>
#include <assert.h>

// Opcode 
#define ALLOCA_OP           0x01
#define LOAD_OP             0x02
#define STORE_OP            0x03
#define BinaryOperator_OP   0x04
#define GEP_OP              0x05
#define CMP_OP              0x06
#define CAST_OP             0x07
#define BR_OP               0x08
#define Call_OP             0x09
#define Ret_OP              0x0A

#define OP_TOTAL            0x0A


// pointer size
#define POINTER_SIZE 8




// BinaryOperator codes
// please check /home/xgx/llvm-8.0.1/llvm-8.0.1.src/include/llvm/IR/Instruction.def
// llvm-8.0.1 is different with newer XOR=29
// llvm-9.0 XOR=30
// newer: https://llvm.org/doxygen/IR_2Instruction_8h_source.html#l00704

#define BINOP_ADD       12
#define BINOP_FADD      13
#define BINOP_SUB       14
#define BINOP_FSUB      15
#define BINOP_MUL       16
#define BINOP_FMUL      17
#define BINOP_UDIV      18
#define BINOP_SDIV      19
#define BINOP_FDIV      20
#define BINOP_UREM      21
#define BINOP_SREM      22
#define BINOP_FREM      23
#define BINOP_SHL       24
#define BINOP_LSHR      25
#define BINOP_ASHR      26
#define BINOP_AND       27
#define BINOP_OR        28
#define BINOP_XOR       29

// // llvm 9+
// #define BINOP_ADD       13
// #define BINOP_FADD      14
// #define BINOP_SUB       15
// #define BINOP_FSUB      16
// #define BINOP_MUL       17
// #define BINOP_FMUL      18
// #define BINOP_UDIV      19
// #define BINOP_SDIV      20
// #define BINOP_FDIV      21
// #define BINOP_UREM      22
// #define BINOP_SREM      23
// #define BINOP_FREM      24
// #define BINOP_SHL       25
// #define BINOP_LSHR      26
// #define BINOP_ASHR      27
// #define BINOP_AND       28
// #define BINOP_OR        29
// #define BINOP_XOR       30



// Opcode              U L G E    Intuitive operation
// only icmp without fcmp
// https://llvm.org/doxygen/InstrTypes_8h_source.html#l00402

#define ICMP_EQ     32  ///< equal
#define ICMP_NE     33  ///< not equal
#define ICMP_UGT    34  ///< unsigned greater than
#define ICMP_UGE    35  ///< unsigned greater or equal
#define ICMP_ULT    36  ///< unsigned less than
#define ICMP_ULE    37  ///< unsigned less or equal
#define ICMP_SGT    38  ///< signed greater than
#define ICMP_SGE    39  ///< signed greater or equal
#define ICMP_SLT    40  ///< signed less than
#define ICMP_SLE    41  ///< signed less or equal






// functions
uint64_t unpack_code(int size);
uint64_t unpack_data(uint64_t offset, int size);
uint64_t unpack_addr(uint64_t address, int size);
void pack_store_addr(uint64_t address, uint64_t value, int size);
uint64_t get_value_with_size(uint8_t value_size, uint8_t value_type);
uint64_t get_value();
void alloca_handler();
void load_handler();
void store_handler();
void binaryOperator_handler();
void gep_handler();
void cmp_handler();
void cast_handler();
void br_handler();
void return_handler();
void vm_interpreter();
void data_seg_clear();


