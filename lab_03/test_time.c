#include "sort.h"

int main(int argc, const char* argv[])
{
    if(argc != 2)
        return 0;
    size_t size;

    sscanf(argv[1], "%ld", &size);
    srand(time(NULL));

    int* a = allocateA(size);
    int* c = allocateA(size);
    randA(a, size);
    
    clock_t start_bubble_mid,   end_bubble_mid,
            start_merge_mid,    end_merge_mid,
            start_insert_mid,   end_insert_mid,
            
            start_bubble_best,  end_bubble_best,
            start_merge_best,   end_merge_best,
            start_insert_best,  end_insert_best,
            
            start_bubble_worst, end_bubble_worst,
            start_merge_worst,  end_merge_worst,
            start_insert_worst, end_insert_worst;
           
//          Middle time tests --------------------------
//

    copyA(a, c, size);

    start_bubble_mid = clock();
    bubble(c, size);
    end_bubble_mid = clock();

    copyA(a, c, size);

    start_merge_mid = clock();
    mergeSort(c, size);
    end_merge_mid = clock();

    copyA(a, c, size);

    start_insert_mid = clock();
    insert(c, size);
    end_insert_mid = clock();


//          Best time tests --------------------------
//

    fillBestCase(c, size);
    
    start_bubble_best = clock();
    bubble(c, size);
    end_bubble_best = clock();

    fillBestCase(c, size);

    start_merge_best = clock();
    mergeSort(c, size);
    end_merge_best = clock();

    fillBestCase(c, size);

    start_insert_best = clock();
    insert(c, size);
    end_insert_best = clock();


//          Worst time tests --------------------------
//

    fillWorstCase(c, size);
    
    start_bubble_worst = clock();
    bubble(c, size);
    end_bubble_worst = clock();

    fillWorstCase(c, size);

    start_merge_worst = clock();
    mergeSort(c, size);
    end_merge_worst = clock();

    fillWorstCase(c, size);

    start_insert_worst = clock();
    insert(c, size);
    end_insert_worst = clock();


    printf("%f %f %f\n%f %f %f\n%f %f %f\n\n", 
                1000*(double)(end_bubble_best-start_bubble_best) / CLOCKS_PER_SEC,
                1000*(double)(end_insert_best-start_insert_best) / CLOCKS_PER_SEC,
                1000*(double)(end_merge_best-start_merge_best) / CLOCKS_PER_SEC,

                1000*(double)(end_bubble_mid-start_bubble_mid) / CLOCKS_PER_SEC,
                1000*(double)(end_insert_mid-start_insert_mid) / CLOCKS_PER_SEC,
                1000*(double)(end_merge_mid-start_merge_mid) / CLOCKS_PER_SEC,
                
                1000*(double)(end_bubble_worst-start_bubble_worst) / CLOCKS_PER_SEC,
                1000*(double)(end_insert_worst-start_insert_worst) / CLOCKS_PER_SEC,
                1000*(double)(end_merge_worst-start_merge_worst) / CLOCKS_PER_SEC); //time in mi s

    free(a);
    free(c);
    return 1;
}

