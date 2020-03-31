#include <stdio.h>

int main(void)
{
  int nombreLettresEtEspace=0,nombreVoyelles=0;
  char caractere;

  printf("Veuillez taper une chaine de caractère se terminant par le caractère '#' : ");
  scanf("%c", &caractere);

  while (caractere != '#')
  {
    if((caractere >= 'a' && caractere <= 'z') || caractere == ' ')
    {

      if(caractere == 'a' || caractere == 'e' || caractere == 'i' || caractere == 'o' || caractere == 'u' || caractere == 'y')
      {
        nombreVoyelles++;
      }


      nombreLettresEtEspace++;
      scanf("%c", &caractere);

    }else{
      printf("\n");
      printf("------------------");
      printf("\n\n");
      printf("Programme interrompu.\n");
      printf("La chaine de caractere doit uniquement contenir des lettres minuscules non accentuée ou un espace et doit se terminer par le caractère '#'.\n");
      //code ASCII d'un caractère : faire printf("%d\n", caractere);
      printf("Le caractere erroné est : '%c' et son code est : '%d'.\n", caractere, caractere);
      printf("\n");
      printf("------------------");
      printf("\n\n");
      return 0;
    }
  }

  printf("\n");
  printf("------------------");
  printf("\n\n");
  printf("Nombre de lettres et d'espace : %d | Nombre de voyelles : %d\n", nombreLettresEtEspace, nombreVoyelles);
  printf("\n");
  printf("------------------");
  printf("\n\n");

  return 0;
}
