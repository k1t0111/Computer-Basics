/**************

@description: ͼ�Ĵ洢�ڽӾ���� һЩ���� 
@time: 2023/12/1
@author: Kit
  
***************/ 


#include <stdio.h>
#define  max 10



/*��������:ʵ���󶥵����� ����*/
void mat(int mat1[max][max]) 
{
	int i,j; 
	int in=0,out=0,out0=0;                                 //in ��� out ���� out0 ����Ϊ0
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)                                   //˫��ѭ�� ����ÿ������ 
		{
			if(mat1[j][i]==1)
			  in++;
			if(mat1[i][j]==1)
			  out++;
			 
		}
		printf("%d�����Ϊ:%d\n",i,in); 
		printf("%d�ĳ���Ϊ:%d\n",i,out); 
		if(out==0)
		out0++; 
		out=0;in=0;                                        //��0 ������һ���ڵ� �ж� 
	}
	printf("����Ϊ0�Ķ�������Ϊ:%d",out0); 
	
}

int main()
{
	//����  �ڽӾ��� 
	int mat1[max][max]={{0,1,1,1},{0,0,0,1},{0,1,0,0},{0,0,0,0}};
	mat(mat1); 
	
	
} 
