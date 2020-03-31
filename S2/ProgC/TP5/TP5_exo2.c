#include <stdio.h>

void convertir_seconde(int duree, int *pHeure, int *pMinute, int *pSeconde)
{
    *pHeure = duree / 60 / 60 % 24;
    *pMinute = duree / 60 % 60;
    *pSeconde = duree % 60;
}

void convertir_seconde_dans_tableau(int duree, int Tab[])
{
    Tab[0] = duree / 60 / 60 % 24;
    Tab[1] = duree / 60 % 60;
    Tab[2] = duree % 60;
}

void fonction_principale()
{
  int duree, heure = 0, minute = 0, seconde = 0;
  int Tab[3]={0,0,0};

  printf("Veuillez taper un temps en seconde : ");
  scanf("%d", &duree);

  // Fonction de conversion de secondes en heures, minutes, secondes
  convertir_seconde(duree, &heure, &minute, &seconde);
  printf("%d seconde(s) correspond à %d heure(s) %d minute(s) et %d seconde(s).", duree, heure, minute, seconde);
  printf("\n");

  // Fonction de conversion de secondes en heures, minutes, secondes avec affichage de tableau
  convertir_seconde_dans_tableau(duree, Tab);
  printf("%d seconde(s) dans un tableau : ", duree);
  for(int i = 0; i < 3; i++)
  {
    printf("%d ", Tab[i]);
  }
  printf("\n");
}

int main(void)
{
  fonction_principale();
  return 0;
}
