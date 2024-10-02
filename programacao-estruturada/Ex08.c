#include <stdio.h>
#include <math.h>

float get_float(char* prompt);

int main(void)
{
    float a = get_float("");
    float b = get_float("");
    float hipotenusa = sqrt(a * a + b * b);
    printf("A hipotenusa eh: %f\n", hipotenusa);
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