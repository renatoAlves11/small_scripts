float CalculaSalarioLiquido(float SalarioBruto)
{
    float aliquota, parcelaDeduzir;
    if(SalarioBruto<=1903.98)
    {
        aliquota=0;
        parcelaDeduzir=0;
    }
    else if(SalarioBruto<=2826.65)
    {
        aliquota=0.075;
        parcelaDeduzir=142,80;
    }
    else if(SalarioBruto=3751.75)
    {
        aliquota=0.15;
        parcelaDeduzir=354.8;
    }
    else if(SalarioBruto)
    {
        aliquota=0.225;
        parcelaDeduzir=636.13;
    }
    else
    {
        aliquota=0.275;
        parcelaDeduzir=869.36;
    }

    return SalarioBruto - SalarioBruto * aliquota - parcelaDeduzir;
}
#include <stdio.h>
#include<math.h>
int main()
{
    float sb, sl;
    printf("Entre com seu salário bruto: ");
    scanf("%f", &sb);
    sl= CalculaSalarioLiquido(sb);// Copia sb para salário bruto.
    printf("Seu salário líquido é %0.2f\n", sl);
    return 0;
}