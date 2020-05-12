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
    pc->cartes[pc->nbre] = c;
    pc->nbre++;
}

// Question 1 (2 fonctions)
struct carte retirer_carte(struct paquet_cartes *pc)
{
    struct carte c = pc->cartes[pc->nbre-1];
    pc->nbre--;
    return c;
};

// Question 2
int meilleure_carte(struct carte c1, struct carte c2)
{
    if (c1.valeur == c2.valeur)
    {
        return 0;
    }
    if (c1.valeur == 1 || (c1.valeur > c2.valeur && c2.valeur != 1))
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

// Question 3
void distribuer_2joueurs(struct paquet_cartes *jeu, struct paquet_cartes *j1, struct paquet_cartes *j2)
{
    while (jeu->nbre > 0)
    {
        ajouter_carte(j1, retirer_carte(jeu));

        if (jeu->nbre > 0)
        {
            ajouter_carte(j2, retirer_carte(jeu));
        }
    }
}

// Question 4
int main(void)
{
    struct paquet_cartes jeu; /* jeu de cartes complet */
    struct paquet_cartes j1, j2; /* paquets des joueurs 1 et 2 */
    int pj1 = 0, pj2 = 0; /* points des joueurs 1 et 2 */
    struct carte cj1, cj2;
    int res;

    initialiser_jeu(&jeu);
    melanger_jeu(&jeu);
    distribuer_2joueurs(&jeu, &j1, &j2);

    while (j1.nbre > 0 && j2.nbre > 0)
    {
        cj1 = retirer_carte(&j1);
        cj2 = retirer_carte(&j2);
        res = meilleure_carte(cj1, cj2);

        if (res == 1)
        {
            pj1++;
        }

        else
        {
                if (res == -1)
                {
                    pj2++;
                }
        }
    }


    if (pj1 == pj2)
    {
            printf("Egalité !");
    }

    if (pj1 > pj2)
    {
            printf("Le joueur 1 gagne !");
    }

    if (pj1 < pj2)
    {
            printf("Le joueur 2 gagne !");
    }

    return 0;
}
