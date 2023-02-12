#include "xVMPInterpreter.h"
#include <stdio.h>

// #define GOVM_CPP_DEBUG

#define SEG_SIZE 5000

#define IS_INLINE_FUNC

#define TEST_GOVM_C

uint8_t gv_code_seg[SEG_SIZE] = {
    #ifdef TEST_GOVM_C
    //  0, 8, 0, 12, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 28, 0, 0, 0, 0, 0, 0, 0, 36, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 40, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0, 0, 17, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 12, 0, 0, 0, 0, 0, 0, 0, 17, 4, 0, 8, 0, 0, 0, 0, 0, 0, 0, 8, 0, 28, 0, 0, 0, 0, 0, 0, 0, 17, 4, 11, 0, 0, 0, 0, 8, 0, 40, 0, 0, 0, 0, 0, 0, 0, 96, 0, 126, 0, 0, 0, 0, 0, 0, 0, 16, 4, 0, 52, 0, 0, 0, 0, 0, 0, 0, 8, 0, 40, 0, 0, 0, 0, 0, 0, 0, 16, 4, 0, 56, 0, 0, 0, 0, 0, 0, 0, 8, 0, 28, 0, 0, 0, 0, 0, 0, 0, 64, 40, 1, 0, 60, 0, 0, 0, 0, 0, 0, 0, 4, 0, 52, 0, 0, 0, 0, 0, 0, 0, 4, 0, 56, 0, 0, 0, 0, 0, 0, 0, 96, 1, 1, 0, 60, 0, 0, 0, 0, 0, 0, 0, 228, 0, 0, 0, 0, 0, 0, 0, 14, 2, 0, 0, 0, 0, 0, 0, 16, 8, 0, 61, 0, 0, 0, 0, 0, 0, 0, 8, 0, 12, 0, 0, 0, 0, 0, 0, 0, 16, 4, 0, 69, 0, 0, 0, 0, 0, 0, 0, 8, 0, 40, 0, 0, 0, 0, 0, 0, 0, 80, 8, 0, 73, 0, 0, 0, 0, 0, 0, 0, 4, 0, 69, 0, 0, 0, 0, 0, 0, 0, 48, 1, 11, 8, 0, 81, 0, 0, 0, 0, 0, 0, 0, 8, 0, 61, 0, 0, 0, 0, 0, 0, 0, 8, 0, 73, 0, 0, 0, 0, 0, 0, 0, 16, 1, 0, 89, 0, 0, 0, 0, 0, 0, 0, 8, 0, 81, 0, 0, 0, 0, 0, 0, 0, 80, 4, 0, 90, 0, 0, 0, 0, 0, 0, 0, 1, 0, 89, 0, 0, 0, 0, 0, 0, 0, 32, 29, 4, 0, 94, 0, 0, 0, 0, 0, 0, 0, 4, 0, 90, 0, 0, 0, 0, 0, 0, 0, 4, 11, 58, 0, 0, 0, 80, 1, 0, 98, 0, 0, 0, 0, 0, 0, 0, 4, 0, 94, 0, 0, 0, 0, 0, 0, 0, 17, 1, 0, 98, 0, 0, 0, 0, 0, 0, 0, 8, 0, 81, 0, 0, 0, 0, 0, 0, 0, 96, 0, 190, 1, 0, 0, 0, 0, 0, 0, 16, 4, 0, 99, 0, 0, 0, 0, 0, 0, 0, 8, 0, 40, 0, 0, 0, 0, 0, 0, 0, 32, 12, 4, 0, 103, 0, 0, 0, 0, 0, 0, 0, 4, 0, 99, 0, 0, 0, 0, 0, 0, 0, 4, 11, 1, 0, 0, 0, 17, 4, 0, 103, 0, 0, 0, 0, 0, 0, 0, 8, 0, 40, 0, 0, 0, 0, 0, 0, 0, 96, 0, 126, 0, 0, 0, 0, 0, 0, 0, 240, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    243, 149, 17, 126, 14, 92, 244, 62, 16, 249, 39, 46, 15, 215, 218, 109, 247, 148, 139, 153, 184, 179, 1, 197, 71, 203, 253, 79, 245, 251, 238, 205, 163, 80, 118, 201, 130, 155, 240, 35, 189, 175, 219, 162, 206, 47, 50, 86, 244, 152, 43, 206, 127, 7, 96, 119, 37, 102, 184, 254, 124, 155, 77, 58, 139, 170, 132, 121, 240, 116, 126, 214, 205, 100, 252, 152, 52, 140, 120, 219, 59, 193, 209, 118, 220, 192, 214, 152, 143, 83, 100, 77, 57, 188, 93, 250, 68, 63, 108, 155, 22, 167, 228, 220, 170, 140, 10, 45, 104, 130, 211, 251, 19, 57, 102, 108, 126, 85, 231, 187, 100, 93, 150, 50, 253, 3, 33, 213, 60, 239, 3, 11, 161, 97, 25, 34, 219, 88, 79, 248, 180, 38, 6, 212, 162,154, 2, 134, 179, 143, 126, 212, 140, 97, 130, 46, 230, 127, 234, 144, 237, 169, 186, 228, 86, 179, 113, 217, 52, 175, 203, 137, 105, 211, 180, 119, 188, 10, 32, 95, 209, 108, 233, 12, 99, 194, 144, 72, 35, 10, 121, 124, 8, 71, 170, 33, 90, 158, 233, 11, 65, 73, 142, 49, 188, 210, 200, 250, 146, 117, 24, 16, 129, 114, 246, 70, 178, 106, 216, 100, 147, 138, 111, 235, 36, 159, 86, 130, 47, 136, 128, 246, 187, 98, 226, 242, 240, 148, 170, 161, 171, 34, 24, 131, 73, 13, 7, 7, 156, 237, 190, 53, 75, 168, 231, 138, 0, 39, 130, 190, 155, 242, 130, 173, 20, 151, 199, 112, 211, 116, 113, 172, 189, 150, 228, 122, 78, 191, 177, 161, 119, 63, 74, 187, 121, 199, 165, 0, 146, 203, 253, 189, 85, 144, 24, 162, 117, 130, 200, 223, 110, 92, 116, 98, 240, 209, 246, 12, 19, 236, 6, 242, 36, 76, 32, 26, 101, 82, 176, 68, 218, 125, 48, 20, 14, 221, 234, 50, 141, 216, 17, 57, 243, 191, 56, 145, 204, 213, 193, 162, 89, 21, 143, 170, 184, 238, 62, 92, 62, 19, 43, 160, 171, 223, 23, 187, 144, 35, 19, 116, 64, 11, 27, 212, 249, 236, 34, 77, 191, 45, 58, 139, 156, 39, 255, 15, 163, 196, 154, 151, 74, 102, 211, 135, 198, 225, 185, 139, 98, 149, 71, 200, 109, 47, 161, 181, 161, 215, 84, 82, 173, 45, 160, 55, 116, 159, 30, 180, 46, 45, 84, 25, 120, 245, 51, 197, 195, 11, 19, 184, 239, 242, 155, 31, 94, 131, 55, 68, 43, 82, 55, 27, 86, 95, 25, 1, 59, 183, 105, 11, 36, 89, 218, 16, 123, 215, 208, 64, 98, 205, 55, 150, 100, 117, 172, 110, 3, 47, 48, 159, 86, 85, 49, 226, 210, 129, 151, 80, 102, 10, 186, 68, 202, 42, 182, 211, 51, 26, 140, 209, 166, 236, 252, 244, 115, 137, 234, 90, 223, 105, 195, 89, 231, 92, 155, 205, 80, 216, 200, 224, 160, 219, 96, 51, 153, 177, 42, 64, 237, 40, 8, 174, 26, 49, 159, 189, 228, 251, 164, 70, 182, 10, 146, 227, 88, 231, 103, 157, 72, 143, 126, 217, 44, 11, 187, 164, 237, 209, 34, 214, 186, 19, 51, 72, 154, 190, 233, 168, 79, 130, 28, 15, 237, 53, 26, 218, 250, 119, 134, 25, 23, 48, 60, 198, 90, 60, 66, 8, 61, 30, 27, 58, 226, 42, 144, 220, 161,
    #endif
};
uint8_t gv_data_seg[SEG_SIZE] = {};

//
uintptr_t data_seg_addr = 0;
uintptr_t code_seg_addr = 0;

int ip = 0;

// Opcode encrypt by xorshift32
uint32_t opcode_xorshift32_state = 0;
uint32_t vm_code_state = 0;

#ifdef IS_INLINE_FUNC
    __inline__ __attribute__((always_inline))
#endif
/* The state word must be initialized to non-zero */
uint32_t xorshift32(uint32_t *state)
{
    /* Algorithm "xor" from p. 4 of Marsaglia, "Xorshift RNGs" */
    uint32_t x = *state;
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    return *state = x;
}

#ifdef IS_INLINE_FUNC
    __inline__ __attribute__((always_inline))
#endif
uint8_t get_byte_code() {
    uint8_t tmp = ((uint8_t *)code_seg_addr)[ip++];
    tmp ^= (xorshift32(&vm_code_state) & 0xFF);
    return tmp;
}

#ifdef IS_INLINE_FUNC
    __inline__ __attribute__((always_inline))
#endif
// unpack data from code_seg directly(without xorshift32)
uint32_t get_xorshift_seed() {
    uint32_t res = 0;
    
    for (int i = 0; i < 4; i++) {
        res |= (uint32_t)((uint8_t *)code_seg_addr)[ip++] << (8 * i);
    }

    return res;
}

#ifdef IS_INLINE_FUNC
    __inline__ __attribute__((always_inline))
#endif
// unpack data from code_seg
uint64_t unpack_code(int size) {
    uint64_t res = 0;
    
    for (int i = 0; i < size; i++) {
        res |= (uint64_t)get_byte_code() << (8 * i);
    }

    return res;
}

#ifdef IS_INLINE_FUNC
    __inline__ __attribute__((always_inline))
#endif
// unpack data from data_seg
uint64_t unpack_data(uint64_t offset, int size) {
    uint64_t res = 0;
    
    for (int i = 0; i < size; i++) {
        // must add (uint64_t), or overflow int32
        res |= (uint64_t)((uint8_t *)data_seg_addr)[offset++] << (8 * i);
    }

    return res;
}

#ifdef IS_INLINE_FUNC
    __inline__ __attribute__((always_inline))
#endif
uint64_t unpack_addr(uint64_t address, int size) {
    uint8_t * ptr = (uint8_t *) address;

    uint64_t res = 0;
    
    for (int i = 0; i < size; i++) {
        res |= (uint64_t)*ptr << (8 * i);
        ptr ++;
    }

    return res;
}

#ifdef IS_INLINE_FUNC
    __inline__ __attribute__((always_inline))
#endif
void pack_store_addr(uint64_t address, uint64_t value, int size) {
    uint8_t * ptr = (uint8_t *) address;

    for (int i = 0; i < size; i++) {
        *ptr = value & 0xFF;
        ptr ++;
        value = value >> 8;
    }
}

#ifdef IS_INLINE_FUNC
    __inline__ __attribute__((always_inline))
#endif
// get a var or const directly 
uint64_t get_value_with_size(uint8_t value_size, uint8_t value_type) {

    uint64_t res = 0;
    if (value_type == 0) {
        // is a var

        // get var_offset of data_seg
        uint64_t var_offset = unpack_code(POINTER_SIZE);

        // fetch data from data_seg
        res = unpack_data(var_offset, value_size);
    }
    else {
        // const

        // unpack const from code
        res = unpack_code(value_size);
    }

    return res;
}

#ifdef IS_INLINE_FUNC
    __inline__ __attribute__((always_inline))
#endif
uint64_t get_value() {

    uint8_t value_size = get_byte_code();
    uint8_t value_type = get_byte_code();

    uint64_t res = 0;
    if (value_type == 0) {
        // is a var

        // get var_offset of data_seg
        uint64_t var_offset = unpack_code(POINTER_SIZE);

        // fetch data from data_seg
        res = unpack_data(var_offset, value_size);
    }
    else {
        // const

        // unpack const from code
        res = unpack_code(value_size);
    }

    return res;
}

#ifdef IS_INLINE_FUNC
    __inline__ __attribute__((always_inline))
#endif
void alloca_handler() {
    // size and type of pointer is useless
    uint8_t var_size = get_byte_code();
    uint8_t var_type = get_byte_code();

    // get pointer var offset
    uint64_t var_offset = unpack_code(POINTER_SIZE);

    // get alloca area offset
    uint64_t area_offset = unpack_code(POINTER_SIZE);

    // store area virtual address to var
    // set_var(var_offset, POINTER_SIZE, data_seg_addr+area_offset);
    pack_store_addr(data_seg_addr+var_offset, data_seg_addr+area_offset, var_size);
}

#ifdef IS_INLINE_FUNC
    __inline__ __attribute__((always_inline))
#endif
void load_handler() {
    uint8_t var_size = get_byte_code();
    uint8_t var_type = get_byte_code();
    uint64_t var_offset = unpack_code(POINTER_SIZE);


    uint8_t ptr_size = get_byte_code();
    uint8_t ptr_type = get_byte_code();
    uint64_t ptr_offset = unpack_code(POINTER_SIZE);

    // load virtual address
    uint64_t ptr = unpack_data(ptr_offset, POINTER_SIZE);

    // load value from address
    uint64_t load_value = unpack_addr(ptr, var_size);

    // printf("load  ptr: %lx, load_value: %lx, var_size: %lx\n", ptr, load_value, var_size);
    // store value to var
    pack_store_addr(data_seg_addr+var_offset, load_value, var_size);
}

#ifdef IS_INLINE_FUNC
    __inline__ __attribute__((always_inline))
#endif
void store_handler() {
    uint8_t var_size = get_byte_code();
    uint8_t var_type = get_byte_code();
    uint64_t store_value = get_value_with_size(var_size, var_type);

    uint8_t ptr_size = get_byte_code();
    uint8_t ptr_type = get_byte_code();
    uint64_t ptr_offset = unpack_code(POINTER_SIZE);

    uint64_t ptr = unpack_data(ptr_offset, POINTER_SIZE);

    // printf("store ptr: %lx, store_value: %lx, var_size: %lx\n", ptr, store_value, var_size);
    pack_store_addr(ptr, store_value, var_size);
}

#ifdef IS_INLINE_FUNC
    __inline__ __attribute__((always_inline))
#endif
void binaryOperator_handler() {
    // binary op_code
    uint8_t op_code = get_byte_code();

    uint8_t res_size = get_byte_code();
    uint8_t res_type = get_byte_code();
    uint64_t res_offset = unpack_code(POINTER_SIZE);

    // get operands
    uint64_t op1_value = get_value();
    uint64_t op2_value = get_value();

    uint64_t res_value = 0;

    switch (op_code)
    {
        case BINOP_ADD:
            res_value = op1_value + op2_value;
            break;
        case BINOP_SUB:
            res_value = op1_value - op2_value;
            break;
        case BINOP_MUL:
            res_value = op1_value * op2_value;
            break;
        case BINOP_UDIV:
            res_value = op1_value / op2_value;
            break;
        case BINOP_SDIV:
            res_value = op1_value / op2_value;
            break;
        case BINOP_UREM:
            res_value = op1_value % op2_value;
            break;
        case BINOP_SREM:
            res_value = op1_value % op2_value;
            break;
        case BINOP_SHL:
            res_value = op1_value << op2_value;
            break;
        case BINOP_LSHR:
            res_value = op1_value >> op2_value;
            break;
        case BINOP_ASHR:
            res_value = op1_value >> op2_value;
            break;
        case BINOP_AND:
            res_value = op1_value & op2_value;
            break;
        case BINOP_OR:
            res_value = op1_value | op2_value;
            break;
        case BINOP_XOR:
            res_value = op1_value ^ op2_value;
            break;
        
        default:
            break;
    }

    // printf("bn op1_value: %lx, op2_value: %lx, res_value: %lx\n", op1_value, op2_value, res_value);
    // store to result var
    pack_store_addr(data_seg_addr+res_offset, res_value, res_size);

}

#ifdef IS_INLINE_FUNC
    __inline__ __attribute__((always_inline))
#endif
void gep_handler() {
    // get gep size and type
    uint8_t gep_size = get_byte_code();
    uint8_t gep_type = get_byte_code();

    // get return value
    uint8_t res_size = get_byte_code();
    uint8_t res_type = get_byte_code();
    uint64_t res_offset = unpack_code(POINTER_SIZE);

    uint64_t ptr_value = get_value();

    uint64_t idx_value = get_value();

    uint64_t res_value = 0;

    if (gep_size != 0 && gep_type != 0) {
        // array type
        res_value = ptr_value + gep_size * idx_value;
    } 
    else {
        // struct type
        res_value = ptr_value + gep_size;
    }

    pack_store_addr(data_seg_addr+res_offset, res_value, res_size);
}

#ifdef IS_INLINE_FUNC
    __inline__ __attribute__((always_inline))
#endif
void cmp_handler() {
    // get Predicate
    uint8_t predicate = get_byte_code();

    uint8_t res_size = get_byte_code();
    uint8_t res_type = get_byte_code();
    uint64_t res_offset = unpack_code(POINTER_SIZE);

    // get operands
    uint64_t op1_value = get_value();
    uint64_t op2_value = get_value();

    uint64_t res_value = 0;
    // printf("op1: 0x%lx, op2: 0x%lx\n", op1_value, op2_value);

    switch (predicate)
    {
        case ICMP_EQ:
            res_value = op1_value == op2_value;
            break;
        case ICMP_NE:
            res_value = op1_value != op2_value;
            break;
        case ICMP_UGT:
            res_value = op1_value >  op2_value;
            break;
        case ICMP_UGE:
            res_value = op1_value >= op2_value;
            break;
        case ICMP_ULT:
            res_value = op1_value <  op2_value;
            break;
        case ICMP_ULE:
            res_value = op1_value <= op2_value;
            break;
        case ICMP_SGT:
            res_value = op1_value >  op2_value;
            break;
        case ICMP_SGE:
            res_value = op1_value >= op2_value;
            break;
        case ICMP_SLT:
            res_value = op1_value <  op2_value;
            break;
        case ICMP_SLE:
            res_value = op1_value <= op2_value;
            break;
        default:
            break;
    }

    pack_store_addr(data_seg_addr+res_offset, res_value, res_size);
}

#ifdef IS_INLINE_FUNC
    __inline__ __attribute__((always_inline))
#endif
void cast_handler() {
    uint8_t res_size = get_byte_code();
    uint8_t res_type = get_byte_code();
    uint64_t res_offset = unpack_code(POINTER_SIZE);

    uint64_t op_value = get_value();

    pack_store_addr(data_seg_addr+res_offset, op_value, res_size);
}

#ifdef IS_INLINE_FUNC
    __inline__ __attribute__((always_inline))
#endif
void br_handler() {
    // get br type
    uint8_t br_type = get_byte_code();

    uint64_t target_addr = 0;

    if (br_type == 0) {
        // uncondition br
        target_addr = unpack_code(POINTER_SIZE);
    }
    else {
        // condition
        uint64_t condition_value = get_value();
        uint64_t true_br = unpack_code(POINTER_SIZE);
        uint64_t false_br = unpack_code(POINTER_SIZE);

        if (condition_value) {
            target_addr = true_br;
        } 
        else {
            target_addr = false_br;
        }
    }

    // set ip
    ip = target_addr;
}

#ifdef IS_INLINE_FUNC
    __inline__ __attribute__((always_inline))
#endif
void data_seg_clean(int return_value_off) {
    // clean data seg, from the end of return value
    for (unsigned i=return_value_off; i<SEG_SIZE; i++) {
        ((uint8_t *)data_seg_addr)[i] = 0;
    }
}

#ifdef IS_INLINE_FUNC
    __inline__ __attribute__((always_inline))
#endif
void return_handler() {
    uint8_t var_size = get_byte_code();
    uint8_t var_type = get_byte_code();
    uint64_t ret_value = get_value_with_size(var_size, var_type);

    if (var_size != 0 || var_type != 0) {
        pack_store_addr((uint64_t)data_seg_addr, ret_value, var_size);
    }
    // we dont know data_seg size, may segmentfault
    // data_seg_clean(var_size);
    // for (unsigned i=var_size; i<SEG_SIZE; i++) {
    //     ((uint8_t *)data_seg_addr)[i] = 0;
    // }
}

void call_handler(uint64_t targetfunc_id) {

}


#ifdef IS_INLINE_FUNC
    __inline__ __attribute__((always_inline))
#endif
/* Get Opcode, Opcode encrypt by xorshift32*/
uint8_t get_opcode() {
    uint8_t cnt = 0;
    uint8_t his[OP_TOTAL+1];

    uint8_t curr_byte = get_byte_code();

    for (int i = 0; i < OP_TOTAL+1; i++) {
        uint8_t tmp = xorshift32(&opcode_xorshift32_state);
        // printf("curr_byte: %d, tmp: %d\n", curr_byte, tmp);
        if (tmp == curr_byte) {
            // find
            return i+1;
        }
        
        // privent xorshift32&0xFF conflict
        uint8_t flag = 1;
        for (int j=0; j < i; j++) {
            if (his[j] == tmp) {
                flag = 0;
            }
        }

        if (flag == 1) {
            his[i] = tmp;
        }
        else {
            i--;
        }
    }

    return 0xFF;
}


void vm_interpreter() {

    // init
    ip = 0;

    // when step into a new basicblock, we need to fetch opcode_seed and vm_code_seed
    uint8_t is_a_new_bb = 1;
    
    while(1) {

        if (is_a_new_bb) {
            opcode_xorshift32_state = get_xorshift_seed();
            vm_code_state = get_xorshift_seed();
            is_a_new_bb = 0;
            
            #ifdef GOVM_CPP_DEBUG
                printf("In a new BasicBlock. IP = %d\n", ip);
                printf("opcode_xorshift32_state: %u\n", opcode_xorshift32_state);
                printf("vm_code_state: %u\n", vm_code_state);
            #endif
        }

        // switch op_code and add ip
        uint8_t opcode = get_opcode();
        #ifdef GOVM_CPP_DEBUG
            printf("ip: %d, \tcurropcode: %d\n", ip, opcode);
        #endif
        switch (opcode) {
                
            case ALLOCA_OP:
                alloca_handler();
                break;
            case LOAD_OP:
                load_handler();
                break;
            case STORE_OP:
                store_handler();
                break;
            case BinaryOperator_OP:
                binaryOperator_handler();
                break;
            case GEP_OP:
                gep_handler();
                break;
            case CMP_OP:
                cmp_handler();
                break;
            case CAST_OP:
                cast_handler();
                break;
            case BR_OP:    
                br_handler();
                is_a_new_bb = 1;
                break;
            case Ret_OP:
                return_handler();
                // data_seg_clean();
                return;
                break;
            case Call_OP:
                // uint64_t targetfunc_id = unpack_code(POINTER_SIZE);
                call_handler(unpack_code(POINTER_SIZE));
                break;
            default:
                return;
                // cannot recognize opcode
                
        }
    }
}

int main() {
    char test[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // char test[10] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    uint32_t len = 10;

    setbuf(stdout, 0);
    setbuf(stderr, 0);

    ((uintptr_t *)gv_data_seg)[0] = (uintptr_t) test;
    ((uint32_t *)gv_data_seg)[2] = len;
    data_seg_addr = (uintptr_t) gv_data_seg;
    code_seg_addr = (uintptr_t) gv_code_seg;

    vm_interpreter();
    //printf("vm_interpreter: %d\n", ((uint32_t *)gv_data_seg)[0]);

    for(int i=0; i < len; i++) {
        printf("%d, ", test[i]);
    }
    printf("\n");
}








