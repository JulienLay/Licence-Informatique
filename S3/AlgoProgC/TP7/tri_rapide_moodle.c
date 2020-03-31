/**
 * \brief Tests sur les tris avec mesure du temps
 * \brief usage : nom_du_prog nom_du_fichier [limite] o� limite dit de ne consid�rer que les limite premiers nombres du fichier �r d�faut limite = 100
 *
 * \author Jean-Paul Bahsoun, Vincent Dugat, Pierre Piccinini
 * \date septembre 2016, septembre 2017
 */
#include "pile.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define TMAX 300000 // dimension maximale des tableaux

typedef int tableau[TMAX];

void echanger(int *a,int *b) // swap
{
    int aux=*a;
    *a=*b;
    *b=aux;
}

void afficher_tab( tableau t , int dim)
{
    int i;
    for (i=0;i<dim;i++)
        printf("%4d",t[i]);
    printf("\n");
}

/* remplit le tableau avec les dim entiers d'un fichier
 s'il n'y a pas assez d'entiers dans le fichier :  le programme stoppe
*/
void tab_fichier(tableau t,int dim, char *nom)
{
    int i;
    FILE * f_in;
    f_in = fopen(nom,"r") ;
    if (f_in == NULL)
        {  fprintf(stderr,"\n Erreur : Impossible d ouvrir le fichier %s\n",nom) ;    exit(EXIT_FAILURE) ;}
     for (i=0;i<dim;i++)
    {
       fscanf(f_in,"%d",&t[i]) ;
       if (feof(f_in))
         {printf("Erreur: Pas assez d'entiers dans le fichier %s\n",nom);  exit(EXIT_FAILURE);}
    }
     fclose(f_in);
}

// copie de dim �l�ments de T1 dans t2
void initCopieTab(tableau t1, tableau t2, int dim){
    int i;
    for(i=0;i<dim;i++) t2[i]=t1[i]; // copie pour un autre tri
    }

// fonctions et proc�dures de tri

/*renvoie un bool�en vrai ssi t[deb1,fin1]<=val*/
bool inf_eq(tableau t, int deb1, int fin1, int val)
{
  int i;
  for (i=deb1;i<=fin1;++i)
          if (t[i]>val)
              return false;
  return true;
}

/*renvoie un bool�en vrai ssi val<t[deb1,fin1]l*/
bool sup(tableau t, int deb1, int fin1, int val)
{
  int i;
  for (i=deb1;i<=fin1;++i)
         if (t[i]<=val)
              return false;
  return true;
}

int partitionnerInv (tableau T, int ind_premier, int ind_dernier)
{
  int ind_pivot = ind_premier ;
  int valPivot = T[ind_pivot];
  int j = ind_dernier ;
  // La zone T [ ind_pivot +1 , j ] est inconnue

  /*
  INV : T [ ind_premier , ind_pivot [ <= T [ ind_pivot ] < T [ j +1 , ind_dernier ] et
  ind_premier <= ind_pivot et ind_pivot <= j <= ind_dernier
  */
  //assert(T[ind_premier, ind_pivot[ <= T[ind_pivot] < T[j+1, ind_dernier]);
  //assert(ind_premier <= ind_pivot);
  //assert(ind_pivot <= j <= ind_dernier);

/*
T [ ind_premier , ind_pivot [ <= T [ ind_pivot ] < T ]j , ind_dernier ] , et ind_pivot <= j
  <= ind_dernier
*/
  //assert(T[ind_premier, ind_pivot[ <= T[ind_pivot] < T]j, ind_dernier]);
  //assert(ind_pivot <= j <= ind_dernier);
while (ind_pivot != j) {
/* T [ ind_premier , ind_pivot [ <= T [ ind_pivot ] < T ]j , ind_dernier ] et ind_pivot <j
<= ind_dernier */
  //assert(T[ind_premier, ind_pivot[ <= T[ind_pivot] < T]j, ind_dernier]);
  //assert(ind_pivot < j <= ind_dernier);
  if (T[ind_pivot] < T[ind_pivot]+1){
    echanger(&T[ind_pivot+1], &T[j]);
    j--;
  }

  else{
    echanger(&T[ind_pivot], &T[ind_pivot+1]);
    ind_pivot++;
  }

  /* T [ ind_premier , ind_pivot [ <= T [ ind_pivot ] < T ]j , ind_dernier ] */
  //assert(T[ind_premier, ind_pivot[ <= T[ind_pivot] < T]j, ind_dernier]);
}
/* T [ ind_premier , ind_pivot [ <= T [ ind_pivot ] < T ]j , ind_dernier ] et ind_pivot = j */
//assert(T[ind_premier, ind_pivot[ <= T[ind_pivot] < T]j, ind_dernier]);
//assert(ind_pivot=j);
return ind_pivot ;
}

/* E: tab tableau de N entiers
    0<=d<N  0<=f<N
 tri rapide
S:  slice tab[d,f] tri�
*/
void triRapide(tableau tab, int d, int f){
    int ind_pivot;
    if (d<f) {
        ind_pivot = partitionnerInv(tab, d, f);
        triRapide(tab, d, ind_pivot-1);
        triRapide(tab, ind_pivot+1, f);
    }
}

// tri bulle : nb de comparaisons de l'ordre de dim^2
void tri_bulle(tableau t,int dim)
{
	int i,j;
	for (i=0;i<dim;i++)
		for(j=i+1;j<dim;j++)
			if (t[i]>t[j])
                                echanger(&t[i],&t[j]);
}


// =================== MAIN =================
/* 2 arguments:     le nom du fichier ,   le nombre d'entiers du fichier trait�s*/

void quickSortIterative(int arr[], int deb, int fin)
{
  pile_t maPile;
  init_pile(&maPile);
  empiler(&maPile, deb);
  empiler(&maPile, fin);

  while (!pile_vide(&maPile)){
    fin = sommet(&maPile);
    depiler(&maPile);
    deb = sommet(&maPile);
    depiler(&maPile);
    int p = partitionnerInv(arr, deb, fin);

    if(p-1>deb){
      empiler(&maPile, deb);
      empiler(&maPile, p-1);
    }

    if(p+1<fin){
      empiler(&maPile, p+1);
      empiler(&maPile, fin);
    }
  }
}

void fusionner(int T[], int p1, int d1, int p2, int d2, int M[]){
  // p1 : indice debut 1ere partie
  // p2 : indice fin 1ere partie
  // p2=d1+1 indice debut 2eme partie
  // d2 : indice din 2eme partie
  // M ; tableau auxiliaire

  int i=p1;
  int j=p2;
  int k=p1;

  while(i<d1+1 && j<d2+1){
    if (T[i]<=T[j]){
      M[k]=T[i];
      i++;
      k++;
    }

    else{
      M[k]=T[j];
      j++;
      k++;
    }

  }

  if(i<d1+1){
    while(i<d1+1){
      M[k]=T[i];
      i++;
      k++;
    }
  }

  if(j<d2+1){
    while(j<d2+1){
      M[k]=T[j];
      j++;
      k++;
    }
  }

  for(int k=p1;k<d2+1;k++){
    T[k]=M[k];
  }
}

void TriFusion(int T[], int prem, int der, int M[]){
  int milieu;
  if(prem<der){
    milieu = (prem+der)/2;
    TriFusion(T, prem, milieu, M);
    TriFusion(T, milieu+1, der, M);
    fusionner(T, prem, milieu, milieu+1, der, M);
  }
}

int main(int argc,char **argv)
{
    int dim;
    tableau t,t2,M;
    clock_t now,end; // d�claration de timers
    switch (argc)
       {
           case 1: printf("Usage : commande fichier [dim]\n");return 1;break;
        case 2: dim=100;break;
        case 3: dim=atoi(argv[2]);break;
        default: printf("Erreur ligne de commande: trop d'arguments\n");return 1;break;
       }
    printf("Dim=%d TMAX=%d\n",dim,TMAX);
    tab_fichier(t,dim, argv[1]); // on lit les donn�es dans le 2�me param�tre de la ligne de commande
    //printf("tab 1:");ecriture_tab(t,dim);

    initCopieTab(t,t2,dim); // les tris se feront toujours sur t2 qui sera r�initialis� � chaque fois

    printf("Tri bulles\n");
    now = clock(); // d�part chrono
    tri_bulle(t2,dim);
    end=clock();
    printf("\nTemps CPU : %.2f secondes \n\n",(double) (end-now)/CLOCKS_PER_SEC); // fin chrono
    //printf("tab 1 trie' ");afficher_tab(t2,dim); // pour v�rifier sur un petit vecteur
    printf("-------------------------------\n");

    initCopieTab(t,t2,dim); // r�initialisation de t2

    printf("Tri rapide r�cursif\n");
    now = clock(); // d�part chrono
    triRapide(t2,0,dim-1);
    end =clock();
    printf("\nTemps CPU : %.2f secondes mais l'avez-vous ajoute' ? \n\n",(double) (end - now) / CLOCKS_PER_SEC); // fin chrono
   //printf("tab 1 trie' ");afficher_tab(t2,dim); // pour v�rifier sur un petit vecteur
    printf("-------------------------------\n");

    initCopieTab(t,t2,dim); // r�initialisation de t2

    // M�me principe pour le tri fusion
    printf("Tri quickSortIterative\n");
    now = clock(); // d�part chrono
    quickSortIterative(t2,0,dim-1);
    end =clock();
    printf("\nTemps CPU : %.2f secondes mais l'avez-vous ajoute' ? \n\n",(double) (end - now) / CLOCKS_PER_SEC); // fin chrono
    //printf("tab 1 trie' ");afficher_tab(t2,dim); // pour v�rifier sur un petit vecteur
    printf("-------------------------------\n");

    initCopieTab(t,t2,dim); // r�initialisation de t2
    initCopieTab(t,M,dim); // r�initialisation de t2

    // M�me principe pour le tri fusion
    printf("Tri fusion\n");
    now = clock(); // d�part chrono
    TriFusion(t2,0,dim-1,M);
    end =clock();
    printf("\nTemps CPU : %.2f secondes mais l'avez-vous ajoute' ? \n\n",(double) (end - now) / CLOCKS_PER_SEC); // fin chrono
    //printf("tab 1 trie' ");afficher_tab(t2,dim); // pour v�rifier sur un petit vecteur
    printf("-------------------------------\n");


    return 0;
}
