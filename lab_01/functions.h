#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#define MAX_STRING_SIZE 1001

int recursiveDistance( char* s1, int i, char *s2, int j);
int levensteinDistance( char* s1, char *s2, 
                        int (*matrix)[MAX_STRING_SIZE][MAX_STRING_SIZE] );
int damerauDistance( char* s1, char *s2, 
                        int (*matrix)[MAX_STRING_SIZE][MAX_STRING_SIZE] );


int min(int count, ...);
int match(char c, char d);
void matrixInit( int (*matrix)[MAX_STRING_SIZE][MAX_STRING_SIZE], 
                                                    int a, int b );

#endif
