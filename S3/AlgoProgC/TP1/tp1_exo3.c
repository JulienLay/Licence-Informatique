#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N_MAX 1000

struct Tab 
{
  int tab[N_MAX]; //tableau statique
  int n;          //Nombre de Valeurs
};

//on suppose v < N_MAX
struct Tab remplir(int v) 
{
  struct Tab mon_tableau;
	
  for (int i = 0; i < v; i++) 
  {
    mon_tableau.tab[i] = rand(); 
  }
  
  mon_tableau.n = v;
  return mon_tableau;
}

void modulo7(struct Tab x) 
{
  int r = 0; //compter le nombre de valeurs du tableau qui sont multiples de 7
  for(int i = 0; i < x.n; i++) 
  {
    if(x.tab[i] % 7 == 0) 
    {
      r+=1;
    }
  }
}

int main(void) 
{
  srand(time(NULL));
  struct Tab x;
  int v;

  printf("Donnez le nombre de valeur(s) du tableau : ");
  scanf("%d", &v);

  printf("Le tableau contient les valeurs : \n");
  x = remplir(v);

  for (int i = 0; i < x.n; i++) 
  {
    printf("%d\n", x.tab[i]);
  }

  return 0;
}