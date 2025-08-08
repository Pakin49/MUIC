#include<stdio.h>
void main()

{
    int n,i,count;
    printf("Input : ");
    scanf("%d",&n);
    for (i=1;(i<(2*n)+1);i++)
    {
        for(count=1;count<=(n+1-i);count++)
            printf(" ");
        for(count=1;count<=i;count++)
            printf("*");
        printf("\n");
    }
}


/*{
    int n,count=0,i;
    printf("Input n (2<=n<=20): ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        count = 0;
        do {
            printf(" ");
            count++;
        }while(count<=(n-i+1));
        do{
            printf("*");
            count++;
        }while(count<=i);
}*/
