    #include <stdio.h>
#include <time.h>
#include <stdlib.h>

void up ();
void down();
void right ();
void left();
void show();
void gen();

int count;
int table[4][4]={0};
void main()
{
    char move;
    srand(time(NULL));
  {
    gen();gen();
    show ();

    while(1)
    {
        int space;
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                if(table[i][j]==0)
                  space++;
        if (space==0)
        {
            printf("**********************\n");
            printf("        You Lost\n");
            printf("**********************\n");
            break;
        }
        scanf(" %c",&move);
        int check=0;
        switch(move)
        {
        case 'w' :{ up();break;}
        case 'a' :{ left();break;}
        case 's' :{ down();break;}
        case 'd' :{ right();break;}
        default : {printf("Only use wasd to move\n"); check=1;break;}
        }
        if (check==1)continue;
        if (count==0)
        {
            printf("Can't move try other direction!\n");
            continue;
        }
        for (int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                if (table[i][j]==2048)
                {
                    printf("**********************\n");
                    printf("        You Win\n");
                    printf("**********************\n");
                    break;
                }
        gen();printf("\n");
        show ();
    }
  }
}
void show()
{
    for(int i=0;i<24;i++)printf("*");printf("\n");
    for(int i=0 ; i < 4;i++)
    {
      for (int j = 0; j < 4 ; j++)
        {
          printf("%5d",table[i][j]);
        }
      printf("\n");
    }
    for(int i=0;i<24;i++)printf("*");printf("\n");
}

void gen()
{
    int i,j;
    while(1)
    {
        i = rand()%4;
        j = rand()%4;

    if (table[i][j]==0)
        {
            table[i][j] = (rand() / (RAND_MAX + 1.0) < 0.9) ? 2 : 4;
            break;
        }
    }
}

void up()
{
    int j,i;
    count=0;
    for (j=0 ; j<4 ;j++)
    {
        for( i = 0; i<3 ;i++)
            if (table[i][j] == 0)
            {
                for (int n=1;n<=3-i;n++)
                {
                 if (table[i+n][j]!=0)
                  {
                    table[i][j]=table[i+n][j];
                    table[i+n][j]=0;
                    //printf("Hello %d\n",++count);
                    count++;
                    break;
                  }
                }
            }
    }
    for (int j=0;j<4;j++)
        for (int i=0;i<3;i++)
        {
            if (table[i][j]==table[i+1][j])
            {
                table[i][j] *= 2;
                table[i+1][j] = 0;
                if (table[i][j]!=0)/*printf("Hii %d\n",++count);*/
                    count++;
            }
        }
    for (j=0 ; j<4 ;j++)
    {
        for( i = 0; i<3 ;i++)
            if (table[i][j] == 0)
            {
                for (int n=1;n<=3-i;n++)
                {
                 if (table[i+n][j]!=0)
                  {
                    table[i][j]=table[i+n][j];
                    table[i+n][j]=0;
                    //printf("Hello %d\n",++count);
                    count++;
                    break;
                  }
                }
            }
    }
    printf("move up\n");
}

void left()
{
    int j,i;
    count=0;
    for (i=0 ; i<4 ;i++)
    {
        for( j = 0; j<3 ;j++)
            if (table[i][j] == 0)
            {
                for (int n=1;n<=3-j;n++)
                {
                 if (table[i][j+n]!=0)
                  {
                    table[i][j]=table[i][j+n];
                    table[i][j+n]=0;
                    //printf("Hello %d\n",++count);
                    count++;
                    break;
                  }
                }
            }
    }
    for (int i=0;i<4;i++)
        for (int j=0;j<3;j++)
        {
            if (table[i][j]==table[i][j+1])
            {
                table[i][j] *= 2;
                table[i][j+1] = 0;
                if (table[i][j]!=0)/*printf("Hii %d\n",++count);*/
                    count++;
            }
        }
    for (i=0 ; i<4 ;i++)
    {
        for( j = 0; j<3 ;j++)
            if (table[i][j] == 0)
            {
                for (int n=1;n<=3-j;n++)
                {
                 if (table[i][j+n]!=0)
                  {
                    table[i][j]=table[i][j+n];
                    table[i][j+n]=0;
                    //printf("Hello %d\n",++count);
                    count++;
                    break;
                  }
                }
            }
    }
    printf("move left\n");
}

void right()
{
    int j,i;
    count=0;
    for (i=0 ; i<4 ;i++)
    {
        for( j = 3; j>0 ;j--)
            if (table[i][j] == 0)
            {
                for (int n=1;n<=j;n++)
                {
                 if (table[i][j-n]!=0)
                  {
                    table[i][j]=table[i][j-n];
                    table[i][j-n]=0;
                    //printf("Hello %d\n",++count);
                    count++;
                    break;
                  }
                }
            }
    }
    for (int i=0;i<4;i++)
        for (int j=3;j>0;j--)
        {
            if (table[i][j]==table[i][j-1])
            {
                table[i][j] *= 2;
                table[i][j-1] = 0;
                if (table[i][j]!=0)/*printf("Hii %d\n",++count);*/
                    count++;
            }
        }
    for (i=0 ; i<4 ;i++)
    {
        for( j = 3; j>0 ;j--)
            if (table[i][j] == 0)
            {
                for (int n=1;n<=j;n++)
                {
                 if (table[i][j-n]!=0)
                  {
                    table[i][j]=table[i][j-n];
                    table[i][j-n]=0;
                    //printf("Hello %d\n",++count);
                    count++;
                    break;
                  }
                }
            }
    }
    printf("move right\n");
}
void down()
{
    int j,i;
    count=0;
    for (j=0 ; j<4 ;j++)
    {
        for( i = 3; i>0 ;i--)
            if (table[i][j] == 0)
            {
                for (int n=1;n<=i;n++)
                {
                 if (table[i-n][j]!=0)
                  {
                    table[i][j]=table[i-n][j];
                    table[i-n][j]=0;
                    //printf("Hello %d\n",++count);
                    count++;
                    break;
                  }
                }
            }
    }
    for (int j=0;j<4;j++)
        for (int i=3;i>0;i--)
        {
            if (table[i][j]==table[i-1][j])
            {
                table[i][j] *= 2;
                table[i-1][j] = 0;
                if (table[i][j]!=0)/*printf("Hii %d\n",++count);*/
                    count++;
            }
        }
    for (j=0 ; j<4 ;j++)
    {
        for( i = 3; i>0 ;i--)
            if (table[i][j] == 0)
            {
                for (int n=1;n<=i;n++)
                {
                 if (table[i-n][j]!=0)
                  {
                    table[i][j]=table[i-n][j];
                    table[i-n][j]=0;
                    //printf("Hello %d\n",++count);
                    count++;
                    break;
                  }
                }
            }
    }
    printf("move down\n");
}
