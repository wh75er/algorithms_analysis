echo starting...

rm tests/test_output
for i in {2..1000..100}; do
    for j in {2..1000..100}; do
        for k in {2..1000..100}; do
            ./test_time.out ${i} ${j} ${k} >> tests/test_output
            echo -n '|'
        done
    done
    echo
    echo -e " --- A = ${i} x ${j} and B = ${j} x ${k}  ---" >> tests/test_output
    echo  -e " > A = ${i} x ${j} | B = ${j} x ${k} passed\n"

done

        echo DONE!

