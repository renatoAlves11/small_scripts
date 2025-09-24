#include <stdio.h>
int situacao_eleitoral (int idade)
{
    if (idade < 16)
    {
        return printf ("Nao eleitor");
    }
    else if (idade < 18 || (idade >70 && idade<150))
    {
        return printf ("Eleitor facultativo");
    }
        else if (idade <= 70)
        {
            return  printf("Eleitor");
        }
        else if (idade >=150)
        {
         printf ("Morreu");
        }
}
int main ()
{   int idade;
    printf ("Digite a idade do potencial eleitor:\n");
    scanf ("%d", &idade);
    situacao_eleitoral(idade);
    return 0;
}