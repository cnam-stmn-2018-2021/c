#include <stdlib.h>
#include <stdio.h>

#define N 9

void echange(int *tab, int a, int b);
void tri3(int *tab, int taille);

void main(void)
{
    int tab[N] = { 2, 1, 2, 3, 3, 1, 2, 1, 2 };
    tri3(tab, N);
    int i;
    for (i = 0; i < N; i++) {
        printf("%d\n", tab[i]);
    }
}

void tri3(int *tab, int taille)
{
    int i = 0, debut = 0, fin = taille - 1;
    while (i <= fin) {
        if (tab[i] == 1) {
            echange(tab, i, debut);
            debut++;
        } else if (tab[i] == 3) {
            echange(tab, i, fin);
            fin--;
            i--;
        }
        i++;
    }
}

void echange(int *tab, int a, int b)
{
    int tmp;
    tmp = tab[a];
    tab[a] = tab[b];
    tab[b] = tmp;
}