#!/bin/bash
#autoconf && ./configure --enable-debug && make -j 12

if [ $? -eq 0 ]; then
    echo "jemalloc build success"
    exit 0
else 
    echo "jemalloc build failure"
    exit 1
fi
