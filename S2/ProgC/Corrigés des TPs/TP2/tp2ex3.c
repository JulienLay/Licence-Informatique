#include <stdio.h>

int main(void)
{
  int NbNotes,Compteur;
  float Note,Somme;

  printf("Calcul de la moyenne\n"
         "--------------------\n");
  /* Saisie du nombre de notes */
  printf("Tapez le nombre de notes : ");
  scanf("%d",&NbNotes);
  
  /* Calcul de la somme des notes */
  Somme=0.0;
  for (Compteur=1;Compteur<=NbNotes;Compteur++)
  {
    /* Saisie de la note courante */
    printf("Note %d : ",Compteur);
    scanf("%f",&Note);
    /* Boucle de re-saisie si la note n'est pas valide */
    while (Note<0.0 || Note>20.0)
    {
      printf("Erreur : une note doit être comprise entre 0 et 20 !\n");
      printf("Note %d : ",Compteur);
      scanf("%f",&Note);
    }
    /* Mise a jour de la somme */
    Somme=Somme+Note;
  }

  /* Affichage du resultat */
  printf("Moyenne des %d notes = %f.\n",NbNotes,Somme/NbNotes);

  return 0;
}