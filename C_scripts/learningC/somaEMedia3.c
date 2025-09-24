#include <stdio.h>
int calcula_soma()
{  
    int a, b, c, x;
    scanf ("%i%i%i", &a,&b,&c);
    x=a+b+c;
    printf ("%i + %i + %i = %i\n", a, b, c, x );
    return x;
}
int calcula_media(int x)
{   
    int y;
    y=(x)/3;
    return printf ("Media = %i\n", y);
}
int main()
{   int a,b,c,x,y;
    printf ("Digite tres numeros:\n");
    x= calcula_soma();
    y= calcula_media (x);
    return 0;
}