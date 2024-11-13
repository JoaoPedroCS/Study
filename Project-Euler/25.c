#include <stdio.h>

void fibbo(char* x, char* y, int* index);

int main(void) 
{
    char* X = (char*)malloc(1000 * sizeof(char));
    if (X == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    char* Y = (char*)malloc(1000 * sizeof(char));
    if (Y == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    int index = 2;
}

void fibbo(char* x, char* y, int* index)
{
    if (*x >= index)
    {
        return;
    }
    char* tmp;
    tmp = *x;
    *x += *y;
    *y = tmp;
    *index += 1;
    printf("%s, ", x);
    /*fibbo(x, y, index);*/
}

void sum_of_strings(char* x, char* y)
{

}