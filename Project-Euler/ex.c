#include <stdio.h>
#include <stdlib.h>

void insertSort(char** x, int size);
int compareStrings(char* a, char* b);



int main() {

    FILE* example = fopen("./assets/22.txt", "r");
    if (example == NULL)
    {
        printf("Error: could not open file.");
        return 1;
    }

    int expected = 5500;
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
    
    char ch;
    long long int result = 0;
    int currentSum = 0;
    int count = 1;

    for (int i = 0; i < w; i++) {
        free(names[i]);
    }
    free(names);
    fclose(example);
    return 0;
}


void insertSort(char** x, int size)
{
    for (int i = 0; i <= size; i++)
    {
        char* tmp;
        char* smallest = x[i];
        int index = i;
        for (int k = i+1; k <= size; k++)
        {
            if (compareStrings(smallest, x[k]) == 1)
            {
                smallest = x[k];
                index = k;
            }
        }
        tmp = x[i];
        x[i] = smallest;
        x[index] = tmp;
    }
}

int compareStrings(char* a, char* b)
{
    int z = 0;
    while (a[z] != '\0' && b[z] != '\0')
    {
        if (a[z] < b[z])
        {
            return 0;
        }
        else if (a[z] > b[z])
        {
            return 1;
        }
        z+=1;
    }
    if (a[z] <= b[z])
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
