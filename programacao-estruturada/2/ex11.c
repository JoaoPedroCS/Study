#include <stdio.h>

float get_float(char* prompt);
float fahrenheit_C(float n1);

int main(void)
{
    float n = get_float("");
    float r = fahrenheit_C(n);
    printf("%f\n", r);
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

float fahrenheit_C(float n1)
{
    return (n1 - 32) * 5 / 9;
}