#include <cs50.h>
#include <stdio.h>

int main(void) {
int n;
    do {
        n = get_int("Largura: ");
    } while (n < 1);

int t;
    do {
        t = get_int("Comprimento: ");
    } while (t < 1);

    for (int i = 0; i < t; i++) {
        for (int j = 0; j < n; j++) {
            printf("#");
        }
        printf("\n");
    }


}
//return 0;
