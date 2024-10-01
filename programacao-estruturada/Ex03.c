#include <stdio.h>

int get_int(char* prompt);

int main(void)
{
    int girls = get_int("");
    int boys = get_int("");
    if (girls > boys) 
    {
        printf("Quantidade de alunas eh maior do que de alunos!\n");
    }
    else if (boys > girls)
    {
        printf("Quantidade de alunos eh maior do que de alunas!\n");
    }
    else
    {
        printf("Mesma quantidade!\n");
    }
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