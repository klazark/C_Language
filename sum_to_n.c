#include <stdio.h>

int main(void) {
    long long n;
    printf("Въведете n (положително цяло число): ");
    if (scanf("%lld", &n) != 1) {
        printf("Невалиден вход.\n");
        return 1;
    }
    if (n < 1) {
        printf("n трябва да е по-голямо или равно на 1.\n");
        return 1;
    }
    long long sum = n * (n + 1) / 2;
    printf("Сумата от 1 до %lld е: %lld\n", n, sum);
    return 0;
}
