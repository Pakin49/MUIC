#include<stdio.h>
void main()
{
    int i,j,n;
    printf("Input : ");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        for (j=n-i;j>0;j--)
            printf(" ");

        for (j=1; j<=i;j++)
            printf("*");
        printf("\n");
    }
}
