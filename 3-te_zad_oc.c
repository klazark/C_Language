#include <stdio.h>
#include <ctype.h>

int main()
{
    int ch;            // int за getchar()
    int is_digits = 1; // флаг: 1=само цифри

 //printf("ch =");
 //scanf("%d", &ch);

    while ((ch = getchar()) != '\n')
    { // чете до Enter
        if (!isdigit(ch))
        {
            is_digits = 0;
            break; // спира рано
        }
    }

    printf("is_digits = %d", is_digits);
    // после принтирай според is_digits
}

