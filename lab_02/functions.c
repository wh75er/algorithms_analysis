#include "functions.h"

void winograd(  int** a, int r_a, int c_a , 
                int** b, int r_b, int c_b, 
                int** c, int r_c, int c_c,
                int* rows, int* columns)
{
    int d = c_a / 2;

    for(int i = 0; i < r_a; i++) {
        rows[i] = rows[i] + a[i][0] * a[i][1];
        for(int j = 1; j < d; j++)
            rows[i] = rows[i] + a[i][2*j] * a[i][2*j+1];
    }

    for(int i = 0; i < c_b; i++) {
        columns[i] = columns[i] + b[0][i]*b[1][i];
        for(int j = 1; j < d; j++)
            columns[i] = columns[i] + b[2*j][i] * b[2*j+1][i];
    }

    for(int i = 0; i < r_a; i++)
        for(int j = 0; j < c_b; j++) {
            c[i][j] = -rows[i] - columns[j];
            for(int k = 0; k < d; k++)
                c[i][j] = c[i][j] + (a[i][2*k] + b[2*k+1][j]) * 
                            (a[i][2*k+1] + b[2*k][j]);
        }

    if(c_a%2)
        for(int i = 0; i < r_a; i++)
            for(int j = 0; j < c_b; j++)
                c[i][j] = c[i][j] + a[i][c_a-1] * b[c_a-1][j];
}

void winograd_enhanced( int** a, int r_a, int c_a , 
                        int** b, int r_b, int c_b, 
                        int** c, int r_c, int c_c,
                        int* rows, int* columns)
{
    int d = c_a - 1;
    for(int i = 0; i < r_a; i++) {
        for(int j = 0; j < d; j+=2)
            rows[i] += a[i][j] * a[i][j+1];
    }

    for(int i = 0; i < c_b; i++) {
        for(int j = 0; j < d; j+=2)
            columns[i] += b[j][i] * b[j+1][i];
    }

    for(int i = 0; i < r_a; i++)
        for(int j = 0; j < c_b; j++) {
            c[i][j] = -rows[i] - columns[j];
            for(int k = 0; k < d; k+=2)
                c[i][j] += (a[i][k] + b[k+1][j]) * 
                            (a[i][k+1] + b[k][j]);
        }

    if(c_a%2)
        for(int i = 0; i < r_a; i++)
            for(int j = 0; j < c_b; j++)
                c[i][j] += a[i][d] * b[d][j];
}


int** allocateM(size_t r, size_t c)
{
    int** matrix = (int**)malloc(sizeof(int*) * r);
    if(matrix)
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

void randM(int** a, size_t r, size_t c)
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


