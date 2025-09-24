#include <stdio.h>
#include <math.h>
int main()
{
    float a,b,c,delta,x1,x2;
printf ("Entre com os coeficientes da equacao do 2o grau\n");
scanf ("%f%f%f",&a,&b,&c);
delta = (b*b)-(4*a*c);
if (delta>0)
{
x1=(-b+sqrt(delta))/(2*a);
x2=(-b-sqrt(delta))/(2*a);
printf ("As raizes sao: %0.2f%0.2f\n", x1,x2);
}
if(delta==0)
{
    x1=-b/(2*a);
    printf ("A raiz e: %0.2f\n", x1);
    }
if(delta<0)
{
printf ("Resultado inexistente\n");
}
return 0;
}