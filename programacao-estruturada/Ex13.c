#include <stdio.h>
#include <math.h>

float get_float(char* prompt);

int main(void)
{
    float a = get_float("");
    float b = get_float("");
    float c = get_float("");
    if (a < 0 || b < 0 || c < 0)
    {
        printf("Entrada INVALIDA!\n");
    }
    else if (a == b && b == c)
    {
        printf("Triangulo EQUILATERO!\n");
    }
    else if (a == b || b == c || a == c)
    {
        printf("Triangulo ISOSCELES!\n");
    }
    else
    {
        printf("Triangulo ESCALENO!\n");
    }
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