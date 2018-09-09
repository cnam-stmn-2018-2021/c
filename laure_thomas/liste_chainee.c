#include <stdlib.h>
#include <stdio.h>

struct maillon 
{
    int val;
    struct maillon *suivant;
};

void ajoute(struct maillon **tete, int val);
void listeTriee(struct maillon **tete, int val);

void main(void)
{

}

void listeTriee(struct maillon **tete, int val)
{
    if (*tete == NULL) {
        ajoute(*tete, val);
    } else {
        struct maillon *prec, *ptr, *nouv;
        prec = (struct maillon *)malloc(sizeof(struct maillon));
        ptr = (struct maillon *)malloc(sizeof(struct maillon));
        ptr = *tete;
        while (ptr != NULL) {
            if (ptr->val < val) {
                prec = ptr;
                ptr = ptr->suivant;
            } else {
                nouv = (struct maillon *)malloc(sizeof(struct maillon));
                nouv->suivant = ptr;
                prec->suivant = nouv;
            }
        }
    }
}

void ajoute(struct maillon **tete, int val)
{
    struct maillon *ptr;
    ptr = (struct maillon *)malloc(sizeof(struct maillon));
    ptr->suivant = *tete;
    ptr->val = val;
}