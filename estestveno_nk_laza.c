#include<stdio.h>

int main() {

    int k;
    int n = 0;
    int num = 0;
    int count_out = 0;


    printf("k = ");
    scanf("%d", &k);

    printf("n = ");
    scanf("%d", &n);

    for(int i = 0; i<n; i++) {
        //printf("\n n1 = %d", n);
        printf("\n give number = ");
        scanf("%d", &num);

        int k_num = 0;
        while(num > 0) {
            printf("\n num = %d", num);
            num=num / 10;
            k_num++;
        }

        printf("\n k_num = %d", k_num);

        if(k_num == 2)  {
            count_out++;
            // count_out+=1;
            // count_out = count_out + 1;
        }

    }
    
    printf("\n count_out = %d", count_out);
}