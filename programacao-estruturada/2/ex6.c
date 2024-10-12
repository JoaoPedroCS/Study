#include <stdio.h>

int get_int(char* prompt);

int main(void)
{
    int n = get_int("");
    float m = 0.1;
    for (int i = 1; i <= n+1; i++)
    {
        m += 1 / i;
    }
    m -= 0.1;
    printf("%.1f\n", m);
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