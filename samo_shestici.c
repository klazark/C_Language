#include <stdio.h>

int main(void)
{
    int n, i, ocenka;
    int count = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &ocenka);
        if (ocenka == 6)
        {
            printf("%d\n", ocenka);
            count = count + 1;
        }
    }

    return 0;
}
