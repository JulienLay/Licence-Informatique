#include <stdio.h>

#define LMAX 512
#define CMAX 512


int main(void)
{
  int NbLignes,NbColonnes,NivMax,i,j,l;
  unsigned char Im1[LMAX][CMAX],Im2[CMAX][LMAX];
  char Signature[3];

  /* Lecture de l'image */
  scanf("%2s",Signature);
  scanf("%d",&NbColonnes);
  scanf("%d",&NbLignes);
  scanf("%d",&NivMax);
  for(i=0;i<NbLignes;i++)
    for (j=0;j<NbColonnes;j++)
      scanf("%hhu",&Im1[i][j]);

  /* Rotation de l'image */
  for (i=0;i<NbLignes;i++)
  {
    l=NbColonnes-1;
    for (j=0;j<NbColonnes;j++)
    {
      Im2[l][i]=Im1[i][j];
      l--;
    }
  }
  
  /* Affichage du resultat */
  printf("%s\n%d %d\n%d\n",Signature,NbColonnes,NbLignes,NivMax);
  for (i=0;i<NbColonnes;i++)
  {
    for (j=0;j<NbLignes;j++)
      printf("%3d ",Im2[i][j]);
    printf("\n");
  }

  return 0;
}


