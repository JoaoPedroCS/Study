#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertSort(char** x, int size);
int compareStrings(char* a, char* b);
long long evaluate(char** x, int size);
int sumLet(char* x);




int main() {
    clock_t start, end;
    double cpu_time_used;
    start = clock();

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
    w +=1;

    names = realloc(names, w * sizeof(char*));

    insertSort(names, w);

    long long answer = evaluate(names, w);
    printf("--------> %lld <--------\n", answer);    

    end = clock();  // End time
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;  // Convert to seconds

    printf("-----> Time: %fs <-----\n", cpu_time_used);

    for (int i = 0; i < w; i++) {
        free(names[i]);
    }
    free(names);
    fclose(example);
    return 0;
}


void insertSort(char** x, int size)
{
    for (int i = 0; i < size; i++)
    {
        char* tmp;
        char* smallest = x[i];
        int index = i;
        for (int k = i+1; k < size; k++)
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

long long evaluate(char** x, int size)
{
    long long answer = 0;
    for (int i = 0; i < size; i++)
    {
        answer += (sumLet(x[i]) * (i+1));
    }
    return answer;
}

int sumLet(char* x)
{
    int i = 0;
    int sum = 0;
    while (x[i] != 0)
    {
        sum += x[i] - 64;
        i++;
    }
    return sum;
}