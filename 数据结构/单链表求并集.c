/*

单链表 集合 A B
求并集 C 
 
                        --作者:Kit 
*/


#include <stdio.h>
#include <stdlib.h>

/* 定义单链表结构体 */
typedef struct dlinkcode
{
	int data;
	struct dlinkcode *next; 
}linkcode;


/*函数功能:初始化双链表*/
void init_link(linkcode *L)
{
	L->next=NULL; 
} 
 
/*函数功能:末尾插入节点*/
void insert_link(linkcode *L,int num)
{
	linkcode *s,*p=L;                           //s 新节点
	while(p->next!=NULL)
	{
		p=p->next;	
	}                                          //找到末尾节点 
	s=(linkcode *)malloc(sizeof(linkcode));
	s->data=num;
	p->next=s;
	s->next=NULL; 
}

/*函数功能:计算链表长度*/
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


/*函数功能:单链表排序*/
void sort_link(linkcode *L,int length)
{
	int i,j,temp;                              //i ,j 循环 temp 交换临时变量
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

/*函数功能:去除单链表重复元素*/
void delrea_link(linkcode *L)
{
	linkcode *p1=L->next,*p2,*temp;  //p1 p2 前后两个节点   temp 替换节点 
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
 
 
/*函数功能:尾插法创建双链表*/
void creat_link(linkcode *L,int num[],int n)
{
	linkcode *r=L,*s;                   //s 新链表 
	int i;                              //循环
	for(i=0;i<n;i++)
	{
		s=(linkcode *)malloc(sizeof(linkcode));
		s->data=num[i];
		r->next=s;
		r=s; 
	} 
	r->next=NULL; 
	 
} 

/*函数功能:求两个集合的所有元素合并集合*/ 
void union_link(linkcode *A,linkcode *B,linkcode *C) 
{
	linkcode *p1=A->next,*p2=B->next;
	while(p1!=NULL&&p2!=NULL)
	{
		if(p1->data<p2->data)
		{
			insert_link(C,p1->data);//把小的插入新链表
			p1=p1->next; 
		} 
		else
		{
			insert_link(C,p2->data);//把小的插入新链表
			p2=p2->next; 
		} 
	} 
	while(p1!=NULL)                //防止A比B长 
	{
		insert_link(C,p1->data);
		p1=p1->next; 
	}
	while(p2!=NULL)                //防止B比A长
	{
		insert_link(C,p2->data);
		p2=p2->next; 
	} 	 
}

/*函数功能:展示链表所有数据*/
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
	int length=0;                  //C 的长度           
	int num1[5]={1,12,3,2,1},num2[7]={2,3,8,5,13,12,12}; 
	linkcode *A,*B,*C;             //创建初始化新链表A B    C为AB并集 
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
	union_link(A,B,C);             //求A B所有元素集合
	printf("\n");
	display_link(C);
	/*
	length=length_link(C);
	sort_link(C,length);           //排序
	delrea_link(C);                //删除重复元素
	display_link(C);               //展示所有元素 
	 */
	return 0;
} 
