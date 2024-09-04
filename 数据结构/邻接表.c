/*
************************

@description: ͼ�Ĵ洢�ڽӱ�洢��һЩ���� 
@time: 2023/12/1
@author: Kit

************************  
*/ 


#include <stdio.h>
#include <stdbool.h> 
#include <stdlib.h> 
#define max 4 



/*�ڽӱ�߽ڵ�*/
typedef struct node1
{
	struct node1 *next;                         //ָ��  ���� Ȩ�� 
	int data;
	int weight;
	 
}Wnode; 


/*�ڽӱ�ͷ�ڵ�*/
typedef struct node2
{
	            
	int data;                                   //�ڵ�����  ��ָ�� 
	Wnode *Wnext; 
	
}Hnode; 


/*��������:����һ��ͼ���ڽӱ�*/
bool  Creat_list(int mat1[max][max],Hnode head[max])
{

	Wnode *p,*p1;                               //p�����±߽ڵ� p1����ͷͷ�ڵ�ָ�� 
	int i,j=0;                                  // i j�������� 
	for(i=0;i<max;i++)                          //��ʼ��ͷ�ڵ����� 
	{
		head[i].data=i;
		head[i].Wnext=NULL; 
	} 
	i=0;
	int n=0;
	while(i<max)
	{ 
		while(j<max)                            //��ʼ���ӱ߽ڵ� 
		{
			if(mat1[i][j]==1)                   //�ж����� �� 
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
				{                               //��ӱ߽ڵ� 
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


/*��������:�ͷ��ڽӱ��ڴ�*/
bool Free(Hnode head[max])
{
	int i,j;
	Wnode *p,*p1;                              //p ��p1����ɾ�� 
	for(i=0;i<max;i++)
	{
		p=head[i].Wnext;
		while(p!=NULL)
		{
			p1=p; 
			p=p->next;
			free(p1);
			printf("�ɹ�!"); 
			
		}
		printf("\n");
		
	}
	return true; 
	 
}

/*��������:�����ڽӱ��ÿ������ ��ȳ����Լ� ����Ϊ0����*/
bool  Calculate(Hnode head[max])
{
	Wnode *p,*p1;                           //�߽�����ʹ��ָ�� 
	int i,j;                           
	int num[max+2];                         //num ��¼ÿ���������
	for(i=0;i<max+2;i++)
		num[i]=0;
	for(i=0;i<max;i++)
	{
		p=head[i].Wnext;
		if(p==NULL)
		   num[max]++;                      //num[max] ��¼����Ϊ0�ĸ��� 
		while(p!=NULL)
		{ 
			num[max+1]++;                   //num[max+1] ��¼���ȵĸ���
			num[p->data]++;
			p=p->next;
		}
		printf("����%d�ĳ���Ϊ:%d\n",i,num[max+1]); 
		num[max+1]=0;
	}
	printf("����Ϊ0�Ķ������Ϊ:%d\n",num[max]);
	for(i=0;i<max;i++)
		printf("����%d�����:%d\n",i,num[i]); 
} 

int main()
{
	int mat1[max][max]={{0,1,1,1},{0,0,0,1},{0,1,0,0},{0,0,0,0}};
	Hnode head[max];                           //����ͷ�ڵ����� 
	Creat_list(mat1,head);
	Calculate(head);
	Free(head);
	 
} 
