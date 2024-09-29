#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    long n;
    do
    {
        n = get_long("credit cards number: ");
    } while (n <= 0);

    char str[20];
    sprintf(str, "%li", n);

    int length = strlen(str);
    if (length < 13 || length == 14 || length > 16)
    {
        printf("INVALID");
    }
    else
    {
        int sum[8];
        int x = 0;
        for (int i = length - 2; i >= 0; i -= 2)
        {
            x += 1;
            sum[x] = str[i] - '0';
            if (sum[x] * 2 > 9)
            {
                sum[x] = (sum[x] * 2) - 10;
                sum[x + 1] = 1;
                x += 1;
            }
            else
            {
                sum[x] *= 2;
            }
            printf("%i, ", sum[x]);
        }
    }
}