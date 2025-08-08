#include<stdio.h>
void main()
{
    int i;
    float score,sum = 0;
    for(i=1;1;i++)
    {
        printf("Score %d : ",i);
        scanf("%f",&score);
        if (score == -100)
        {
            i-=1;break;
        }
        if (score<0 || score>100)
        {
            printf("-- Score must be 0 to 100\n");
            i-=1; continue;
        }
        sum += score;
    }
    printf("Average = %.2f",(sum/i));
}
