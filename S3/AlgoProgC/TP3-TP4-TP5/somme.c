/*
 * Somme d'entiers.
 */

#include <stdio.h>

#include "pile.h"

/**
 * Calcul de la somme de l'expression representée en
 * chaine de caractere, mode récursif.
 * @param p		Pointeur sur le caractère courant.
 * @param s		Nombre courant.
 * @return		Résultat de la somme.
 */
int somme_rec(char *p, int s) {
	if(*p == '\0')
		return s;
	else if(*p == '+')
		return s + somme_rec(p + 1, 0);
	else
		return somme_rec(p + 1, s * 10 + *p - '0');
}


/**
 * Calcul de la somme de l'expression representée en
 * chaine de caractere, mode itératif en utilisant une pile.
 * @param c		Pointeur sur le début de la chaîne de caractère.
 * @return		Résultat de la somme.
 */
int somme_iter(char *c) {
	
	int somme = 0;
    int reconstituerChiffre = 0;
    
    pile_t p;
    init_pile(&p);
    
    while(*c != '\0')
    {
        if(*c == '+' && !pile_vide(&p)){
            
            somme+=p.elts[p.tete];
            depiler(&p);
            reconstituerChiffre=0;
            
        } else if(*c == '+' && pile_vide(&p)){
            
            somme = 0;
            
        } else if(pile_vide(&p)) {
            
            empiler(&p, *c - '0');
            
        } else {
            
            reconstituerChiffre = p.elts[p.tete] * 10 + (*c - '0');
            depiler(&p);
            empiler(&p, reconstituerChiffre);
            
        }
        
        c++;
    }
    if(pile_vide(&p)){
        return 0;
    }
	
	return somme + p.elts[p.tete];
}

int main() {
	char ch[256];
	
	printf("Entrez une somme :\n");
	scanf("%s", ch);
	
	printf("Resultat recursif : %d\n", somme_rec(ch, 0));
	printf("Resultat itératif : %d\n", somme_iter(ch));
	
	return 0;
}
