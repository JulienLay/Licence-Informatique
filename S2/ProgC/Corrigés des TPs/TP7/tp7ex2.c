#include <stdio.h>
#include <string.h>

#define LGMAXNOM 30
#define LGMAXPRENOM 20
#define LGMAXMAIL 254
#define LGMAXREP 64

/**************
 * EXERCICE 1 *
 **************/

struct sContact
{
  char Nom[LGMAXNOM+1];
  char Prenom[LGMAXPRENOM+1];
  char Mail[LGMAXMAIL+1];
};

void AfficherContact1(struct sContact Contact)  
{
  printf("%s\n%s\n%s\n",
         Contact.Nom,
         Contact.Prenom,
         Contact.Mail);
}  
  
void AfficherContact2(const struct sContact *pContact)  
{
  printf("%s\n%s\n%s\n",
         pContact->Nom,
         pContact->Prenom,
         pContact->Mail);
}  

void VidageTamponEntree(void)
{
  while (getchar()!='\n')
    ;
}

void LireLigne(char Ch[], int LongueurMax)
{
  int Dernier;
  fgets(Ch,LongueurMax+1,stdin);
  Dernier=strlen(Ch)-1;
  if (Ch[Dernier]=='\n')
    Ch[Dernier]='\0'; /* suppression du \n mis par fgets */
  else
    VidageTamponEntree();
}
  
void LireContact(struct sContact *pContact)
{  
  LireLigne(pContact->Nom,LGMAXNOM);
  LireLigne(pContact->Prenom,LGMAXPRENOM);
  LireLigne(pContact->Mail,LGMAXMAIL);
}

/**************
 * EXERCICE 2 *
 **************/

/* Question 1 */
void AfficherRepertoire(struct sContact Repertoire[], int NbContacts)
{
  int i;

  printf("--------------------------------------------------------------\n");
  for (i=0;i<NbContacts;i++)
  {
    AfficherContact2(&(Repertoire[i]));
    printf("--------------------------------------------------------------\n");
 }
}

/* Question 3 */
void AjouterContact(struct sContact Repertoire[], int *pNbContacts)
{
  printf(
"Tapez les informations du contact (nom, prenom, adresse mail) sur 3 lignes :\n");
  LireContact(&(Repertoire[*pNbContacts]));
  (*pNbContacts)++;
}

/* Question 5 */
int Rechercher(char NomRecherche[],struct sContact Repertoire[], int NbContacts)
{
  int Ind=-1,i=0;
  
  while (i<NbContacts)
  {
    if (!strcmp(NomRecherche,Repertoire[i].Nom))
    {
      Ind=i;
      i=NbContacts;
    }
    else
      i++;
  }
  return Ind;
}

/* Question 6 */
void RechercherContact(struct sContact Repertoire[], int NbContacts)
{
  char NomRecherche[LGMAXNOM+1];
  int Ind;

  printf("Tapez le nom du contact : ");
  fflush(stdout);
  LireLigne(NomRecherche,LGMAXNOM);
  Ind=Rechercher(NomRecherche,Repertoire,NbContacts);
  if (Ind==-1)
    printf("%s n'est pas dans le repertoire.\n",NomRecherche);
  else
    AfficherContact2(&(Repertoire[Ind]));
}

/* Questions 2, 4 et 7 */
int main(void)
{
  struct sContact Repertoire[LGMAXREP]=
    {{"KARENA","Emma","emma.karena@legria.es"},
     {"DEUF","John","john.deuf@mayonnaise.fr"},
     {"MANVUSSA","Gerard","gerard.manvussa@etonnant.com"},
    };
  int NbContacts;
  
  NbContacts=3;
  AfficherRepertoire(Repertoire,NbContacts);
  AjouterContact(Repertoire,&NbContacts);
  AfficherRepertoire(Repertoire,NbContacts);
  RechercherContact(Repertoire,NbContacts);
    
  return 0;
}

