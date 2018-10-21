echo starting...
DIR='tests/test_results'

rm ${DIR}
for i in {1000..10000..1000}; do
    ./test_time.out ${i} >> ${DIR}
    echo -n '|'
    echo
    #echo -e " --- A = ${i} x ${i} and B = ${i} x ${i}  ---" >> tests/test_even
    echo  -e " > ${i} thousand passed\n"

done

        echo DONE!

