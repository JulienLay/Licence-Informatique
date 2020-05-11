#include <stdio.h>
#define NBMAXETU 500
#define LGMAX 127

// Fonction déjà écrite dans l'énoncé
struct etudiant {
    int num_etu; /* numéro de l'étudiant */
    char nom[LGMAX+1];
    char prenom[LGMAX+1];
};

// Fonction déjà écrite dans l'énoncé
struct note {
    int num_etu; /* numéro de l'étudiant */
    float valeur; /* note sur 20 */
};

// Fonctions déjà écrites dans l'énoncé
void lire_classe(char *nom_fich, struct etudiant etudiants[], int *p_nb_etu){}
void lire_notes(char *nom_fich, struct note notes[], int *p_nb_notes){}

//Question 1
float note(int numero_etudiant, struct note notes[], int nb_notes)
{
    for (int i = 0; i < nb_notes; i++)
    {
        if (numero_etudiant == notes[i].num_etu)
        {
            return notes[i].valeur;
        }
    }

    return -1;
}

// Question 2
int numero(char *nom, char *prenom, struct etudiant etudiants[], int nb_etu, int *p_num_etu)
{
    for (int j = 0; j < nb_etu; j++)
    {
        if ((strcmp(etudiants[j].nom, *nom) == 0) && (strcmp(etudiants[j].prenom, *prenom) == 0))
        {
            p_num_etu = etudiants[j].num_etu;
            return 1;
        }
    }

    return 0;
}

// Question 3
void statistiques(struct note notes[], int nb_notes, float *p_min, float *p_max, float *p_moy)
{
    pmin = notes[0].valeur;
    pmax = notes[0].valeur;
    p_moy = 0;

    for (int n = 1; n < nb_notes; n++)
    {
        if (notes[n].valeur < pmin)
        {
            pmin = notes[n].valeur;
        }

        if (notes[n].valeur > pmax)
        {
            pmax = notes[n].valeur;
        }

        p_moy += notes[n].valeur;
    }

    p_moy /= nb_notes;
}

// Question 4
int main(void)
{
    struct etudiant etudiants[NBMAXETU];
    struct note notes[NBMAXETU];
    int nb_etu, nb_notes, numero_etudiant;
    float min, max, moy;
    char nom[LGMAX+1], prenom[LGMAX+1];

    lire_classe("l1.txt", etudiants, &nb_etu);
    lire_notes("notes_progc.txt", notes, &nb_notes);

    char c_nom, c_prenom;
    printf("Tapez un nom : ");
    scanf("%s", c_nom);
    printf("Tapez un prenom : ");
    scanf("%s", c_prenom);

    if (numero(&c_nom, &c_prenom, etudiants, nb_etu, &numero_etudiant) == 1)
    {
        float la_note = note(numero_etudiant, notes, nb_notes)
        printf("La note : %f", &la_note);
    }

    statistiques(notes, nb_notes, &min, &max, &moy);

    printf("Le minimum est : %f", &min);
    printf("Le maximum est : %f", &max);
    printf("La moyenne est : %f", &moy);

    return 0;
}
