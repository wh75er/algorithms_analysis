#!/bin/bash
echo starting...
DIR='results_for_8'

rm ${DIR}
for i in 8; do
    for j in {101..1001..100}; do
        target/debug/lab_05 ${i} ${j} >> ${DIR}
        echo ${j}x${j} ${i} passed
    done

done

echo DONE!

