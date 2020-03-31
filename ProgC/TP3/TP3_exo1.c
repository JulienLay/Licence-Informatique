#include <stdio.h>

#define MAX_TAB 100

int main()
{
    int nbrVal;
    int tableau[MAX_TAB];
    float moyenne = 0;

    printf("Nombre de valeur(s) contenu dans le tableau (doit être inférieur ou égal à 100): ");
    scanf("%d", &nbrVal);

    if (nbrVal > 100)
    {
        printf("Veuillez taper une valeur inférieure ou égale à 100): ");
        scanf("%d", &nbrVal);
    }

    printf("Entrez les valeurs : \n");
    for(int i = 0; i < nbrVal; i++)
    {
        printf("Veuillez taper la %ième valeur : ", i+1);
        scanf("%d", &tableau[i]);
    }

    for(int i = 0; i < nbrVal; i++)
    {
        moyenne = moyenne + tableau[i];
    }

    moyenne = moyenne/nbrVal;
    printf("Moyenne = %.2f\n", moyenne);

    printf("La/Les valeur(s) au dessus de la moyenne est/sont : ");
    for(int i = 0; i < nbrVal; i++)
    {
        if (tableau[i] > moyenne)
        {
            printf("%d ", tableau[i]);
        }
    }

    printf("\n");

    return 0;
}
