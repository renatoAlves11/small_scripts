#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define num 5
void createArray(int A[])
{
    for(int i=0; i<num; i++)
        for (int j=0; j<num; j++)
            if(A[i]==A[j])
            A[i]= rand () % 6;
}
void printaArray (int A[])
{
    for (int i=0; i<num; i++)
        printf("%i=A[%d]\n", A[i],i);
}
void troca (int A[], int x, int y)
{
    int aux;
    aux=A[x];
    A[x]=A[y];
    A[y]=aux;
}
void quick(int A[], int inicio, int fim)
{
    if((fim-inicio)<2){
        if ((fim-inicio)==1)
            if(A[inicio]<A[fim])
                troca(A,inicio,fim);
    }       
    else{
    int i=inicio,j=fim,chave=A[inicio];
    while (i<j)
    {
        i++;
    while(chave<A[i])
    {
        i++;
    }
    while (chave>A[j])
    {
        j--;
    }
    if (i<j)
    {
        troca(A,i,j);
    }
    }
    troca(A,inicio,j);
    quick(A,inicio,j-1);
    quick(A,j+1,fim);
    }
}
int buscabi(int A[], int n, int inicio, int fim)
{
    int meio=(inicio+fim)/2;
    if (A[meio]==A[inicio] && A[meio]==A[fim] && A[meio]!=n)
        return -1;
    if (n==A[meio])
        return n;
    else if (n<A[meio])
        buscabi(A,n,meio+1,fim);
    else if(n>A[meio])
        buscabi(A,n,inicio,meio-1);
}
int main ()
{
    srand(time(0));
    int A[num];
    int roleta, resultado;
    do
    {
        printf("Digite valor entre 0 e 6\n");
        scanf("%d", &roleta);
    }
    while (roleta<0 || roleta>6);
    createArray(A);
    printf("Array original:\n");
    printaArray(A);
    quick(A, 0, num-1);
    printf("Array ordenado:\n");
    printaArray(A);
    resultado=buscabi(A, roleta, 0, num);
    if(resultado==-1)
        printf("Você morreu");
    else
        printf("Você ainda está vivo");
    return 0;
}
//quick -> recursão