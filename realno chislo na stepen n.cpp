#include <stdio.h>


int global_x = 12;
int global_y = 10;



float stepen(float a, int n);
void  fig(int n, char c);
void  change_stойност(int a, int b);
void  change_globalni();
void  change_ukazatel(int *pa, int *pb);
int   uravn(float a, float b, float *px);



float stepen(float a, int n)
{
    float P = 1;
    int m, i;

    if (n > 0) m = n; else m = -n;

    for (i = 1; i <= m; i++)
        P = P * a;

    if (n < 0) P = 1 / P;

    return P;
}