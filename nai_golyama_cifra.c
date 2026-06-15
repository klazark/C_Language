#include <stdio.h>

int main(void) {
    int n;
    int max = 0;

    scanf("%d", &n);

    while (n > 0) {
        int c = n % 10;
        if (c > max) {
            max = c;
        }
        n = n / 10;
    }

    printf("%d\n", max);
    return 0;
}
