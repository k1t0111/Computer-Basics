/*

  双链表的九个基本运算
  及数据结构实验二的实验题三 
  
                     作者:Kit 
*/ 


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef int ElemType;                      //重命名 int
    
/*定义双链表结构体*/
typedef struct linkcode
{
	ElemType date;
	struct linkcode *next;
	struct linkcode *prior; 
}dlinkcode;

/*函数功能:初始化双链表*/
void initlink(dlinkcode *L)
{
	L->next=NULL;
	L->prior=NULL; 
} 

/*函数功能:头插法创建双链表 */ 
void  hcreatlink(dlinkcode *L,ElemType n,ElemType num[])
{
	ElemType i;                                //循环 
	dlinkcode *s;                         //新节点
	for(i=0;i<n;i++)
	{
		s=(dlinkcode *)malloc(sizeof(dlinkcode));
		s->date=num[i];
		s->next=L->next;
		if(L->next!=NULL)
			L->next->prior=s;
		s->prior=L;
		L->next=s; 
	} 
}


/*函数功能:尾插法创建双链表 */ 
void  rcreatlink(dlinkcode *L,ElemType n,ElemType num[5])
{
	ElemType i;                           //循环 
	dlinkcode *s,*r;                      //新节点
	r=L; 
	for(i=0;i<n;i++)
	{
		s=(dlinkcode *)malloc(sizeof(dlinkcode));
		s->date=num[i];
		r->next=s;
		s->prior=r;
		r=s; 
	}
	r->next=NULL; 
} 


/*函数功能: 销毁双链表*/
void destroylink(dlinkcode *L)
{
	dlinkcode *pre=L,*p=L->next;
	while(p!=NULL)
	{
		free(pre);
		pre=p;
		p=pre->next;
		
	}  
	free(pre);
}

/*函数功能:判断链表是否为空*/
bool emptylink(dlinkcode *L)
{
	if(L->next==NULL)
	return true;
	else
	return false; 
} 


/*函数功能:判断链表节点数量*/
ElemType numberlink(dlinkcode *L)
{
	ElemType n=0;                         // n记录节点个数 头节点为0
	dlinkcode *p=L;
	while(p->next!=NULL)
	{
		n++;
		p=p->next; 
	}
	return n; 
} 

/*函数功能:展示节点所有数据*/
void displaylink(dlinkcode *L)
{
	dlinkcode *p=L;
	while(p->next!=NULL)
	{
		p=p->next; 
		printf("%4d",p->date); 
	} 
} 

/*函数功能:根据序号找到相应元素*/
ElemType findlink(dlinkcode *L,ElemType n)
{
	if(L->next==NULL)                     //判空 
	return false;
	dlinkcode *p=L;
	ElemType i=0;                         //i判断节点个数 进行对比
	while(p->next!=NULL)
	{
		i++;
		p=p->next;
		if(i==n)
		return p->date;
	}
	printf("没有相应序号!\n"); 
}

/*函数功能:根据元素判断序号*/
ElemType dfindlink(dlinkcode *L,ElemType n)
{
	if(L->next==NULL)                    //判空
	return false;
	ElemType i=0;                        //i判断节点个数
	dlinkcode *p=L;
	while(p->next!=NULL)
	{
		i++; 
		p=p->next;
		if(p->date==n)
		return i;
	}
	printf("没有相应元素对应的序号!\n");
} 

/*函数功能:插入节点*/
bool insertlink(dlinkcode *L,ElemType num,ElemType n)
{
	
	ElemType i=0;                        //i判断节点个数
	dlinkcode *p=L,*s;                   //s 新生成节点 
	while(p->next!=NULL&&i!=n-1)
	{
		i++;
		p=p->next;                       //找n-1 节点位置 
	}
	if(i!=n-1)
	{
		printf("未找到需要插入的节点！\n");
		return false; 
	}
	else           
	if(p->next==NULL)                    //从最后一个节点插入 
	{
	 
		s=(dlinkcode *)malloc(sizeof(dlinkcode));
		s->date=num;
		s->next=p->next;
		s->prior=p;
	}
	else
	{
		s=(dlinkcode *)malloc(sizeof(dlinkcode));
		s->date=num;
		s->next=p->next;
		s->prior=p;
		p->next->prior=s;
		p->next=s;  
	}
} 

/*函数功能:删除指定节点*/
bool deletelink(dlinkcode *L,ElemType n )
{
	dlinkcode *p=L,*s;                  //s保存要删除的节点
	ElemType i=0;                       //i判断节点个数
	while(p->next!=NULL&&i!=n-1)
	{
		i++;
		p=p->next;
	}
	if(i!=n-1)
	{
		printf("未找到需要删除的节点！\n");
		return false; 
	} 
	else
	{
		s=p->next;
		p->next=p->next->next;
		p->next->prior=p;
		free(s); 
	} 
} 
int main() 
{
                                        //创建头节点 
	dlinkcode *h=(dlinkcode *)malloc(sizeof(dlinkcode));
	initlink(h);                        //(1)初始化双链表h
	int num[5]={1,3,2,4,5}; 
	rcreatlink(h,5,num);                //(2)尾插法插入 abcde 元素 依次为 1 3 2 4 5
	displaylink(h);                     //(3) 输出所有数据
	printf("\n");          
	printf("%d\n",numberlink(h));       //(4)输出节点长度
	printf("%d\n",emptylink(h));        //(5) 判断双链表是否为空
	printf("%d\n",findlink(h,3));       //(6)输出双链表h的第三个元素
	printf("%d\n",dfindlink(h,1));      //(7)输出元素a的位置 
	printf("\n"); 
	insertlink(h,8,4);                  //(8)第四个元素上插入f元素  8
	displaylink(h);                     //(9) 输出双链表h 
	printf("\n"); 
	deletelink(h,3);                    //(10) 删除双链表h的第三个元素
	displaylink(h);                     //(11) 输出双链表h 
	destroylink(h);                     //(12) 释放双链表h                                         									 
	
}
