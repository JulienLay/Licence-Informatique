#include <stdio.h>
#define MAXCARTES 52

// Fonction déjà écrite dans l'énoncé
struct carte {
    char enseigne; /* 'P'=Pique, 'C'=Coeur, 'T'=Trèfle, 'K'=Carreau */
    int valeur; /* 1 à 13 avec 1=As, 11=Valet, 12=Dame, 13=Roi */
};

// Fonction déjà écrite dans l'énoncé
struct paquet_cartes
{
    int nbre; /* nombre de cartes du paquet */
    struct carte cartes[MAXCARTES]; /* les cartes du paquet */
};

// Fonctions déjà écrites dans l'énoncé
void initialiser_jeu(struct paquet_cartes *jc){}
void melanger_jeu(struct paquet_cartes *jc){}

// Question 1 (2 fonctions)
void ajouter_carte(struct paquet_cartes *pc, struct carte c)
{
    int i = (pc->nbre)-1;

    if (i < MAXCARTES)
    {
        pc->cartes[i] = c;
    }
}

// Question 1 (2 fonctions)
struct carte retirer_carte(struct paquet_cartes *pc)
{
    struct carte carte_a_retirer;

    if ((pc->nbre)-1 >= 1)
    {
        carte_a_retirer = pc->cartes[(pc->nbre)-1];
    }

    pc->cartes[(pc->nbre)-1] = ;

    return carte_a_retirer;
};

// Question 2
int meilleure_carte(struct carte c1, struct carte c2)
{
    if ((c1.valeur == 1 && c2.valeur != 1) || (c1.valeur > c2.valeur))
    {
        return 1;
    }

    if ((c2.valeur == 1 && c1.valeur != 1) || (c1.valeur < c2.valeur))
    {
        return -1;
    }

    else
    {
        return 0;
    }
}

// Question 3
void distribuer_2joueurs(struct paquet_cartes *jeu, struct paquet_cartes *j1, struct paquet_cartes *j2)
{
    int max_carte_jeu = jeu->nbre;

    while (max_carte_jeu != 0)
    {
        struct carte carte_du_jeu_j1 = retirer_carte(&jeu);
        ajouter_carte(&j1, carte_du_jeu_j1);

        struct carte carte_du_jeu_j2 = retirer_carte(&jeu);
        ajouter_carte(&j2, carte_du_jeu_j2);

        max_carte_jeu--;
    }
}

// Question 4
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
        struct carte carte_j1 = retirer_carte(&j1);
        struct carte carte_j2 = retirer_carte(&j2);

        if (meilleure_carte(carte_j1, carte_j2) == 1)
        {
            pj1 ++;
        }

        if (meilleure_carte(carte_j1, carte_j2) == -1)
        {
            pj2 ++;
        }
    }


    if (pj1 == pj2)
    {
            printf("Egalité !");
    }

    if (pj1 > pj2)
    {
            printf("Joueur 1 gagne !");
    }

    if (pj1 < pj2)
    {
            printf("Joueur 2 gagne !");
    }

    return 0;
}
