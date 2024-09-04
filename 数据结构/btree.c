/**********************************
@description: 实现二叉树的遍历  

@time:2023/11/19 

                                 */ 



#include <stdio.h>
#include <stdbool.h> 
#include <stdlib.h> 
#define max 50
 
 
 
/*节点结构体*/
typedef struct node
{
	char data; 
	struct  node *lchild;                                     //左右子树
	struct  node *rchild;
	 
}btnode; 
 

/*函数功能: 入 栈*/
bool push(btnode *stack[max],btnode *new1,int top)
{
	stack[top]=new1;
	return true;
} 


/*函数功能: 利用顺序栈 创建一个二叉树 */ 
btnode * creatbt(btnode *B,char str[])
{
	B=NULL; 
	int i=0,j,top=-1;                                        //i 取字符   j判定子树  top 栈顶指针
	btnode *stack[max],*new1;
	char ch; 
	ch=str[i];
	while(ch!='\0')                                          //根据序列判断 树的构成 
	{
		switch(ch)
		{
			case '(':top++;push(stack,new1,top);j=1;break;
			case ',':j=2;break;
			case ')':top--;break;
			default:                                         //遇到数字创建 新节点 
			new1=(btnode *)malloc(sizeof(btnode));
			new1->data=ch;
			new1->lchild=new1->rchild=NULL;
			if(B==NULL)
			{
				B=new1;
			}
			else                                             //判断 是否是第一个节点 
			{
				switch(j)
				{
					case 1:stack[top]->lchild=new1;break;
					case 2:stack[top]->rchild=new1;break;
				}
			}
		}
		i++;ch=str[i];  
	}  
	return B; 
} 

/*函数功能:实现先序遍历*/
bool pre(btnode *B)
{
	if(B!=NULL)
	{
		printf("(%c)",B->data);
		pre(B->lchild);
		pre(B->rchild);
	}
	return true; 	
}

/*函数功能:实现中序遍历*/
bool in(btnode *B)
{
	if(B!=NULL)
	{
		in(B->lchild);
		printf("(%c)",B->data);
		in(B->rchild);
	}
	return true; 	
}

/*函数功能:实现先序遍历*/
bool back(btnode *B)
{
	if(B!=NULL)
	{
		back(B->lchild);
		back(B->rchild);
		printf("(%c)",B->data);
	} 
	return true;	
}  

/*函数功能: 实现二叉树层次遍历*/
void mancen(btnode *B)
{
	printf("(%c)",B->data);
	if(B!=NULL)
	{
		
		printf("(%c)",B->lchild->data);
		printf("(%c)",B->rchild->data);
		pre(B->lchild);
		pre(B->rchild);
	}
} 

int main()
{
	btnode *B;
	char str[max]="A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))";                                                //二叉树字符串
	B=creatbt(B,str);
	printf("先序遍历:");
	pre(B); 
	printf("\n中序遍历:");
	in(B);
	printf("\n后序遍历:");
	back(B); 
	return 0;
}
