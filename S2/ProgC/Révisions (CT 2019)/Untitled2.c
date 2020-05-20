#include <stdio.h>

float note(int numero_etudiant, struct note notes[], int nb_notes)
{
    for(int i=0; i < nb_notes; i++)
    {
        if (notes[i].num_etu == numero_etudiant)
        {
            return notes[i].valeur;
        }
    }
    return -1;
}

int numero(char *nom, char *prenom, struct etudiant etudiants[], int nb_etu, int *p_num_etu)
{
    for(int i=0; i < nb_etu; i++)
    {
        if (!strcmp(etudiants[i].nom, nom) && !strcmp(etudiants[i].prenom, prenom))
        {
            *p_num_etu = etudiants[i].num_etu;
            return 1;
        }
    }
    return 0;
}

void statistiques(struct note notes[], int nb_notes, float *p_min, float *p_max, float *p_moy)
{
    *p_min = notes[0].valeur;
    *p_max = notes[0].valeur;
    *p_moy = notes[0].valeur;

    for(int i=1; i < nb_notes; i++)
    {
        if (*p_min < notes[i].valeur)
        {
            *p_min = notes[i].valeur;
        }
        if (*p_max > notes[i].valeur)
        {
            *p_max = notes[i].valeur;
        }

        *p_moy += notes[i].valeur;
    }
    *p_moy/=nb_notes;
}

int main(void)
{
    struct etudiant etudiants[NBMAXETU];
    struct note notes[NBMAXETU];
    int nb_etu, nb_notes, numero_etudiant;
    float min, max, moy;
    char nom[LGMAX+1], prenom[LGMAX+1];

    lire_classe("l1.txt", etudiants, &nb_etu);
    lire_notes("notes_progc.txt", notes, &nb_notes);
    printf("Nom : "); scanf("%s", nom);
    printf("Prénom : "); scanf("%s", prenom);
    numero(nom, prenom, etudiants, nb_etu, &numero_etudiant);
    printf("Note = %f\n", note(numero_etudiant, notes, nb_notes));
    statisques(notes, nb_notes, &min, &max, &moy);
    printf("min = %f, max = %f, moy = %f\n", min, max, moy);
}
