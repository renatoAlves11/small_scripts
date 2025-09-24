#include <stdio.h>
#include <math.h>
float calcula_distancia(float x1, float y1, float x2, float y2)
{
    return sqrt(pow(x1-x2,2)+pow(y1-y2,2)); 
}
int main ()
{
    float x1,y1,x2,y2,x3,y3, d1, d2, d3, s;
    printf("Digite as cooredenadas do triangulo nessa ordem: (x1,y1); (x2,y2); (x3,y3)\n");
    scanf("%f%f%f%f%f%f", &x1, &y1, &x2, &y2, &x3, &y3);
    d1=calcula_distancia(x1,y1,x2,y2);
    d2=calcula_distancia(x1,y1,x3,y3);
    d3=calcula_distancia(x2,y2,x3,y3);
    s=d1+d2+d3;
    printf("O perimetro e: %0.02f", s);
    return 0;
}