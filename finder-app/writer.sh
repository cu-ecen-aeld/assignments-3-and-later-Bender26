#!/bin/sh

if [ $# -ne 2 ]
then
    echo "Not enough input args!"
    exit 1
fi

WRITEFILE=$1
WRITESTR=$2

if  [ -d "$WRITEFILE" ]
then
    rm -rf $WRITEFILE
fi
dir=$(dirname $WRITEFILE)
mkdir -p $dir

echo $WRITESTR > $WRITEFILE