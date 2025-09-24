#include <stdio.h>
float calcula_idh (float e, float l, float r)
{
    if (e>=l+r)
    {
        return e*l*r/((e+l+r)/3);
    }
    else 
    {
        return (e+l+r)/3;
    }
}
int main ()
{
    float e, l, r, idh;
    printf ("Digite as dimensões educação, longevidade e riqueza nesta ordem:\n");
    scanf("%f%f%f", &e, &l, &r);
    idh=calcula_idh(e, l, r);
    printf("O idh e: %0.2f", idh);
    return 0;
}