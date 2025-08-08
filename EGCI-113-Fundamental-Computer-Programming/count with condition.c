#include<stdio.h>
void main()
{
    int n;
    printf("Input: ");
    scanf("%d",&n);
    int count=0, x=0;
    while (++x<=n)
        {
            if (((x%3)==0)||((x%7)==0))
                {
                count++;
                }
        }
    printf("Count = %d",count);
}
