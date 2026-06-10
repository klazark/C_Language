/*
 * Максимум от n цели числа, само сред тези, които се делят на 3
 */

#include <stdio.h>

int main(void)
{
    int n, i, chislo;
    int max = 0;
    int ima = 0;   /* има ли поне едно число, делящо се на 3 */

    printf("Kolko chisla? ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        printf("Chislo %d: ", i);
        scanf("%d", &chislo);

        if (chislo % 3 == 0) {
            if (ima == 0 || chislo > max) {
                max = chislo;
            }
            ima = 1;
        }
    }

    if (ima) {
        printf("Max (deli se na 3): %d\n", max);
    } else {
        printf("Nqma chislo, koeto se deli na 3.\n");
    }

    return 0;
}
