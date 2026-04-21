#include <stdio.h>

int main(void)
{
    int a, b, c;
    printf("Въведете три цели числа, разделени с интервал: ");
    if (scanf("%d %d %d", &a, &b, &c) != 3)
    {
        printf("Невалиден вход\n");
        return 1;
    }

    printf("Въведени: a=%d, b=%d, c=%d\n", a, b, c);

    /* Метод 1: Вложени if-else (пълна/непълна форма) */
    int max1;
    if (a >= b)
    {
        if (a >= c)
            max1 = a;
        else
            max1 = c;
    }
    else
    {
        if (b >= c)
            max1 = b;
        else
            max1 = c;
    }
    printf("Максимум (вложени if): %d\n", max1);

    /* Метод 2: Последователни сравнения (по-четим и често предпочитан) */
    int max2 = a;
    if (b > max2)
        max2 = b;
    if (c > max2)
        max2 = c;
    printf("Максимум (последователни сравнения): %d\n", max2);

    return 0;
}
