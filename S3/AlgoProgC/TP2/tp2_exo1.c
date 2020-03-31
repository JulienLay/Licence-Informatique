#include <stdio.h>
#include <stdlib.h>

int main(void)
    {
        int T[5]={1,2,3,4,5};
        int N=3;
        int* tab=malloc(5*N*sizeof(int));
        
        
        for (int i=0; i<5*N; i++)
            {
                tab[i]=T[i%5];
                printf("%d", tab[i]);
            }
            
        return 0;
    }
