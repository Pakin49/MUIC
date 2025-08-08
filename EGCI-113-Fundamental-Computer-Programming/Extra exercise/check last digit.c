#include<stdio.h>
void main()
{
    int a,b;
    printf("Input1: ");
    scanf("%d",&a);
    printf("Input2: ");
    scanf("%d",&b);

    if (a%10 == b%10)
        printf("The last digit is the same");
    else printf("The last digit is not the same");
}
