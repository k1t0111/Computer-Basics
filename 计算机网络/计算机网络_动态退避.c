#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define back_time 50                         //�̶���ʱ�� 

/*��������: �����ȡk ģ���ظ�����*/
int Get_K(){
	int k=rand()%10;
	if(k<10)
		return k;
	else 
		return 10; 
} 

int main(){
	
	int Time_Sco,Num;                        // ��Χ Num ���� 
	srand(time(NULL));                       //���������
	Time_Sco=(1<<Get_K())-1;               
	printf("%d",Time_Sco);
	Num=rand()%Time_Sco;                     //��0-2`k-1 ѡ��
	printf("����ʱ��Ϊ%d,%d",Num,Num*back_time);
			
}
	

