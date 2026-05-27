#include <stdio.h>

int main(void) {
    int n;
    int i;
    int suma = 0;
    int ocenka;

    printf("Vuvedete n: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        scanf("%d", &ocenka);
        suma = suma + ocenka;
    }

    printf("Sreden uspeh: %.2f\n", (double)suma / n);
    return 0;
}
