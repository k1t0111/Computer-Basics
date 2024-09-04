/*
    实现循环队列的基本运算   


                             --作者：Kit 
*/


#include <stdio.h>
#define  MAXSIZE 10
#include <stdbool.h>
#include <stdlib.h> 

/*  定义char 为ElemType*/
typedef char ElemType;
 
/*定义 顺序队列结构体 */
typedef struct
{
	ElemType data[MAXSIZE]; 
	int front,rear;
		 
}line;
 
/*函数功能: 初始化循环队列 */
bool init_line(line *L)
{
	L->front=0;
	L->rear=0; 
	return true;
}


/*函数功能:创建 循环队列*/
bool creat_line(line *L,ElemType chr[],int n)
{
	int i;                                //i 用于循环 
	if(n>MAXSIZE)
	return false;
	for(i=0;i<n;i++)
	{
		
		L->data[(L->rear+1)%MAXSIZE]=chr[i];
		L->rear=(L->rear+1)%MAXSIZE;
	}
	return true; 
}

/*函数功能: 销毁队列*/ 
bool destroy_line(line *L)
{
	free(L); 
} 

/*函数功能:判断队列是否为空*/
bool empty_line(line *L)
{
	if(L->front==L->rear)
	return true;
	else
	return false;	
} 

/*函数功能: 向队列中添加元素*/
bool insert_line(line *L,ElemType chr)
{
	if((L->rear+1)%MAXSIZE==L->front)      // 判断 队列为满 
	return false;
	L->data[(L->rear+1)%MAXSIZE]=chr;
	L->rear=(L->rear+1)%MAXSIZE;
	
}

/*函数功能:删除队列中的元素*/
ElemType delete_line(line *L)
{
	ElemType chr; 
	if(L->front==L->rear)                  //判断 队列为空 
	return false;
	chr=L->data[(L->front+1)%MAXSIZE]; 
	L->front=(L->front+1)%MAXSIZE;
	return chr;
	 
} 

int main()
{
	int i; 
	line *q;                               //q 新创建队列
	init_line(q);                          //(1) 初始化队列 
    printf("%4d\n",empty_line(q));         //(2) 判断队列是否为空 
	insert_line(q,'a');                    //(4) 依次进队 abc 
	insert_line(q,'b');
	insert_line(q,'c');
	printf("%4c\n",delete_line(q));        //(5) 出队一个元素并且输出
	insert_line(q,'d');                    //(6) 依次进队 def 
	insert_line(q,'e');
	insert_line(q,'f');
	for(i=0;i<5;i++)                       //(7) 出队序列 
	{
		printf("%4c",delete_line(q));      
	} 
	destroy_line(q);                       //(8) 释放序列            
} 
