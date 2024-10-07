#include <stdio.h>

int get_int(char* prompt);

char* dias[] = {"Domingo!", "Segunda-feira!", "Terca-feira!", "Quarta-feira!", "Quinta-feira!", "Sexta-feira!", "Sabado!"};

int main(void)
{
    int dia = get_int("");
    

    if (dia >= 1 || dia <= 7)
    {
        printf("%s\n", dias[dia - 1]);
    }
    else
    {
        printf("Numero invalido!\n");
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