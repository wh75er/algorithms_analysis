#include "winograd.h"

int main()
{
    srand(time(NULL));
    int** a = allocateM(A_ROWS, A_COLS);
    randM(a, A_ROWS, A_COLS);

    int** b = allocateM(A_ROWS, B_COLS);
    randM(b, A_ROWS, B_COLS);

    int** c = allocateM(A_ROWS, B_COLS);

    if(a && b && c)
        winograd_enhanced(  a, A_ROWS, A_COLS,
                            b, A_ROWS, B_COLS,
                            c, A_ROWS, B_COLS);

    printM(a, A_ROWS, A_COLS);
    printf("\n");
    printM(b, A_ROWS, B_COLS);
    printf("\n");
    printM(c, A_ROWS, B_COLS);

    freeM(a, A_ROWS);
    freeM(b, A_ROWS);
    freeM(c, A_ROWS);

    return 1;
}

