#include <stdio.h>

#define MAX 80

int main(void)
{
  char Ligne[MAX+1], /* Tableau de caracteres contenant la ligne */
       c; /* Caractere courant */
  int i,j, /* Indices permettant de parcourir le tableau */
      Palindrome; /* Indicateur */

  /* Lecture de la Ligne */
  printf("Tapez une ligne de texte :\n");
  scanf("%c",&c); /* Lecture du premier caractere */
  i=0; /* Initialisation de l'indice du tableau */
  while (i<MAX && c!='\n') /* Tant qu'on n'est pas a la fin de la ligne */
  {
    Ligne[i]=c; /* Rangement du caractere courant dans le tableau */
    i++; /* Incrementation de l'indice du tableau */
    scanf("%c",&c); /* Lecture du caractere suivant */
  }
  Ligne[i]='\0'; /* Marqueur de fin de la chaine de caracteres */

  /* Affichage de la ligne de texte */
  printf("Vous avez saisi la ligne suivante :\n%s\n"
         "Elle contient %d caracteres.\n",Ligne,i);

  i--; /* Pour que i contienne l'indice du dernier caractere du tableau */

  /* Affichage de la chaine a l'envers */
  printf("Voici la ligne a l'envers :\n");
  for (j=i;j>=0;j--)
    printf("%c",Ligne[j]);
  printf("\n");

  /* Est-ce un palindrome ? */
  j=0; /* j va parcourir le tableau de gauche a droite, i de droite a gauche */
  Palindrome=1; /* A priori, c'est un palindrome */
  while (j<i && Palindrome) /* Tant que les indices ne se sont pas rejoints */
  {                         /* et que c'est un palindrome                   */
    /* On ignore les espaces */
    while (Ligne[j]==' ' && j<i)
      j++; /* j va de gauche a droite */
    while (Ligne[i]==' ' && j<i)
      i--; /* i va de droite a gauche */
    if (Ligne[j]!=Ligne[i])
      Palindrome=0; /* Ce n'est pas un palindrome */
    else /* Jusque la, c'est toujours un palindrome */
    {
      j++; /* Incrementation de j */
      i--; /* Decrementation de i */
    }
  }

  /* Affichage du resultat */
  if (Palindrome)
    printf("C'est un palindrome.\n");
  else
    printf("Ce n'est pas un palindrome.\n");

  return 0;
}
