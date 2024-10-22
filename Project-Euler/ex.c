#include <stdio.h>
#include <stdlib.h>


int main() {
    FILE* example = fopen("./assets/22.txt", "r");
    if (example == NULL)
    {
        printf("Error: could not open file.");
        return 1;
    }

    int expected = 6000;
    int standLetters = 20;
    int c;
    int w = 0;
    char l = 0;
    char** names = malloc(expected * sizeof(char*));
    for (int i = 0; i < expected; i++)
    {
        names[i] = malloc(standLetters * sizeof(char));
    }

    while ((c = fgetc(example)) != EOF)
    {
       if (c >= 'A' && c <= 'Z')
        {
            names[w][l] = c;
            l += 1;
        }
        else if (c == ',')
        {
            names[w][l+1] = '\0';
            w += 1;
            l = 0;
        }
    }

    names = realloc(names, w * sizeof(char*));

    printf("%s", names[0]);
    for (int i = 1; i <= w; i++)
    {
        printf(", %s", names[i]);
    }

    for (int i = 0; i < w; i++) {
        free(names[i]);
    }
    free(names);
    fclose(example);
    return 0;
}
