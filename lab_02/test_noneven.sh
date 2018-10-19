echo starting...
DIR='tests/test_noneven'

rm ${DIR}
for i in {101..1001..100}; do
    ./test_time.out ${i} ${i} ${i} >> ${DIR}
    echo -n '|'
    echo
    #echo -e " --- A = ${i} x ${i} and B = ${i} x ${i}  ---" >> tests/test_noneven
    echo  -e " > A = ${i} x ${i} | B = ${i} x ${i} passed\n"

done

        echo DONE!

