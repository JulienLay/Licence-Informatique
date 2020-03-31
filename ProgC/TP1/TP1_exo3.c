#include<stdio.h>

int main(void) {
  int nbr;
  printf("Tapez un nombre : ");
  scanf("%d",&nbr);
  nbr *= nbr;
  printf("Ce nombre au carré est : %d\n",nbr);
  return 0;
}
