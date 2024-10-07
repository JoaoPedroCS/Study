#include <stdio.h>

int get_int(char* prompt);

int main(void)
{
    int n = get_int("");
    for (int i = 0; i < n+1; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = n; i >= 0; i--)
    {
        printf("%d ", i);
    }
    printf("\n");
}

int get_int(char* prompt)
{
    int n;
    printf("%s", prompt);
    while (scanf("%d", &n) != 1)
    {
        printf("");
        while (getchar() != '\n')
            continue;
    }
    return n;
}