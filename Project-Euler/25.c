#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fibbo(char* x, char* y, int* index);
void string_rev(char* x);

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
    strcpy(X, Y);
    string_rev(X);
    printf("X: %s\n", X);
}

void fibbo(char* x, char* y, int* index)
{
    /*
    if (*x != *y)
    {
        return;
    }
    char* tmp;
    tmp = *x;
    *x += *y;
    *y = tmp;
    *index += 1;
    printf("%s, ", x);
    fibbo(x, y, index);*/
}

void sum_of_strings(char* x, char* y)
{
    
}

void string_rev(char *x)
{
    int len = 0;
    while (x[len] != '\0') {
        len++;
    }

    for (int i = 0; i < len / 2; i++) {
        char temp = x[i];
        x[i] = x[len - i - 1];
        x[len - i - 1] = temp;
    }
}