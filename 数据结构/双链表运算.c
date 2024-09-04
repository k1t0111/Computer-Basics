/*

  ˫����ľŸ���������
  �����ݽṹʵ�����ʵ������ 
  
                     ����:Kit 
*/ 


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef int ElemType;                      //������ int
    
/*����˫����ṹ��*/
typedef struct linkcode
{
	ElemType date;
	struct linkcode *next;
	struct linkcode *prior; 
}dlinkcode;

/*��������:��ʼ��˫����*/
void initlink(dlinkcode *L)
{
	L->next=NULL;
	L->prior=NULL; 
} 

/*��������:ͷ�巨����˫���� */ 
void  hcreatlink(dlinkcode *L,ElemType n,ElemType num[])
{
	ElemType i;                                //ѭ�� 
	dlinkcode *s;                         //�½ڵ�
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


/*��������:β�巨����˫���� */ 
void  rcreatlink(dlinkcode *L,ElemType n,ElemType num[5])
{
	ElemType i;                           //ѭ�� 
	dlinkcode *s,*r;                      //�½ڵ�
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


/*��������: ����˫����*/
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

/*��������:�ж������Ƿ�Ϊ��*/
bool emptylink(dlinkcode *L)
{
	if(L->next==NULL)
	return true;
	else
	return false; 
} 


/*��������:�ж�����ڵ�����*/
ElemType numberlink(dlinkcode *L)
{
	ElemType n=0;                         // n��¼�ڵ���� ͷ�ڵ�Ϊ0
	dlinkcode *p=L;
	while(p->next!=NULL)
	{
		n++;
		p=p->next; 
	}
	return n; 
} 

/*��������:չʾ�ڵ���������*/
void displaylink(dlinkcode *L)
{
	dlinkcode *p=L;
	while(p->next!=NULL)
	{
		p=p->next; 
		printf("%4d",p->date); 
	} 
} 

/*��������:��������ҵ���ӦԪ��*/
ElemType findlink(dlinkcode *L,ElemType n)
{
	if(L->next==NULL)                     //�п� 
	return false;
	dlinkcode *p=L;
	ElemType i=0;                         //i�жϽڵ���� ���жԱ�
	while(p->next!=NULL)
	{
		i++;
		p=p->next;
		if(i==n)
		return p->date;
	}
	printf("û����Ӧ���!\n"); 
}

/*��������:����Ԫ���ж����*/
ElemType dfindlink(dlinkcode *L,ElemType n)
{
	if(L->next==NULL)                    //�п�
	return false;
	ElemType i=0;                        //i�жϽڵ����
	dlinkcode *p=L;
	while(p->next!=NULL)
	{
		i++; 
		p=p->next;
		if(p->date==n)
		return i;
	}
	printf("û����ӦԪ�ض�Ӧ�����!\n");
} 

/*��������:����ڵ�*/
bool insertlink(dlinkcode *L,ElemType num,ElemType n)
{
	
	ElemType i=0;                        //i�жϽڵ����
	dlinkcode *p=L,*s;                   //s �����ɽڵ� 
	while(p->next!=NULL&&i!=n-1)
	{
		i++;
		p=p->next;                       //��n-1 �ڵ�λ�� 
	}
	if(i!=n-1)
	{
		printf("δ�ҵ���Ҫ����Ľڵ㣡\n");
		return false; 
	}
	else           
	if(p->next==NULL)                    //�����һ���ڵ���� 
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

/*��������:ɾ��ָ���ڵ�*/
bool deletelink(dlinkcode *L,ElemType n )
{
	dlinkcode *p=L,*s;                  //s����Ҫɾ���Ľڵ�
	ElemType i=0;                       //i�жϽڵ����
	while(p->next!=NULL&&i!=n-1)
	{
		i++;
		p=p->next;
	}
	if(i!=n-1)
	{
		printf("δ�ҵ���Ҫɾ���Ľڵ㣡\n");
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
                                        //����ͷ�ڵ� 
	dlinkcode *h=(dlinkcode *)malloc(sizeof(dlinkcode));
	initlink(h);                        //(1)��ʼ��˫����h
	int num[5]={1,3,2,4,5}; 
	rcreatlink(h,5,num);                //(2)β�巨���� abcde Ԫ�� ����Ϊ 1 3 2 4 5
	displaylink(h);                     //(3) �����������
	printf("\n");          
	printf("%d\n",numberlink(h));       //(4)����ڵ㳤��
	printf("%d\n",emptylink(h));        //(5) �ж�˫�����Ƿ�Ϊ��
	printf("%d\n",findlink(h,3));       //(6)���˫����h�ĵ�����Ԫ��
	printf("%d\n",dfindlink(h,1));      //(7)���Ԫ��a��λ�� 
	printf("\n"); 
	insertlink(h,8,4);                  //(8)���ĸ�Ԫ���ϲ���fԪ��  8
	displaylink(h);                     //(9) ���˫����h 
	printf("\n"); 
	deletelink(h,3);                    //(10) ɾ��˫����h�ĵ�����Ԫ��
	displaylink(h);                     //(11) ���˫����h 
	destroylink(h);                     //(12) �ͷ�˫����h                                         									 
	
}
