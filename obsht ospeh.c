#include <stdio.h>

#define MAX_U 30
#define MAX_P 20

int main(void)
{
    int marks[MAX_U][MAX_P];
    int n = 0, m = 0;

    do
    {
        printf("n=? (1..%d): ", MAX_U);
        scanf("%d", &n);
    } while (n < 1 || n > MAX_U);

    do
    {
        printf("m=? (1..%d): ", MAX_P);
        scanf("%d", &m);
    } while (m < 1 || m > MAX_P);

    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < m; k++)
        {
            do
            {
                printf("Ocenka %d za uchenik %d = ", k + 1, i + 1);
                scanf("%d", &marks[i][k]);
            } while (marks[i][k] < 2 || marks[i][k] > 6);
        }
    }

    printf("\n--- Sreden uspeh po uchenici ---\n");

    double klasen_sum = 0;

    for (int i = 0; i < n; i++)
    {
        double sum = 0;

        for (int k = 0; k < m; k++)
        {
            sum += marks[i][k];
        }

        double sreden = sum / m;
        klasen_sum += sreden;

        printf("Uchenik %d: sreden uspeh = %.2f\n", i + 1, sreden);
    }

    printf("\n--- Obsht sreden uspeh na klasa ---\n");
    printf("Sreden uspeh na klasa = %.2f\n", klasen_sum / n);

    return 0;
}
