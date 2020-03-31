#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
    {
        int m1,m2;
        int N=,P=;
        
        int** m=malloc(N*sizeof(int*));
        int i=0;
        for(i=0; i<N; i++)
            {
                int* m[i]=malloc(P*sizeof(int)):
            }
            
        int i=0;j=0;s=0;
        
        for(i=0; i<n; i++)
        {
         for(j=0; j<n; j++)
            {
                    s = s + m1[i][j] * m2[j][i]
            }   
        }
        
        for(i=0; i<N; i++)
            {
                free(m[i]);
            }
        free(m);
        
        return 0;
    }
