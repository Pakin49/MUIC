#include<stdio.h>
void main()
{
    int n,a=2;
    scanf("%d",&n);
    for(int i=1;i<n;i++)
        a*= 2;
    printf("%d",a);
}
