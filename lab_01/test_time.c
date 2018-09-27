#include "functions.h"
#include <time.h>

int main(int argc, const char* argv[])
{
    if(argc != 3)
        return 0;
    char s1[MAX_STRING_SIZE-1] = "";
    char s2[MAX_STRING_SIZE-1] = ""; 
    memcpy(s1, argv[1], strlen(argv[1]));
    memcpy(s2, argv[2], strlen(argv[2]));

    int matrix[MAX_STRING_SIZE][MAX_STRING_SIZE];

    clock_t start_lt, end_lt,
            start_dt, end_dt,
            start_rt, end_rt;

    matrixInit(&matrix, strlen(s1), strlen(s2));

    start_lt = clock();
    levensteinDistance(s1, s2, &matrix);
    end_lt = clock();

    matrixInit(&matrix, strlen(s1), strlen(s2));

    start_dt = clock();
    damerauDistance(s1, s2, &matrix);
    end_dt = clock();

    int i = strlen(s1);
    int j = strlen(s2);
    start_rt = clock();
    if(i < 16 && j < 16)
        recursiveDistance(s1, i, s2, j);
    end_rt = clock();

    printf("%f %f %f\n", (double)(end_lt-start_lt) / CLOCKS_PER_SEC,
                         (double)(end_dt-start_dt) / CLOCKS_PER_SEC,
                         (double)(end_rt-start_rt) / CLOCKS_PER_SEC);

    return 1;
}
