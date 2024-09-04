/*

好好好 有用的来了 有用的来了
记得自己曾经做过 一个迷宫的游戏 

好好好 现在终于会一个自动寻址路径的算法了


									--作者:Kit  

*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#define maxsize 30                                 //定义保存路径的最大值 


/*方块结构体*/
typedef struct 
{
	int i;                                         //i j 行列 di方位 
	int j;
	int di;  
}Box; 

/*定义顺序栈*/
typedef struct 
{
	Box data[maxsize];
	int top; 
}Stack;   

/*函数功能:实现初始化顺序栈*/
bool Init_stack(Stack *stack)
{
	stack->top=-1;
	return true; 
} 

/*函数功能：销毁顺序栈*/
bool Destroy_stack(Stack *stack)
{
	free(stack);
	return true;
}
 
/*函数功能:取栈顶元素*/
Box Get_top(Stack *stack)
{
	Box e;
	e=stack->data[stack->top]; 
	return e;
} 

/*函数功能:出栈*/
bool Pop_stack(Stack *stack)
{
	if(stack->top==-1)
	return false; 
	stack->top--;
	return true; 
	 
}

/*函数功能:入栈*/
bool Push_stack(Stack *stack,Box e)
{
	if(stack->top==maxsize-1)
	return false;
	else 
	{
		stack->top++;
		stack->data[stack->top]=e;
	}  
	return true; 
}

/*函数功能:判空顺序栈*/
bool Empty_stack(Stack *stack)
{
	if(stack->top==-1)
	return true;
	else
	return false; 
} 

/*函数功能:找路径*/
bool find_road(int xi1,int xi2,int xe1,int xe2,int map[6][6])
{
	Box path[maxsize];                             // 保存路径 
	Stack *stack;
	stack=(Stack *)malloc(sizeof(Stack));
	Init_stack(stack); 
	int i,j,di,xi,xj;                              // i j di 保存取栈顶元素  xi xj 寻新空格
	int length,y;                                  //length 保存路径长度 y用于循环 
	Box e;
	e.di=-1;e.i=xi1;e.j=xi2;
	Push_stack(stack,e);                           //先将入口弹入栈顶 
	map[xi1][xi2]=-1;                              //弹入栈顶后 地图位置值为0
	bool find;                                     //find 用于是否找到下一步空格 
	while(!Empty_stack(stack))
	{
		e=Get_top(stack);                          //取栈顶元素 
		i=e.i;j=e.j;di=e.di;
		if(i==xe1&&j==xe2)                         //若找到出口
		{
			length=stack->top+1; 
			while(!Empty_stack(stack))
			{
				path[stack->top]=stack->data[stack->top];
				stack->top--; 
			}
			printf("找到啦！"); 
			for(y=0;y<length;y++)                  //输出路径 
			printf("(%d,%d)",path[y].i,path[y].j);
			Destroy_stack(stack);
			return true; 
			
		}                
		
		find=false;                               
		while(di<4&&!find)                         //寻找下一个方块 
		{
			di++; 
			switch(di)
			{
				case 0:xi=i-1;xj=j;break;
				case 1:xi=i;xj=j+1;break; 
				case 2:xi=i+1;xj=j;break; 
				case 3:xi=i;xj=j-1;break; 
				default:break; 
			}
			if(map[xi][xj]==0)
			find=true; 
		}
		if(di==4)                                  //说明此时 di=4 那么没有新方块可以走
		{
			Pop_stack(stack);
			map[i][j]=0;                           //回溯  
		}
		else                                       //找到方块 
		{
			stack->data[stack->top].di=di;         //找到栈顶 元素方位       
			e.i=xi;e.j=xj;e.di=-1;                 //将新方格弹进栈顶 
			Push_stack(stack,e);
			map[xi][xj]=-1;  
		} 
		                      
	}
	printf("呜呜呜,没找到路径！");
	Destroy_stack(stack); 
	return false; 
	 
} 

int main()
{
	int map[6][6]={
	{1,1,1,1,1,1},
	{1,0,0,0,1,1},
	{1,0,1,0,0,1},  
	{1,0,0,0,1,1},
	{1,1,0,0,0,1},
	{1,1,1,1,1,1}
	};                                             //初始化地图
	int xi1=1,xi2=1,xe1=4,xe2=4;                   //xi xj 入口 xe1 xe2 出口 
	find_road(xi1,xi2,xe1,xe2,map); 
	
}
