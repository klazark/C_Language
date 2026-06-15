#include <stdio.h>

int main(void)
{
    int n, i;
    float o, s = 0;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%f", &o);
        s += o;
    }
    printf("%.2f\n", s / n);
}
