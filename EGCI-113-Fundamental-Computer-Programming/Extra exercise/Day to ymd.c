#include<stdio.h>
void main()
{
    int number_day,day,week,year;

    printf("number of days : ");
    scanf("%d",&number_day);

    year = number_day/365;
    number_day %= 365;
    week = number_day/7;
    day = number_day%=7;

    printf("Years: %d\n",year);
    printf("Weeks: %d\n",week);
    printf("Days; %d",day);
}
