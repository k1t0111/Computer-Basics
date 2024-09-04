/***************************

顺序表  以第一个元素为基准 
将大于等于基准的元素放在基准的左边
小于基准的元素放在基准的右边


算法: 交换法

描述: 从左向右找到小于基准的元素
      从右向左找到大于基准的元素
	  
	             作者：Kit 

****************************/ 

#include <stdio.h>
#include <stdlib.h> 
#include <sys/time.h>
#include <stdbool.h> 

typedef struct list                             //创建顺序表 
{
	int data[10];
	int length;                     
}List; 
 
 
int main()
{

	srand((unsigned) time(NULL));               //随机数种子 
	
	List L1;
	int i,base;                                 //i循环时使用变量    base 基准值
	L1.length=10;
	int j=L1.length-1,temp;                     //i从左到右 j从右到左 temp临时交换变量
	
	for(i=0;i<10;i++)
		L1.data[i]=rand()%10;                   //随机生成十以内值进行赋值	
	for(i=0;i<10;i++)                           //展示所有数据 
	printf("%4d",L1.data[i]); 
	base=L1.data[0]; 
	i=0; 
	while(i<j)
	{
		while(i<j&&L1.data[i]>=base)            //左->右找小于base的值 
		i++;
		
		while(i<j&&L1.data[j]<base)             //右->左找大于等于base的值
		j--;
		
		if(i<j)
		{
			temp=L1.data[i];                    //交换 
			L1.data[i]=L1.data[j];
			L1.data[j]=temp; 
		} 
	} 
	temp=L1.data[0];                    //交换 
	L1.data[0]=L1.data[i];
	L1.data[i]=temp; 
	printf("\n");
	for(i=0;i<10;i++)                           //展示排列后所有数据 
	printf("%4d",L1.data[i]); 
} 
 
