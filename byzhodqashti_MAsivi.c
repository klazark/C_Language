#include <stdio.h>

#define MAX_U 30
#define MAX_P 20

int main(void)
{
    int marks[MAX_U][MAX_P];
    int n = 0, m = 0; // n e broi uchenici i m e broi predmeti

    do
    {
        printf("n=? (1..%d): ", MAX_U); // vyvejdane na broi uchenici
        scanf("%d", &n);
    } while (n < 1 || n > MAX_U);

    do
    {
        printf("m=? (1..%d): ", MAX_P); // vyvejdane na broi predmeti
        scanf("%d", &m);
    } while (m < 1 || m > MAX_P);

    for (int i = 0; i < n; i++)
    { // vyvejdane na ocenki
        for (int k = 0; k < m; k++)
        {
            do
            {
                printf("mark %d for student %d = ", k + 1, i + 1);
                scanf("%d", &marks[i][k]);
            } while (marks[i][k] < 2 || marks[i][k] > 6);
        }
    }
}