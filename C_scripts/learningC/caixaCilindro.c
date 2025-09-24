#include <stdio.h>
#include <math.h>
float volCaixa(float a, float b, float c)
{
    return a*b*c;
}
float volCilindro (float r, float h)
{
    return 3.14*h*r*2;
}
int main ()
{   
    float a, b, c, r, h, vCaixa, vCilindro, volT;
    printf("Digite a altura, largura e comprimento da caixa:\n");
    scanf("%f%f%f", &a,&b,&c);
    vCaixa=volCaixa(a,b,c);
    printf ("Digite a altura e o raio do furo cilindro:\n");
    scanf ("%f%f", &r, &h);
    vCilindro=volCilindro(r,h);
    volT=vCaixa-vCilindro;
    printf("O volume total da caixa é: %0.2f", volT);
    return 0;
}