#include <stdio.h>


int main(void) {
    int ch = 34;
    char *filename = "./assets/22.txt";
    FILE *fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Error: could not open file %s", filename);
        return 1;
    }

    char ch;
    long sum;
    int current = 0;
    int count = 1;
    int end = 0;
    while ((ch = fgetc(fp)) != EOF)
    {
        current = 0;
        if (ch == "")
        {

        }


    }
        



    fclose(fp);

}