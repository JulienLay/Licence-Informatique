#include <stdio.h>
#include <string.h>

#define LONGUEURMAX 63

// size_t strlen(const char *Ch)
// La fonction strlen retourne le nombre de caractères
// de la chaîne représentée par Ch,
// caractère ’\0’ non compris.

typedef struct sStats
{
  int NbMots;
  float LongMoy;
}tStats;

void Statistiques(FILE *f, tStats *pStats)
{
  char ch[LONGUEURMAX];

  pStats->NbMots = 0;
  pStats->LongMoy = 0.0;

  while(feof(f) == 0)
  {
    fscanf(f,"%s",ch);

    pStats->NbMots++;
    pStats->LongMoy += strlen(ch);
  }

  pStats->NbMots--;
  pStats->LongMoy -= strlen(ch);

  pStats->LongMoy /= (pStats->NbMots);

  printf("NbMots : %d\n", pStats->NbMots);
  printf("LongMoy : %f\n", pStats->LongMoy);
}

/* Lecture d'une ligne dans un fichier
 * Lit une ligne de texte dans le fichier d'identificateur f et la stocke
 * sous forme d'une chaine de caracteres terminee par \0 dans le tableau
 *  Ch dont la longueur doit etre superieure ou egale a LongueurMax+1
 * La lecture s'arrete :
 * - soit a la fin de la ligne (\n n'est pas stocke dans le tableau),
 * - soit quand LongueurMax caracteres ont ete lus.
 * Apres la lecture, le tampon d'entree est systematiquement vide.
 * La fonction retourne Ch ou NULL si la fin du fichier est atteinte.
 */
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
  scanf("%s", ch);

  f = fopen(ch,"rt");

  if (f == NULL)
  {
    perror("Le fichier n'existe pas dans le dossier courant actuel");
    return 1;
  }

  Statistiques(f,&testStats);

  fclose(f);

  return 0;
}
