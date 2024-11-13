#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    end = clock(); 
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("-----> Time: %fs <-----\n", cpu_time_used);
}