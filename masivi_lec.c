// Задача: Да се състави програма, която въвежда дневните температури за период
// от n дни (n<=100). Да се изчисли средната температура за периода и отклоненията на
// дневните температури от средната за периода
#include <stdio.h>
const int max_br = 100;

int main()
{
    float temp[max_br];
    float s = 0, avr;
    int n, i;

    do {
        printf("n=?(n<=%d):", max_br);
        scanf("%d", &n);
    } while (n < 1 || n > max_br);

    for (i = 0; i < n; i++) {
        printf("temp for day %d=", i + 1);
        scanf("%f", &temp[i]);
    }

    for (i = 0; i < n; i++) {
        s += temp[i];
    }
    
    avr = s / n;
    printf("\navr=%.2f", avr);
    
    for (i = 0; i < n; i++) {
        printf("\ndeviation for day %d=%.2f", i + 1, temp[i] - avr);
    }
    
    return 0;
}