#include <stdlib.h>
#include <stdio.h>

#define N 7

int cherche(int *tab, int taille, int val);

// La condition pour appliquer une recherche par dichotomie est d'avoir un tableau trié par ordre croissant.
void main(void)
{
    int tab[7] = { 1, 2, 3, 6, 9, 14 };
    int trouve = cherche(tab, N, 9);
    if (trouve != -1) {
        printf("%s", "La valeur est dans le tableau au rang ");
        printf("%d\n", trouve);
    } else {
        printf("%s\n", "La valeur n'est pas dans le tableau.");
    }
}

int cherche(int *tab, int taille, int val)
{
    int debut, fin, milieu, trouve;
    debut = 0;
    trouve = 0;
    fin = taille - 1;
    while (trouve == 0 && debut < fin) {
        milieu = (debut + fin) / 2;
        if (tab[milieu] == val) {
            trouve = 1;
        } else {
            if (tab[milieu] < val) {
                debut = milieu;
            } else {
                fin = milieu;
            }
        }
    }
    if (trouve == 1) {
        return milieu;
    } else {
        return -1;
    }
}