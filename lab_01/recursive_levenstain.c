#include <stdio.h> 
#include <string.h>
#include <stdarg.h>

#define MAX_STRING_SIZE 1000

int levensteinDistance( char* s1, int i, char *s2, int j);

int inputData( char* s1, char* s2, int* err );
int min(int count, ...);
int match(char c, char d);



int main() {
        int err = 0;

        char s1[MAX_STRING_SIZE] = "";
        char s2[MAX_STRING_SIZE] = ""; 
        inputData(s1, s2, &err);

        int i = strlen(s1);
        int j = strlen(s2);
        int len = levensteinDistance(s1, i, s2, j);

        printf("Length is : %d\n", len);
}



int levensteinDistance( char* s1, int i, char* s2, int j )
{
    if(i == 0) return j;
    if(j == 0) return i;

    return min( 3,levensteinDistance(s1, i-1, s2, j) + 1,
                  levensteinDistance(s1, i, s2, j-1) + 1,
                  levensteinDistance(s1, i-1, s2, j-1) + match(s1[i], s2[j]) );
}


int match(char c, char d)
{
    if(c == d) return 0;
    else return 1;
}

int min(int count, ...) {
    va_list ap;

    va_start(ap, count);
    int min = va_arg(ap, int);
    for(int i = 0; i < count-1; i++) {
        int x = va_arg(ap, int);
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

