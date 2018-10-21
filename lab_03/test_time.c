#include "sort.h"

int main(int argc, const char* argv[])
{
    if(argc != 4)
        return 0;
    size_t r_a;
    size_t c_a;
    size_t c_b;

    sscanf(argv[1], "%ld", &r_a);
    sscanf(argv[2], "%ld", &c_a);
    sscanf(argv[3], "%ld", &c_b);

    srand(time(NULL));
    
    clock_t start_t,   end_t;
           
    
    start_t = clock();
    // paste algorithm here
    end_t = clock();


    printf("%f\n", 1000*(double)(end_t-start_t) / CLOCKS_PER_SEC); //time in mi s

    return 1;
}

