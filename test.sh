#!/bin/sh

echo "Hello World"

FIRST_ARGUMENT="$1"
echo "Hello World $FIRST_ARGUMENT"

mkdir "/tmp/My Folder"

FILENAME="/tmp/My Folder"
#ls "$FILENAME"

#ls $FILENAME

#echo "$PATH"

#printenv

DEFINED=printenv | grep -c '^PATH='

echo "$DEFINED"

MYVAR 

echo "$MYVAR"

unset MYVAR

echo "MYVAR is \"$MYVAR\""
