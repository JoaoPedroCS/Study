#include <stdio.h>

int get_int(char* prompt);

int main(void)
{
    int operador = get_int("");
    int x = get_int("");
    int y = get_int("");

    if (operador == 1) {printf("O resultado da soma eh: %i\n", x + y);}
    else if (operador == 2) {printf("O resultado da subtracao eh: %i\n", x - y);}
    else if (operador == 3) {printf("O resultado da divisao eh: %f\n", (float)x / y);}
    else if (operador == 4) {printf("O resultado da multiplicacao eh: %f\n", (float)x * y);}
    else {printf("Numero Invalido!\n");}
    
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