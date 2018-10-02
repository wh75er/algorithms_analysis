#include <stdio.h> 
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>

#define MAX_STRING_SIZE 1000


typedef struct tree_t
{
    char* s1;
    char* s2;
    struct tree_t* left;
    struct tree_t* mid;
    struct tree_t* right;
} tree_t;

int levensteinDistance( char* s1, int i, char *s2, int j, int* counter, tree_t* head);

int inputData( char* s1, char* s2, int* err );
int min(int count, ...);
int match(char c, char d);


char* mkstr()
{
    char* s = (char*)malloc(MAX_STRING_SIZE);
    return s;
}

tree_t* mknode(tree_t* head, char* s1, char* s2, int i, int j)
{
    tree_t* node = (tree_t *)malloc(sizeof(tree_t));
    node->s1 = mkstr();
    node->s2 = mkstr();
    strncpy(node->s1, s1, i);
    strncpy(node->s2, s2, j);
    node->left = NULL;
    node->mid = NULL;
    node->right = NULL;
    if(head) {
        if(!(head->right))
            head->right = node;
        else
            if (!(head->left))
                head->left = node;
            else
                if (!(head->mid))
                    head->mid = node;
    }
    return node;
}

void freeTree(tree_t* node)
{
    if (!node)
        return;
    
    freeTree(node->left);
    freeTree(node->right);
    freeTree(node->mid);

    free(node->s1);
    free(node->s2);
    free(node);
}

char depth[ 2056 ];
int di;

void push(char c)
{
    depth[ di++ ] = ' ';
    depth[ di++ ] = c;
    depth[ di++ ] = ' ';
    depth[ di++ ] = ' ';
    depth[ di ] = 0;
}

void pop()
{
    depth[ di -= 4 ] = 0;
}

void printTree( tree_t* node ) 
{
    printf("(%s, %s)\n", node->s1, node->s2);

    if( node->right )
    {
        printf("%s `--", depth);
        push('|');
        printTree(node->right);
        pop();

        printf("%s `--", depth);
        push('|');
        printTree(node->left);
        pop();

        printf("%s `--", depth);
        push(' ');
        printTree(node->mid);
        pop();

    }
}

int main() {
        int err = 0;

        //char s1[MAX_STRING_SIZE] = "";
        //char s2[MAX_STRING_SIZE] = ""; 
        char* s1 = mkstr();
        char* s2 = mkstr();
        strcpy(s1, "");
        strcpy(s2, "");
        inputData(s1, s2, &err);

        tree_t* head = mknode(NULL, s1, s2, strlen(s1), strlen(s2));

        int i = strlen(s1);
        int j = strlen(s2);
        int counter = 0;
        int len = levensteinDistance(s1, i, s2, j, &counter, head);

        printf("Length is : %d\nfunction called %d times\n", len, counter);

        printTree(head);

        free(s1);
        free(s2);
        freeTree(head);
}



int levensteinDistance( char* s1, int i, char* s2, int j, int* counter, tree_t* head)
{
    (*counter)++;
    if(i == 0) return j;
    if(j == 0) return i;

    return min( 3,levensteinDistance(s1, i-1, s2, j, counter, mknode(head, s1, s2, i-1, j)) + 1,
                  levensteinDistance(s1, i, s2, j-1, counter, mknode(head, s1, s2, i, j-1)) + 1,
                  levensteinDistance(s1, i-1, s2, j-1, counter, mknode(head, s1, s2, i-1, j-1)) + match(s1[i], s2[j]) );
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

