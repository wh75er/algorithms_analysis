#include "sort.h"

int main(int argc, const char* argv[])
{
    if(argc != 2)
        return 0;
    size_t size;

    sscanf(argv[1], "%ld", &size);
    srand(time(NULL));
    
    clock_t start_t,   end_t;
           
    
    start_t = clock();
    // paste algorithm here
    end_t = clock();


    printf("%f\n", 1000*(double)(end_t-start_t) / CLOCKS_PER_SEC); //time in mi s

    return 1;
}

