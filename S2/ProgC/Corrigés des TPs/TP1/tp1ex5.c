#include <stdio.h>

int main(void)
{
  int a,b,aux;

  /* Lecture des valeurs */
  printf("Tapez la valeur entiere de a : ");
  scanf("%d",&a);
  printf("Tapez la valeur entiere de b : ");
  scanf("%d",&b);
  /* Permutation des valeurs en utilisant une variable intermediaire */
  aux=a;
  a=b;
  b=aux;
  /* Affichage des valeurs */
  printf("Apres permutation : a=%d et b=%d.\n",a,b);

  return 0;
}

