#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fibbo(char* x, char* y, int* index);
void sum_of_strings(char* x, char* y);
void string_rev(char* x);
int strLen(char* x);

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
    strcpy(X, "1");
    strcpy(Y, "1");
    fibbo(X, Y, &index);
    printf("\nindex: %i\n", index);
}

void fibbo(char* x, char* y, int* index)
{
    if (strLen(x) >= 3)
    {
        return;
    }
    sum_of_strings(x, y);
    *index += 1;
    fibbo(x, y, index);
}

void sum_of_strings(char* x, char* y)
{
    char tmp[1000];
    strcpy(tmp, x);
    string_rev(x);
    string_rev(y);
    int i = 0;
    int sobe = 0;
    while (x[i] != '\0')
    {
        if (y[i] != '\0')
        {
            if ((x[i] + y[i] - '0' + sobe) <= '9')
            {
                x[i] = x[i] + y[i] - '0' + sobe;
                sobe = 0;
            }
            else 
            {
                x[i] = x[i] + y[i] - '0' - 10 + sobe;
                sobe = 1;
            }
        }
        else
        {
            if ((x[i] + sobe) <= '9')
            {
                x[i] += sobe;
                sobe = 0;
            }
            else 
            {
                x[i] = 0;
                sobe = 1;
            }
        }
        i ++;
    }
    strcpy(y, tmp);
    string_rev(x);
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

int strLen(char* x)
{
    int i = 0;
    while (x[i] != '\0')
    {
        i++;
    }
    return i;
}