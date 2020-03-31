#include<stdio.h>

int main(void) {

  int tempFahrenheit, tempCelcius;
  printf("Tapez une température en degré Fahrenheit : ");
  scanf("%d",&tempFahrenheit);
  tempCelcius = (tempFahrenheit - 32)*5/9;
  printf("La temperature en celcius est de : %d°C\n",tempCelcius);
  return 0;
}
