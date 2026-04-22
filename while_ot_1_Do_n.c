#include <stdio.h>

int main(void)
{
    int n = 3;
    int i = 1;

    printf("n = ");
    scanf("%d", &n);

    while (i <= n)
    {
        printf("%d\n", i);
        i++;
    }

    for (i = 1; i <= n; i++)
    {
        printf("%d\n", i);
    }

    while (i <= n)
    {
        printf("%d\n", i);
        i++;
    }

    while (n > 0)
    {
        printf("n = %d\n", n);
        n--;
    }

    return 0;
}