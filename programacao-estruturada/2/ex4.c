#include <stdio.h>

int get_int(char* prompt);

int main(void)
{
    int operation = get_int("");
    if (operation == 1)
    {
        int a = get_int("");
        for (int i = 0; i < n+1; i++)
        {
            printf("%d ", i);
        }
        printf("\n");
    }
    else if (operation == 2)
    {
        int n = get_int("");
        for (int i = n; i >= 0; i--)
        {
            printf("%d ", i);
        }
        printf("\n");
    }
    else
    {
        printf("Invalid operation\n");
    }
    
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

void menu(void)
{
    int n = get_int("");
    if (n == 1)
    {
        int a = get_int("");
        int b = get_int("");
        printf("%d\n", a + b);
    }
    else if (n == 2)
    {
        int a = get_int("");
        int b = get_int("");
        int c = get_int("");
        printf("%d\n", (a + b + c));
    }
    else if (n == 3)
    {
        int a = get_int("");
        int b = get_int("");
        printf("%d\n", a * b);
    }
    else
    {
        
    }

}