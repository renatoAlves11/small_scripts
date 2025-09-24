#include <stdio.h>
int calculaSemana (int d)
{   int s, d1;
    s= d/7;
    d1= d % 7;
    return printf ("O evento durou por %d semanas e %d dias.\n", s, d1);
}
int main ()
{   int d, sd;
    printf("Digite quantos dias durou o evento:\n");
    scanf ("%d", &d);
    sd= calculaSemana (d);
    return 0;
}
