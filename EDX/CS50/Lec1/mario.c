#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do {
        n = get_int("blocks height: ");
    }
    while (n < 0);

    for (int i = 0; i < n; i++) {
        for (int bl = i+1; bl < n; bl++) {printf(" ");}
        for (int hs = 0; hs < i; hs++) {printf("#");}
        printf("#  #");
        for (int sp = 0; sp < i; sp++) {printf("#");}
        printf("\n");
    }
    return 0;
}
