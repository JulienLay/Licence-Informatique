#include <stdio.h>

int main(void)
{
  unsigned char n,n2;

  printf("Tapez un entier : ");
  scanf("%hhu",&n);
  n2=n*n;
  printf("Le carre de %d est %d.\n",n,n2);

  return 0;
}

