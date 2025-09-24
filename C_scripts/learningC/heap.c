#include <stdio.h>
#include <stdlib.h>

void troca (int * x, int * y){
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}

void subir (int A[6], int i){
    int j = i/2;
    if (j>=0)
    if(A[i]>A[j]){
        troca(&A[i], &A[j]);
        subir(A,j);
    }
}

void descer (int A[], int i, int q){
    int d = 2*i+2;
    int e = 2*i+1;
    int maior = i;
    if(d < q && A[d]>A[i]){
        maior = d;
    }
    if(e < q && A[e]>A[maior]){
        maior = e;
    }
    if (maior != i){
        troca(&A[maior], &A[i]);
        descer(A, maior, q);
    }
}

void heap (int A[], int t){
    for(int i = (t/2); i>=0; i--)
    descer (A, i, t-1);
}

void heapsort (int A[], int n){
heap(A, n);
for(int i = n-1; i>=1; i--)
descer(A, 0, i-1);
}

int main(){
    int A[6]={6,3,9,2,15,5};
    heapsort (A, 6);
    for (int i = 0; i < 6; i++){
        printf("\n%d\n", A[i]);
    }
}