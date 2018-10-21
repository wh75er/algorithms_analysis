#include "functions.h"

void insert(int* a, size_t size)
{
    int j, tmp;
    
    for(int i = 1; i < size; i++) {
        tmp = a[i];
        for (j = i - 1; j >= 0 && a[j] > tmp; j--)
            a[j + 1] = a[j];
        a[j + 1] = tmp;
    }
}

// ---------------------------------------------------------------------------------------------

void merge(int* a, int* l, size_t leftCount, int* r, size_t rightCount)
{
	int i = 0, 
        j = 0, 
        k = 0;

	while(i<leftCount && j< rightCount) {
		if(l[i]  < r[j]) a[k++] = l[i++];
		else a[k++] = r[j++];
	}
	while(i < leftCount) a[k++] = l[i++];
	while(j < rightCount) a[k++] = r[j++];
}

void mergeSort(int* a, size_t n)
{
	int mid, i, *l, *r;
	if(n < 2) return;

	mid = n/2;

	l = (int*)malloc(mid*sizeof(int)); 
	r = (int*)malloc((n - mid)*sizeof(int)); 
	
	for(i = 0; i<mid; i++) l[i] = a[i]; // creating left subarray
	for(i = mid; i<n; i++) r[i-mid] = a[i]; // creating right subarray

	mergeSort(l, mid);
	mergeSort(r, n-mid);
	merge(a, l, mid, r, n-mid);
        free(l);
        free(r);
}

// ---------------------------------------------------------------------------------------------

void bubble(int* a, size_t size)
{
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size-j-i; j++)
            if(a[j] > a[j+1])
                swap(&a[j], &a[j+1]);
}

// ---------------------------------------------------------------------------------------------

void swap(int* ap, int* bp)
{
    int tmp = *ap;
    *ap = *bp;
    *bp = tmp;
}

int* allocateA(size_t size)
{
    int* array = (int*)malloc(sizeof(int) * size);
    
    return array;
}

void randA(int* a, size_t size)
{
    for(int i = 0; i < size; i++)
        a[i] = rand() % 50;
}

void printA(int* a, size_t size) 
{ 
    for(int i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
} 

