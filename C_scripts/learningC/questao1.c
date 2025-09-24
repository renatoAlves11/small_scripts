#include <stdio.h>
int calcula_perimetro( float xmax, float xmin, float ymax, float ymin)
{
    float s;
    s=(2*(xmax-xmin))+(2*(ymax-ymin));
    return s;
}
int main()
{
    int i,n, z1=0, z2=0, z3=0, z4=0;
    float x=0, y=0, xmax=0, xmin=0, ymax=0,ymin=0, s;
    printf("Digite a quantidade de pontos\n");
    scanf ("%d", &n);
    for (i=0;i<n;i=i+1)
    {
        printf("Escreva x e y do ponto %d nessa ordem\n", i+1);
        scanf("%f%f", &x,&y);
        if (x > 0 && y>0)
        {
            z1++;
        }
        if (x < 0 && y>0)
        {
            z2++;
        }
        if (x < 0 && y<0)
        {
            z3++;
        }
        if (x > 0 && y<0)
        {
            z4++;
        }
        if (i==0)
        {
         xmax=x;
         xmin=x;
         ymin=y;
         ymax=y;   
        }
        if (x<xmin)
        {
            xmin=x;
        }
        if (x>xmax)
        {
            xmax=x;
        }
        if (y>ymax)
        {
            ymax=y;
        }
        if (y<ymin)
        {
            ymin=y;
        }
    }
    s= calcula_perimetro (xmax, xmin, ymax, ymin);
    printf("O perimetro e %f\n", s);
    printf("%f %f %f %f\n", xmax, xmin, ymax, ymin);
    printf (" z1=%d z2=%d z3=%d z4=%d\n", z1, z2, z3, z4);
    return 0;
}