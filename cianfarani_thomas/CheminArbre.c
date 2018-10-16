#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct noeud {
  struct noeud *fd, *fg, *papa;
  int val;
};

struct maillon {
  struct maillon *suivant;
  struct noeud *val;
};

// Affichage des éléments d'une liste chainée
void printListeChainee(struct maillon *tete) {
  while (tete != NULL) {
    printf("%d ", tete->val->val);
    tete = tete->suivant;
  }
  printf("\n");
}

int compterElements(struct maillon *tete) {
  int nb = 0;

  while (tete != NULL) {
    nb++;
    tete = tete->suivant;
  }

  return nb;
}

// Méthode ajoutant au début d'une liste chainée
void ajoute (struct maillon **tete, struct noeud *val) {
  struct maillon *ptr;
  ptr = (struct maillon*) malloc (sizeof(struct maillon));
  ptr->suivant = *tete;
  ptr->val = val;
  *tete = ptr;
}

// Méthode ajoutant au début d'une liste chainée
struct maillon* ajouteEnQueue (struct maillon **queue, struct noeud *val) {
  struct maillon *ptr;
  ptr = (struct maillon*) malloc (sizeof(struct maillon));
  ptr->val = val;
  ptr->suivant = NULL;
  (*queue)->suivant = ptr;
  return (*queue)->suivant;
}

// im looking for da way
// On a n notre noeud dont on veut obtenir le chemin
// On veut remonter du noeud n à la racine, on va utiliser n->papa pour ça
// On va remonter jusqu'à ce que le papa soit r->val
struct maillon* obtenirChemin (struct noeud *r, struct noeud *n) {
  struct maillon *chemin = NULL;

  // On va de n à la racine
  while(n != NULL) {
    // On ajoute à la liste chainee du chemin
    ajoute(&chemin, n);

    // On remonte au papa
    n = n->papa;
  }

  return chemin;
}

// im looking for da common way
struct maillon* obtenirCheminCommun(struct maillon *cheminUno, struct maillon *cheminDos) {
  struct maillon *cheminCommun = NULL;
  struct maillon *queue = NULL;

  // On cherche les maillons identiques et au meme chemin
  while(cheminUno != NULL && cheminDos != NULL) {
    if (cheminUno->val == cheminDos->val) {
      if (cheminCommun == NULL) {
        ajoute(&cheminCommun, cheminUno->val);
        queue = cheminCommun;
      } else {
        queue = ajouteEnQueue(&queue, cheminUno->val);
      }
    }

    cheminUno = cheminUno->suivant;
    cheminDos = cheminDos->suivant;
  }

  return cheminCommun;
}

int distanceEntreNoeuds(struct noeud *racine, struct noeud *noeudUno, struct noeud *noeudDos) {
  // Récupération des chemins racines - noeuds
  struct maillon *cheminRacineNoeudUno = obtenirChemin(racine, noeudUno);
  struct maillon *cheminRacineNoeudDos = obtenirChemin(racine, noeudDos);

  int nbCheminsUno = compterElements(cheminRacineNoeudUno) - 1;
  int nbCheminsDos = compterElements(cheminRacineNoeudDos) - 1;
  int nbNoeudsCommuns = compterElements(obtenirCheminCommun(cheminRacineNoeudUno, cheminRacineNoeudDos));
  
  // Si seule la racine est en commun, on ne compte pas comme un chemin
  if (nbNoeudsCommuns == 1)
    nbNoeudsCommuns = 0;

  // Calcul de la distance
  return nbCheminsUno + nbCheminsDos - nbNoeudsCommuns;
}

// Point d'entrée du programme
int main(int argc, char const *argv[]) {
  struct noeud *racine = (struct noeud*) malloc(sizeof(struct noeud));
  struct noeud *fd1 = (struct noeud*) malloc(sizeof(struct noeud));
  struct noeud *fd2 = (struct noeud*) malloc(sizeof(struct noeud));
  struct noeud *fg2 = (struct noeud*) malloc(sizeof(struct noeud));
  struct noeud *fg1 = (struct noeud*) malloc(sizeof(struct noeud));

  fd2->papa = fd1;
  fd2->val = 15;
  fd2->fd = NULL;
  fd2->fg = NULL;

  fg2->papa = fd1;
  fg2->val = 7;
  fg2->fd = NULL;
  fg2->fg = NULL;

  fd1->papa = racine;
  fd1->val = 4;
  fd1->fd = fd2;
  fd1->fg = fg2;

  fg1->papa = racine;
  fg1->val = 1;
  fg1->fd = NULL;
  fg1->fg = NULL;

  racine->papa = NULL;
  racine->val = 3;
  racine->fd = fd1;
  racine->fg = fg1;

  // Affichage de chemins
  //printListeChainee(obtenirChemin(racine, fd2)); // doit donner 3 4 15
  //printListeChainee(obtenirChemin(racine, fg2)); // doit donner 3 4 7

  // Affichage de chemins communs
  //printListeChainee(obtenirCheminCommun(obtenirChemin(racine, fd2), obtenirChemin(racine, fg2))); // doit donner 3 4
  //printListeChainee(obtenirCheminCommun(obtenirChemin(racine, fd2), obtenirChemin(racine, fd2))); // doit donner 3 4 15

  // Affichage de la distance entre deux noeuds
  printf("Distance : %d (attendu : 3)\n", distanceEntreNoeuds(racine, fg1, fd2)); // doit donner 3
  printf("Distance : %d (attendu : 2)\n", distanceEntreNoeuds(racine, racine, fd2)); // doit donner 2
  printf("Distance : %d (attendu : 2)\n", distanceEntreNoeuds(racine, fd2, fg2)); // doit donner 2
  printf("Distance : %d (attendu : 3)\n", distanceEntreNoeuds(racine, fd2, fg1)); // doit donner 3
  printf("Distance : %d (attendu : 1)\n", distanceEntreNoeuds(racine, fd2, fd1)); // doit donner 1

  return 0;
}
