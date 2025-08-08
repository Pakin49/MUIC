#include<stdio.h>
#include<string.h>

typedef struct
{
    char name[20];
    int score;
}data;
void sort(data highscore[]);

void sort(data highscore[])
{
    data temp;
    for (int i=0;i<6;i++)
        for(int j=i+1;j<6;j++)
            if (highscore[i].score< highscore[j].score)
            {
                temp = highscore[i];
                highscore[i] = highscore[j];
                highscore[j] = temp;
            }
}

void main()
{
    data highscore[6];
    do
    {
        FILE *fp1, *fp2;
        if ((fp1 = (fopen("file.txt","r")))==NULL)
            printf("Error: the file is not exist\n");

        for (int i=0;i<5;i++)
        {
            fscanf(fp1,"%s %d\n",&highscore[i].name,&highscore[i].score);
        }

        printf("Name : ");scanf("%s",&highscore[5].name);
        printf("Score: ");scanf("%d",&highscore[5].score);
        sort(highscore);

        printf("Top 5\n");
        for(int i=0;i<5;i++)
        {
            printf("%d. %-10s %2d\n",i+1,highscore[i].name,highscore[i].score);
        }

        fp2 = fopen("file.txt","w");
        for (int i=0;i<5;i++)
        {
            fprintf(fp2,"%s %d\n",highscore[i].name,highscore[i].score);
        }

        fclose(fp1);fclose(fp2);
    }while(strcmp("quit",highscore[5].name)!=0);
}
