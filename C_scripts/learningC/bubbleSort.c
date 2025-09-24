#include <stdio.h>
int main()
{   
    int n,t,i,j;
    printf ("Quantos elementos?\n");
    scanf ("%d", &n);
    int a[n];
    printf ("Quais os elementos em ordem?\n");
    for (i=0;i<n;i++)
    {
        scanf ("%d", &a[i]);
    }
    for (i=0;i<n;i++)
    {
        for (j=0;j<n-i;j++)
        {
        if (a[j]>=a[j+1])
        {
            t=a[j];
            a[j]=a[j+1];
            a[j+1]=t;
        }}
    }
    for (i=0;i<n;i++)
    {
    printf ("%d\n", a[i]);
    }
    return 0;
    
}