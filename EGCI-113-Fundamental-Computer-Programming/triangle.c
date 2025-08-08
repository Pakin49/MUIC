#include<stdio.h>
void main()
{
    int n,i,j,k;
    printf("Input(1-9): ");
    scanf("%d",&n);

    for(i=n;i>=1;i--)
    {
        for(k=n-1;k>=1;k--)
        {
            printf(" ");
        }
        for(j=i;j>=1;j--)
        {
            printf("*");
        }
    printf("\n");
    }
}
