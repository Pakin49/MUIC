#include<stdio.h>
void main()
{
    int n,i,j,count;
    printf("Input: ") ;
    scanf("%d",&n);

    for(i=2;i<(n/2);i++)
    {
        count = 0;
        for(j=2;j<i/2;j++)
        {
            if (i%j==0)
                count++;
        }
        if (count!=0)
                printf("%d",i);
    }
}
