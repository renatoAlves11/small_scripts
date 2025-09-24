#include<stdio.h>
int exibe_tabuada (int n)
{
    int i=0;
    while (i<11)
    {
        printf ("%d * %d = %d\n", n, i, n*i);
        i=i+1;
    }
    
}
int main ()
{
    int i , n=1;
    i=0;
    while (i<10)
    {
    exibe_tabuada(n);
    i++;
    n++;
    }
    return 0;
}
