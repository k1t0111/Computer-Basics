/***********************************************
								
@description:顺序存储结构二叉树,求叶子节点个数  
@time: 2023/11/15				
@author:Kit  					
								
***********************************************/

#include <stdio.h>

/*函数功能:计算叶子节点个数*/
int count(char bt[])
{
	char chr1,chr2;                                    //chr  1 2  对比相邻字符 
	int i=1,sum=0;                                     //i 依次取数组值  sum 叶子节点总数 
	while(bt[i]!='\0')
	{

		if(i%2==0)                                     //判断是不是 偶数对子 
		{
			chr2=bt[i];
			if(chr2!='#'&&chr1!='#')
			sum++; 
		}
		else                                           //奇数给chr1 
		{
			chr1=bt[i]; 
		}
		i++;
	}
	return sum+1;
	
} 

int main()
{
	char bt[11]={'A','B','C','#','D',
				 '#','E','F','#','G'};                //构造二叉树 
	printf("%d",count(bt)); 
		
	return 0;
}



