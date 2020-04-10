#include <stdio.h>

#define MAXTABLEAU 2
#define MAXSOURCE 255
#define MAXDESTINATION 255

void Remplacer(char Ch[], FILE *Source, FILE *Destination)
{
  int caractere;

  caractere = fgetc(Source);

  while(caractere != EOF)
  {
    if (caractere == Ch[0])
    {
      fputc(Ch[1],Destination);
    } else {
      fputc(caractere,Destination);
    }

    caractere = fgetc(Source);
  }
}

int main(void)
{
  FILE *Source, *Destination;
  char Ch[MAXTABLEAU], TabSource[MAXSOURCE], TabDestination[MAXDESTINATION];

  printf("Veuillez taper la chaîne de deux caractères décrivant le remplacement \
  (le premier est le caractère à remplacer et le second est le remplaçant) : ");

  scanf("%s", Ch);

  printf("Veuillez taper le nom du fichier source : ");
  scanf("%s", TabSource);

  Source = fopen(TabSource,"rt");

  if (Source == NULL)
  {
    perror("Le fichier n'existe pas dans le dossier courant actuel");
    return 1;
  }

  printf("Veuillez taper le nom du fichier destination : ");
  scanf("%s", TabDestination);

  Destination = fopen(TabDestination,"wt");

  Remplacer(Ch,Source,Destination);

  fclose(Source);
  fclose(Destination);

  return 0;
}
