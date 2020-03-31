#include <stdio.h>
#include <math.h>

int main(void) {
  double nbr;
  printf("Tapez un nombre réel : ");
  scanf("%lf",&nbr);
  nbr = sqrt(nbr);
  printf("Sa racine carré : %lf\n",nbr);
  return 0;
}
