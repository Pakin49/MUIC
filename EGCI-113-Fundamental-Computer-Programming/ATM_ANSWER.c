#include <stdio.h>
int main (){
	int t=10, f=10, h=10, T, F, H;
	int money, i=1;
	printf("Start...\n");
	printf("#100  : %d\n",h);
	printf("#500  : %d\n",f);
	printf("#1000 : %d\n",t);
	do{
		printf("Person%d-Withdraw: ",i);
		scanf("%d",&money);
		if(money==0)
			break;

		T=(money/1000);
		if(T>t) T=t;
		money = money-(T*1000);

		F=money/500;
		if(F>f) F=f;
		money = money-(F*500);

		H=money/100;
		if(H>h) H=h;
		money = money-(H*100);

		if(money!=0){
			printf(" Cannot Pay!\n");
			continue;
		}
		printf(" #100  : %d\n",H);
		printf(" #500  : %d\n",F);
		printf(" #1000 : %d\n",T);
		t=t-T;
		f=f-F;
        h=h-H;
		i++;

	}while(1);
	printf("End");
}
