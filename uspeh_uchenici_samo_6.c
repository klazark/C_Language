/*
 * Общ успех на учениците + кои имат само 6
 * Вариант на uspeh_uchenici.c
 */

#include <stdio.h>

int main(void)
{
    int n, i, j;
    int ocenka, suma = 0;
    int broi_samo_6 = 0;

    printf("Kolko uchenika? ");
    scanf("%d", &n);

    int samo_6[n];

    for (i = 1; i <= n; i++) {
        printf("Ocenka %d (2..6): ", i);
        scanf("%d", &ocenka);
        suma = suma + ocenka;

        if (ocenka == 6) {
            samo_6[broi_samo_6] = i;
            broi_samo_6++;
        }
    }

    printf("\nObsht uspeh: %.2f\n", (float)suma / n);

    printf("\n--- Uchenici samo s 6 ---\n");
    if (broi_samo_6 == 0) {
        printf("Nqma takiva uchenici.\n");
    } else {
        for (j = 0; j < broi_samo_6; j++) {
            printf("Uchenik %d\n", samo_6[j]);
        }
        printf("Obshto: %d\n", broi_samo_6);
    }

    return 0;
}
