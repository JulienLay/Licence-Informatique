#include <stdio.h>
#include <string.h>

#define MAXNOM 30
#define MAXPRENOM 24
#define MAXMAIL 254

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

/*
void LireLigne(char Ch[], int LongueurMax)
{
  fgets();
}
*/

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

void AfficherRepertoire(struct sContact Repertoire[], int NbContacts)
{
  for(int i=0; i<NbContacts; i++)
  {
    AfficherContact2(&Repertoire[i]);
  }
}

void AjouterContact(struct sContact Repertoire[], int *pNbContacts)
{
  
}

int main(void)
{
  struct sContact Repertoire[3];
  struct sContact Contact1 = {"Julien","Lay","julien-lay@outlook.fr"};
  struct sContact Contact2 = {"Michel","Lol","michel-lol@outlook.fr"};
  struct sContact Contact3 = {"Jacques","Dood","jacques-dood@outlook.fr"};

  Repertoire[0] = Contact1;
  Repertoire[1] = Contact2;
  Repertoire[2] = Contact3;

  AfficherRepertoire(Repertoire, 2);

  return 0;
}
