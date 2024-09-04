 /*
 	实现链串的各种算法
	 
	 					--作者:Kit 
 
 */
 
#include <stdio.h>
#define max 30
#include <stdbool.h>
#include <string.h> 
#include <stdlib.h> 


/*定义串的结构体*/ 
typedef struct str1
{
	char str[max];
	int  length; 
}string; 

/*函数功能: 创建一个字符串*/
bool StrAssign(string *s)
{ 
	s->length=0; 
	return true; 
} 

/*函数功能:销毁串*/
bool destroy(string *s)
{
	free(s);
	return true; 
} 

/*函数功能:串的复制*/
bool copystr(char cstr[max],string *s)
{
	strcpy(s->str,cstr);
	s->length=strlen(cstr); 
	return 0; 
} 

/*函数功能:判断两个串是否相等*/
bool judgestr(string *s1,string *s2)
{
	if(strcmp(s1->str,s2->str)==0)
	return true;
	else
	return false;
} 

/*函数功能：求串长*/
int lenstr(string *s1)
{
	return s1->length;
} 

/*函数功能: 字符串连接*/
bool linkstr(string *s1,string *s2)
{
	 strcat(s1->str,s2->str);
	 return true; 
}

/*函数功能:求字串*/
bool findstr(string *s1,int i,int j)
{
	int x;                                            //x用于循环 
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
 
  
