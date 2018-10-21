#include "sort.h"

int main(int argc, const char* argv[])
{
    if(argc != 4)
        return 0;
    size_t r_a;
    size_t c_a;
    size_t c_b;

    sscanf(argv[1], "%ld", &r_a);
    sscanf(argv[2], "%ld", &c_a);
    sscanf(argv[3], "%ld", &c_b);

    srand(time(NULL));
    int** a = allocateM(r_a, c_a);
    randM(a, r_a, c_a);

    int** b = allocateM(c_a, c_b);
    randM(b, c_a, c_b);

    int** c = allocateM(r_a, c_b);

    int* rows = (int*)malloc(sizeof(int) * r_a);
    for(int i = 0; i < r_a; i++)
        rows[i] = 0;
    int* columns = (int*)malloc(sizeof(int) * c_b);
    for(int i = 0; i < c_b; i++)
        columns[i] = 0;

    //printf("\n");
    //printM(a, r_a, c_a);
    //printf("\n");
    //printM(b, c_b, c_b);
    //printf("\n");

    clock_t start_enh, end_enh,
            start_t,   end_t,
            start_classic, end_classic;

    if(a && b && c) {
        start_enh = clock();
        //winograd_enhanced(  a, r_a, c_a,
        //                    b, c_a, c_b,
        //                    c, r_a, c_b,
        //                    rows, columns);
        end_enh = clock();
    }

    //printM(c, r_a, c_b);
    //printf("\n");

    for(int i = 0; i < r_a; i++)
        rows[i] = 0;
    for(int i = 0; i < c_b; i++)
        columns[i] = 0;
    for(int i = 0; i < r_a; i++)
        for(int j = 0; j < c_b; j++)
            c[i][j] = 0;


    if(a && b && c) {
        start_t = clock();
        //winograd(   a, r_a, c_a,
        //            b, c_a, c_b,
        //            c, r_a, c_b,
        //            rows, columns);
        end_t = clock();
    }

    for(int i = 0; i < r_a; i++)
        for(int j = 0; j < c_b; j++)
            c[i][j] = 0;

    if(a && b && c) {
        start_classic = clock();
        classic (   a, r_a, c_a,
                    b, c_a, c_b,
                    c, r_a, c_b);
        end_classic = clock();
    }

    //printM(c, r_a, c_b);
    //printf("\n");

    printf("%f %f %f\n", 1000*(double)(end_t-start_t) / CLOCKS_PER_SEC,
                      1000*(double)(end_enh-start_enh) / CLOCKS_PER_SEC,
                      1000*(double)(end_classic-start_classic) / CLOCKS_PER_SEC);



    freeM(a, r_a);
    freeM(b, c_a);
    freeM(c, r_a);
    free(columns);
    free(rows);

    return 1;
}

