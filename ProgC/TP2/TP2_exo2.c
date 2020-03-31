#include <stdio.h>
#define MAX_LETTRES 50
#define NB_VOYELLES 6

int main()
{
    char chaineCara[MAX_LETTRES];
    char voyelles[NB_VOYELLES] = {'a', 'e', 'i', 'o', 'u', 'y'};
    int nombreLettres, nombreVoyelles, i = 0;

    printf("Entrez une chaine de caractères : ");
    scanf("%s", chaineCara);

    while((chaineCara[i] != '#' ) && (i != MAX_LETTRES)){
        if (chaineCara[i] => 'z' && chaineCara[i] <= 'a')
        {
          printf("Le caractère tapé n'est pas une lettre minuscule non accentuée ou un espace.");
          printf("Le caractère erroné est : %c", chaineCara[i]);
          printf("Son code est : %d", chaineCara[i]);
          return 1;
        }

        printf("%c", chaineCara[i]);

        for(int j = 0; j < NB_VOYELLES; j++)
        {
            if (chaineCara[i] == voyelles[j])
            {
                nombreVoyelles ++;
            }
        }

        i++;
        nombreLettres ++;
    }
    printf("\n");

    printf("Nombre de lettres: %d Nombre de voyelles: %d\n", nombreLettres, nombreVoyelles);
    return 0;
}
