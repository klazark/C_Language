#include<stdio.h>

int main() {

    int n;
    int m;
    int sum = 0;
    printf("vyvedete estestveno chislo \n");
    scanf("%d", &n);

    printf(" n= %d\n", n);
    while(n>0) {

        m = n%10;  // Вземи последната цифра
        if (m%2 == 0)
        {
            sum = sum + m; //sum += m;
        }
        n = n/10;  // Премахни последната цифра
        // else {
        //   sum =0;
        //}
    }

    if (sum == 0){

        printf("Nqama chetni cifri");
    }




}