#include <stdio.h>


int main(void) {
    int f = 34;
    printf("%c\n", f);
    char *filename = "./assets/22.txt";
    FILE *fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Error: could not open file %s", filename);
        return 1;
    }

    char ch;
    long result = 0;
    int currentSum = 0;
    int count = 1;
    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch == 34 && currentSum > 0)
        {
            result += currentSum * count;
            count += 1;
            currentSum = 0;
        }
        else if (ch >=65 && ch<= 90)
        {
            
        }


    }
        



    fclose(fp);

}