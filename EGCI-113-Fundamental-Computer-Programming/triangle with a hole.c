#include<stdio.h>
void main()
{
    int i,j,n,a;

    while(1)
    {
        printf("Input : ");
        scanf("%d",&n);
        a = n/2;

        if(n==0)
            break;

        if(n<1 || n>19 || n%2==0)
        {
            printf("No output -_-\n");
            continue;
        }

        for(i=0; i<=(n/2);i++)
        {
           if (i==0)
           {
                for(j=1;j<=(a-i);j++)
                    printf(" ");
                printf("*\n");
           }
           else if (i==a)
           {
               for(j=1;j<=n;j++)
                   printf("*");
                printf("\n");
           }
           else
           {
                for(j=1;j<=(a-i);j++)
                    printf(" ");
                printf("*");
                for(j=1;j<=((2*i)-1);j++)
                    printf(" ");
                printf("*\n");
           }
        }
    }
    printf("Bye ^_^");
}
