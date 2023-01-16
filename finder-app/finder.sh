#!/bin/sh

if [ $# -ne 2 ]
then
    echo "Not enough input args!"
    exit 1
fi
FILESDIR=$1
SEARCHSTR=$2
if [ -d "$FILESDIR" ]
then
    echo "Directory exists!"
else
    echo "Directory not found"
    exit 1
fi

FILES=$( ls $FILESDIR | wc -l )

MATCH_STR=$( grep -r $SEARCHSTR $FILESDIR | wc -l )

echo The number of files are $FILES and the number of matching lines are $MATCH_STR