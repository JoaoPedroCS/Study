#include <stdio.h>
#include <math.h>

float get_float(char* prompt);

char* pesos[] = {"Obesidade Grau III", "Obesidade Grau II", "Obesidade Grau I", "Sobrepeso", "Normal", "Abaixo do Peso"};

int main(void)
{
    float a = get_float("");
    float p = get_float("");
    float IMC = p / (a * a);
    printf("Seu IMC eh: %.2f\nA Classificacao eh: ", IMC);
    if (IMC > 40)
    {
        printf("%s", pesos[0]);
    }
    else if (IMC > 35)
    {
        printf("%s", pesos[1]);
    }
    else if (IMC > 30)
    {
        printf("%s", pesos[2]);
    }
    else if (IMC > 25)
    {
        printf("%s", pesos[3]);
    }
    else if (IMC > 18.5)
    {
        printf("%s", pesos[4]);
    }
    else
    {
        printf("%s", pesos[5]);
    }
    printf("!\n");
}

float get_float(char* prompt)
{
    float n;
    printf("%s", prompt);
    while (scanf("%f", &n) != 1)
    {
        printf("Invalid input. Please enter a float: ");
        while (getchar() != '\n')
            continue;
    }
    return n;
}