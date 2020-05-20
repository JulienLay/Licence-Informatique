#include <stdio.h>

void ajouter_carte(struct paquet_cartes *pc, struct carte c)
{
    pc->cartes[pc->nbre] = c;
    pc->nbre++;
}

struct carte retirer_carte(struct paquet_cartes *pc)
{
    struct carte c = pc->cartes[pc->nbre-1];
    pc->nbre--;
    return c;
};

int meilleure_carte(struct carte c1, struct carte c2)
{
    if (c1.valeur == c2.valeur)
        return 0;
    if (c1.valeur == 1 || (c1.valeur > c2.valeur && c2.valeur != 1))
        return 1;
    else
        return -1;
}

void distribuer_2joueurs(struct paquet_cartes *jeu, struct paquet_cartes *j1, struct paquet_cartes *j2)
{
    while (jeu->nbre > 0)
    {
        ajouter_carte(j1, retirer_carte(jeu));
        if (jeu->nbre > 0)
            ajouter_carte(j2, retirer_carte(jeu));
    }
}

int main(void)
{
    struct paquet_cartes jeu; /* jeu de cartes complet */
    struct paquet_cartes j1, j2; /* paquets des joueurs 1 et 2 */
    int pj1 = 0, pj2 = 0; /* points des joueurs 1 et 2 */

    initialiser_jeu(&jeu);
    melanger_jeu(&jeu);
    distribuer_2joueurs(&jeu, &j1, &j2);

    while (j1.nbre > 0 && j2.nbre > 0)
    {
        if (meilleure_carte(retirer_carte(&c1), retirer_carte(&c2)) == 1)
            pj1++;
        if (meilleure_carte(retirer_carte(&c1), retirer_carte(&c2)) == -1)
            pj2++;
     }

    if (pj1 == pj2)
        printf("Egalité");
    else if (pj1 > pj2)
        printf("Le joueur 1 gagne.");
    else
        printf("Le joueur 2 gagne.");
}
