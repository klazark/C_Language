#include <stdio.h>
#define MAX_STUDENTS 30 // max_u
#define MAX_SUBJECTS 20 // max_p

int main()
{
    int marks[MAX_STUDENTS][MAX_SUBJECTS];
    int n, m;

    // въвеждане на брой ученици (n) и брой предмети (m)
    do
    {
        printf("n=? (n<=%d):", MAX_STUDENTS);
        if (scanf("%d", &n) != 1)
            return 1;
    } while (n < 1 || n > MAX_STUDENTS);

    do
    {
        printf("m=? (m<=%d):", MAX_SUBJECTS);
        if (scanf("%d", &m) != 1)
            return 1;
    } while (m < 1 || m > MAX_SUBJECTS);

    // въвеждане на оценките
    int i, k;
    for (i = 0; i < n; i++)
        for (k = 0; k < m; k++)
        {
            do
            {
                printf("mark %d for student %d=", k + 1, i + 1);
                scanf("%d", &marks[i][k]);
            } while (marks[i][k] < 2 || marks[i][k] > 6);
        }

    // изчисляване на средния успех на всеки ученик
    float avr_u[MAX_STUDENTS];
    for (i = 0; i < n; i++)
    {
        avr_u[i] = 0.0f;
        for (k = 0; k < m; k++)
            avr_u[i] += marks[i][k];
        avr_u[i] /= m;
    }

    // изчисляване на средния успех на класа по всеки предмет
    float avr_p[MAX_SUBJECTS];
    for (k = 0; k < m; k++)
    {
        avr_p[k] = 0.0f;
        for (i = 0; i < n; i++)
            avr_p[k] += marks[i][k];
        avr_p[k] /= n;
    }

    // изчисляване на средния успех на класа
    float avr = 0.0f;
    for (i = 0; i < n; i++)
        for (k = 0; k < m; k++)
            avr += marks[i][k];
    avr /= (n * m);

    // отпечатване в табличен вид: всеки ред - оценки на ученик + среден успех на ученика
    for (i = 0; i < n; i++)
    {
        for (k = 0; k < m; k++)
            printf("%-6d", marks[i][k]);
        printf("%-6.2f\n", avr_u[i]);
    }

    // ред със средните по предмети и общия среден успех
    for (k = 0; k < m; k++)
        printf("%-6.2f", avr_p[k]);
    printf("%-6.2f\n", avr);

    return 0;
}
