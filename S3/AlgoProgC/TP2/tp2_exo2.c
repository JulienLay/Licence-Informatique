#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Tab
    {
        int* tab; //tableau dynamique
        int n; //nombre de valeurs
    };

int main(void)
    {
        struct Tab T;
        
        printf("Valeur de n :");
        scanf("%d", &T.n);
        int* T.tab=malloc(T.n*sizeof(int));
        for (int i = 0; i < T.n; i++) 
            {
                T.tab[i]=rand()%101;
                printf("%d", T[i]);
            }
        
        //partie corigée par le prof au tableau 
        
        int i=0;
        while (i<T.n)
            {
                if (T.tab[i]%7==0)
                    t7.tab[j]=T.tab[i];
                    j++;
                    T.tab[i] = T.tab[T.n-1];
                    t.n--;
            }
        
        return 0;
    }
