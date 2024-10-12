#include <stdio.h>

int get_int(char* prompt);

int main(void)
{
    int n = get_int("");
    int count = 1;
    for (int lines = 1 ; lines <= n ; lines++)
    {
        
        for (int i = 1; i <= lines; i++)
        {
            printf("%i", count);
            if (count >= 10) {printf("..");}
            else {printf("...");}
            count++;
        }
        printf("\n");
        
    }
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