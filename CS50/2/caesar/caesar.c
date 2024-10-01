#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

void encrypt(string txt, int key, string cryptxt);

int main(int argc, string argv[])
{
    if (argc != 2) {
        printf("ERROR 1: != 1 arguments\n");
        return 1;
    }
    int num = 0;
    int length = strlen(argv[1]);
    for (int i = 0; i < length; i++)
    {
        if (isdigit(argv[1][i]) == 0)
        {
            printf("error 1: argument != 0-9\n");
            return 1;
        }
        num *= 10;
        num += argv[1][i] - '0';
    }
    num = num % 26;
    string pltxt = get_string("plaintext: ");
    string cryptxt = pltxt;
    encrypt(pltxt, num, cryptxt);
    printf("ciphertext: %s\n", cryptxt);
}

void encrypt(string txt, int key, string crypt) {
    int l = strlen(txt);
    for (int i = 0; i < l; i++)
    {
        if (txt[i] >= 97 && txt[i] <= 122 && (txt[i]+key) > 122)
        {
            crypt[i] = txt[i] + key - 26;
        }
        else if (txt[i] >= 65 && txt[i] <= 90 && (txt[i]+key) > 90)
        {
            crypt[i] = txt[i] + key - 26;
        }
        else if (isalpha(txt[i]))
        {
            crypt[i] = txt[i] + key;

        }

    }
}
