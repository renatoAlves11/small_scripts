#include <stdio.h>
#include <math.h>
float calcula_area(float h, float p)
{
  return (sqrt(h*p))/60;
}
float varia_area (float a1, float a2)
{
  if (a1==a2)
  {
    return printf ("Manteve área inalterada");
  }
  else if (a1<a2)
  {
    return printf ("Aumentou área corporal");
  }
  else
  {
    return printf ("Diminuiu área corporal");
  }
}
int main ()
{
  float p1, p2,h1, h2, a1, a2;
  printf ("Qual era o seu peso e altura no início do ano?\n");
  scanf ("%f%f", &p1, &h1);
  a1=calcula_area(p1, h1);
  printf ("Qual era/é o seu peso e altura no fim do ano?\n");
  scanf ("%f%f", &p2, &h2);
  a2=calcula_area(p2, h2);
  varia_area(a1,a2);
  return 0;
}