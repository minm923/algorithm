#!/bin/sh

ulimit -c 10240000
ulimit -s 16384

chmod +x mysvr 
./mysvr &

