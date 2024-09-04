/***

	@description:汉诺塔非递归算法
	@time:2023/10/27
	@author:Kit 

 ***/
#include <stdio.h> 

/*定义一个三个环的结构体 top环指向最高位置 */ 
struct hanoi1
{
	int top1,top2,top3;
}; 


int hanoi(struct honoi1 *h1)
{
	if(h1->top1==3)
	{
		printf("A->C");
		printf("A->B");
		h1->top2++;
		h1->top3++;
		return hanoi(h1); 
	}
	if(h1->top2==1&&h1->top3==1)
	{
		printf("C->B");
		printf("A->C");
		printf("B->A");
		printf("B->C");
		h1->top2=0;
		h1->top1=1;
		h1->top3=2; 
		return honoi(h1); 
	}
	if(h1->top3==2)
	{
		printf("A->C");
		return 0; 
	} 
	 
} 

int main()
{
	struct hanoi1 *h1;
	h1=(struct hanoi1*)malloc(sizeof(struct hanoi1));
	h1->top1=3;h1->top2=0;h1->top3=0;
	honoi(h1); 
} 
