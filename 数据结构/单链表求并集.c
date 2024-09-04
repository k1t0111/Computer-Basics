/*

������ ���� A B
�󲢼� C 
 
                        --����:Kit 
*/


#include <stdio.h>
#include <stdlib.h>

/* ���嵥����ṹ�� */
typedef struct dlinkcode
{
	int data;
	struct dlinkcode *next; 
}linkcode;


/*��������:��ʼ��˫����*/
void init_link(linkcode *L)
{
	L->next=NULL; 
} 
 
/*��������:ĩβ����ڵ�*/
void insert_link(linkcode *L,int num)
{
	linkcode *s,*p=L;                           //s �½ڵ�
	while(p->next!=NULL)
	{
		p=p->next;	
	}                                          //�ҵ�ĩβ�ڵ� 
	s=(linkcode *)malloc(sizeof(linkcode));
	s->data=num;
	p->next=s;
	s->next=NULL; 
}

/*��������:����������*/
int length_link(linkcode *L)
{
	int length=0;   
	linkcode *p=L->next;
	while(p!=NULL)
	{
		length++;
		p=p->next; 
	}
	return length; 
} 


/*��������:����������*/
void sort_link(linkcode *L,int length)
{
	int i,j,temp;                              //i ,j ѭ�� temp ������ʱ����
	linkcode *p1=L,*p2;  
	for(i=1;i<length;i++)
	{
		p1=p1->next;
		p2=p1->next;
		for(j=i+1;j<=length;j++)
		{
			if(p1->data>=p2->data)
			{
				temp=p1->data;
				p1->data=p2->data;
				p2->data=temp; 
			}
			p2=p2->next; 
		} 
	} 
}

/*��������:ȥ���������ظ�Ԫ��*/
void delrea_link(linkcode *L)
{
	linkcode *p1=L->next,*p2,*temp;  //p1 p2 ǰ�������ڵ�   temp �滻�ڵ� 
	p2=p1->next; 
	while(p2!=NULL)
	{
		if(p1->data==p2->data)
		{
			temp=p2;
			p2=p2->next;
			p1->next=p2;
			free(temp); 
		} 
		else
		{
			p1=p2;
			p2=p2->next;
		}	
	} 
	 
} 
 
 
/*��������:β�巨����˫����*/
void creat_link(linkcode *L,int num[],int n)
{
	linkcode *r=L,*s;                   //s ������ 
	int i;                              //ѭ��
	for(i=0;i<n;i++)
	{
		s=(linkcode *)malloc(sizeof(linkcode));
		s->data=num[i];
		r->next=s;
		r=s; 
	} 
	r->next=NULL; 
	 
} 

/*��������:���������ϵ�����Ԫ�غϲ�����*/ 
void union_link(linkcode *A,linkcode *B,linkcode *C) 
{
	linkcode *p1=A->next,*p2=B->next;
	while(p1!=NULL&&p2!=NULL)
	{
		if(p1->data<p2->data)
		{
			insert_link(C,p1->data);//��С�Ĳ���������
			p1=p1->next; 
		} 
		else
		{
			insert_link(C,p2->data);//��С�Ĳ���������
			p2=p2->next; 
		} 
	} 
	while(p1!=NULL)                //��ֹA��B�� 
	{
		insert_link(C,p1->data);
		p1=p1->next; 
	}
	while(p2!=NULL)                //��ֹB��A��
	{
		insert_link(C,p2->data);
		p2=p2->next; 
	} 	 
}

/*��������:չʾ������������*/
void display_link(linkcode *L)
{
	linkcode *p=L->next;
	while(p!=NULL)
	{
		printf("%4d",p->data);
		p=p->next; 
	} 
} 

int main()
{
	int length=0;                  //C �ĳ���           
	int num1[5]={1,12,3,2,1},num2[7]={2,3,8,5,13,12,12}; 
	linkcode *A,*B,*C;             //������ʼ��������A B    CΪAB���� 
	init_link(A);                       
	printf("1"); 
	B->next=NULL;
	C->next=NULL;
	printf("1");	
	creat_link(A,num1,5);
	creat_link(B,num2,7);
	display_link(A);
	printf("\n");
	display_link(B);
	/* 
	union_link(A,B,C);             //��A B����Ԫ�ؼ���
	printf("\n");
	display_link(C);
	/*
	length=length_link(C);
	sort_link(C,length);           //����
	delrea_link(C);                //ɾ���ظ�Ԫ��
	display_link(C);               //չʾ����Ԫ�� 
	 */
	return 0;
} 
