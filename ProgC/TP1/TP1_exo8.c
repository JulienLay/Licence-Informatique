#include <stdio.h>

int main(void) {
  int plusGrand, plusPetit, tab[5];

  for (int i=0; i<5; i++)
  { //mise à 0 de tous les éléments
    tab[i] = 0;
  }

  for (int j = 0; j < 5; j++)
  { //init tableau
    printf("Tapez un entier : ");
    scanf("%d",&tab[j]);
  }

  plusGrand = tab[0];
  plusPetit = tab[0];

  for (int k = 1; k < 5; k++)
  {
    if (tab[k] < plusPetit)
    {
      plusPetit = tab[k];
    }
    if (tab[k] > plusGrand)
    {
      plusGrand = tab[k];
    }
  }

  printf("Plus petit = %d Plus grand = %d\n",plusPetit, plusGrand );

  return 0;
}
