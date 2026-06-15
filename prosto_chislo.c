#include <stdio.h>

int main(void)
{
    int n, i, p = 1;

    scanf("%d", &n);
    for (i = 2; i < n; i++)
        if (n % i == 0)
            p = 0;
    printf(p ? "da\n" : "ne\n");
}
