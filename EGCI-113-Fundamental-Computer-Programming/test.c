#include<stdio.h>

int x2(int m, int n);
void main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    printf("%d %d\n",m,n);
    printf("M+N *2 == %d\n",x2(m,n));
    printf("%d %d\n",m,n);
}

int x2(int m, int n)//m+n*2
{
    return (m+n)*2;
    m*=10000;
    n*=10000;
}
