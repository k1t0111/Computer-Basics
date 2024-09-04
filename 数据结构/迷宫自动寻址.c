/*

�úú� ���õ����� ���õ�����
�ǵ��Լ��������� һ���Թ�����Ϸ 

�úú� �������ڻ�һ���Զ�Ѱַ·�����㷨��


									--����:Kit  

*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#define maxsize 30                                 //���屣��·�������ֵ 


/*����ṹ��*/
typedef struct 
{
	int i;                                         //i j ���� di��λ 
	int j;
	int di;  
}Box; 

/*����˳��ջ*/
typedef struct 
{
	Box data[maxsize];
	int top; 
}Stack;   

/*��������:ʵ�ֳ�ʼ��˳��ջ*/
bool Init_stack(Stack *stack)
{
	stack->top=-1;
	return true; 
} 

/*�������ܣ�����˳��ջ*/
bool Destroy_stack(Stack *stack)
{
	free(stack);
	return true;
}
 
/*��������:ȡջ��Ԫ��*/
Box Get_top(Stack *stack)
{
	Box e;
	e=stack->data[stack->top]; 
	return e;
} 

/*��������:��ջ*/
bool Pop_stack(Stack *stack)
{
	if(stack->top==-1)
	return false; 
	stack->top--;
	return true; 
	 
}

/*��������:��ջ*/
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

/*��������:�п�˳��ջ*/
bool Empty_stack(Stack *stack)
{
	if(stack->top==-1)
	return true;
	else
	return false; 
} 

/*��������:��·��*/
bool find_road(int xi1,int xi2,int xe1,int xe2,int map[6][6])
{
	Box path[maxsize];                             // ����·�� 
	Stack *stack;
	stack=(Stack *)malloc(sizeof(Stack));
	Init_stack(stack); 
	int i,j,di,xi,xj;                              // i j di ����ȡջ��Ԫ��  xi xj Ѱ�¿ո�
	int length,y;                                  //length ����·������ y����ѭ�� 
	Box e;
	e.di=-1;e.i=xi1;e.j=xi2;
	Push_stack(stack,e);                           //�Ƚ���ڵ���ջ�� 
	map[xi1][xi2]=-1;                              //����ջ���� ��ͼλ��ֵΪ0
	bool find;                                     //find �����Ƿ��ҵ���һ���ո� 
	while(!Empty_stack(stack))
	{
		e=Get_top(stack);                          //ȡջ��Ԫ�� 
		i=e.i;j=e.j;di=e.di;
		if(i==xe1&&j==xe2)                         //���ҵ�����
		{
			length=stack->top+1; 
			while(!Empty_stack(stack))
			{
				path[stack->top]=stack->data[stack->top];
				stack->top--; 
			}
			printf("�ҵ�����"); 
			for(y=0;y<length;y++)                  //���·�� 
			printf("(%d,%d)",path[y].i,path[y].j);
			Destroy_stack(stack);
			return true; 
			
		}                
		
		find=false;                               
		while(di<4&&!find)                         //Ѱ����һ������ 
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
		if(di==4)                                  //˵����ʱ di=4 ��ôû���·��������
		{
			Pop_stack(stack);
			map[i][j]=0;                           //����  
		}
		else                                       //�ҵ����� 
		{
			stack->data[stack->top].di=di;         //�ҵ�ջ�� Ԫ�ط�λ       
			e.i=xi;e.j=xj;e.di=-1;                 //���·��񵯽�ջ�� 
			Push_stack(stack,e);
			map[xi][xj]=-1;  
		} 
		                      
	}
	printf("������,û�ҵ�·����");
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
	};                                             //��ʼ����ͼ
	int xi1=1,xi2=1,xe1=4,xe2=4;                   //xi xj ��� xe1 xe2 ���� 
	find_road(xi1,xi2,xe1,xe2,map); 
	
}
