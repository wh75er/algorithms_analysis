#!/bin/bash
echo starting...
DIR='results_for_8'

rm ${DIR}
for j in 8; do
    for i in {101..1001..100}; do
        target/debug/lab_05 ${j} ${i} >> ${DIR}
        echo ${j}x${j} ${i} passed
    done

done

echo DONE!

