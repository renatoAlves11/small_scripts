#include <stdio.h>
int main ()
{
    int n=3, a=0;
    float nota=0,t, media;
    while (n!=-1)
    {
        scanf ("%f", &nota);
        t=nota+t;
        n--;
        a=a+1;
    }
    media = t/a;
    if (media >= 7)
    {
        printf ("Aprovado");
    }
    else if (media >= 3 && media <=7)
    {
        printf ("PF");
    }
    else 
    {
        printf ("Reprovado");
    }
    return 0;
}