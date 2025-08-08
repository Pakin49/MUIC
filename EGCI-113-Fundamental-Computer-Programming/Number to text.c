#include<stdio.h>
void main()
{
    int n,h,t,u;
    printf("Input : ");
    scanf("%d",&n);
    printf("Output : ");
    h=n/100;t=(n/10)%10;u=n%10;

    if (n<0 || n>999)
        printf("No answer \n");
    else if (n==0)
        printf("Zero");
    switch(h)
   {
    case 1: printf("One Hundred");break;
    case 2: printf("Two Hundred");break;
    case 3: printf("Three Hundred");break;
    case 4: printf("Four Hundred");break;
    case 5: printf("Five Hundred");break;
    case 6: printf("Six Hundred");break;
    case 7: printf("Seven Hundred");break;
    case 8: printf("Eight Hundred");break;
    case 9: printf("Nine Hundred");break;
   }
    if (h>0 && (t!=0 || u!=0))
        printf(" and ");
    switch(t)
    {
    case 2: printf("Twenty ");break;
    case 3: printf("Thirty ");break;
    case 4: printf("Forty ");break;
    case 5: printf("Fifty ");break;
    case 6: printf("Sixty ");break;
    case 7: printf("Seventy ");break;
    case 8: printf("Eighty ");break;
    case 9: printf("Ninety ");break;
    case 1: switch(u)
        {
            case 0: printf("Ten");break;
            case 1: printf("Eleven");break;
            case 2: printf("Twelve");break;
            case 3: printf("Thirteen");break;
            case 4: printf("Fourteen");break;
            case 5: printf("Fifteen");break;
            case 6: printf("Sixteen");break;
            case 7: printf("Seventeen");break;
            case 8: printf("Eighteen");break;
            case 9: printf("Nineteen");break;
        }
    }
    if (t!=1)
    switch (u)
    {
        case 1: printf("One");break;
        case 2: printf("Two");break;
        case 3: printf("Three");break;
        case 4: printf("Four");break;
        case 5: printf("Five");break;
        case 6: printf("Six");break;
        case 7: printf("Seven");break;
        case 8: printf("Eight");break;
        case 9: printf("Nine");break;
        }
}
