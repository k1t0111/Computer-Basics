 /*
 	ʵ�������ĸ����㷨
	 
	 					--����:Kit 
 
 */
 
#include <stdio.h>
#define max 30
#include <stdbool.h>
#include <string.h> 
#include <stdlib.h> 


/*���������ڵ�*/
typedef struct code
{
	char data; 
	struct code *next; 
}strcode; 

/*��������: ����һ���ַ���*/
bool StrAssign(char cstr[],strcode *s)
{ 
	s->next=NULL;
	int i;
	strcode *r=s,*p;  
	for(i=0;i<strlen(cstr);i++)
	{	
		p=(strcode *)malloc(sizeof(strcode));
		r->next=p;
		p->data=cstr[i];
		r=p;  
	} 
	p->next=NULL;
	return true; 
} 

/*��������:���ٴ�*/
bool destroy(strcode *s)
{
	strcode *pre=s,*p=s->next;
	while(p!=NULL)
	{
		free(pre);
		pre=p;
		p=pre->next; 
	} 
	free(pre); 
	return true; 
} 

/*��������:���ĸ���*/
bool copystr(strcode *s1,strcode *s2)
{
	destroy(s1);
	s1=(strcode *)malloc(sizeof(strcode));
	strcode *pre=s2->next,*p1,*p=s1;                      //p1�����½ڵ�  p��������s1 
	while(pre!=NULL)
	{
		p1=(strcode *)malloc(sizeof(strcode));            //s1�½ڵ�
		p->next=p1;
		p1->data=pre->data;
		p=p1; 
		pre=pre->next; 
	}
	return true; 
} 

/*��������:�ж��������Ƿ����*/
bool judgestr(strcode*s1,strcode *s2)
{
	strcode *p1=s1->next,*p2=s2->next;                    //p1 p2 �ֱ��Ӧs1 s2 ��ѭ�� 
	if(lenstr(s1)!=lenstr(s2))
	return false;
	while(p1!=NULL)
	{
		if(p1->data!=p2->data)
		return false;
		p1=p1->next;
		p2=p2->next;	 
	}
	return true; 
} 

/*�������ܣ��󴮳�*/
int lenstr(strcode *s)
{
	int count=0;                                         //count ���� 
	strcode *p=s->next;
	while(p!=NULL)
	{
		count++;
		p=p->next;
	}
	return count;
	
} 

/*��������: �ַ�������*/
strcode * linkstr(strcode *s1,strcode *s2)
{
	strcode *p=s1,*pre=s2;                              //p��s1���һ��  pre��s2��һ�� 
	while(p->next!=NULL)
	{
		p=p->next; 
	}
	p->next=pre->next;
	free(pre); 
	return s1; 
}

/*��������:���Ӵ�*/
strcode* substr(strcode *s,int i,int j)
{
	char cstr[max]; 
	int count,x=-1;                                         //count���� 
	if(i<1||i>lenstr(s)||i+j-1>lenstr(s))
	return false;
	strcode *p=s->next;
	while(p!=NULL)
	{
		count++;
		if(count>=i&&count<i+j)
		{
			x++;
			cstr[x]=p->data;
		}
		p=p->next;
	}
	strcode* s3=(strcode*)malloc(sizeof(strcode)); 
	StrAssign(cstr,s3);
	return s3; 
	  
}

/*��������:���ַ�������*/
strcode* insstr(strcode *s1,strcode *s2,int i)
{
	if(i-1>lenstr(s1))
	return  false; 
	int count=0;                                           //count ���� 
	strcode *p=s1->next,*p1;                               //pѰλ�� p1�ݴ����� 
	while(p!=NULL)
	{
		count++;
		if(count==i-1)
		break;
		p=p->next; 
	}
	p1=p->next;                                            //����s1������һ���ڵ� 
	p->next=s2->next;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=p1;
	free(s2); 
	return s1;
} 

/*��������:ɾ���Ӵ�*/
strcode* deletestr(strcode *s,int i,int j)
{
	int count=0,x;                                         //count���� 
	if(i<1||i>lenstr(s)||i+j-1>lenstr(s))
	return false;
	strcode *p=s->next,*p1,*pre;
	while(p!=NULL)
	{
		count++;
		if(count==i-1)
		break;
		p=p->next;	
	}
	p1=p;                                                  //p1����iǰһ�� 
	p=p->next;
	for(x=0;x<j;x++)
	{
		pre=p->next;
		free(p);
		p=pre;
	}
	p1->next=p;
	return s;
} 
/*��������:�滻�ַ���*/
strcode* repstr(strcode *s1,int i,int j,strcode *s2)
{
	int count=0,x;                                         //count���� 
	if(i<1||i>lenstr(s1)||i+j-1>lenstr(s1))
	return false;
	strcode *p=s1->next,*p1,*pre;
	while(p!=NULL)
	{
		count++;
		if(count==i-1)
		break;
		p=p->next;	
	}
	p1=p;                                                  //p1����iǰһ��
	p=p->next;
	for(x=0;x<j;x++)
	{
		pre=p->next;
		free(p);
		p=pre;
	}
	p1->next=s2->next;
	free(s2);
	while(p1->next!=NULL)
	{
		p1=p1->next;		
	}
	p1->next=p; 
	return s1;	
} 

/*��������:��ʾ�����ַ���*/
bool disstr(strcode *s)
{
	strcode *p=s->next;
	while(p!=NULL)
	{
		printf("%c",p->data);
		p=p->next; 
	}
	return true; 
	 
} 
int main()
{
	
	char cstr1[max]={'a','b','c','d','f','g','h',       // (1) ����s ��s1 
	'i','j','k','l','m','n'},cstr2[max]={'x','y','z'};
	strcode *s=(strcode *)malloc(sizeof(strcode));
	strcode *s1=(strcode *)malloc(sizeof(strcode));
	StrAssign(cstr1,s);
	StrAssign(cstr2,s1);
	disstr(s);                                         //(2) �����s 
	printf("\n%d\n",lenstr(s));                        //(3) �����s����
	strcode *s2=insstr(s,s1,9);                        //(4)��s ��9������s1 ����s2 
	disstr(s2);										   //(5)�����s2
	printf("\n");
	destroy(s->next);
	StrAssign(cstr1,s);
	s1=(strcode *)malloc(sizeof(strcode));
	StrAssign(cstr2,s1);
	s2=deletestr(s,2,5);                               //(6) ɾ����s 2 ��ʼ 5 ���ӷ� 
	disstr(s2); 									   //(7) �����s2 
	printf("\n");
	destroy(s->next);
	StrAssign(cstr1,s);
	s2=repstr(s,2,5,s1);                               //(8) �滻��s 2 ��ʼ 5 ���ӷ�  s1 
	disstr(s2);                                        //(9) �����s2
	printf("\n");
	destroy(s->next);
	StrAssign(cstr1,s);
	s1=(strcode *)malloc(sizeof(strcode));
	StrAssign(cstr2,s1);
	strcode *s3=substr(s,2,10);                        //(10) ȡs 2��ʼʮ���ַ���s3 
	disstr(s3);                                        //(11) ���s3
	printf("\n");
	strcode *s4=linkstr(s1,s2);                        //(13) ����s1 s2
	disstr(s4);  
	destroy(s1);
	destroy(s3);
	return 0; 
} 
 
  
