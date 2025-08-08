#include<stdio.h>
void main()
{
    int n,fac,i,j,k;
    printf("Input : ");
    scanf("%d",&n);

    for (j=1;j<=n;j++)
    {
        for(k=j;k)
        {
            printf(" ");
        }
        for (i=1;i<=j;i++)
        {
            printf("*");
        }
        printf("\n");
    }

}
