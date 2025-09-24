#include <stdio.h>
int main ()
{
    int cod, qtd;
    float preco;
    char tipo;
    printf("Digite o código:\n");
    scanf("%d", &cod);
    printf("Digite o tipo:\n(N)Nacional\n(I)Importado\n");
    scanf("%s", tipo);
    while (tipo!='N' && tipo!='I')
    {
        printf("Tipo invalido, digite o tipo\n");
        scanf("%s", tipo);
    }
    printf("Digite a quantidade em estoque:\n");
    scanf ("%d", &qtd);
    

    return 0;
}