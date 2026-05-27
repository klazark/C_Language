#include <stdio.h>

int main(void) {
    int n;
    int i;
    int suma = 0;

    printf("Vuvedete n: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        suma = suma + i;
    }

    printf("Sumata ot 1 do %d e %d\n", n, suma);
    return 0;
}
