#include <stdio.h>

void fill_array(int* x, int n);
void print_array(int* x, int n);

int main(void)
{
    int n;
    scanf("%d", &n);
    int* array[n*2];
    int arrayf[n];
    int arrayb[n];
    fill_array(arrayf, n);
    fill_array(arrayb, n);
    printf("F:");
    print_array(arrayf, n);
    printf("B:");
    print_array(arrayb, n);
}


void fill_array(int* x, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x[i]);
    }
}

void print_array(int* x, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %i", x[i]);
    }
    printf("\n");
}

void sort_array(int* x, int n)
{
    int xsorted[n];
    
}

