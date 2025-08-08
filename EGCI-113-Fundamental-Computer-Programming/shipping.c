#include<stdio.h>

void main()
{
    int distance,shipping,price;
    printf("Price     : ",&price);
    scanf("%d",&price);
    printf("Distance  : ");
    scanf("%d",&distance);

    if (distance>40)
        shipping += (30*(distance-40));
    if (distance>=31)
        {
        if (distance<=40)
            shipping += (20*(distance-30));
        else
            shipping += 200;
        }
     if (distance>=21)
        {
        if (distance<=30)
            shipping += (15*(distance-20));
        else
            shipping += 150;
        }
    if (distance>=16)
        {
        if (distance<=20)
            shipping += (10*(distance-15));
        else
            shipping += 50;
        }
   if (price<5000)
        {
        if (distance>15)
            shipping+=(5*15);
        else
            shipping += (distance*5);
        }
    printf("TotalPrice: %d",(price+shipping));
}
