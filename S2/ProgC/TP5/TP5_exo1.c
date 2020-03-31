#include <stdio.h>
#define Elem 10

/*
Affichage tous les entiers d’un tableau sur la même ligne, avec un espace entre chaque entier (et un retour à la ligne après l’affichage).
* Tab : tableau de int.
* NbElt : nombre d'éléments du tableau Tab.
*/
void AfficherTab(int Tab[], int NbElt)
{
  for (int i = 0; i < Elem; i++)
  {
    if (Tab[i] > 0)
    {
      printf("%d ", Tab[i]);
    }
  }

  printf("\n");
}

/*
Retourne le plus petit élément d’un tableau d’entiers.
* Tab : tableau de int.
* NbElt : nombre d'éléments du tableau Tab.
*/
int Min(int Tab[], int NbElt)
{
  int min = Tab[0];

  for (int i = 1; i < Elem; i++)
  {
    if (Tab[i] < min)
    {
      min = Tab[i];
    }
  }

  return min;
}

/*
Retourne le plus grand élément d’un tableau d’entiers.
* Tab : tableau de int.
* NbElt : nombre d'éléments du tableau Ta.
*/
int Max(int Tab[], int NbElt)
{
  int max = Tab[0];

  for (int i = 1; i < Elem; i++)
  {
    if (Tab[i] > max)
    {
      max = Tab[i];
    }
  }

  return max;
}

/* Retourne le plus petit et le plus grand élément d’un tableau d’entiers.
* Tab : tableau de int.
* NbElt : nombre d'éléments du tableau Tab.
* pMin : adresse où doit être stocké le plus petit élément.
* pMax : adresse où doit être stocké le plus grand élément.
*/

void MinMax(int Tab[], int NbElt, int *pMin, int *pMax)
{
  *pMin = Tab[0];
  *pMax = Tab[0];

  for (int i = 1; i < Elem; i++)
  {
    if (Tab[i] < *pMin)
    {
      *pMin = Tab[i];
    }

    if (Tab[i] > *pMax)
    {
      *pMax = Tab[i];
    }
  }

  printf("Le minimum du tableau est : %d et le maximum du tableau est : %d.\n", *pMin, *pMax);
}

/*
Supprime toutes les occurrences d’une valeur dans un tableau d’entiers. Le nombre de suppressions est retourné par la fonction et le nombre d’éléments du tableau est mis à jour.
* Tab : tableau de int.
* pNbElt : adresse pointant vers le nombre d'éléments du tableau.
* Val : valeur à supprimer.
*/
int* Supprimerval(int* tableau, int* taille, int Val)
{
    int i, a = 0, b;
    for (i = 0; i < *taille; i++)
    {
        if (tableau[i] != Val)
        {
            a++;
        }
    }
    int taille1 = a;
    int* tableau2 = malloc(sizeof(int) * taille1);
    int c = 0;
    for (b = 0; b < *taille; b++)
    {
        if (tableau[b] != Val)
        {
            tableau2[c] = tableau[b];
            c++;
        }
    }
    *taille = a;
    return tableau2;
}


int main(void)
{
  // Création du tableau Tab de taille Elem (= 10).
  int Tab[Elem] = {-1,2,-2,3,6,12,-1,-1,-1,-1};

  // Affichage du tableau Tab
  printf("Eléments du tableau supérieurs à 0 : ");
  AfficherTab(Tab, Elem);

  // Affichage du minimum du tableau Tab.
  int minimum = Min(Tab, Elem);
  printf("Le minimum du tableau est : %d.\n", minimum);

  // Affichage du maximum du tableau Tab.
  int maximum = Max(Tab, Elem);
  printf("Le maximum du tableau est : %d.\n", maximum);

  // Affichage du minimum et du maximum du tableau Tab avec usage de pointeur.
  int Min, Max;
  MinMax(Tab, Elem, &Min, &Max);

  // Supprime toutes les occurrences d’une valeur dans un tableau d’entiers. Le nombre de suppressions est retourné par la fonction et le nombre d’éléments du tableau est mis à jour.(Affichage du tableau ensuite pour vérification)
  int taille = sizeof(tableau) / sizeof(int);
    int* tableau2 = Supprimerval(tableau, &taille, 5);
    for (int i = 0; i < taille; i++)
    {
        printf("%d ", tableau2[i]);
    }

    free(tableau2);

  return 0;
}
