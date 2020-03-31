#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool estPalin(int T[],int d,int f){
  int i=0;
  while(T[d+i]==T[f-i] && i<=(f-d)/2){
    i++;
  }
  return(i>(f-d)/2);
}

int forceBrute(int T[],int N){
  int l=0;
  for(int i=0; i<N; i++){
    for(int j=i;j<N;j++){
      if (estPalin(T,i,j)){
        if(j-i+1>l){
          l=j-i+1;
        }
      }
    }
  }
  return l;
}

int dynamique(int* T,int N){

  int** D=malloc(N*sizeof(int*));

  for (int i=0;i<N;i++){
    D[i]=malloc(N*sizeof(int));
  }

  int l=0;

  //diagonale de la matrice
  for(int i=0;i<N;i++){
    D[i][i]=1;
  }

  //diagonale du dessus
  for(int i=0;i<N-1;i++){
    D[i][i+1]=(T[i]==T[i+1]);
  }

  //le reste
  for(int j=2;j<N;j++){
    for(int i=0;i<j-1;i++){
      D[i][j]=T[i]==T[j] && D[i+1][j-1];
        if(D[i][j] && j-i+1>l){
          l=j-i+1;
        }
    }
  }
  free(D);
  return l;
}

int Palindrom(int T[],int fin,int l){
  for(int i=0;i<l;i++){
    if(T[fin-l+i]!=T[fin-i]){
      return 0;
    }
  }
  return 1;
}

int plusLongPal(int* T,int N){
  int l=0;
  int i=0;

  for(int c=0;c<N;c++){

    //palindrome pair

    while(T[c-i]==T[c+1+i] && !(c-i<0) && !(c+1+i>N-1)){;
      if(((c+1+i)-(c-i)+1)>l){
        l=(c+1+i)-(c-i)+1;
      }
      i++;
    }

    i=0;

    //palindrome impair

    while(T[c-1-i]==T[c+1+i] && !(c-1-i<0) && !(c+1+i>N-1)){
      if(((c+1+i)-(c-1-i)+1)>l){
        l=(c+1+i)-(c-1-i)+1;
      }
      i++;
    }

    i=0;
  }

  return l;
}

int main(){
  int n=0;

  printf("\nTapez la longueur du tableau : ");

  scanf("%d", &n);

  int* T=malloc(n*sizeof(int));

  for(int i=0; i<n;i++){
    T[i]=(rand()%10);
  }

  printf("\nLe tableau : ");

  for(int i=0; i<n;i++){
    printf("%d ", T[i]);
  }

  printf("\n\n");

  printf("La longueur du palindrome avec forceBrute : %d\n", forceBrute(T,n));

  printf("\n");

  printf("La longueur du palindrome avec dynamique : %d\n", dynamique(T,n));

  printf("\n");

  printf("La longueur du palindrome avec O(N²) : %d\n", plusLongPal(T,n));
}
