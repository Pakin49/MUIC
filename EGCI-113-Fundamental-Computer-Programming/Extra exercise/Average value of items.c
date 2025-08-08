#include<stdio.h>
void main()
{
    float w1,w2,n1,n2,avg;5

    printf("Weight-item1: ");
    scanf(" %f",&w1);
    printf("No. of item1: ");
    scanf("%f",&n1);
    printf("Weight-item2: ");
    scanf("%f",&w2);
    printf("No. of item2: ");
    scanf("%f",&n2);

    avg = ((w1*n1)+(w2*n2))/(n1+n2);
    printf("Average value = %.6f",avg);
}
