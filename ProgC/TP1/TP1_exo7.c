#include <stdio.h>
#include <math.h>

/* Explication:
Ne tient pas compte de la partie décimale
*/

int main(void) {
  unsigned char nbr;
  printf("Tapez un nombre : ");
  scanf("%hhu",&nbr);
  nbr *= nbr;
  printf("Ce nombre au carré est : %hhu\n",nbr);
  return 0;
}
