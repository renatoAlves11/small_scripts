#include <stdio.h>
int main ()
{   int numeroDeAlunos, i;
    printf ("Digite o número de alunos: ");
    scanf ("%d", &numeroDeAlunos);
    i=1;
    while (i<=numeroDeAlunos)
    {   float nota1, nota2, media;
        printf ("Escreva as notas do aluno %d: ", i);
        scanf ("%f%f", &nota1, &nota2);
        media=(nota1+nota2)/2;
        printf (" A média é %0.2f\n", media);
        i=i+1; //ou i+=1
    }
    return 0;
}