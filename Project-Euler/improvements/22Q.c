#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quickSort(char** x, int low, int high);
int partition(char** x, int low, int high);
int compareStrings(char* a, char* b);
long long evaluate(char** x, int size);
int sumLet(char* x);

int main() {
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    FILE* example = fopen("../assets/22.txt", "r");
    if (example == NULL) {
        printf("Error: could not open file.");
        return 1;
    }

    int expected = 5500;
    int standLetters = 20;
    int c;
    int w = 0;
    char l = 0;
    char** names = malloc(expected * sizeof(char*));
    for (int i = 0; i < expected; i++) {
        names[i] = malloc(standLetters * sizeof(char));
    }

    while ((c = fgetc(example)) != EOF) {
        if (c >= 'A' && c <= 'Z') {
            names[w][l] = c;
            l += 1;
        } else if (c == ',') {
            names[w][l + 1] = '\0';
            w += 1;
            l = 0;
        }
    }
    w += 1;

    names = realloc(names, w * sizeof(char*));

    quickSort(names, 0, w - 1);  // Call quickSort instead of insertSort

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

void quickSort(char** x, int low, int high) {
    if (low < high) {
        int pi = partition(x, low, high); // Partitioning index
        quickSort(x, low, pi - 1);  // Recursively sort elements before partition
        quickSort(x, pi + 1, high); // Recursively sort elements after partition
    }
}

int partition(char** x, int low, int high) {
    char* pivot = x[high]; // Choosing the rightmost element as the pivot
    int i = (low - 1); // Index of the smaller element

    for (int j = low; j < high; j++) {
        if (compareStrings(x[j], pivot) <= 0) { // Use compareStrings to check ordering
            i++; // Increment index of smaller element
            char* temp = x[i];
            x[i] = x[j];
            x[j] = temp; // Swap
        }
    }
    char* temp = x[i + 1];
    x[i + 1] = x[high];
    x[high] = temp; // Swap pivot
    return (i + 1);
}

int compareStrings(char* a, char* b) {
    int z = 0;
    while (a[z] != '\0' && b[z] != '\0') {
        if (a[z] < b[z]) {
            return -1; // Less than
        } else if (a[z] > b[z]) {
            return 1;  // Greater than
        }
        z += 1;
    }
    if (a[z] == '\0' && b[z] == '\0') {
        return 0; // Equal
    } else if (a[z] == '\0') {
        return -1; // a is less than b
    } else {
        return 1; // a is greater than b
    }
}

long long evaluate(char** x, int size) {
    long long answer = 0;
    for (int i = 0; i < size; i++) {
        answer += (sumLet(x[i]) * (i + 1));
    }
    return answer;
}

int sumLet(char* x) {
    int i = 0;
    int sum = 0;
    while (x[i] != 0) {
        sum += x[i] - 64;
        i++;
    }
    return sum;
}
