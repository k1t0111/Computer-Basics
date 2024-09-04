/**************

@description: 图的存储邻接矩阵的 一些计算 
@time: 2023/12/1
@author: Kit
  
***************/ 


#include <stdio.h>
#define  max 10



/*函数功能:实现求顶点的入度 出度*/
void mat(int mat1[max][max]) 
{
	int i,j; 
	int in=0,out=0,out0=0;                                 //in 入度 out 出度 out0 出度为0
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)                                   //双层循环 查找每个顶点 
		{
			if(mat1[j][i]==1)
			  in++;
			if(mat1[i][j]==1)
			  out++;
			 
		}
		printf("%d的入度为:%d\n",i,in); 
		printf("%d的出度为:%d\n",i,out); 
		if(out==0)
		out0++; 
		out=0;in=0;                                        //置0 进行下一个节点 判断 
	}
	printf("出度为0的顶点数量为:%d",out0); 
	
}

int main()
{
	//创建  邻接矩阵 
	int mat1[max][max]={{0,1,1,1},{0,0,0,1},{0,1,0,0},{0,0,0,0}};
	mat(mat1); 
	
	
} 
