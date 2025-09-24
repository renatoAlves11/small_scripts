#include <stdio.h>
int leValidaTipo ()
{
    int tipo;
    printf ("Digite o tipo do produto:\n(1)Fruta\n(2)legume\n(3)verdura\n");
    scanf ("%d", &tipo);
    while (tipo>3||tipo<1)
    {
    printf("Tipo invalidado, digite o tipo do produto:\n(1)Fruta\n(2)legume\n(3)verdura\n");
    scanf ("%d", &tipo);
    }
    return tipo;
}
int alimentos(int qtd, int *qtd1, int *qtd2, int *qtd3)
{
    int i, tipo=0, cod, tip[3]={0,0,0};
    for (i=0;i<qtd;i++)
{
    printf ("Digite o código do produto:\n");
    scanf("%d", &cod);
    tipo = leValidaTipo();
    tipo=tipo-1;
    tip[tipo]++;
}
    *qtd1=tip[0];
    *qtd2=tip[1];
    *qtd3=tip[2];
}
int main()
{
    int qtd, qtd1=0,qtd2=0,qtd3=0;
    printf("Digite o total de produtos:\n");
    scanf("%d", &qtd);
    alimentos(qtd, &qtd1, &qtd2, &qtd3);
    printf("Frutas:%d\n Legumes: %d\n Verduras: %d", qtd1, qtd2, qtd3);
    return 0;
}