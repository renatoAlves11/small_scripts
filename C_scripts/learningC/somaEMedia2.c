#include <stdio.h>
int calcula_soma(int a, int b, int c)
{
int x;
    x=a+b+c;
    return printf ("%i + %i + %i = %i\n", a, b, c, x );
}
int calcula_media(int a, int b, int c)
{
    int y;
    y=(calcula_soma(a,b,c))/3;
    return printf ("(%i + %i + %i)/3 = %i\n", a,b,c,y);
}
int main()
{   int a,b,c,x,y;
    printf ("Digite tres numeros:\n");
    scanf ("%i%i%i", &a,&b,&c);
    x= calcula_soma(a,b,c);
    y= calcula_media (a,b,c);
    return 0;
}