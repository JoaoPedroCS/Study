#include <stdio.h>

void divisors(double x);
double sqrt(double x);

int main(void)
{
    
}

void divisors(double x)
{
    int rounded = (int) sqrt(x);
    for (int i = 2; i <= rounded; i++)
    {

    }
}

double sqrt(double x)
{
    if (x < 0) {
        printf("Negative input error\n");
        return -1;
    }
    
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



