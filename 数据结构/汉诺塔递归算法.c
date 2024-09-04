/***

	@description:汉诺塔递归算法
	@time:2023/10/27
	@author:Kit 

 ***/

#include <stdio.h>

/*n:圆盘数量 pos1:起始位置 pos2:中转位置 pos3:目标位置*/ 
void hanoi(int n,char pos1,char pos2,char pos3)
{
	if(n==1)
	{
		printf("%c->%c\n",pos1,pos3);
	}
	else
	{
		hanoi(n-1,pos1,pos3,pos2);
		printf("%c->%c\n",pos1,pos3);
		hanoi(n-1,pos2,pos1,pos3); 
	} 
	
} 

int main()
{
	hanoi(3,'A','B','C'); 
	return 0; 
} 
