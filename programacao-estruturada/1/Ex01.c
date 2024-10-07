#include <stdio.h>

int get_int(char* prompt);

int main(void)
{
    int boys = get_int("");
    int girls = get_int("");
    printf("Alunos: %i\nAlunas: %i\nTotal: %i\n", boys, girls, (boys + girls));
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