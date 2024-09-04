/***

	@description:��ŵ���ݹ��㷨
	@time:2023/10/27
	@author:Kit 

 ***/

#include <stdio.h>

/*n:Բ������ pos1:��ʼλ�� pos2:��תλ�� pos3:Ŀ��λ��*/ 
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
