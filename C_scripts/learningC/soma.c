#include <stdio.h>
int main()
{
    int a, b, c;
    printf ("Digite os números inteiros a serem somados:\n");
    scanf ("%d%d", &a, &b);
    if (a)
    c=a+b;
    printf ("%d + %d = %d", a, b, c);
    return 0;
}