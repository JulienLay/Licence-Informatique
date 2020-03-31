#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <stdbool.h>
#include <assert.h>
#define NMAX 10000
typedef int tab[NMAX];

bool inf_eq(tab t, int deb1, int fin1, int val){
  int i;
  for (i=deb1;i<=fin1;++i)
          if (t[i]>val)
              return false;
  return true;
}

/* renvoie un booléen vrai ssi val<t[deb1,fin1] */
bool sup(tab t, int deb1, int fin1, int val){
  int i;
  for (i=deb1;i<=fin1;++i)
         if (t[i]<=val)
              return false;
  return true;
}

int f1(tab t, int N){
  int poids;
  int plusGrand=t[0];

  for(int deb=0;deb<N;deb++){
    for(int fin=deb;fin<N;fin++){
      poids=0;
      for(int i=deb;i<fin;i++){
        poids+=t[i];
      }

      if(poids>plusGrand){
        plusGrand=poids;
      }
    }
  }
  return plusGrand;
}

int f2(tab t, int N){
  int poids;
  int plusGrand=t[0];

  for(int deb=0;deb<N;deb++){
    poids=0;
    for(int fin=deb;fin<N;fin++){
      poids+=t[fin];
    }

    if(poids>plusGrand){
      plusGrand=poids;
    }
  }
  return plusGrand;
}

int f3(tab t, int N){

  assert(0<=N && N<=NMAX);/* P */
  tab res;
  int max=t[0];
  res[0]=t[0];
  int i=1;
  assert(g(t,i,max) && f2(t,i) && 0<=i && i<=N);/* Invariant */

  while(i!=N){
    assert(g(t,i,max) && f2(t,i) && 0<=i && i<=N);/* Invariant && condition de boucle */
    if(res[i-1]>0){
      res[i]=res[i-1]+t[i];
    }

    else{
      res[i]=t[i];
    }

    if(res[i]>max){
      max=res[i];
    }

    i++;
    assert(g(t,i,max) && f2(t,i) && 0<=i && i<=N);/* Invariant */
  }

  assert(g(t,i,max) && f2(t,i) && 0<=i && i==N)/* Invariant && !(condition de boucle */
  assert(i==N);/* Q */
  return max;
}

int main(){

  tab t;
  int n=0;
  clock_t now,end; // déclaration de timers

  printf("\nTaille du tableau : ");
  scanf("%d",&n);
  printf("\n");

  for(int i=0; i<n;i++){
    t[i]=(rand()%21-10);
  }

  printf("Affichage du tableau :\n");

  for(int i=0;i<n;i++){
    printf("%d ", t[i]);
  }

  printf("\n");

  now=clock();
  printf("\n==================\n\nnaive (N3)\npoids = %d\n",f1(t,n));
  end=clock();
  printf("\nTemps CPU : %.2f secondes \n\n",(double) (end-now)/CLOCKS_PER_SEC); // fin chrono
  //printf("tab 1 trie' ");afficher_tab(t2,dim); // pour v�rifier sur un petit vecteur

  now=clock();
  printf("\n==================\n\nnaive (N2)\npoids = %d\n",f2(t,n));
  end=clock();
  printf("\nTemps CPU : %.2f secondes \n\n",(double) (end-now)/CLOCKS_PER_SEC); // fin chrono
  //printf("tab 1 trie' ");afficher_tab(t2,dim); // pour v�rifier sur un petit vecteur

  now=clock();
  printf("\n==================\n\ndynamique (N)\npoids = %d\n",f3(t,n));
  end=clock();
  printf("\nTemps CPU : %.2f secondes \n\n",(double) (end-now)/CLOCKS_PER_SEC); // fin chrono
  //printf("tab 1 trie' ");afficher_tab(t2,dim); // pour v�rifier sur un petit vecteur

  return 0;
}
