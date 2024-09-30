#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    long n;
    do
    {
        n = get_long("credit cards number: ");
    }
    while (n <= 0);

    char str[20];
    sprintf(str, "%li", n);

    int length = strlen(str);
    if (length < 13 || length == 14 || length > 16)
    {
        printf("INVALID\n");
    }
    else
    {
        int sum[30];
        for (int r = 0; r < 30; r++)
        {
            sum[r] = 0;
        }
        int x = 0;
        for (int i = length - 2; i >= 0; i -= 2)
        {
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
            x += 1;
        }
        length -= 1;
        while (length > -1)
        {
            sum[x] = str[length] - '0';
            x += 1;
            length -= 2;
        }
        int answer = 0;
        for (int k = 0; k < 30; k++)
        {
            answer += sum[k];
        }
        length = strlen(str);
        int fst = str[0] - '0';
        int t = str[1] - '0';
        if (answer % 10 == 0)
        {
            if (length == 13 && fst == 4)
            {
                printf("VISA\n");
            }
            else if (length == 16 && fst == 4)
            {
                printf("VISA\n");
            }
            else if (length == 16 && fst == 5)
            {

                if (0 < t && t < 6)
                {
                    printf("MASTERCARD\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }
            else if (length == 15 && fst == 3)
            {
                if (t == 4 || t == 7)
                {
                    printf("AMEX\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }
            else
            {
                printf("INVALID\n");
            }
        } else {
            printf("INVALID\n");
        }
    }
}
