/*
 112.������ (5��)
Cʱ�����ƣ�1 ���� |  C�ڴ����ƣ�3000 Kb
��Ŀ���ݣ�
����ĳ��ĳ��ĳ�գ��ж���һ������һ��ĵڼ��죿
��������
�������������գ��м��ÿո��������
2012 6 10
�������
2012-6-10������ĵ�162��
��������
2012 6 10
�������
162
*/ 

#include <stdio.h>

int year, month, day, a[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int fun(int i){
	int sum = 0;
	for(int j = 0; j < i -1; j++){
		sum += a[j];
//		printf("%d\n", sum);
	}
	return sum;
} 

int main(){
	scanf("%d%d%d", &year, &month, &day);
	if(year % 4 == 0){
		if(year % 100 == 0 && year % 400 != 0){
		}else{
			a[1] = 29;
		}
	}
	
	printf("%d", fun(month) + day);
	return 0;
}
