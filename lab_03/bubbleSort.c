#include "sort.h"

int main()
{
    srand(time(NULL));
    printf(">bubble sort\n");

    int* a = allocateA(ARRAY_SIZE);

    randA(a, ARRAY_SIZE);
    printf("\n");
    printA(a, ARRAY_SIZE);

    
    bubble(a, ARRAY_SIZE);


    printf("\n");
    printA(a, ARRAY_SIZE);

    free(a);
    return 1;
}

