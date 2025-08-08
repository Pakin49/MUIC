#include<stdio.h>

void main()
{
    int w,l,r,d ;
    printf("Width : ");
    scanf("%d",&w);

    printf("Lenght: ");
    scanf("%d",&l);

    printf("Radius: ");
    scanf("%d",&r);

    d = 2*r;

    int x,y,n;
    x = l/d;
    y = w/d;
    n = x*y;

    printf("Number of circles: %d\n",n);
    printf("------------------------\n");
    printf("ID: 6580043");
}
