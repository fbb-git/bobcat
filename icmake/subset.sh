#!/bin/bash

# This script is called by 'build' (or must be called from build's directory

rm -f CLASSES.$$

for word in $* 
do
    required=`grep "^$word" dependencies/required.classes`

    for class in $required
    do
        echo $class >> CLASSES.$$
    done
done

sort -u CLASSES.$$
rm -f CLASSES.$$
