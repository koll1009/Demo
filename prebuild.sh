#!/bin/bash
#autoconf && ./configure && make -j 12
make -j 12

if [ $? -eq 0 ]; then
    echo "jemalloc build success"
    exit 0
else 
    echo "jemalloc build failure"
    exit 1
fi
