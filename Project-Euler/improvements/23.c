#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int isAbundant(int x);
double root(int y);
void findSum(int* numbers, int* abundants, int position);

int main(void)
{
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    int* abundants = malloc(6965 * sizeof(int));
    int position = 0;
    for (int i = 12; i < 28124; i++)
    {
        if (isAbundant(i) == 0)
        {
            abundants[position++] = i;
        }
    }
    int* numbers = malloc(28123 * sizeof(int));
    for (int i = 1; i < 28124; i++)
    {
        numbers[i] = i;
    }
    findSum(numbers, abundants, position);

    int sum = 0;
    for (int i = 1; i < 28124; i++)
    {
        sum += numbers[i];
    }
    printf("---------->%i<----------\n", sum);
    end = clock(); 
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("-----> Time: %fs <-----\n", cpu_time_used);
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
    if (x >= 10000)
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
    int tmp;
    for (int i = 0; i < position; i++)
    {
        for (int k = i; abundants[i] + abundants[k] < 28124; k++)
        {
            tmp = abundants[i] + abundants[k];
            numbers[tmp] = 0;
        }
    }
}
