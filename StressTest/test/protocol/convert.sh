#!/bin/bash

CUR_PWD=`pwd`

cd $CUR_PWD
cd cpp_src
rm *.h
rm *.cc

cd $CUR_PWD
cd cs
chmod +x convert_cs.sh
./convert_cs.sh

