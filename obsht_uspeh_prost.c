/*
 * Общ (среден) успех на учениците — проста версия с float
 * Оценките са от 2 до 6 (българска скала)
 */

#include <stdio.h>

int main(void)
{
    int n, i;
    float ocenka, suma = 0.0f;

    printf("Kolko uchenika? ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        printf("Ocenka %d (2..6): ", i);
        scanf("%f", &ocenka);
        suma += ocenka;
    }

    printf("Obsht uspeh: %.2f\n", suma / n);

    return 0;
}
