#include <stdlib.h>
#include <stdio.h>

#define N 8

void triInsertion(int *tab, int taille);

// Pour cet algorithme il est nécessaire d'avoir un tableau non trié, car le but est justement de le trier.
void main(void)
{
    int tab[N] = { 2, 1, 3, 7, 4, 12, 13, 5 };
    triInsertion(tab, N);
    int i;
    for (i = 0; i < N; i++) {
        printf("%d\n", tab[i]);
    }
}

void triInsertion(int *tab, int taille)
{
    int i, j, val;
    for (i = 0; i < taille; i++) {
        val = tab[i];
        j = i;
        while (j > 0 && tab[j - 1] > val) {
            tab[j] = tab[j - 1];
            j--;
        }
        tab[j] = val;
    }
}