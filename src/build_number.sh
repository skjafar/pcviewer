#!/bin/bash
number=`cat build_number.txt`
let number++
echo "$number" | tee build_number.txt #<-- output and save the number back to file
echo "#define BUILD_NUMBER ""$number" | tee ../MyProject/build_number.h