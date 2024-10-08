#include <stdio.h>

int get_int(char *prompt);

int main(void)
{
    int done = -1;
    while (done < 1)
    {
        int smallest;
        int n = get_int("");
        if (n == 1)
        {
            int a = get_int("");
            int b = get_int("");
            printf("(a+b) = %i\n", a + b);
            if (done == -1)
            {
                smallest = a + b;
                done = 0;
            }
            else if (a + b < smallest)
            {
                smallest = a + b;
            }
        }
        else if (n == 2)
        {
            int a = get_int("");
            int b = get_int("");
            int c = get_int("");
            printf("(a+b+c) = %d\n", a + b + c);
            if (done == -1)
            {
                smallest = a + b + c;
                done = 0;
            }
            else if (a + b + c < smallest)
            {
                smallest = a + b + c;
            }
        }
        else if (n == 3)
        {
            int a = get_int("");
            int b = get_int("");
            printf("(a*b) = %d\n", a * b);
            if (done == -1)
            {
                smallest = a * b;
                done = 0;
            }
            else if (a * b < smallest)
            {
                smallest = a * b;
            }
        }
        else if (n == 0 && done == -1)
        {
            printf("Nenhum calculo foi realizado!\n");
            done = 1;
        }
        else if (n == 0)
        {
            done = 1;
            printf("Menor resultado: %d\n", smallest);
        }
    }
}

int get_int(char *prompt)
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