#include <stdio.h>
int calcula_postos ()
{
    int i, cod, val, valmais=0, valT;
    for (i=0;i<20;i++)
    {
        scanf("%d%d", &cod, &val);
        if (valmais==0)
        {
            valmais=val;
        }
        else if(val>valmais)
        {
            valmais=val;
        }
        valT=valT+val;

    }
    printf ("%d", valmais);
    return valT;
}
int main()
{   int valT;
    valT = calcula_postos();
    printf("%d", valT);
    return 0;
}