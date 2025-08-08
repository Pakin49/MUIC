#include<stdio.h>
void main()
{
   int n,i,j,count;
   printf("Input: ") ;
   scanf("%d",&n);

   if(n%2 == 0)
        printf("2");

    for (i=3;i<n;i+2)
    {
        for(j=2;j<=i;j++)
        {
            if (i%j==0)
                count++;
            if (count==0)
                printf("%d",i);
        }
    }
}
