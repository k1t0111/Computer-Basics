/*
ʵ�� �ݹ� �������ƽ���� 

						--����:Kit 
*/ 


/*��������: ��������Ԫ�������ƽ��ֵ*/
int n1;                                           //n1ȫ�ֱ��� �����������  

int average(int num[],int n)
{
	if(n==n1-1)
	return  (num[n]+average(num,n-1))/n1;
	if(n==0)
	return num[0];
	else 
	return num[n]+average(num,n-1); 
} 


#include <stdio.h>
int main()
{
	int num[100]; 
	int i,n;                                      // n��ʾ������� 
	printf("������n:\n");
	scanf("%d",&n);
	n1=n; 
	printf("������n������:\n"); 
	for(i=0;i<n;i++)
	{
		scanf("%d",&num[i]); 
	}
	printf("%d",average(num,n-1)); 
	 
} 
