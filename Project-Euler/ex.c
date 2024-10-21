#include <stdio.h>


#define MAX_WORDS 10
#define MAX_LINE_LEN 100


int main() {
    char* words;
    FILE* example = fopen("./assets/ex.txt", "r");
    if (example == NULL)
    {
        printf("Error: could not open file.");
        return 1;
    }

    char line[MAX_LINE_LEN];
    while (fgets(line, sizeof(line), example)) {
        printf("%s", line);
    }

    
    fclose(example);

    return 0;
}
