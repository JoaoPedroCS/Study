#include <stdio.h>


int main(void) {
    char *filename = "./assets/22.txt";
    FILE *fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Error: could not open file %s", filename);
        return 1;
    }

    // read one character at a time and
    // display it to the output
    char ch;
    while ((ch = fgetc(fp)) != EOF)
        putchar(ch);

    // close the file
    fclose(fp);

}