#include <stdio.h>
int main()
{
  float x;
  int n,i;
  printf ("Quantos vendedores?\n");
  scanf("%d", &n);
  int tip[9]={0};
  for (i=0;i<n;i++)
    {
      printf("Quanto ganha o %d vendedor?\n", i+1);
      scanf("%f\n", &x);
      if (x>=200 && x<300)
      {
        tip[0]++;
      }
      if (x>=300 && x<400)
      {
        tip[1]++;
      }
      if (x>=400 && x<500)
      {
        tip[2]++;
      }
      if (x>=500 && x<600)
      {
        tip[3]++;
      }
      if (x>=600 && x<700)
      {
        tip[4]++;
      }
      if (x>=700 && x<800)
      {
        tip[5]++;
      }
      if (x>=800 && x<900)
      {
        tip[6]++;
      }
      if (x>=900 && x<1000)
      {
        tip[7]++;
      }
      if (x>=1000)
      {
        tip[8]++;
      }
    }
    for (i=0;i<9;i++)
    {
        printf ("%d\n", tip[i]);
    }
  return 0;
}

