/*
    ʵ��ѭ�����еĻ�������   


                             --���ߣ�Kit 
*/


#include <stdio.h>
#define  MAXSIZE 10
#include <stdbool.h>
#include <stdlib.h> 

/*  ����char ΪElemType*/
typedef char ElemType;
 
/*���� ˳����нṹ�� */
typedef struct
{
	ElemType data[MAXSIZE]; 
	int front,rear;
		 
}line;
 
/*��������: ��ʼ��ѭ������ */
bool init_line(line *L)
{
	L->front=0;
	L->rear=0; 
	return true;
}


/*��������:���� ѭ������*/
bool creat_line(line *L,ElemType chr[],int n)
{
	int i;                                //i ����ѭ�� 
	if(n>MAXSIZE)
	return false;
	for(i=0;i<n;i++)
	{
		
		L->data[(L->rear+1)%MAXSIZE]=chr[i];
		L->rear=(L->rear+1)%MAXSIZE;
	}
	return true; 
}

/*��������: ���ٶ���*/ 
bool destroy_line(line *L)
{
	free(L); 
} 

/*��������:�ж϶����Ƿ�Ϊ��*/
bool empty_line(line *L)
{
	if(L->front==L->rear)
	return true;
	else
	return false;	
} 

/*��������: ����������Ԫ��*/
bool insert_line(line *L,ElemType chr)
{
	if((L->rear+1)%MAXSIZE==L->front)      // �ж� ����Ϊ�� 
	return false;
	L->data[(L->rear+1)%MAXSIZE]=chr;
	L->rear=(L->rear+1)%MAXSIZE;
	
}

/*��������:ɾ�������е�Ԫ��*/
ElemType delete_line(line *L)
{
	ElemType chr; 
	if(L->front==L->rear)                  //�ж� ����Ϊ�� 
	return false;
	chr=L->data[(L->front+1)%MAXSIZE]; 
	L->front=(L->front+1)%MAXSIZE;
	return chr;
	 
} 

int main()
{
	int i; 
	line *q;                               //q �´�������
	init_line(q);                          //(1) ��ʼ������ 
    printf("%4d\n",empty_line(q));         //(2) �ж϶����Ƿ�Ϊ�� 
	insert_line(q,'a');                    //(4) ���ν��� abc 
	insert_line(q,'b');
	insert_line(q,'c');
	printf("%4c\n",delete_line(q));        //(5) ����һ��Ԫ�ز������
	insert_line(q,'d');                    //(6) ���ν��� def 
	insert_line(q,'e');
	insert_line(q,'f');
	for(i=0;i<5;i++)                       //(7) �������� 
	{
		printf("%4c",delete_line(q));      
	} 
	destroy_line(q);                       //(8) �ͷ�����            
} 
