#include<stdio.h>
void main()
{
    float n,i,j;
    printf("Input : ");
    scanf("%f",&n);
    float k1 = (0.5*n)+1.5;

    for (i=1; (2*i)<= n+3 ;i++)
    {
        if(i<=k1)//top of diamond
        {
            for (j=1;j<=(3+n-i);j++)
                printf(" ");
            for (j=1;j<=(2*i)-1;j++)
                printf("*");
            printf("\n");
        }
    }

    for (j=1;j<=((n+1)/2);j++)
    printf("i");
    printf("*");
    for (j=1;j<=2+n;j++)
        printf(" ");
    printf("*\n");


}
