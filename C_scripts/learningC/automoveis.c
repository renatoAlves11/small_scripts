#include <stdio.h>
int quantos_estoque (int n)
{
    int t=0, i, mod, qtd;
    for (i=0;i<n;i++)
    {
        scanf ("%d%d", &mod, &qtd);
        if (qtd > 1000)
        {
            t++;
        }
    }
    return t;
}
int main ()
{
    int n, i, t;
    scanf ("%d", &n);
    t=quantos_estoque(n);
    printf("%d", t);
    return 0;
}