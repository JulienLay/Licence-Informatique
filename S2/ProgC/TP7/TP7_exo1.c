#include <stdio.h>
#include <string.h>

#define MAXNOM 30
#define MAXPRENOM 24
#define MAXMAIL 254

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

struct sContact
{
  char Nom[MAXNOM];
  char Prenom[MAXPRENOM] ;
  char Mail[MAXMAIL];
};

void AfficherContact1(struct sContact Contact)
{
  printf("\n");
  printf("\n");
  printf("-------------------------------------------\n");
  printf("\n");
  printf("Test de AfficherContact1");
  printf("\n");
  printf("\n");
  printf("Nom : %s\n", Contact.Nom);
  printf("Prenom : %s\n", Contact.Prenom);
  printf("Mail : %s\n", Contact.Mail);
  printf("-------------------------------------------\n");
  printf("\n");
  printf("\n");
}

void AfficherContact2(const struct sContact *pContact)
{
  printf("\n");
  printf("\n");
  printf("-------------------------------------------\n");
  printf("\n");
  printf("Test de AfficherContact2 (passage d'adresse)");
  printf("\n");
  printf("\n");
  printf("Nom : %s\n", pContact->Nom); // ou (*pContact).Nom
  printf("Prenom : %s\n", pContact->Prenom); // ou (*pContact).Prenom
  printf("Mail : %s\n", pContact->Mail); // ou (*pContact).Mail
  printf("-------------------------------------------\n");
  printf("\n");
  printf("\n");
}

void VidageTamponEntree(void)
{
  printf("\n");
  printf("\n");
  printf("-------------------------------------------\n");
  printf("\n");
  printf("Test de VidageTamponEntree");
  printf("\n");
  printf("\n");
  printf("Vidage du buffer d'entrée :\n");
  printf("Veuillez appuyer sur la touche entrée :\n");
  while (getchar() != '\n');
  printf("Buffer d'entrée vide !\n");
  printf("-------------------------------------------\n");
  printf("\n");
  printf("\n");
}


void LireLigne(char Ch[], int LongueurMax)
{
  printf("\n");
  printf("\n");
  printf("-------------------------------------------\n");
  printf("\n");
  printf("Test de LireLigne\n\n");
  printf("Veuillez taper une chaine de caractère de %d caractère(s) au maximum : \n",LongueurMax);
  fgets(Ch,LongueurMax,stdin);

  for(int i=0;i < LongueurMax; i++)
  {
    if (Ch[i] == '\0')
    {
      Ch[i] = '\n';
    }
  }

  VidageTamponEntree();

  printf("-------------------------------------------\n");
  printf("\n");
  printf("\n");
}


void LireContact(struct sContact *pContact)
{
  printf("\n");
  printf("\n");
  printf("-------------------------------------------\n");
  printf("\n");
  printf("Test de LireContact");
  printf("\n");
  printf("\n");
  printf("Nom du contact : \n");
  scanf("%s", pContact->Nom);
  printf("Prenom du contact : \n");
  scanf("%s", pContact->Prenom);
  printf("Mail du contact : \n");
  scanf("%s", pContact->Mail);
  printf("-------------------------------------------\n");
  printf("\n");
  printf("\n");
}

int main(void)
{
  struct sContact Contact = {"Julien","Lay","julien-lay@outlook.fr"};

  AfficherContact1(Contact);
  AfficherContact2(&Contact);
  VidageTamponEntree();

  int LongueurMax = 6;
  char Ch[LongueurMax];
  LireLigne(Ch, LongueurMax);


  struct sContact ContactTest;
  LireContact(&ContactTest);
  AfficherContact1(ContactTest);
  AfficherContact2(&ContactTest);

  return 0;
}
