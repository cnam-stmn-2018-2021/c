#include <stdio.h>
#include <stdlib.h>

// Méthode qui cherche une valeur dans un tableau donné
// et qui retourne l'index auquel elle se trouve.
int cherche(int *tab, int taille, int k) {
  for(int i = 0; i < taille; i++) {
    if(tab[i] == k) {
      return i;
    }
  }
} // Complexité O(n)

// Méthode qui cherche par dichotomie une valeur dans un tableau donné
// et qui retourne l'index auquel elle se trouve.
int chercheParDichotomie(int *tab, int taille, int k) {
  int d = 0, f = taille - 1, m = f/2;

  while(k != tab[m]) {
    if (k > tab[m]) {
      d = m; // on va à droite
    } else if (k < tab[m]) {
      f = m; // on va à gauche
    }

    m = (d + f) / 2;
  }

  return m;
} // Complexité O(log n)

// Equivalent de la méthode de recherche par dichotomie mais de manière
// récursive.
int chercheRecursif(int *tab, int d, int f, int k) {
  int m = (d + f) / 2;

  if (k != tab[m]) {
    if (k > tab[m]) {
      return chercheRecursif(tab, m, f, k);
    }
    else {
      return chercheRecursif(tab, d, m, k);
    }
  }
  else {
    return m;
  }

  return -1;
} // Complexité O(log n)

// Point d'entrée du programme
int main(int argc, char const *argv[]) {
  int tab[8] = { 1, 2, -10, 3, 80, 10, -4, -70 };
  int tabTrie[8] = { -70, -10, -4, 1, 2, 3, 10, 80 };

  printf("%d\n", cherche(tab, 8, 3));
  printf("%d\n", chercheParDichotomie(tabTrie, 8, 2));
  printf("%d\n", chercheRecursif(tabTrie, 0, 7, 2));

  return 0;
}
