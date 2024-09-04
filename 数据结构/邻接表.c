/*
************************

@description: 图的存储邻接表存储的一些计算 
@time: 2023/12/1
@author: Kit

************************  
*/ 


#include <stdio.h>
#include <stdbool.h> 
#include <stdlib.h> 
#define max 4 



/*邻接表边节点*/
typedef struct node1
{
	struct node1 *next;                         //指针  数据 权重 
	int data;
	int weight;
	 
}Wnode; 


/*邻接表头节点*/
typedef struct node2
{
	            
	int data;                                   //节点数据  边指针 
	Wnode *Wnext; 
	
}Hnode; 


/*函数功能:创建一个图的邻接表*/
bool  Creat_list(int mat1[max][max],Hnode head[max])
{

	Wnode *p,*p1;                               //p创建新边节点 p1保存头头节点指针 
	int i,j=0;                                  // i j矩阵索引 
	for(i=0;i<max;i++)                          //初始化头节点数组 
	{
		head[i].data=i;
		head[i].Wnext=NULL; 
	} 
	i=0;
	int n=0;
	while(i<max)
	{ 
		while(j<max)                            //开始连接边节点 
		{
			if(mat1[i][j]==1)                   //判断有无 边 
			{
				n++;
				if(n==1)
				{
					p=(Wnode *)malloc(sizeof(Wnode));
					p->weight=1;
					p->data=j;
					head[i].Wnext=p;
					p1=p; 
				}
				else
				{                               //添加边节点 
					p=(Wnode *)malloc(sizeof(Wnode));
					p->weight=1;
					p->data=j;
					p1->next=p;
					p1=p;
				}						
			}
			j++; 	 
		}
		p1->next=NULL;n=0;   
		i++;j=0; 
	} 
	return true; 
} 


/*函数功能:释放邻接表内存*/
bool Free(Hnode head[max])
{
	int i,j;
	Wnode *p,*p1;                              //p 和p1交替删除 
	for(i=0;i<max;i++)
	{
		p=head[i].Wnext;
		while(p!=NULL)
		{
			p1=p; 
			p=p->next;
			free(p1);
			printf("成功!"); 
			
		}
		printf("\n");
		
	}
	return true; 
	 
}

/*函数功能:计算邻接表的每个顶点 入度出度以及 出度为0个数*/
bool  Calculate(Hnode head[max])
{
	Wnode *p,*p1;                           //边结点查找使用指针 
	int i,j;                           
	int num[max+2];                         //num 记录每个顶点出度
	for(i=0;i<max+2;i++)
		num[i]=0;
	for(i=0;i<max;i++)
	{
		p=head[i].Wnext;
		if(p==NULL)
		   num[max]++;                      //num[max] 记录出度为0的个数 
		while(p!=NULL)
		{ 
			num[max+1]++;                   //num[max+1] 记录出度的个数
			num[p->data]++;
			p=p->next;
		}
		printf("顶点%d的出度为:%d\n",i,num[max+1]); 
		num[max+1]=0;
	}
	printf("出度为0的顶点个数为:%d\n",num[max]);
	for(i=0;i<max;i++)
		printf("顶点%d的入度:%d\n",i,num[i]); 
} 

int main()
{
	int mat1[max][max]={{0,1,1,1},{0,0,0,1},{0,1,0,0},{0,0,0,0}};
	Hnode head[max];                           //创建头节点数组 
	Creat_list(mat1,head);
	Calculate(head);
	Free(head);
	 
} 
