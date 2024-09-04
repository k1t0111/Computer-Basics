#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define back_time 50                         //固定的时间 

/*函数功能: 随机获取k 模拟重复次数*/
int Get_K(){
	int k=rand()%10;
	if(k<10)
		return k;
	else 
		return 10; 
} 

int main(){
	
	int Time_Sco,Num;                        // 范围 Num 次数 
	srand(time(NULL));                       //随机数种子
	Time_Sco=(1<<Get_K())-1;               
	printf("%d",Time_Sco);
	Num=rand()%Time_Sco;                     //在0-2`k-1 选择
	printf("您的时间为%d,%d",Num,Num*back_time);
			
}
	

