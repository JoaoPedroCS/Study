#include <stdio.h>

int get_int(char* prompt);

int main(void)
{
    int n = get_int("");
    for (int lines = 0 ; lines < n ; lines++)
    {
        int count = 0;
        while (count > -1)
        {
            for (int i = 0; i <= lines; i++)
            {
                count
                printf("%i", count);
                if (count >= 10) {printf("...");}
                else {printf("..");}
                printf("\n");
            }
        }
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