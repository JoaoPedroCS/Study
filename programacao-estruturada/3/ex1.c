#include <stdio.h>

float get_float(char* prompt);

int main(void)
{
    printf("Hello, World!\n");
}

float get_float(char* prompt)
{
    float n;
    printf("%s", prompt);
    while (scanf("%f", &n) != 1)
    {
        printf("\n");
        while (getchar() != '\n')
            continue;
    }
    return n;
}







