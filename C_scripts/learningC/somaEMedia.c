#include <stdio.h>
int calcula_soma (int a, int b, int c)
{   
    return a+b+c;
}
int calcula_media (int a, int b, int c)
{
    int y;
    y=(a+b+c)/3;
    return printf ("(%i + %i + %i)/3 = %i\n", a,b,c,y);
}

int main()
{
    int a,b,c, x, y;
    printf ("Digite três numeros:\n");
    scanf ("%i%i%i", &a, &b, &c);
    x= calcula_soma (a,b,c);
    printf ("%i + %i + %i = %i\n", a, b, c, x );
    y= calcula_media (a,b,c);
    return 0;
}