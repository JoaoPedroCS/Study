#include <stdio.h>

int get_int(char* prompt);

int main(void)
{
    int dd = get_int("");
    int mm = get_int("");
    int aa = get_int("");
    printf("%i/%i/%i\n", dd, mm, aa);
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