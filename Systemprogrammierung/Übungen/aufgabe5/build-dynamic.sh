#!/bin/sh


for s in notenspiegel.c liste.c fachnote.c ; do
    compile_command="gcc -g -W -Wall -ansi -pedantic -fPIC -c $s"
    echo $compile_command
    eval $compile_command
    if [ $? -ne 0 ] ; then
        echo build failed
        exit 1
    fi
done
dynamic_command="gcc -shared fachnote.o liste.o -o libaufgabe5.so"
echo $dynamic_command
eval $dynamic_command
if [ $? -ne 0 ] ; then
    echo build failed
    exit 1
fi

dy_command="gcc notenspiegel.o -L. -l aufgabe5 -o notenspiegel"
echo $dy_command
eval $dy_command
if [ $? -ne 0 ] ; then
    echo build failed
    exit 1
fi

echo build successful
