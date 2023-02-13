#!/bin/bash
set -ex

ROOT_PATH=$(cd $(dirname $0)/../; pwd)
# echo $ROOT_PATH

# use clang-8 to compile interpreter first.
# CLANG_PATH=/ollvm/ollvm/llvm-8/llvm-project/build/bin/
CLANG_PATH=./build/bin/

$CLANG_PATH/clang-8 -O0 -Xclang -disable-O0-optnone -emit-llvm -c $ROOT_PATH/src/xVMPInterpreter/xVMPInterpreter.c -o /tmp/xVMPInterpreter.bc
$CLANG_PATH/llvm-dis /tmp/xVMPInterpreter.bc -o /tmp/xVMPInterpreter.ll

python2 $ROOT_PATH/scripts/interpreter-ir2str.py


