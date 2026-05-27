#include <stdio.h>

int main(void)
{
    long long n;
    int k = 0;
    printf("Chislo (>=0): ");
    if (scanf("%lld", &n) != 1 || n < 0)
        return 1;
    do {
        k++;
        n /= 10;
    } while (n > 0);
    printf("Cifri: %d\n", k);
    return 0;
}
