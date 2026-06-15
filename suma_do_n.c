/*
 * Сума на числата от 1 до n — с цикъл
 */

#include <stdio.h>

int main(void)
{
    int n, i, suma = 0;

    printf("Do koe chislo n? ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        suma = suma + i;
    }

    printf("Sumata ot 1 do %d e: %d\n", n, suma);

    return 0;
}
