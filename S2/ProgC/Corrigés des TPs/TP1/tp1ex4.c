#include <stdio.h>
#include <math.h> /* Ne pas oublier de compiler avec l'option -lm */

int main(void)
{
  double x;

  printf("Tapez un reel : ");
  scanf("%lf",&x);
  printf("La racine carree de %f est %f.\n",x,sqrt(x));

  return 0;
}

