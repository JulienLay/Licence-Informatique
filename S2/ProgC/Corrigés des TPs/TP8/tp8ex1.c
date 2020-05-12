#include <stdio.h>
#include <string.h>

#define LGMAXMOT 63
#define LGMAXNOMFICHIER 255

#define ERREUROUVERTURE 1
#define OK 0

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
  
  /* Construction du format : 
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

/* Definition de la structure contenant les statistiques */
struct sStats
{
  int NbMots;
  float LongMoy;
};

/* Definition du synonyme de la structure */
typedef struct sStats tStats;

/* Calcul des statistiques sur les mots contenus dans un fichier
 * d'identificateur f qui est ouvert en lecture par l'appelant
 */
void Statistiques(FILE *f, tStats *pStats)
{
  int NbMots,NbCaracteres;
  char Mot[LGMAXMOT+1];

  NbMots=0;
  NbCaracteres=0;
  fscanf(f,"%s",Mot);
  while (!feof(f))
  {
    NbMots++;
    NbCaracteres=NbCaracteres+strlen(Mot);
    fscanf(f,"%s",Mot);
  }
  pStats->NbMots=NbMots;
  pStats->LongMoy=((float)NbCaracteres)/NbMots;
}

/* Fonction principale
 */
int main(void)
{
  char NomFichier[LGMAXNOMFICHIER+1];
  FILE *f;
  tStats Stats;
  
  printf("Donnez le nom du fichier : ");
  LireLigne(NomFichier,LGMAXNOMFICHIER,stdin);
  f=fopen(NomFichier,"rt");
  if (f==NULL)
  {
    perror(NomFichier);
    return ERREUROUVERTURE;
  }
  Statistiques(f,&Stats);
  fclose(f);
  printf("Le fichier %s contient %d mots.\n"
         "Leur longueur moyenne est de %.1f caracteres.\n",
         NomFichier,Stats.NbMots,Stats.LongMoy);
  return OK;
}
