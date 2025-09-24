#include <stdio.h>
#include <math.h>

int calculaDelta (int, int, int);

int main (){
    int a, b, c, delta, x1, x2;
    printf("Vmos calcular raizes, dê coeficientes a b e c\n\n");
    scanf("%d%d%d", &a, &b, &c);
    delta = calculaDelta (a,b,c);
    if (delta < 0) printf("\nnão tem raíz\n");
    else {
    x1 = (-b+sqrt(delta))/(2*a);
    x2 = (-b-sqrt(delta))/(2*a);
    if (delta == 0) printf("Raiz: %d", x1);
    else printf("Raizes: %d e %d", x1, x2);
    }
}

int calculaDelta (int a,int b,int c){
    return (pow(b, 2) - (4 * a * c));
}