#include<stdio.h>
void main()
{
    int data[1000];
    int i=0,sum=0;
    do
    {
        scanf("%d",&data[i]);
        if(data[i]<0)
            break;
        sum+=data[i];
    }while(data[i++]>=0);

    FILE *fp;
    if ((fp=fopen("result.txt","w"))==NULL)
    {
        printf("Cannot open.\n");
        return -1;
    }
    for(int j=0;j<i;j++)
        {
        fprintf(fp,"%d ",data[j]);
        printf("%d ",data[j]);
        }
    fprintf(fp,"\nsum=%d",sum);
    printf("\nsum=%d",sum);
    fclose(fp);
}
