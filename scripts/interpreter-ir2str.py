import binascii
import os

def cut(obj, sec):
    return [obj[i:i+sec] for i in range(0,len(obj),sec)]


def bytecode2string2():

    # tranverse .bc to hex output
    f = open("/tmp/xVMPInterpreter.bc", "rb")
    data = f.read()
    data_hex = binascii.b2a_hex(data)
    f.close()

    # f = open("/tmp/vm.h", "w")
    currpath = os.path.dirname(os.path.abspath(__file__))
    f = open(currpath+"/../src/include/llvm/Transforms/Obfuscation/vm.h", "w")

    f.write("#include <string>\n")
    f.write("const int binary_ir_length = " + str(len(data)) +";\n")

    f.write("std::vector<std::string> binary_ir_vector = \n{")

    for data_cut in cut(data_hex, 10000):
        f.write("\tstd::string(\"")
        for i in range(len(data_cut)//2):
            f.write("\\x" + data_cut[2*i: 2*(i+1)])
        f.write("\", %d),\n" % (len(data_cut)//2))

    f.write("\n};\n\n")

    f.write("std::string binary_ir;")

    # f.write("""
    # binary_ir.resize(binary_ir_length);
    # int binary_ir_idx = 0;
    # for(auto s: binary_ir_vector) {
    #     for (int i = 0; i < s.size(); i++) {
    #         binary_ir[binary_ir_idx++] = s[i];
    #     }
    # }
    # """)

    f.close()


bytecode2string2()

print("[*] finish!")

