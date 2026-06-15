#include <stdio.h>

int main(void)
{
    int n, i, ocenka, suma = 0;

    printf("Kolko uchenika? ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        printf("Ocenka %d: ", i);
        scanf("%d", &ocenka);
        suma += ocenka;
    }

    printf("Obsht uspeh: %.2f\n", (float)suma / n);
    return 0;
}
