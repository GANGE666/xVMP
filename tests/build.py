import os
import subprocess

os.chdir(os.path.dirname(os.path.realpath(__file__)))

# filelist = [
#     f"test{i}.c" for i in range(1, 7)
# ]

TESTBEGIN = 1
TESTEND = 21+1

SRC_PATH = "./samples/"
OUTPUT_PATH = "/tmp/xvmp_test/"
PREFIX="sample"

clang_path = os.path.dirname(os.path.realpath(__file__))+"/../build/bin/clang"

if not os.path.exists(OUTPUT_PATH):
    os.mkdir(OUTPUT_PATH)
    os.mkdir(OUTPUT_PATH+"original/")
    os.mkdir(OUTPUT_PATH+"govmp_out/")

def run_cmd(cmd):
    print("\033[31;43;1m", "Running command: ", cmd, "\033[0m")
    if cmd.startswith("cd "):
        os.chdir(cmd.split(" ")[1])
        return
    ret = os.system(cmd)
    if "Virtualize" in cmd:
        return
    if ret != 0:
        print("Error: ", ret)
        exit(0)


def test_samples():

    for idx in range(TESTBEGIN, TESTEND):
        ori_cmd = f"{clang_path} {SRC_PATH}/{PREFIX}{idx}.c -o {OUTPUT_PATH}/original/{PREFIX}{idx}_ori"
        run_cmd(ori_cmd)

        clang_cmd = f"{clang_path} -DENABLE_GOVMP {SRC_PATH}/{PREFIX}{idx}.c -o {OUTPUT_PATH}/govmp_out/{PREFIX}{idx}_govmp"
        run_cmd(clang_cmd)

        cmd_l = f"{OUTPUT_PATH}/original/{PREFIX}{idx}_ori 123456"
        r1 = subprocess.getoutput(cmd_l)
        cmd_l = f"{OUTPUT_PATH}/govmp_out/{PREFIX}{idx}_govmp 123456"
        r2 = subprocess.getoutput(cmd_l)

        if r1 == r2:
            # all the output is same
            print(f"Test result: {PREFIX}{idx} OK")
            print(r1)
            print(r2)
        else:
            print(f"Test result: {PREFIX}{idx} FAIL")
            print(r1)
            print(r2)
            exit(0)

        print(f"Done {PREFIX}{idx}")
        print("\033[31;43;1m", "Success!", "\033[0m")

if __name__ == "__main__":
    test_samples()
    

