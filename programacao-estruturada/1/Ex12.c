#include <stdio.h>

int get_int(char* prompt);

int main(void)
{
    int x = get_int("");
if (x == 0) {printf("Numero NEUTRO!\n");}
else if (x % 2 != 0) {printf("Numero IMPAR!\n");}
else {printf("Numero PAR!\n");}    
}

int get_int(char* prompt)
{
    int n;
    printf("%s", prompt);
    while (scanf("%d", &n) != 1)
    {
        printf("Invalid input. Please enter an integer: ");
        while (getchar() != '\n')
            continue;
    }
    return n;
}