/*

ʵ���ж� ��֤ջ�ĳ�ʼ��ĩ̬��Ϊ��
�жϸ���io���������ܷ�ɹ� 


						--����:Kit 

*/

#include <stdio.h>
#include <stdbool.h>

bool judge(char list[])
{
	int i,top=0;                          //top��Ϊ����ջ��ָ�� 
	for(i=0;i<8;i++)
	{
		if(list[i]=='I')
		{
			top++;
		}
		else
		{
			top--;
			if(top<0)
			break;
		}
		 
	}
	if(i!=8||top!=0)
	return false;
	else
	return true; 
}

int main()
{
	int i;                       
	char list[8]={'I','O','I','I','O','I','O','O'};  //�������� 
	printf("%d",judge(list));             			 //�ж��Ƿ�������� 
}
  
