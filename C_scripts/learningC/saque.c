#include <stdio.h>
int calculaCedulas (int t)
{   int ced;
    ced=0;
    while (t>=100)
    {   
        ced=ced+1;
        t=t-100;
    }
        while (t>=50)
    {
        ced=ced+1;
        t=t-50;
    }
    while (t>=20)
    {
        ced=ced+1;
        t=t-20;
    }
    while (t>=10)
    {
        ced=ced+1;
        t=t-10;
    }
    while (t>=5)
    {
        ced=ced+1;
        t=t-5;
    }
    while (t>=2)
    {
        ced=ced+1;
        t=t-2;
    }
    while (t>=1)
    {
        ced=ced+1;
        t=t-1;
    }
    return ced;
}
int main()
{   int t, ced;
    printf ("Digite a quantia total de dinheiro a ser sacado:\n");
    scanf ("%i", &t);
    ced = calculaCedulas (t);
    if (ced>=1)
    {
    printf("A quantidade total de cedulas a ser sacada é: %i cedulas\n", ced);
    }
    else
    {
        printf("Sem troco em moedas :(");
    }
    return 0;
}