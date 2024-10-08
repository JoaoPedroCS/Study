#include <stdio.h>

int get_int(char* prompt);

int main(void)
{
    int n = get_int("");
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (n % i == 0) 
        {
            sum += i;
        }
    }
    printf("%d", sum);
}

int get_int(char* prompt)
{
    int n;
    printf("%s", prompt);
    while (scanf("%d", &n) != 1)
    {
        printf("/n");
        while (getchar() != '\n')
            continue;
    }
    return n;
}