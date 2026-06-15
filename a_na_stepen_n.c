#include <stdio.h>

int main(void)
{
    double a, r = 1;
    int n, i;

    scanf("%lf %d", &a, &n);
    for (i = 0; i < (n < 0 ? -n : n); i++)
        r *= a;
    if (n < 0)
        r = 1 / r;
    printf("%g\n", r);
}
