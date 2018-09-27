#!/bin/sh
s10="f"
s11="fm"
s12="fmt"
s13="fmtz"
s14="fmtzq"
s15="fmtzqp"
s16="fmtzqpy"
s17="fmtzqpys"
s18="fmtzqpysi"
s19="fmtzqpysio"

s20="g"
s21="gc"
s22="gci"
s23="gcil"
s24="gcilw"
s25="gcilwb"
s26="gcilwbp"
s27="gcilwbpt"
s28="gcilwbptk"
s29="gcilwbptg"

echo starting...

rm tests/test_output_recursive
for i in {0..8}; do
    eval s1='$'"s1${i}"
    eval s2='$'"s2${i}"
    for j in {0..99}; do
        ./main $s1 $s2 >> tests/test_output_recursive
        echo -e -n  '|'
    done
    s1=$s1$inc1
    s2=$s2$inc2
    echo -e "--- $((i+1))00 passed ---" >> tests/test_output_recursive
    echo
    echo  -e " > $i symbol passed\n"
done

echo DONE!
