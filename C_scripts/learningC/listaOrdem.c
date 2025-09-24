#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void selection(int A[])
{
    int inicio=0, fim=49, menor, aux;
    for(int i=0; i<49;i++)
    {
        menor=i;
    for (int j=i+1; j<50; j++)
    {
        if (A[menor]>A[j])
        menor=j;
    }
        aux=A[menor];
        A[menor]=A[i];
        A[i]=aux;
    }  //complexidade O(n^2)
}
void bubble(int A[])
{
    int aux;
    for (int i=0; i<50; i++)
    {
        for (int j=i+1; j<50; j++)
        {
            if (A[j]<A[i])
            {
                aux=A[j];
                A[j]=A[i];
                A[i]=aux;
            }
        }
    }
}  //complexidade O(n^2)
void insertion (int A[])
{
    int k, aux;
    for (int i=1; i<50; i++)
    {
        k=i-1;
        for (;k>=0;k--)
        {
            if (A[k]>=A[i])
            {
                aux=A[k];
                A[k]=A[i];
                A[i]=aux;
            }
        }

    }
} //complexidade O(n^2)

int main()
{
    srand (time(0));
    int A[50]={0};
    for (int i=0; i<50; i++)
    {
        A[i]= rand () %100;
    }
    selection(A);
    for (int i=0; i<50; i++)
    {
        printf("%d\n", A[i]);
    }
    bubble(A);
    for (int i=0; i<50; i++)
    {
        printf("%d\n", A[i]);
    }
    insertion(A);
    for (int i=0; i<50; i++)
    {
        printf("%d\n", A[i]);
    }
}