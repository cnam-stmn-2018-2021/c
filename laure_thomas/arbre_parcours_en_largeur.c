#include <stdlib.h>
#include <stdio.h>

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

int enfile(struct maillon **tete, struct maillon **queue, struct noeud *val);
struct noeud *defile(struct maillon **tete, struct maillon **queue);
void parcoursLg(struct noeud *n);

// FIFO
void main(void)
{

}

void parcoursLg(struct noeud *n)
{
    struct maillon *tete = NULL, *queue = NULL;
    struct noeud *ptr;
    enfiler(&tete, &queue, n);
    while (tete != NULL && queue != NULL) {
        ptr = defile(&tete, &queue);
        printf("%d\n", ptr->val);
        if (ptr->filsGauche != NULL) {
            enfile(&tete, &queue, ptr->filsGauche);
        }
        if (ptr->filsDroit != NULL) {
            enfile(&tete, &queue, ptr->filsDroit);
        }
    }
}

int enfile(struct maillon **tete, struct maillon **queue, struct noeud *val)
{
    struct maillon *ptr;
    ptr = (struct maillon *)malloc(sizeof(struct maillon));
    ptr->val = val->val;
    if (*tete == NULL && *queue == NULL) {
        *tete = ptr;
        *queue = ptr;
    } else if (*tete == NULL || *queue == NULL) {
        return -1;
    } else {
        (*queue)->suivant = ptr;
        *queue = ptr;
    }
    free(ptr); // Le free permet de libérer l'espace mémoire alloué pour éviter qu'à la fin du programme l'espace soit toujours utilisé.
    return 1;
}

struct noeud *defile(struct maillon **tete, struct maillon **queue)
{
    struct noeud *ptr, *tmp;
    if (*tete != NULL && *queue != NULL) {
        if (*tete != *queue) {
            ptr = (*tete)->val;
            tmp = *tete;
            *tete = (*tete)->suivant;
            free(tmp);
            return ptr;
        } else {
            ptr = (*tete)->val;
            free(*tete);
            *tete = NULL;
            *queue = NULL;
            return ptr;
        }
    }
}