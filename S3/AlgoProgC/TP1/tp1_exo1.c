#include <stdio.h>

float puissit(float X, int N)
{
    int i=0;
    float res=1;
    
    for (i=0; i<N; i++)
        {
            res =res*X;
        }
    return res;
}

float puissrec(float X, int N)
{
    if (N == 0)
        return 1;
    else
        return X*puissrec(X,N-1);
}

int main()
{
    printf("%f\n",puissit(2,3));
    printf("%f\n",puissrec(2,3));
    return 0;
}