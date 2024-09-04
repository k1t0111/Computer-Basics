/*

实现判断 保证栈的初始和末态都为空
判断给出io操作序列能否成功 


						--作者:Kit 

*/

#include <stdio.h>
#include <stdbool.h>

bool judge(char list[])
{
	int i,top=0;                          //top作为虚拟栈顶指针 
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
	char list[8]={'I','O','I','I','O','I','O','O'};  //保存序列 
	printf("%d",judge(list));             			 //判断是否符合条件 
}
  
