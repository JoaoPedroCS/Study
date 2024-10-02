#include <stdio.h>

int get_int(char* prompt);

int main(void)
{
    int x = get_int("");
    int y = get_int("");

    if (x > y)
    {
        printf("O %i eh o maior numero!\n", x);
    }
    else if (x == y)
    {
        printf("Numeros iguais!\n");
    }
    else
    {
        printf("O %i eh o maior numero!\n", y);
    }
}

int get_int(char* prompt)
{
    int n;
    printf("%s", prompt);
    while (scanf("%d", &n) != 1)
    {
        printf("Invalid input. Please enter an integer: ");
        while (getchar() != '\n')
            continue;
    }
    return n;
}