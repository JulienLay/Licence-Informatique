#include <stdio.h>

int main(void)
{
  int Farenheit,Celsius;
 
  printf("Donnez la temperature en degres Farenheit : ");
  scanf("%d",&Farenheit);

  Celsius =(5*(Farenheit-32))/9;
  /* Attention, l'expression (5/9)*(Farenheit-32) vaut toujours 0 ! */
  
  printf("%d degres Farenheit = %d degres Celsius\n",Farenheit, Celsius);

  return(0);
}
