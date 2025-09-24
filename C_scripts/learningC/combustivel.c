#include <stdio.h>
float calculaValor ( float a, float b)
{   float c;
    c= a * b;
    return c;
}
float main ()
{   float a, b, c;
    printf ("Qual o valor do litro de combustivel e a quantidade abastecida em litros respectivamente?\n");
    scanf ("%f%f", &a, &b);
    c= calculaValor(a, b);
    printf ("O valor a ser pago e: %0.2f\n", c);
    return 0;
}