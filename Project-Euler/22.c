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
    long sum;
    int current;
    while ((ch = fgetc(fp)) != EOF) {
        current = 0;

    }
        



    fclose(fp);

}