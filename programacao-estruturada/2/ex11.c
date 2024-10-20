#include <stdio.h>

float get_float(char* prompt);
char get_char(char* prompt);
float operacao(float n1, float n2, char simb);

int main(void)
{
    float n1 = get_float("Digite o primeiro número: ");
    float n2 = get_float("Digite o segundo número: ");
    char simb = get_char("Digite o operador: ");
    printf("%f", operacao(n1, n2, simb));
}

float get_float(char* prompt)
{
    float n;
    printf("%s", prompt);
    while (scanf("%f", &n) != 1)
    {
        printf("\n");
        while (getchar() != '\n')
            continue;
    }
    return n;
}

char get_char(char* prompt)
{
    char n;
    printf("%s", prompt);
    scanf(" %c", &n);
    return n;
}

float operacao(float n1, float n2, char simb)
{
    if (simb == '+')
        return n1 + n2;
    else if (simb == '-')
        return n1 - n2;
    else if (simb == '*')
        return n1 * n2;
    else if (simb == '/')
        return n1 / n2;
    else
        return 6.9;   
}