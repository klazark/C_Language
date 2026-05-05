#include <stdio.h>

#define MAX_UCHENICI 30
#define MAX_PREDMETI 20

int main(void)
{
    int n, m;
    double ocenki[MAX_UCHENICI][MAX_PREDMETI];

    do
    {
        printf("Broi uchenici (1-%d): ", MAX_UCHENICI);
        scanf("%d", &n);
    } while (n < 1 || n > MAX_UCHENICI);

    do
    {
        printf("Broi predmeti (1-%d): ", MAX_PREDMETI);
        scanf("%d", &m);
    } while (m < 1 || m > MAX_PREDMETI);

    for (int i = 0; i < n; i++)
    {
        printf("\n-- Uchenik %d --\n", i + 1);
        for (int j = 0; j < m; j++)
        {
            do
            {
                printf("  Predmet %d ocenka (2-6): ", j + 1);
                scanf("%lf", &ocenki[i][j]);
            } while (ocenki[i][j] < 2 || ocenki[i][j] > 6);
        }
    }

    printf("\n=============================\n");
    printf("  Sreden uspeh po uchenici\n");
    printf("=============================\n");

    double klassen_sreden = 0;

    for (int i = 0; i < n; i++)
    {
        double suma = 0;
        for (int j = 0; j < m; j++)
        {
            suma += ocenki[i][j];
        }
        double sreden = suma / m;
        klassen_sreden += sreden;
        printf("Uchenik %2d: %.2f\n", i + 1, sreden);
    }

    printf("-----------------------------\n");
    printf("Klasen sreden uspeh: %.2f\n", klassen_sreden / n);
    printf("=============================\n");

    return 0;
}
