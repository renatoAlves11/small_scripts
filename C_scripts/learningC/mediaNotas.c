#include <stdio.h>
#include <math.h>
float calculaMedia (float a, float b)
{
    float c;
    c= (a+b)/2;
    return c;
}

int main()
{   float a, b, media;
    printf ("Digite as notas de dois alunos:\n");
    scanf ("%f%f", &a, &b);
    media = calculaMedia (a, b);
    printf ("A media desses alunos e: %0.2f\n", media);
    return 0;
}