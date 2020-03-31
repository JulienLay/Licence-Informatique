#include <stdio.h>

#define LMAX 512
#define CMAX 512

void LireImage(unsigned char Im[LMAX][CMAX], int *pNbLignes, int *pNbColonnes)
{
  char charControle[3]; // SIGNATURE
  unsigned char MaxNvxGris;

  scanf("%2s", charControle); //oook
  scanf("%hhu", &MaxNvxGris); // ok

  for(int i = 0; i < *pNbLignes; i++)  //OK
  {
      for(int j = 0; j < *pNbColonnes; j++)
      {
          scanf("%hhu", &Im[i][j]);
          pNbColonnes++;
      }
      pNbLignes++;
  }

  printf("%d %d\n", *pNbColonnes, *pNbLignes); //ok
}

int main(void)
{
  unsigned char Im[LMAX][CMAX];
  int nbLigMax, nbColsMax;

  printf("LireImage : ");
  LireImage(Im, &nbLigMax, &nbColsMax);

  return 0;
}
