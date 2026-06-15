#include <stdio.h>

int main(void)
{
    int n, i, k = 0;

    printf("Estestveno chislo n: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            printf("%d ", i);
            k++;
        }
    }

    printf("\nBroi deliteli: %d\n", k);
    return 0;
}
