#include <stdio.h>
int verificaPrimosEntreSi(int,int);

int mdc (int a, int b)
{
  int resto;
  while (b!=0)
  {
    resto=a % b;
    a = b;
    b =resto;
  }
  return a;
}

int main(){  //Algoritmo de euclides
  int a,b,c;
  printf("Digite o número maior e o número menor respectivamente:");
  scanf ("%d%d", &a, &b);
  c = mdc(a,b);  
  if(verificaPrimosEntreSi(a,b)==1){
    printf ("%d e %d são primos entre si.\n", a, b);
  }
    else {
      printf ("%d e %d não são primos entre si.\n", a, b);
    }
  printf("O mdc é: %d\n", c);
  return 0;
}

int verificaPrimosEntreSi(int a,int b)
{
  if(mdc(a,b)==1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
  }
