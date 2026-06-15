#include <stdio.h>

int main(void) {
    int n;
    int m = 0;

    scanf("%d", &n);

    while (n > 0) {
        m = m * 10 + (n % 10);
        n = n / 10;
    }

    printf("%d\n", m);
    return 0;
}
