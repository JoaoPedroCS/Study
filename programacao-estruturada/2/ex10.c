#include <stdio.h>

int get_int(char* prompt);
int somar_inteiros(int n1, int n2);

int main(void)
{
    int n = get_int("");
    int m = get_int("");
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

int somar_inteiros(int n1, int n2)
{
    return n1 + n2;
}