#include <stdio.h>

int main()
    {
        int N=0;
        int t[10];
        
        printf("Donnez la dimension du tableau : ");
        scanf("%d", &N);
        
        printf("Donnez les valeurs du tableau : \n");

        for (int i=0; i<N; i++)
        {
            scanf("%d", &t[i]);
        }
        
        int j=0;
        
        while ((t[j] == t[N-1-j]) && (j<(N/2)))
            {
                j+=1;
            }
            
        if (j == N/2)
            printf("C'est un palindrome.");
        else
            printf("Ce n'est pas un palindrome.");
        
        return 0;
    }