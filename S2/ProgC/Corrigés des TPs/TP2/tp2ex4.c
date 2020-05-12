#include <stdio.h>

int main(void)
{
  int NbEspaces,NbEtoiles,NbLignes,Compteur;

  printf("Tapez le nombre de lignes : ");
  scanf("%d",&NbLignes);

  NbEspaces=NbLignes-1;
  NbEtoiles=1;
  while (NbLignes>0)
  {
    for(Compteur=1;Compteur<=NbEspaces;Compteur++)
      printf(" ");
    for(Compteur=1;Compteur<=NbEtoiles;Compteur++)
      printf("*");
    printf("\n");
    NbLignes--;
    NbEspaces--;
    NbEtoiles+=2;
  }
  return 0;
}
