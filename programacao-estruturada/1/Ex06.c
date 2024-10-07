#include <stdio.h>

int get_int(char* prompt);

int main(void)
{
    int num = get_int("");
    printf("Antecessor de %i eh: %i\nSucessor de %i eh: %i\n", num, (num -1), num, (num + 1));
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