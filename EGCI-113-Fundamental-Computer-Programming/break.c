#include<stdio.h>
void main()
{
  int i;
  double num,sum = 0;

  for (i=1;i<=10;i++)
  {
      printf("Input%d : ",i);
      scanf("%lf",&num);
      if (num<0)
        continue;
      sum+=num;
  }
    printf("Output: %lf",sum);
}
