#include <stdio.h>
#include <stdlib.h>

int isAbundant(int x);
double root(int y);

int main(void)
{
    int* abundants = malloc(7000 * sizeof(int));
    int position = 0;
    for (int i = 12; i < 28124; i++)
    {
        if (isAbundant(i) == 0)
        {
            abundants[position] = i;
            position += 1;
        }
    }
    abundants = realloc(abundants, position * sizeof(int));
    
    int* numbers = malloc(28123 * sizeof(int));
    for (int i = 1; i < 28124; i++)
    {
        numbers[i] = i;
    }

    free(abundants);
    free(numbers);
}

int isAbundant(int x)
{
    int rounded = (int) root(x);
    int sum_divisors = 1;
    for (int i = 2; i <= rounded; i++)
    {        
        if (x % i == 0)
        {
            sum_divisors += i;
            if (x/i > rounded)
            {
                sum_divisors += x/i;
            }
        }
    }
    if (sum_divisors > x)
    {
        return 0;
    }
    return 1;
}

double root(int y)
{
    if (y < 0) {
        printf("Negative input error\n");
        return -1;
    }

    double x = (double) (y);
    double tolerance = 0.000001;
    double guess = x / 2.0;
    if (x >= 1000000)
    {
        double guess = x / 1000000.0;
    }
    else if (x >= 10000)
    {
        double guess = x / 100.0;
    }
    else if (x >= 100)
    {
        double guess = x / 10.0;
    }
    
    while ((guess * guess - x) > tolerance || (guess * guess - x) < -tolerance) {
        guess = (guess + x / guess) / 2.0;
    }
    
    return guess;
}

void findSum(int* numbers, int* abundants, int position)
{
    for (int i = 0; i < position; i++)
    {
        
    }
}

