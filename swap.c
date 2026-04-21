#include <stdio.h>

int main(void)
{
    int a, b;
    printf("Въведете две цели числа, разделени с интервал: ");
    if (scanf("%d %d", &a, &b) != 2)
    {
        printf("Невалиден вход\n");
        return 1;
    }

    printf("Преди: a=%d, b=%d\n", a, b);

    /* Метод 1: С трета променлива */
    int x = a, y = b;
    int temp = x;
    x = y;
    y = temp;
    printf("След размяна с трета променлива: a=%d, b=%d\n", x, y);

    /* Метод 2: Без трета променлива - с операции (+,-) */
    int u = a, v = b;
    u = u + v; /* възможен overflow при големи стойности */
    v = u - v;
    u = u - v;
    printf("След размяна с операции (+,-): a=%d, b=%d\n", u, v);

    return 0;
}
