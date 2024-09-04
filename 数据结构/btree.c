/**********************************
@description: ʵ�ֶ������ı���  

@time:2023/11/19 

                                 */ 



#include <stdio.h>
#include <stdbool.h> 
#include <stdlib.h> 
#define max 50
 
 
 
/*�ڵ�ṹ��*/
typedef struct node
{
	char data; 
	struct  node *lchild;                                     //��������
	struct  node *rchild;
	 
}btnode; 
 

/*��������: �� ջ*/
bool push(btnode *stack[max],btnode *new1,int top)
{
	stack[top]=new1;
	return true;
} 


/*��������: ����˳��ջ ����һ�������� */ 
btnode * creatbt(btnode *B,char str[])
{
	B=NULL; 
	int i=0,j,top=-1;                                        //i ȡ�ַ�   j�ж�����  top ջ��ָ��
	btnode *stack[max],*new1;
	char ch; 
	ch=str[i];
	while(ch!='\0')                                          //���������ж� ���Ĺ��� 
	{
		switch(ch)
		{
			case '(':top++;push(stack,new1,top);j=1;break;
			case ',':j=2;break;
			case ')':top--;break;
			default:                                         //�������ִ��� �½ڵ� 
			new1=(btnode *)malloc(sizeof(btnode));
			new1->data=ch;
			new1->lchild=new1->rchild=NULL;
			if(B==NULL)
			{
				B=new1;
			}
			else                                             //�ж� �Ƿ��ǵ�һ���ڵ� 
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

/*��������:ʵ���������*/
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

/*��������:ʵ���������*/
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

/*��������:ʵ���������*/
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

/*��������: ʵ�ֶ�������α���*/
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
	char str[max]="A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))";                                                //�������ַ���
	B=creatbt(B,str);
	printf("�������:");
	pre(B); 
	printf("\n�������:");
	in(B);
	printf("\n�������:");
	back(B); 
	return 0;
}
