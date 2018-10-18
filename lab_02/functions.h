#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void winograd(  int** a, int r_a, int c_a , 
                int** b, int r_b, int c_b, 
                int** c, int r_c, int c_c);

void winograd_enhanced( int** a, int r_a, int c_a , 
                        int** b, int r_b, int c_b, 
                        int** c, int r_c, int c_c);

int** allocateM(size_t n, size_t m);
void randM(int** a, size_t r, size_t c);
void printM( int** a, size_t len1, size_t len2 );
void freeM(int** a, size_t r);

#endif
