#include <stdio.h>
float mais20 ( float a)
{   float c;
    c = a * 1.2;
    return c;
}
int main()
{   float a, pF;
    printf ("Digite o preco que sofrera um aumento de 20%:\n");
    scanf ("%f", &a);
    pF= mais20 (a);
    printf ("O resultado do aumento de preço e: %0.2f\n", pF);
    return 0;
}