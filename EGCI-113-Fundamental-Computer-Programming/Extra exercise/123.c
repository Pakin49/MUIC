#include<stdio.h>
void main()
{
    int n,a=1,i;
    printf("Input: ");
    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        printf("%d\n",a++);
        if (a==4)
            a = 1;
    }
}
