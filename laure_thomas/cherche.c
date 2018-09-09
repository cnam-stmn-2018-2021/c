#include <stdlib.h>
#include <stdio.h>

#define N 3

int cherche(int *tab, int taille, int k);
int chercheIndex(int *tab, int taille, int k);

void main(void)
{
    int tab[N] = { 1, 2, 3 };
    /*if (cherche(tab, N, 4) == 1) {
        printf("%s\n", "Le nombre est présent dans le tableau.");
    } else {
        printf("%s\n", "Le nombre n'est pas présent dans le tableau.");
    }*/
    int indice = chercheIndex(tab, N, 2);
    if (indice != -1) {
        printf("%s", "Le nombre est présent dans le tableau à l'indice ");
        printf("%d\n", indice);
    } else {
        printf("%s\n", "Le nombre n'est pas présent dans le tableau.");
    }
}

// Renvoie un booléen si le nombre est dans le tableau.
int cherche(int *tab, int taille, int k)
{
    int trouve = 0;
    int i;
    for (i = 0; i < taille; i++) {
        if (tab[i] == k) {
            trouve = 1;
            return trouve;
        }
    }
    return -1;
}

// Renvoie l'index de l'élément s'il est présent dans le tableau.
int chercheIndex(int *tab, int taille, int k)
{
    int i;
    for (i = 0; i < taille; i++) {
        if (tab[i] == k) {
            return i;
        }
    }
    return -1;
}