#include <stdio.h>
float calcula_media ( float a, float b)
{
    return (a+b)/2;
}
int main()
{
    int matricula;
    float p1, p2, t1, t2, med1, med2, medF;
    printf("Escreva nesta ordem: a matrícula do aluno, a nota da sua primeira prova, da sua segunda prova, do seu primeiro trabalho e do seu segundo trabalho\n");
    scanf("%i%f%f%f%f", &matricula, &p1, &p2, &t1, &t2);
    med1= calcula_media (p1, p2);
    med2= calcula_media (t1,t2);
    medF= calcula_media (med1, med2);
    printf("Os resultados do aluno %i são: Media de provas = %0.2f; Media de trabalhos = %0.2f; Media final = %0.2f", matricula, med1, med2, medF);
    return 0;
}