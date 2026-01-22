#include<stdio.h>

int main()
{
//sum ot n chisla
    int n;
    printf("n=");
    scanf("%d", &n);
    int a;
    int sum = 0;


    for(int i = 1; i<=n; i++)
    {
        printf("a=");
        scanf("%d", &a);
        if (a%3==0) {
            sum+=a;
        }
        
    }


    printf("%d\n", sum);


    return 0;
}