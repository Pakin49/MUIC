#include<stdio.h>
void main()
{
    int n,i,j;
    printf("Input: ");
    scanf("%d",&n);

    for(i=1;i<=8*n;i++)
    {
        if(((i-1)/n)%2==0)
        {
            for(j=1;j<=(8*n);j++)
            {
                if((((j-1)/n)%2)==0)
                printf(" ");
                else printf("*");
            }
            printf("\n");
        }
        else
        {
            for(j=1;j<=(8*n);j++)
            {
                if((((j-1)/n)%2)==0)
                printf("*");
                else printf(" ");
            }
            printf("\n");
        }
    }

}
