#!/bin/sh

ulimit -c 10240000
ulimit -s 16384

mysvrpid=`lsof -dtxt | grep mysvr | awk '{print $2}'`

kill ${mysvrpid}

