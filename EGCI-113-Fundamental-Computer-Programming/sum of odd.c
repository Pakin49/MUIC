#include<stdio.h>
void main()
{
    int n,total ;
    n = 1;
    total = 0;

    while ( n<1000)
    {
        total += n;
        n+=2;
    }
    printf("Total = %d",total);
}
