#include <stdio.h>
#include <stdlib.h>


float get_float(char* prompt);

int main(void)
{
    float ba = get_float("");
    float aa = get_float("");
    float bb = get_float("");
    float ab = get_float("");

    if (ba == aa || bb == ab)
    {
        printf("Os dados informados nao formam o retangulo A ou o retangulo B!");
    }
    else
    {
        printf("A area do retangulo A eh: %f\n", ba * aa);
        printf("A area do retangulo B eh: %f\n", bb * ab);
        if (ba * aa > bb * ab)
        {
            printf("A area do retangulo A eh maior do que a do retangulo B!\n");
        }
        else if (bb * ab > ba * aa)
        {
            printf("A area do retangulo B eh maior do que a do retangulo A!\n");
        }
        else
        {
            printf("A area do retangulo A eh igual ao do retangulo B!\n");
        }
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