/***************************

˳���  �Ե�һ��Ԫ��Ϊ��׼ 
�����ڵ��ڻ�׼��Ԫ�ط��ڻ�׼�����
С�ڻ�׼��Ԫ�ط��ڻ�׼���ұ�


�㷨: ������

����: ���������ҵ�С�ڻ�׼��Ԫ��
      ���������ҵ����ڻ�׼��Ԫ��
	  
	             ���ߣ�Kit 

****************************/ 

#include <stdio.h>
#include <stdlib.h> 
#include <sys/time.h>
#include <stdbool.h> 

typedef struct list                             //����˳��� 
{
	int data[10];
	int length;                     
}List; 
 
 
int main()
{

	srand((unsigned) time(NULL));               //��������� 
	
	List L1;
	int i,base;                                 //iѭ��ʱʹ�ñ���    base ��׼ֵ
	L1.length=10;
	int j=L1.length-1,temp;                     //i������ j���ҵ��� temp��ʱ��������
	
	for(i=0;i<10;i++)
		L1.data[i]=rand()%10;                   //�������ʮ����ֵ���и�ֵ	
	for(i=0;i<10;i++)                           //չʾ�������� 
	printf("%4d",L1.data[i]); 
	base=L1.data[0]; 
	i=0; 
	while(i<j)
	{
		while(i<j&&L1.data[i]>=base)            //��->����С��base��ֵ 
		i++;
		
		while(i<j&&L1.data[j]<base)             //��->���Ҵ��ڵ���base��ֵ
		j--;
		
		if(i<j)
		{
			temp=L1.data[i];                    //���� 
			L1.data[i]=L1.data[j];
			L1.data[j]=temp; 
		} 
	} 
	temp=L1.data[0];                    //���� 
	L1.data[0]=L1.data[i];
	L1.data[i]=temp; 
	printf("\n");
	for(i=0;i<10;i++)                           //չʾ���к��������� 
	printf("%4d",L1.data[i]); 
} 
 
