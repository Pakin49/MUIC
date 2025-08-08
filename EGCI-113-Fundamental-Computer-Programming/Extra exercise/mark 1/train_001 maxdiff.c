#include<stdio.h>
void main()
{
    int n , i , max , min ,x;
    printf("Number of integers: ");
    scanf("%d",&n);
    printf("Integers: ");

    for (i=0;i<n; i++)
       {
        scanf("%d",&x);
        if (i==0)
        {
            min=x;max=x;
        }
        else
        {
        if ( x > max)
            max = x;
        if ( x < min )
            min =  x;
        }
       }
    printf("max=%d min=%d\n",max,min);
    printf("Max-Min = %d",(max-min));
}
