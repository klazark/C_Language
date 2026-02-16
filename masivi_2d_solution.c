// Двумерни масиви
// Задача: Да се въведат срочните оценки на учениците от един клас (брой ученици <=30, брой предмети<=20).
// Да се изчислят:
// а/ средният успех на всеки ученик
// б/ средният успех на класа по всеки предмет
// в/ средният успех на класа
// Резултатите да се изведат в табличен вид.
// Пример:

// 5      5      5      5.00
// 4      4      4      4.00
// 6      6      6      6.00
// 5.00 5.00 5.00 5.00

#include <stdio.h>
#define max_u 30
#define max_p 20
int main()
{

    int marks[max_u][max_p];
    int n, m;
    // въвеждане на брой ученици (n) и брой предмети (m)

    do
    {
        printf("n=? (n<=%d):", max_u);
        scanf("%d", &n);
    } while (n < 1 || n > max_u);
    do
    {
        printf("m=? (m<=%d):", max_p);
        scanf("%d", &m);
    } while (m < 1 || m > max_p);

    // въвеждане на оценките
    int i, k;
    for (i = 0; i < n; i++)
        for (k = 0; k < m; k++)
            do
            {
                printf("mark %d for student %d=", k + 1, i + 1);
                scanf("%d", &marks[i][k]);
            } while (marks[i][k] < 2 || marks[i][k] > 6);

    // изчисляване на средния успех на всеки ученик
    float avr_u[max_u];

    for (i = 0; i < n; i++)
    {
        avr_u[i] = 0;
        for (k = 0; k < m; k++)
            avr_u[i] = avr_u[i] + marks[i][k];
        avr_u[i] = avr_u[i] / m;
    }

    // // изчисляване на средния успех на класа по всеки предмет
    // float avr_p[max_p];

    // for (k = 0; k < m; k++)
    // {
    //     avr_p[k] = 0;
    //     for (i = 0; i < n; i++)
    //         avr_p[k] = avr_p[k] + marks[i][k];
    //     avr_p[k] = avr_p[k] / n;
    // }

    // // изчисляване на средния успех на класа
    // float avr = 0;

    // for (i = 0; i < n; i++)
    //     for (k = 0; k < m; k++)
    //         avr = avr + marks[i][k];
    // avr = avr / (n * m);

    // for (i = 0; i < n; i++)
    // {
    //     for (k = 0; k < m; k++)
    //         printf("%-5d", marks[i][k]);
    //     printf("%-5.2f\n", avr_u[i]);
    // }
    // for (i = 0; i < m; i++)
    //     printf("%-5.2f", avr_p[i]);
    printf("%-5.2f", avr);

    return 0;
}
