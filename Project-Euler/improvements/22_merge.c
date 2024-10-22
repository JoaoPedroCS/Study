#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mergeSort(char** x, int left, int right);
void merge(char** x, int left, int mid, int right);
int compareStrings(char* a, char* b);
long long evaluate(char** x, int size);
int sumLet(char* x);

int main() {
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    FILE* example = fopen("./assets/22.txt", "r");
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

    mergeSort(names, 0, w - 1);  // Call mergeSort instead of insertSort

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

void mergeSort(char** x, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(x, left, mid);
        mergeSort(x, mid + 1, right);
        merge(x, left, mid, right);
    }
}

void merge(char** x, int left, int mid, int right) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    char** leftArray = malloc(leftSize * sizeof(char*));
    char** rightArray = malloc(rightSize * sizeof(char*));

    for (int i = 0; i < leftSize; i++) {
        leftArray[i] = x[left + i];
    }
    for (int j = 0; j < rightSize; j++) {
        rightArray[j] = x[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < leftSize && j < rightSize) {
        if (compareStrings(leftArray[i], rightArray[j]) <= 0) {
            x[k] = leftArray[i];
            i++;
        } else {
            x[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        x[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        x[k] = rightArray[j];
        j++;
        k++;
    }

    free(leftArray);
    free(rightArray);
}

int compareStrings(char* a, char* b) {
    int z = 0;
    while (a[z] != '\0' && b[z] != '\0') {
        if (a[z] < b[z]) {
            return -1;  // Changed to -1 for less than
        } else if (a[z] > b[z]) {
            return 1;   // Changed to 1 for greater than
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
