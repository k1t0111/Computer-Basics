/*
实现 递归 求数组的平均数 

						--作者:Kit 
*/ 


/*函数功能: 计算数组元素里面的平均值*/
int n1;                                           //n1全局变量 保存数组个数  

int average(int num[],int n)
{
	if(n==n1-1)
	return  (num[n]+average(num,n-1))/n1;
	if(n==0)
	return num[0];
	else 
	return num[n]+average(num,n-1); 
} 


#include <stdio.h>
int main()
{
	int num[100]; 
	int i,n;                                      // n表示数组个数 
	printf("请输入n:\n");
	scanf("%d",&n);
	n1=n; 
	printf("请输入n个整数:\n"); 
	for(i=0;i<n;i++)
	{
		scanf("%d",&num[i]); 
	}
	printf("%d",average(num,n-1)); 
	 
} 
