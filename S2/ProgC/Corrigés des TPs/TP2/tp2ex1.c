#include <stdio.h>

int main(void)
{
  int Annee;

  printf("Tapez une annee : ");
  scanf("%d",&Annee);
  if (((Annee%4==0)&&(Annee%100!=0))||(Annee%400==0))
    printf("%d est une annee bissextile.\n",Annee);
  else
    printf("%d n'est pas une annee bissextile.\n",Annee);

  return 0;
}
