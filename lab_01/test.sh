#!/bin/sh
s1="ffggsadlfkhwoqpoiwerhfvnaskjldfhidofgqiuowehfakjdsfhowqiegrfqdsfkasjdbvhfasjdkfhqwuifghasdqwqerfasd"
inc1=$s1
s2="hhbnfdjgkjpojnkkkjmpgnmogjinmjogjhgofghpmnfjghomjfoghjmogkhnmjpnogfmionjmbinjmbiohfgjmonpbonijmfzzq"
inc2=$s2
echo starting...

rm tests/test_output
for i in {0..9}; do
    for j in {0..99}; do
        ./main $s1 $s2 >> tests/test_output
        echo -n '|'
    done
    s1=$s1$inc1
    s2=$s2$inc2
    echo
    echo -e "--- $((i+1))00 passed ---" >> tests/test_output
    echo  -e " > $i decade passed\n"
done

echo DONE!
