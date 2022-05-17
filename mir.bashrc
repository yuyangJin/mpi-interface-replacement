#!/bin/bash
PREFIX=/mnt/ssd/jinyuyang/build
PROGLIST="rose"

for prog in $PROGLIST
do
        export PATH=${PREFIX}/${prog}/bin64:${PREFIX}/${prog}/bin:$PATH
        export INCLUDE=${PREFIX}/${prog}/include64:${PREFIX}/${prog}/include:$INCLUDE
        export C_INCLUDE_PATH=${PREFIX}/${prog}/include64:${PREFIX}/${prog}/include:$C_INCLUDE_PATH
        export CPLUS_INCLUDE_PATH=${PREFIX}/${prog}/include64:${PREFIX}/${prog}/include:$CPLUS_INCLUDE_PATH
        export LIBRARY_PATH=${PREFIX}/${prog}/lib64:${PREFIX}/${prog}/lib:$LIBRARY_PATH
        export LD_LIBRARY_PATH=${PREFIX}/${prog}/lib64:${PREFIX}/${prog}/lib:$LD_LIBRARY_PATH:/usr/lib:/usr/lib64
done