#include <stdio.h>


int main(void) {
    char *filename = "./assets/22.txt";
    FILE *fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Error: could not open file %s", filename);
        return 1;
    }

    char ch;
    long long int result = 0;
    int currentSum = 0;
    int count = 1;
    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch == '\"' && currentSum > 0)
        {
            result += currentSum * count;
            count += 1;
            currentSum = 0;
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            currentSum += ch - 64;
        }
        if (count >= 4995 && currentSum == 0) {printf("%lld \n", result);}
    }

    fclose(fp);
    printf("%lld", result);

}