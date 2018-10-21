#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include <stdlib.h>
#include <time.h>
#include <stdio.h>


void bubble(int* a, size_t size);
void mergeSort(int* a, size_t n);
void insert(int* a, size_t size);

int* allocateA(size_t size);
void swap(int* ap, int* bp);
void randA(int* a, size_t size);
void printA(int* a, size_t size);

void copyA(int* src, int* dest, size_t size);
void fillBestCase(int* dest, size_t size);
void fillWorstCase(int* dest, size_t size);

#endif
