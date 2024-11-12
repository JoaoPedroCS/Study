#include <stdio.h>

void fibbo(int* x, int* y, int limit);

int main(void) 
{
    int x = 1;
    int y = 1;
    int z;
    scanf("%i", &z);
    fibbo(&x, &y, z);
    printf("\nx: %i\n", x);
}

void fibbo(int* x, int* y, int limit)
{
    if (*x >= limit)
    {
        return;
    }
    int tmp;
    tmp = *x;
    *x += *y;
    *y = tmp;
    printf("%i, ", *x);
    fibbo(x, y, limit);
}