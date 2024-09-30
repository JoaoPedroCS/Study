#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

void transform(string x, int a[], int lx);
int eval(int a[], int lx);
int points[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{
    string x = get_string("Player 1: ");
    string y = get_string("Player 2: ");
    int lx = strlen(x);
    int a[lx];
    int ly = strlen(y);
    int b[ly];
    transform(x, a, lx);
    transform(y, b, ly);
    int px = eval(a, lx);
    int py = eval(b, ly);
    printf("x: %i\ny: %i\n", px, py);
    if (px == py)
    {
        printf("Tie!\n");
    }
    else if (px > py)
    {
        printf("Player 1 wins!\n");
    }
    else if (px < py)
    {
        printf("Player 2 wins!\n");
    }
}

void transform(string x, int a[], int lx)
{
    for (int i = 0; i < lx; i++)
    {
        x[i] = tolower(x[i]);
        a[i] = x[i] - 'a';
    }
}

int eval(int a[], int lx)
{
    int sum = 0;
    for (int i = 0; i < lx; i++)
    {
        if (a[i] >= 0 && a[i] <= 25)
        {
            sum += points[a[i]];
        }
    }
    return sum;
}
