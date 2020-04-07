#include <stdio.h>
#include <string.h>

#define LONGUEURMAX 63

// size_t strlen(const char *Ch)
// La fonction strlen retourne le nombre de caractères
// de la chaîne représentée par Ch,
// caractère ’\0’ non compris.

//int strcmp(const char *Ch1, const char *Ch2)
//La fonction strcmp retourne :
//◦ 0 si les deux chaînes sont identiques ;
//◦ un entier positif si la chaîne représentée par Ch1
// est supérieure à la chaîne représentée par Ch2 selon l’ordre lexicographique;
//◦ un entier négatif si la chaîne représentée par Ch1
// est inférieure à la chaîne représentée par Ch2 selon l’ordre lexicographique.

typedef struct sStats
{
  int NbMots;
  float LongMoy;
}tStats;

void Statistiques(FILE *f, tStats *pStats)
{
  char ch[LONGUEURMAX];

  f = fopen("texte.txt","rt");

  fscanf(f,"%s",ch);
  pStats->NbMots = 1;
  pStats->LongMoy = strlen(ch);

  while(feof(f) == 0)
  {
    fscanf(f,"%s",ch);
    pStats->NbMots += 1;
    pStats->LongMoy += strlen(ch);
  }

  fclose(f);

  pStats->LongMoy /= (pStats->NbMots);

  printf("NbMots : %d\n", pStats->NbMots);
  printf("LongMoy : %f\n", pStats->LongMoy);
}

char *LireLigne(char Ch[], int LongueurMax, FILE *f)
{
  char Format[32]; /* Chaine qui va contenir le format passe a scanf */
  int Lu;

  /* Construction du format : %LongueurMax[^\n]
    %[^\n] signifie "tous les caracteres sauf \n"
    le gabarit permet de limiter la lecture a LongueurMax caracteres
  */
  sprintf(Format,"%%%d[^\n]",LongueurMax);

  /* Lecture de la ligne */
  Lu=fscanf(f,Format,Ch);
  if (Lu!=EOF) /* Si la fin du fichier n'a pas ete atteinte */
  {
    /* Vidage du tampon d'entree du fichier :
       - consommation de \n si la fin de la ligne a ete atteinte
       - consommation de la fin de la ligne jusqu'au \n si le nombre limite
         de caracteres a ete atteint
    */
    while (fgetc(f)!='\n')
      ;
    return Ch;
  }
  else
    return NULL;
}

int main(void)
{
  FILE *f;
  char ch[LONGUEURMAX];
  tStats testStats;

  printf("Veuillez taper le nom du fichier à traiter : ");
  f = LireLigne(ch, LONGUEURMAX, f);

  Statistiques(f,&testStats);

  return 0;
}
