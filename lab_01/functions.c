#include "functions.h"

int recursiveDistance( char* s1, int i, char* s2, int j )
{
    if(i == 0) return j;
    if(j == 0) return i;

    return min( 3,recursiveDistance(s1, i-1, s2, j) + 1,
                  recursiveDistance(s1, i, s2, j-1) + 1,
                  recursiveDistance(s1, i-1, s2, j-1) + match(s1[i], s2[j]) );
}

int levensteinDistance( char* s1, char* s2, 
                        int (*matrix)[MAX_STRING_SIZE][MAX_STRING_SIZE] )
{
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);

    int cost = 1; 
    for(int i = 1; i <= len1; i++)
        for(int j = 1; j <= len2; j++) {
            if(s1[i-1] == s2[j-1])
                cost = 0;
            else
                cost = 1;
            (*matrix)[i][j] = min( 3,
                        (*matrix)[i-1][j]+1, 
                        (*matrix)[i][j-1]+1,
                        (*matrix)[i-1][j-1]+cost );
        }
}



int damerauDistance( char* s1, char* s2, 
                        int (*matrix)[MAX_STRING_SIZE][MAX_STRING_SIZE] )
{
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);

    int cost = 1; 
    for(int i = 1; i <= len1; i++)
        for(int j = 1; j <= len2; j++) {
            int flag = 0;
            if(s1[i-1] == s2[j-1])
                cost = 0;
            else
                cost = 1;
            int l1= min( 3,
                        (*matrix)[i-1][j]+1, 
                        (*matrix)[i][j-1]+1,
                        (*matrix)[i-1][j-1]+cost );
            int l2 = l1;
            if(i>=2 && j>=2)
                if(s1[i-1] == s2[j-2] && s2[j-1] == s1[i-2])
                    l2 = (*matrix)[i-2][j-2]+1;
            (*matrix)[i][j] = min(2, l1, l2);
        }
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

void matrixInit( int (*matrix)[MAX_STRING_SIZE][MAX_STRING_SIZE], 
                int a, int b )
{
    for(; a >= 0; a--)
        (*matrix)[a][0] = a;
    for(; b > 0; b--)
        (*matrix)[0][b] = b;
}
