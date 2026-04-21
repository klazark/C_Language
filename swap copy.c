#include <stdio.h>

int main(void)
{
    int a, b;
    printf("vYVEDETE TVE CELI CHISLA, RAZDELENI S INTERVAL: ");
    if (scanf("%d %d", &a, &b) != 2)
    {
        printf("NEVALIDEN VHOD\n");
        return 1;
    }
}