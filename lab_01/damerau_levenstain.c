#include <stdio.h> 
#include <string.h>
#include <stdarg.h>

#define MAX_STRING_SIZE 1001

int inputData( char* s1, char* s2, int* err );
int levensteinDistance( char* s1, char *s2, 
                        int (*matrix)[MAX_STRING_SIZE][MAX_STRING_SIZE] );

void printMatrix( int m[MAX_STRING_SIZE][MAX_STRING_SIZE],
                                                int len1, int len2 );
void matrixInit( int (*matrix)[MAX_STRING_SIZE][MAX_STRING_SIZE], 
                                                    int a, int b );
int min(int count, ...);




int main() {
        int err = 0;

        char s1[MAX_STRING_SIZE-1] = "";
        char s2[MAX_STRING_SIZE-1] = ""; 
        inputData(s1, s2, &err);

        int matrix[MAX_STRING_SIZE][MAX_STRING_SIZE];
        levensteinDistance(s1, s2, &matrix);

        printMatrix(matrix, strlen(s1), strlen(s2));
}



int levensteinDistance( char* s1, char* s2, 
                        int (*matrix)[MAX_STRING_SIZE][MAX_STRING_SIZE] )
{
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);

    matrixInit(matrix, len1, len2);

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


int inputData( char* s1, char* s2, int* err )
{
    printf(" Input s1: ");
    scanf("%s", s1);

    printf(" Input s2: ");
    scanf("%s", s2);

    return 1;
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

void printMatrix( int m[MAX_STRING_SIZE][MAX_STRING_SIZE],
                    int len1, int len2 )
{
    for(int i = 0; i <= len1; i++) {
        printf("\n");
        for(int j = 0; j <= len2; j++)
            printf("%d ", m[i][j]);
    }
}

void matrixInit( int (*matrix)[MAX_STRING_SIZE][MAX_STRING_SIZE], 
                int a, int b )
{
    for(; a >= 0; a--)
        (*matrix)[a][0] = a;
    for(; b > 0; b--)
        (*matrix)[0][b] = b;
}
