/*
 * Общ (среден) успех на учениците — без масиви
 * Оценките се въвеждат в цикъл; намира и учениците с шестица (6)
 */

#include <stdio.h>

int main(void)
{
    int n, i;
    int ocenka, suma = 0, broi_shestici = 0;

    printf("Kolko uchenika? ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        printf("Ocenka %d (2..6): ", i);
        scanf("%d", &ocenka);
        suma = suma + ocenka;

        if (ocenka == 6) {
            broi_shestici++;
            printf("  -> Uchenik %d ima shestica\n", i);
        }
    }

    printf("Obsht uspeh: %.2f\n", (float)suma / n);
    printf("Uchenici s shestica: %d\n", broi_shestici);

    return 0;
}
