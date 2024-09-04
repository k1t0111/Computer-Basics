 /*
 	实现链串的各种算法
	 
	 					--作者:Kit 
 
 */
 
#include <stdio.h>
#define max 30
#include <stdbool.h>
#include <string.h> 
#include <stdlib.h> 


/*定义链串节点*/
typedef struct code
{
	char data; 
	struct code *next; 
}strcode; 

/*函数功能: 创建一个字符串*/
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

/*函数功能:销毁串*/
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

/*函数功能:串的复制*/
bool copystr(strcode *s1,strcode *s2)
{
	destroy(s1);
	s1=(strcode *)malloc(sizeof(strcode));
	strcode *pre=s2->next,*p1,*p=s1;                      //p1产生新节点  p用来保存s1 
	while(pre!=NULL)
	{
		p1=(strcode *)malloc(sizeof(strcode));            //s1新节点
		p->next=p1;
		p1->data=pre->data;
		p=p1; 
		pre=pre->next; 
	}
	return true; 
} 

/*函数功能:判断两个串是否相等*/
bool judgestr(strcode*s1,strcode *s2)
{
	strcode *p1=s1->next,*p2=s2->next;                    //p1 p2 分别对应s1 s2 来循环 
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

/*函数功能：求串长*/
int lenstr(strcode *s)
{
	int count=0;                                         //count 计数 
	strcode *p=s->next;
	while(p!=NULL)
	{
		count++;
		p=p->next;
	}
	return count;
	
} 

/*函数功能: 字符串连接*/
strcode * linkstr(strcode *s1,strcode *s2)
{
	strcode *p=s1,*pre=s2;                              //p找s1最后一个  pre找s2第一个 
	while(p->next!=NULL)
	{
		p=p->next; 
	}
	p->next=pre->next;
	free(pre); 
	return s1; 
}

/*函数功能:求子串*/
strcode* substr(strcode *s,int i,int j)
{
	char cstr[max]; 
	int count,x=-1;                                         //count计数 
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

/*函数功能:将字符串插入*/
strcode* insstr(strcode *s1,strcode *s2,int i)
{
	if(i-1>lenstr(s1))
	return  false; 
	int count=0;                                           //count 计数 
	strcode *p=s1->next,*p1;                               //p寻位置 p1暂存插入点 
	while(p!=NULL)
	{
		count++;
		if(count==i-1)
		break;
		p=p->next; 
	}
	p1=p->next;                                            //保存s1插入点后一个节点 
	p->next=s2->next;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=p1;
	free(s2); 
	return s1;
} 

/*函数功能:删除子串*/
strcode* deletestr(strcode *s,int i,int j)
{
	int count=0,x;                                         //count计数 
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
	p1=p;                                                  //p1保存i前一个 
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
/*函数功能:替换字符串*/
strcode* repstr(strcode *s1,int i,int j,strcode *s2)
{
	int count=0,x;                                         //count计数 
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
	p1=p;                                                  //p1保存i前一个
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

/*函数功能:显示所有字符串*/
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
	
	char cstr1[max]={'a','b','c','d','f','g','h',       // (1) 创建s 和s1 
	'i','j','k','l','m','n'},cstr2[max]={'x','y','z'};
	strcode *s=(strcode *)malloc(sizeof(strcode));
	strcode *s1=(strcode *)malloc(sizeof(strcode));
	StrAssign(cstr1,s);
	StrAssign(cstr2,s1);
	disstr(s);                                         //(2) 输出串s 
	printf("\n%d\n",lenstr(s));                        //(3) 输出串s长度
	strcode *s2=insstr(s,s1,9);                        //(4)在s 的9处插入s1 返回s2 
	disstr(s2);										   //(5)输出串s2
	printf("\n");
	destroy(s->next);
	StrAssign(cstr1,s);
	s1=(strcode *)malloc(sizeof(strcode));
	StrAssign(cstr2,s1);
	s2=deletestr(s,2,5);                               //(6) 删除串s 2 开始 5 个子符 
	disstr(s2); 									   //(7) 输出串s2 
	printf("\n");
	destroy(s->next);
	StrAssign(cstr1,s);
	s2=repstr(s,2,5,s1);                               //(8) 替换串s 2 开始 5 个子符  s1 
	disstr(s2);                                        //(9) 输出串s2
	printf("\n");
	destroy(s->next);
	StrAssign(cstr1,s);
	s1=(strcode *)malloc(sizeof(strcode));
	StrAssign(cstr2,s1);
	strcode *s3=substr(s,2,10);                        //(10) 取s 2开始十个字符给s3 
	disstr(s3);                                        //(11) 输出s3
	printf("\n");
	strcode *s4=linkstr(s1,s2);                        //(13) 连接s1 s2
	disstr(s4);  
	destroy(s1);
	destroy(s3);
	return 0; 
} 
 
  
