/***********************************************
								
@description:˳��洢�ṹ������,��Ҷ�ӽڵ����  
@time: 2023/11/15				
@author:Kit  					
								
***********************************************/

#include <stdio.h>

/*��������:����Ҷ�ӽڵ����*/
int count(char bt[])
{
	char chr1,chr2;                                    //chr  1 2  �Ա������ַ� 
	int i=1,sum=0;                                     //i ����ȡ����ֵ  sum Ҷ�ӽڵ����� 
	while(bt[i]!='\0')
	{

		if(i%2==0)                                     //�ж��ǲ��� ż������ 
		{
			chr2=bt[i];
			if(chr2!='#'&&chr1!='#')
			sum++; 
		}
		else                                           //������chr1 
		{
			chr1=bt[i]; 
		}
		i++;
	}
	return sum+1;
	
} 

int main()
{
	char bt[11]={'A','B','C','#','D',
				 '#','E','F','#','G'};                //��������� 
	printf("%d",count(bt)); 
		
	return 0;
}



