 /*
 	ʵ�������ĸ����㷨
	 
	 					--����:Kit 
 
 */
 
#include <stdio.h>
#define max 30
#include <stdbool.h>
#include <string.h> 
#include <stdlib.h> 


/*���崮�Ľṹ��*/ 
typedef struct str1
{
	char str[max];
	int  length; 
}string; 

/*��������: ����һ���ַ���*/
bool StrAssign(string *s)
{ 
	s->length=0; 
	return true; 
} 

/*��������:���ٴ�*/
bool destroy(string *s)
{
	free(s);
	return true; 
} 

/*��������:���ĸ���*/
bool copystr(char cstr[max],string *s)
{
	strcpy(s->str,cstr);
	s->length=strlen(cstr); 
	return 0; 
} 

/*��������:�ж��������Ƿ����*/
bool judgestr(string *s1,string *s2)
{
	if(strcmp(s1->str,s2->str)==0)
	return true;
	else
	return false;
} 

/*�������ܣ��󴮳�*/
int lenstr(string *s1)
{
	return s1->length;
} 

/*��������: �ַ�������*/
bool linkstr(string *s1,string *s2)
{
	 strcat(s1->str,s2->str);
	 return true; 
}

/*��������:���ִ�*/
bool findstr(string *s1,int i,int j)
{
	int x;                                            //x����ѭ�� 
	if(i<1||i>s1->length||i+j-1>s1->length)
		return false;
	else
	{	
	 	for(x=i-1;x<i+j-1;x++)
	 	{
	 		printf("%c ",s1->str[x]); 
		}
	} 
	return true; 
}
int main()
{
	
	char cstr[max]={'a','b','c','d','e'};
	string *s1=(string *)malloc(sizeof(string));
	string *s2=(string *)malloc(sizeof(string));
	copystr(cstr,s1);
	copystr(cstr,s2); 
	findstr(s1,1,3); 
	return 0; 
} 
 
  
