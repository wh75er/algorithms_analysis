#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define A_ROWS 4
#define A_COLS 4

#define B_COLS 2


void winograd(  int** a, int r_a, int c_a , 
                int** b, int r_b, int c_b, 
                int** c, int r_c, int c_c);

int** allocateM(size_t n, size_t m);
int randM(int** a, size_t r, size_t c);
void printM( int** a, size_t len1, size_t len2 );
void freeM(int** a, size_t r);


int main()
{
    srand(time(NULL));
    int** a = allocateM(A_ROWS, A_COLS);
    randM(a, A_ROWS, A_COLS);

    int** b = allocateM(A_ROWS, B_COLS);
    randM(b, A_ROWS, B_COLS);

    int** c = allocateM(A_ROWS, B_COLS);

    if(a && b && c)
        winograd(   a, A_ROWS, A_COLS,
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

void winograd(  int** a, int r_a, int c_a , 
                int** b, int r_b, int c_b, 
                int** c, int r_c, int c_c)
{
    int d = c_a / 2;

    int* rows = (int*)malloc(sizeof(int) * r_a);
    for(int i = 0; i < r_a; i++) {
        rows[i] = 0;
        rows[i] += a[i][0] * a[i][1];
        for(int j = 1; j < d; j++)
            rows[i] += a[i][2*j] * a[i][2*j+1];
    }

    int* columns = (int*)malloc(sizeof(int) * c_b);
    for(int i = 0; i < c_b; i++) {
        columns[i] = 0;
        columns[i] += b[0][i]*b[1][i];
        for(int j = 1; j < d; j++)
            columns[i] += b[2*j][i] * b[2*j+1][i];
    }

    for(int i = 0; i < r_a; i++)
        for(int j = 0; j < c_b; j++) {
            c[i][j] = -rows[i] - columns[j];
            for(int k = 0; k < d; k++)
                c[i][j] += (a[i][2*k] + b[2*k+1][j]) * 
                            (a[i][2*k+1] + b[2*k][j]);
        }

    if(c_b%2)
        for(int i = 0; i < r_a; i++)
            for(int j = 0; j < c_b; j++)
                c[i][j] += a[i][c_a-1] * b[c_a-1][j];

    free(rows);
    free(columns);
}

int** allocateM(size_t r, size_t c)
{
    int** matrix = (int**)malloc(sizeof(int*) * r);
    if(matrix)
    //    for(int i = 0; i < r; i++)
    //        matrix[i] = (int*)malloc(sizeof(int) * c);
        matrix[0] = (int*)malloc(sizeof(int) * c * r);
    else
        return NULL;

    for(int i = 0; i < r; i++)
        matrix[i] = (*matrix + c * i);
    
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            matrix[i][j] = 0;

    return matrix;
}

int randM(int** a, size_t r, size_t c)
{
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            a[i][j] = rand() % 50;
}

void printM( int** a, size_t len1, size_t len2 )
{
    for(int i = 0; i < len1; i++) {
        printf("\n");
        for(int j = 0; j < len2; j++)
            printf("%d ", a[i][j]);
    }
}

void freeM(int** a, size_t r)
{
    free(a[0]);
    //for(int i = 0; i < r; i++)
    //    free(a[i]);
    free(a);
}

