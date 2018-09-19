#include <stdio.h> 
#include <string.h>
#include <stdarg.h>

#define MAX_STRING_SIZE 1000

size_t levensteinDistance( char* s1, size_t sl1, char *s2, size_t sl2);

int inputData( char* s1, char* s2, int* err );
size_t min(int count, ...);



int main() {
        int err = 0;

        char s1[MAX_STRING_SIZE] = "";
        char s2[MAX_STRING_SIZE] = ""; 
        inputData(s1, s2, &err);

        size_t sl1 = strlen(s1);
        size_t sl2 = strlen(s2);
        size_t len = levensteinDistance(s1, sl1, s2, sl2);

        printf("Length is : %d\n", len);
}



size_t levensteinDistance( char* s1, size_t sl1, char* s2, size_t sl2 )
{
    if(!sl1) 
        return sl2;
    if(!sl2)
        return sl1;
    size_t cost = 1;
    if(s1[sl1-1] == s2[sl2-1])
        cost = 0;

    size_t a = levensteinDistance(s1, sl1-1, s2, sl2);
    size_t b = levensteinDistance(s1, sl1, s2, sl2-1);
    size_t c = levensteinDistance(s1, sl1-1, s2, sl2-1) + cost;

    size_t result = min(a, b, c);

    return result;
}


size_t min(int count, ...) {
    va_list ap;

    va_start(ap, count);
    int min = va_arg(ap, size_t);
    for(int i = 0; i < count-1; i++) {
        int x = va_arg(ap, size_t);
        if(x < min)
            min = x;
    }
    va_end(ap);
    
    return min; 
}

int inputData( char* s1, char* s2, int* err )
{
    printf(" Input s1: ");
    scanf("%s", s1);

    printf(" Input s2: ");
    scanf("%s", s2);

    return 1;
}

