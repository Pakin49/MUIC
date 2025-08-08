#include<stdio.h>
void main()
{
    char name[20];
    int number_son ;
    int acre,yard,foot;
    printf("=================================\n");
    printf("  Name: ");
    scanf("%s",&name);
    printf("  Number of Sons: ");
    scanf("%d",&number_son);
    printf("  Area(acre-yd2-ft2): ");
    scanf("%d-%4d-%d",&acre,&yard,&foot);

    int total_in_foot;
    int foot_for_son, yard_for_son, acre_for_son;
    total_in_foot = (acre*4840*9)+(yard*9)+foot;
    foot_for_son = total_in_foot /4 ;

    int remainder_foot, first_total_foot, first_foot,first_yard,first_acre;
    remainder_foot =  total_in_foot % 4;
    first_total_foot = foot_for_son + remainder_foot;
    first_foot = first_total_foot%9;
    first_yard = first_total_foot/9;
    first_acre = first_yard/4840, first_yard %=4840;


    yard_for_son = foot_for_son/9, foot_for_son %=9 ;
    acre_for_son = yard_for_son/4840; yard_for_son %= 4840;


    printf("  The First Son: %d-%4d-%d\n",first_acre, first_yard, first_foot);
    printf("  Other son(s) : %d-%4d-%d\n",acre_for_son, yard_for_son, foot_for_son);
    printf("=================================\n");
    printf("ID: 6580043");

}
