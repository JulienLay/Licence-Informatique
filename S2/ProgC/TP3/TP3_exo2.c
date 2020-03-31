#include <stdio.h>
#include <math.h>

#define ORDRE 10
#define PRECISION pow(10, -10)

int main()
{
    double tableau[ORDRE][ORDRE];
    int ordreUtil;
    printf("Entrez l'ordre de la matrice : ");
    scanf("%d", &ordreUtil);

    // INITIALISE LE TABLEAU
    for(int i = 0; i < ordreUtil; i++)
    {
        printf("Ligne %d: ", i+1);
        for(int j = 0; j < ordreUtil; j++)
        {
            scanf("%lf", &tableau[i][j]);
        }
    }

    // Cherche a savoir si la matrice est symétrique
    for(int i=0; i<ordreUtil; i++)
    {
        for(int j=0; i<ordreUtil; i++)
        {
            if(i != j)
            {
                if (tableau[i][j] != tableau[j][i] || fabs(tableau[i][j] - tableau[j][i]) >= PRECISION)
                {
                    printf("La matrice n'est pas symétrique :(\n");
                    return 0;
                }
            }
        }
    }

    printf("La matrice est symétrique :)\n");

    return 0;
}
