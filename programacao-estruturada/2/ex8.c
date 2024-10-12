#include <stdio.h>

int get_int(char* prompt);

int main(void)
{
    int n = get_int("");
    float m = 0;
    float div;
    for (int i = 1; i <= n; i++)
    {
        div = 1;
        for (int j = 1; j <= i; j++)
        {
            div *= j;
        }
        m += (float) 1 / div;
    }
    printf("%.2f\n", m);
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