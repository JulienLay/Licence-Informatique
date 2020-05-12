#include <stdio.h>

#define TAILLEMAX 100

int main(void)
{
  float Tab[TAILLEMAX],Somme,Moyenne;
  int i,NbValeurs;
  
  /* Lecture du nombre de valeurs */
  printf("Combien de valeurs allez-vous taper : ");
  scanf("%d",&NbValeurs);
  while (NbValeurs<1 || NbValeurs>TAILLEMAX)
  {
    printf("Tapez un entier compris entre 1 et %d : ",TAILLEMAX);
    scanf("%d",&NbValeurs);
  }

  /* Boucle de lecture des valeurs et de calcul de leur somme */
  Somme=0.0;
  for (i=0; i<TAILLEMAX && i<NbValeurs; i++)
  {
    printf("Donnez la valeur numero %d : ",i+1);
    fflush(stdout);
    scanf("%f",&Tab[i]);
    Somme+=Tab[i];
  }
  
  /* Calcul et affichage de la moyenne */
  Moyenne=Somme/NbValeurs;
  printf("La moyenne est egale a : %f\n",Moyenne);

  /* Affichage des valeurs superieures a la moyenne */
  printf("Valeurs superieures a la moyenne :\n");
  for (i=0;i<NbValeurs;i++)
    if (Tab[i]>Moyenne)
      printf("%f ",Tab[i]);
  printf("\n");

  return(0);
}
