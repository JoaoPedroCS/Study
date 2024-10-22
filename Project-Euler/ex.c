#include <stdio.h>


#define maxWords 7
#define maxLetters 20

int main() {
    char* words;
    FILE* example = fopen("./assets/ex.txt", "r");
    if (example == NULL)
    {
        printf("Error: could not open file.");
        return 1;
    }

    int c;
    int w = 0;
    char l = 0;
    char names[maxWords][maxLetters];
    while ((c = fgetc(example)) != EOF)
    {
       if (c >= 'A' && c <= 'Z')
        {
            names[w][l] = c;
            l += 1;
        }
        else if (c == ' ')
        {
            names[w][l+1] = '\0';
            w += 1;
            l = 0;
        }
    }

    names[w][l+1] = '\0';
    names[w+1][0] = '\0';


    for (int i = 0; i < 5; i++)
    {
        printf("%s, ", names[i]);
    }

    
    fclose(example);

    return 0;
}
