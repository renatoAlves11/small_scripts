#include <stdio.h>
int calculaHora(int h, int m)
{   int mt;
    mt=(h*60)+m;
    return mt;
}
int main ()
{   int h, m, mt, h1, m1, mt1, mT;
    printf ("Digite as horas e os minutos esperados para a chegada do seu vôo:\n");
    scanf ("%d%d", &h, &m);
    mt= calculaHora (h,m);
    printf ("Os minutos totais esperados são: %d\n", mt);
    printf ("Agora digite as horas e os minutos efetivos para a chegada do vôo:\n");
    scanf ("%d%d", &h1, &m1);
    mt1= calculaHora (h1, m1);
    printf ("Os minutos totais efetivados são: %d\n", mt1);
    mT = mt - mt1;
    printf ("A diferença entre o tempo estimado e o efetivado do se vôo foi de %d minutos.\n", mT);
    return 0;
}