#include<stdio.h>
void main()
{
    int a=0,b=1,c=1, tri, n,i;

    printf("Tribonacci position : ");
    scanf("%d",&n);
    printf("Tribonacci Value : ")
    if (n<0 && n==0)
        printf("can not compute")
    if (n==1)
        printf("0");
    if (n==2 || n==3)
        printf("1");
    else
        for(i=4;i<=n;i++)
        {
            tri = a+b+c;
            a=b;
            b=c;
            c=tri;
        }
    printf("%d",tri);
}
