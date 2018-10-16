#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct noeud {
  struct noeud *fd, *fg;
  int val;
};

struct maillon {
  struct maillon *suivant;
  struct noeud *val;
};

// Méthode inserant un noeud dans un ABR
void insere (struct noeud **racine, int val) {
  bool insered = false;
  if (*racine == NULL) {
    *racine = (struct noeud*) malloc (sizeof(struct noeud));
    (*racine)->val = val;
  } else {
    struct noeud *noeudParcouru = *racine;
    while (!insered) {
      if (val < noeudParcouru->val) {
        if (noeudParcouru->fg != NULL) {
          noeudParcouru = noeudParcouru->fg;
        } else {
          struct noeud *nouv = (struct noeud*) malloc (sizeof(struct noeud));
          nouv->val = val;
          noeudParcouru->fg = nouv;
          insered = true;
        }
      } else {
        if (noeudParcouru->fd != NULL) {
          noeudParcouru = noeudParcouru->fd;
        } else {
          struct noeud *nouv = (struct noeud*) malloc (sizeof(struct noeud));
          nouv->val = val;
          noeudParcouru->fd = nouv;
          insered = true;
        }
      }
    }
  }
}

// Méthode créant un arbre binaire de recherche à partir d'un tableau donné
struct noeud* creeABR(int *tab, int taille) {
  struct noeud *racine = NULL;
  for(int i = 0; i < taille; i++) {
    insere(&racine, tab[i]);
  }

  return racine;
}

// Parcours en profondeur de l'arbre vers la gauche
void parcoursProfondeurGauche(struct noeud *r) {
  if (r != NULL) {
    printf("%d\n", r->val); // Print ici -> traitement préfixe
    parcoursProfondeurGauche(r->fg);
    // Print ici -> traitement infixe
    parcoursProfondeurGauche(r->fd);
    // Print ici -> traitement postfixe
  }
}

// Parcours en profondeur de l'arbre vers la droite
void parcoursProfondeurDroite(struct noeud *r) {
  if (r != NULL) {
    printf("%d\n", r->val); // Print ici -> traitement préfixe
    parcoursProfondeurDroite(r->fd);
    // Print ici -> traitement infixe
    parcoursProfondeurDroite(r->fg);
    // Print ici -> traitement postfixe
  }
}

// Enfile un maillon en queue
void enfile(struct maillon **queue, struct maillon **tete, struct noeud *val) {
  struct maillon *nouv = (struct maillon*) malloc(sizeof(struct maillon));
  nouv->val = val;
  nouv->suivant = NULL;

  if(*tete == NULL && *queue == NULL) {
    *tete = nouv;
    *queue = nouv;
  }
  else {
    (*queue)->suivant = nouv;
    *queue = nouv;
  }
}

// On défile en tete
struct noeud* defile(struct maillon **tete, struct maillon  **queue) {
  struct noeud *ptr;
  struct maillon *tmp;
  
  if (*tete != NULL && *queue != NULL) {
    ptr = (*tete)->val;
    
    if (*tete != *queue) {
      tmp = *tete;
      *tete = (*tete)->suivant;
      free(tmp);
      return ptr;
    } else {
      free(*tete);
      *tete = NULL;
      *queue = NULL;
      return ptr;
    }
  }
}

// Parcours en largeur de l'arbre en allant à gauche
void parcoursLargeurGauche(struct noeud *racine){
  struct maillon *queue = NULL;
  struct maillon *tete = NULL;
  enfile(&queue, &tete, racine);

  while (tete != NULL && queue != NULL) {
    struct noeud *ptr = defile(&tete, &queue);
    printf("%d\n", ptr->val);

    if(ptr->fg != NULL) {
      enfile(&queue, &tete, ptr->fg);
    }
    if(ptr->fd != NULL) {
      enfile(&queue, &tete, ptr->fd);
    }
  }
}

// Parcours en largeur de l'arbre en allant à gauche
void parcoursLargeurDroite(struct noeud *racine){
  struct maillon *queue = NULL;
  struct maillon *tete = NULL;
  enfile(&queue, &tete, racine);

  while (tete != NULL && queue != NULL) {
    struct noeud *ptr = defile(&tete, &queue);
    printf("%d\n", ptr->val);

    if(ptr->fd != NULL) {
      enfile(&queue, &tete, ptr->fd);
    }
    if(ptr->fg != NULL) {
      enfile(&queue, &tete, ptr->fg);
    }
  }
}

// Point d'entrée du programme
int main() {
  int tab[8] = { 1, 2, -10, 3, 80, 10, -4, -70 };

  // Création de l'ABR
  struct noeud *racine = creeABR(tab, 8);

  printf("Parcours profondeur gauche\n");
  parcoursProfondeurGauche(racine);

  printf("Parcours profondeur droitre\n");
  parcoursProfondeurDroite(racine);

  printf("Parcours largeur gauche\n");
  parcoursLargeurGauche(racine);

  printf("Parcours largeur droitre\n");
  parcoursLargeurDroite(racine);

  return 0;
}
