#include <stdio.h>
int matricula(int f)
{ int x, y, z;
  x=f/1000;
  f=f-(x*1000);
  y=f/100;
  z=f-(y*100);
  if (x<10||x>22||y<1||y>2||z<1||z>90){
   return 0;
  }
  else 
  {
    return 1;
  }
}
int main()
{
  int x, y, z, m; 
  printf("Digite a matrícula para ser confirmada:\n");
  scanf("%i", &m);
  m=matricula(m);
  if (m==0) 
  {
  printf("Matrícula invalidada\n");
  }
  else 
  {
    printf("Matrícula validada\n");
  }
  return 0;
}

