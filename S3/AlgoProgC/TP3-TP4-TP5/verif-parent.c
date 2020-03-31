/*
 * Vérification de parenthèses.
 */

#include <stdio.h>

#include "pile.h"

int main() {
	pile_t p;
	char c;
	
	init_pile(&p);
	
	scanf("%c", &c);
	while(c != '$') {

        if (c=='('){
            empiler(&p, 1);
        }
        if (c==')'){
            if (sommet(&p)=='('){
                depiler(&p);
            }
            
        }
        
        if (c=='['){
            empiler(&p, 1);
        }
        if (c==']'){
            if (sommet(&p)=='('){
                depiler(&p);
            }
            
        }
        
        if (c=='{'){
            empiler(&p, 1);
        }
        if (c=='}'){
            if (sommet(&p)=='('){
                depiler(&p);
            }
            
        }
        
        
		scanf("%c", &c);
	}

	return 0;
}
