#include <stdio.h>
#include <string.h>

#define LGMAXNOM 30
#define LGMAXPRENOM 20
#define LGMAXMAIL 254

/* Question 1 */
struct sContact
{
  char Nom[LGMAXNOM+1];
  char Prenom[LGMAXPRENOM+1];
  char Mail[LGMAXMAIL+1];
};

/* Question 2 */
void AfficherContact1(struct sContact Contact)  
{
  printf("%s\n%s\n%s\n",
         Contact.Nom,
         Contact.Prenom,
         Contact.Mail);
}  

/* Question 4 */
void AfficherContact2(const struct sContact *pContact)  
{
  printf("%s\n%s\n%s\n",
         pContact->Nom,
         pContact->Prenom,
         pContact->Mail);
}  

/* Question 6 */
void VidageTamponEntree(void)
{
  while (getchar()!='\n')
    ;
}

/* Question 7 */
void LireLigne(char Ch[], int LongueurMax)
{
  int Dernier;
  fgets(Ch,LongueurMax+1,stdin);
  Dernier=strlen(Ch)-1;
  if (Ch[Dernier]=='\n')
    Ch[Dernier]='\0';
  else
    VidageTamponEntree();
}
  
/* Question 8 */
void LireContact(struct sContact *pContact)
{  
  LireLigne(pContact->Nom,LGMAXNOM);
  LireLigne(pContact->Prenom,LGMAXPRENOM);
  LireLigne(pContact->Mail,LGMAXMAIL);
}

/* Questions 3, 5 et 9 */
int main(void)
{
  struct sContact Personne={"KARENA",
                            "Emma",
                            "emma.karena@legria.es"};
                           
  AfficherContact1(Personne);
  printf("Tapez les informations du contact (nom, prenom, adresse mail)"
         " sur 3 lignes :\n");
  LireContact(&Personne);
  AfficherContact2(&Personne);

  return 0;
}

