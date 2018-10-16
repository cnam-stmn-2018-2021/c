#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool AreEqual(int *tab1, int taille1, int *tab2, int taille2);
void echange(int *tab, int a, int b);

// Méthode de tri par insertion
void triInsertion (int *tab, int taille) {
  for (int i = 1; i < taille; i++) {
    for (int j = i - 1; j >= 0; j--) {
      if (tab[j+1] < tab[j]) {
        echange(tab, j+1, j);
      }
    }
  }
} // Complexité: O(n²)

// Méthode de tri 3 valeurs
void tri3(int *tab, int taille) {
  int i = 0, d = 0, f = taille -1;

  while (i <= f) {
    if (tab[i] == 1) {
      echange(tab, i, d);
      d++;
    } else if (tab[i] == 3) {
      echange(tab, i, f);
      f--; i--;
    }

    i++;
  }
} // Complexité: O(n)

// Point d'entrée du programme
int main(int argc, char const *argv[]) {
  int tab[8] = { 1, 2, -10, 3, 80, 10, -4, -70 };
  int tabTrie[8] = { -70, -10, -4, 1, 2, 3, 10, 80 };
  int tab3[8] = {1, 2, 1, 1, 2, 3, 3, 1};
  int tab3Trie[8] = {1, 1, 1, 1, 2, 2, 3, 3};

  triInsertion(tab, 8);
  printf("%d\n", AreEqual(tab, 8, tabTrie, 8));
  tri3(tab3, 8);
  printf("%d\n", AreEqual(tab3, 8, tab3Trie, 8));

  return 0;
}

void echange(int *tab, int a, int b) {
  int temp = tab[a];
  tab[a] = tab[b];
  tab[b] = temp;
}

bool AreEqual(int *tab1, int taille1, int *tab2, int taille2) {
  if (taille1 != taille2)
    return false;

  for (int i = 0; i < taille1; i++) {
    if (tab1[i] != tab2[i])
      return false;
  }

  return true;
}
