#include <stdio.h>

int get_int(char* prompt);
void get_print(void);

int main(void)
{
    get_print();
    printf("FIM!\n");
    return 0;
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

void get_print(void)
{
    int n = get_int("");

    if (n < 0) 
    {
        printf("O numero deve ser >=0!\n");
        get_print();
    }
    else
    {
        for (int i = n; i >= 0; i--)
        {
            printf("%i ", i);
        }
        printf("\n");
    }
}