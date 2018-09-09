#include <stdio.h>
#include <stdlib.h>

struct noeud
{
    int val;
    struct noeud *filsGauche, *filsDroit;
};

struct maillon
{
    struct noeud *val;
    struct maillon *suivant;
};

void insere_abr(struct noeud **racine, int val); 
struct noeud *cree_abr(int *tab, int taille);
struct noeud *defile(struct maillon **tete, struct maillon **queue);

void main(void)
{

}

// Insère un seul élément dans l'arbre.
void insere_abr(struct noeud **racine, int val)
{
    int fini = 0;
    struct noeud *ptr, *ptr2;
    ptr = (struct noeud *)malloc(sizeof(struct noeud));
    ptr->val = val;
    ptr->filsGauche = NULL;
    ptr->filsDroit = NULL;
    if (*racine == NULL) {
        *racine = ptr;
    } else {
        ptr2 = *racine;
        while (!fini) {
            if (ptr2->val > val) {
                if (ptr2->filsGauche == NULL) {
                    ptr2->filsGauche = ptr;
                    fini = 1;
                } else {
                    ptr2 = ptr2->filsGauche;
                }
            } else {
                if (ptr2->filsDroit == NULL) {
                    ptr2->filsDroit = ptr;
                    fini = 1;
                } else {
                    ptr2 = ptr2->filsDroit;
                }
            }
        }
    }
}

struct noeud *cree_abr(int *tab, int taille)
{
    struct noeud *racine = NULL;
    int i;
    for (i = 0; i < taille; i++) {
        insere(&racine, tab[i]);
    }
    return racine;
}

struct noeud *defile(struct maillon **tete, struct maillon **queue)
{
    struct noeud *val, *tmp;
    if (*tete != NULL && *queue != NULL) {
        if (*tete != *queue) {
            val = (*tete)->val;
            tmp = *tete;
            *tete = (*tete)->suivant;
            free(tmp);
            return val;
        } else {
            val = (*tete)->val;
            free(*tete);
            *tete = NULL;
            *queue = NULL;
            return val;
        }
    }
}