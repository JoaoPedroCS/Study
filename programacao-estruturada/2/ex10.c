#include <stdio.h>

int get_int(char* prompt);
float fahrenheit_C(float n1);

int main(void)
{
    int n = get_int("");
    int r = somar_inteiros(n, m);
    printf("%i\n%i\n%i\n", n, m, r);
}

int get_int(char* prompt)
{
    int n;
    printf("%s", prompt);
    while (scanf("%d", &n) != 1)
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