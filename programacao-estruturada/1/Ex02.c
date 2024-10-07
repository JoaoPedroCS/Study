#include <stdio.h>

int get_int(char* prompt);

int main(void)
{
    int sony = get_int("");
    int dell = get_int("");
    int toshiba = get_int("");
    printf("%i notebook(s) da Sony\n%i notebook(s) da Dell\n%i notebook(s) da Toshiba\nTotal de %i notebooks", sony, dell, toshiba, (sony + dell + toshiba));
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