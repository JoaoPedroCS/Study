#include <stdio.h>

int get_int(char* prompt);

int main(void)
{
    int n = get_int("");
    float m = 0;
    float div;
    for (int i = 1; i <= n; i++)
    {
        m += (float) 1 / i;
    }
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