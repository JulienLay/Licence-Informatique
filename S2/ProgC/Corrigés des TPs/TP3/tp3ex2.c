#include <stdio.h>
#include <math.h>

#define N 10 /* Ordre maximal */
#define EPS 1e-10 /* Precision pour la comparaison de deux doubles */

int main(void)
{
  double Mat[N][N];
  int i,j,n,Sym;

  /* Lecture de l'ordre de la matrice */
  printf("Ordre de la matrice : ");
  scanf("%d",&n);
  while (n<1 || n>N)
  {
    printf("Tapez un entier compris entre 1 et %d : ",N);
    scanf("%d",&n);
  }

  /* Lecture des elements de la matrice */
  for (i=0;i<n;i++)
  {
    printf("Ligne %d : ",i+1);
    for (j=0;j<n;j++)
      scanf("%lf",&Mat[i][j]);
  }

  /* Verification de la symetrie */
  Sym=1; /* A priori, elle est symetrique */
  for (i=0; i<n && Sym; i++)
    for (j=0; j<n && Sym; j++)
      if (fabs(Mat[i][j]-Mat[j][i])>=EPS)
        Sym=0;

  /* Affichage du resultat */
  if (Sym)
    printf("Cette matrice est symetrique.\n");
  else
    printf("Cette matrice n'est pas symetrique.\n");

  return 0;
}

