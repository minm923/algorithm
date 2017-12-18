#!/bin/bash

CUR_PWD=`pwd`

# @TODO 加入要转化的目录，并以空格隔开 
DIRS=("./")

for DIR in $DIRS;
do
    ABS_PATH=${CUR_PWD}/$DIR;
    # echo $ABS_PATH;
    cd $ABS_PATH;
    protoc --cpp_out=../cpp_src --proto_path=. *.proto
done

