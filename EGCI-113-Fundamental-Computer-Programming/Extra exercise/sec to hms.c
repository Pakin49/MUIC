#include<stdio.h>
void main()
{
    int time,h,m,s;
    while(1)
    {
        if(time==0)
            break;
        printf("Input: ");
        scanf("%d",&time);

        h = time/3600;
        time = time-(h*3600);
        m = time/60;
        time = time-(m*60);
        s = time;
        printf("%02d:%02d:%02d\n",h,m,s);
    }
}
