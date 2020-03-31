#include <stdio.h>
#include <stdbool.h>
#include "pile.h"

typedef pile_t jeu_t[3]; //jeu-t est un nouveau type tableau statiques de 3 pile_t

void initialiserJeu(int N, jeu_t tours){
    for(int i=0; i<3; i++){
        init_pile(&tours[i]);
    }
    for(int j=N; j>0; j--){
        empiler(&tours[0],j);
    }
}

void afficherJeu(jeu_t tours){
    for(int i=0; i<3; i++){
        printf("Tour %d = ", i);
        afficher_pile(&tours[i]);
        printf("\n");
    }
}

void deplacerAnneau(jeu_t tours, int depart, int arrivee){
    printf("\n");
    printf("Déplacemment du sommet de Tour %d (sa valeur = %d) vers Tour %d :\n",depart, sommet(&tours[depart]),arrivee);
    printf("\n");
    empiler(&tours[arrivee], sommet(&tours[depart])),
    depiler(&tours[depart]);
    afficherJeu(tours);
}

bool deplacementPossible(jeu_t tours, int depart, int arrivee){
    return ((!pile_vide(&tours[depart])) && (pile_vide(&tours[arrivee]) || sommet(&tours[depart]) < sommet(&tours[arrivee])));
}

void hanoiRec (int N, char tourDep, char tourAux, char tourArr){
    if(N==1){
        printf("\ndeplacer un anneau de la tour \%c vers la tour \%c.", tourDep, tourArr);
    }
    else{
        hanoiRec(N-1, tourDep, tourArr, tourAux);
        hanoiRec(1, tourDep, tourAux, tourArr);
        hanoiRec(N-1, tourAux ,tourDep ,tourArr);
    }
}

int main(void){
    int n=0;
    jeu_t tours;
    
    printf("n=");
    scanf("%d", &n);
    
    printf("\n");
    
    initialiserJeu(n, tours);
    afficherJeu(tours);
    
    deplacerAnneau(tours,0,1);
    
    printf("\n");
    
    printf(deplacementPossible(tours,2,1) ? "Déplacement possible\n" : "/!\\ Deplacement impossible\n");
    
    hanoiRec(n,'0','1','2');
    
    printf("\n");
    
}
