#include <stdio.h>
#include <stdlib.h>

#define N 4

int returnMax(int *tab, int taille);

void main(void)
{
    int tab[N] = { 1, 2, 3, 4 };
    /*int max = tab[0];
    int i;
    for (i = 1; i < N; i++) {
        if (tab[i] > max) {
            max = tab[i];
        }
    }*/
    int max = returnMax(tab, N);
    printf("%d\n", max);
}

int returnMax(int *tab, int taille) {
    int max = tab[0];
    int i;
    for (i = 1; i < taille; i++) {
        if (tab[i] > max) {
            max = tab[i];
        }
    }
    return max;
}