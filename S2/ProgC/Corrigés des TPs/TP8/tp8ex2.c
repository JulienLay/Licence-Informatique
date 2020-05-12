#include <stdio.h>

#define LGMAXNOMFICHIER 255

#define ERREUROUVERTURESOURCE 1
#define ERREUROUVERTUREDESTINATION 2
#define OK 0

/* Lecture d'une ligne dans un fichier
 */
char *LireLigne(char Ch[], int LongueurMax, FILE *f)
{
  char Format[32];
  int Lu;
  
  sprintf(Format,"%%%d[^\n]",LongueurMax);
  Lu=fscanf(f,Format,Ch);
  if (Lu!=EOF)
  {
    while (fgetc(f)!='\n')
      ;
    return Ch;
  }
  else
    return NULL;
}

/* Recopie du contenu du fichier d'identificateur Source dans le fichier
 * d'identificateur Destination en remplacant toutes les occurrences de 
 * Ch[0] par Ch[1]
 */
void Remplacer(char Ch[], FILE *Source, FILE *Destination)
{
  char cs,cd;
  int c;
  
  cs=Ch[0];
  cd=Ch[1];
  c=fgetc(Source);
  while (c!=EOF)
  {
    if (c==cs) fputc(cd,Destination);
    else fputc(c,Destination);
    c=fgetc(Source);
  }  
}


int main(void)
{
  char NomFichierSource[LGMAXNOMFICHIER+1],
       NomFichierDestination[LGMAXNOMFICHIER+1],
       Ch[3];
  FILE *Source,*Destination;
  
  printf("Donnez la chaine qui decrit la transformation : ");
  LireLigne(Ch,2,stdin);

  printf("Donnez le nom du fichier source : ");
  LireLigne(NomFichierSource,LGMAXNOMFICHIER,stdin);
  Source=fopen(NomFichierSource,"rt");
  if (Source==NULL)
  {
    perror(NomFichierSource);
    return ERREUROUVERTURESOURCE;
  }
  
  printf("Donnez le nom du fichier destination : ");
  LireLigne(NomFichierDestination,LGMAXNOMFICHIER,stdin);
  Destination=fopen(NomFichierDestination,"wt");
  if (Destination==NULL)
  {
    perror(NomFichierDestination);
    fclose(Destination);
    return ERREUROUVERTUREDESTINATION;
  }  

  Remplacer(Ch,Source,Destination);
  
  fclose(Source);
  fclose(Destination);
  return OK;
}
