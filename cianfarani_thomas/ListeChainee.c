#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct maillon {
  int val;
  struct maillon *suivant;
};

// Méthode ajoutant au début d'une liste chainée
void ajoute (struct maillon **tete, int val) {
  struct maillon *ptr;
  ptr = (struct maillon*) malloc (sizeof(struct maillon));
  ptr->suivant = *tete;
  ptr->val = val;
  *tete = ptr;
} // Complexité:

// Ajout dans une une liste triée
void ajouteDansTrie (struct maillon **tete, int val) {
  struct maillon *ptr = *tete;
  struct maillon *nouv = (struct maillon*) malloc (sizeof(struct maillon));
  nouv->val = val;
  struct maillon *prec = NULL;

  if(*tete != NULL) {
    while (ptr != NULL && ptr->val < val) {
      prec = ptr;
      ptr = ptr->suivant;
    }
    if (ptr != NULL && ptr->val >= val) {
      nouv->suivant = ptr;
      if (prec == NULL) {
        *tete = nouv;
      } else {
        prec->suivant = nouv;
      }
    } else {
      nouv->suivant = NULL;
      prec->suivant = nouv;
      //printf("%d\n", prec->suivant->val);
    }
  } else {
    nouv->suivant = NULL;
    *tete = nouv;
  }
} // Complexité: O(n)

// Méthode cherchant une valeur dans une liste chainée et retournant son maillon
struct maillon* chercher(struct maillon *tete, int val) {
  struct maillon *ptr = tete;
  while (ptr != NULL && ptr->val != val) {
    ptr = ptr->suivant;
  }

  return ptr;
}

// Enlève un maillon de la liste chainée
void enlever(struct maillon **tete, int val) {
  if (tete != NULL) {
    struct maillon *ptr = *tete;
    struct maillon *prec;

    if (ptr->val == val) {
      *tete = ptr->suivant;
    } else {
      while (ptr->suivant != NULL && ptr->val != val) {
        prec = ptr;
        ptr = ptr->suivant;
      }

      if (ptr->val == val) {
        if (prec != NULL)
          prec->suivant = ptr->suivant;
        free(ptr);
      }
    }
  }
} // Complexité: O(n)

// Affichage des éléments d'une liste chainée
void printListeChainee(struct maillon *tete) {
  while (tete != NULL) {
    printf("%d\n", tete->val);
    tete = tete->suivant;
  }
}

// Point d'entrée du programme
int main(int argc, char const *argv[]) {
  int tab[8] = { 1, 2, -10, 3, 80, 10, -4, -70 };
  int tabTrie[8] = { 80, 10, 3, 2, 1, -4, -10, -70 };
  struct maillon *tete = NULL;

  // Ajout dans liste
  for (int i = 0; i < 8; i++) {
    ajoute(&tete, tabTrie[i]);
  }

  ajouteDansTrie(&tete, 9);
  ajouteDansTrie(&tete, -5);
  ajouteDansTrie(&tete, 100);
  ajouteDansTrie(&tete, -100);
  ajouteDansTrie(&tete, 350);

  // Possible que la fonction enlever ne fonctionne pas parfaitement
  enlever(NULL, -70);
  enlever(&tete, -70);
  enlever(&tete, -45);
  enlever(&tete, 100);
  enlever(&tete, 350);
  enlever(&tete, -100);

  printListeChainee(tete);

  printf("Nombre suivant 80 : %d\n", chercher(tete, 80)->suivant->val);

  return 0;
}
