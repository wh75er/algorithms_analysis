#include "winograd.h"

int main()
{
    srand(time(NULL));
    int** a = allocateM(A_ROWS, A_COLS);
    randM(a, A_ROWS, A_COLS);

    int** b = allocateM(A_COLS, B_COLS);
    randM(b, A_COLS, B_COLS);

    int** c = allocateM(A_ROWS, B_COLS);

    int* rows = (int*)malloc(sizeof(int) * A_ROWS);
    for(int i = 0; i < A_ROWS; i++)
        rows[i] = 0;

    int* columns = (int*)malloc(sizeof(int) * B_COLS);
    for(int i = 0; i < B_COLS; i++)
        columns[i] = 0;


    if(a && b && c)
        winograd_enhanced(  a, A_ROWS, A_COLS,
                            b, A_COLS, B_COLS,
                            c, A_ROWS, B_COLS,
                            rows, columns);

    printM(a, A_ROWS, A_COLS);
    printf("\n");
    printM(b, A_COLS, B_COLS);
    printf("\n");
    printM(c, A_ROWS, B_COLS);

    freeM(a, A_ROWS);
    freeM(b, A_COLS);
    freeM(c, A_ROWS);
    free(columns);
    free(rows);

    return 1;
}

