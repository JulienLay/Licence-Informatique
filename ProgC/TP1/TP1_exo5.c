#include<stdio.h>

int main(void) {
  int a, b, temp;
  printf("Tapez la première variable : ");
  scanf("%d",&a);
  printf("Tapez la seconde variable : ");
  scanf("%d",&b);
  temp = a;
  a = b;
  b = temp;
  printf("Premiere entree: %d  Deuxieme entree: %d\n",a ,b);
  return 0;
}
