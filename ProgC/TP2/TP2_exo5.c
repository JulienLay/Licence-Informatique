#include <stdio.h>

#define ENT_MAX 18

int main(void)
{
    int lignes, colonnes;

    printf("Tapez le nombre max de lignes de la table de multiplication : ");
    scanf("%d", &lignes);

    if (lignes < 0 || lignes > ENT_MAX)
    {
	    printf("Veuillez taper une valeur de nombre de colonnes entre 0 compris et 18 compris : ");
	    scanf("%d", &lignes);
    }

    printf("Tapez le nombre max de colonnes de la table de multiplication : ");
    scanf("%d", &colonnes);
    if (colonnes < 0 || colonnes > ENT_MAX)
    {
	    printf("Veuillez taper une valeur de nombre de colonnes entre 0 compris et 18 compris : ");
	    scanf("%d", &colonnes);
    }

    printf("\n");

    printf(" x  |");
    for(int i = 0; i < colonnes + 1; i++)
    {
        printf("%4d", i);
    }
    printf("\n");
    printf("-----");

    for(int v = 0; v< colonnes + 1; v++)
    {
      printf("----");
    }

    printf("\n");

    for(int w = 0; w < lignes + 1; w++)
    {
      if (w >= 10)
      {
        printf("%d  |", w);
      }
      else
      {
        printf(" %d  |", w);
      }

      for (int k = 0; k < colonnes + 1; k++)
      {
        printf("%4d", k*w);
      }

      printf("\n");
    }

    printf("\n");

    return 0;
}
