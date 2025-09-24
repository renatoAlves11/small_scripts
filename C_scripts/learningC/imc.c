#include <stdio.h>
int main()
{ 
    float peso, altura, imc;
    printf ("Digite o peso e a altura\n");
    scanf("%f%f", &peso, &altura);
    if(peso<=0||altura<=0)
    {
    printf ("Peso ou altura inválidos\n");
    return 1;
    }
    imc=peso/(altura*altura);
    printf ("Seu imc é:%0.2f\n", imc);
    if (imc<18.5)
    {
    printf ("Faixa: Magreza\n");
    }   
    else
    if (imc<30)
    {   
    printf ("Faixa: Saudável\n");
    }
    else
{
    printf("Faixa: Sobrepeso\n");
}    
    return 0;
}