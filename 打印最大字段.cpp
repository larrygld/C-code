#include <stdio.h>

/*
	pos1: ����ֶο�ʼλ��
	pos2: ����λ�� 
*/ 

int n, a[101], sum[101], max = -99999, pos1 = 0, pos2 = 0;


int main(){
	
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}

	sum[0] = a[0];
	
	for(int i = 1; i < n; i++){
		if(a[i] + sum[i - 1] > a[i]){
			sum[i] = a[i] + sum[i - 1];
		}else{
			sum[i] = a[i];
		}
		//�������ֶκ͸����ˣ���ô���Ǹ���pos2λ�� 
		if(sum[i] > max){
			max = sum[i];
			pos2 = i;
		}
		//�������ֶκ;͵��ڵ�ǰλ�ã�����ǰ��һ�ط�����С����ô���ǰ�pos1 pos2�����¡� 
		if(max == a[i]){
			pos1 = pos2 = i;
		}
	}
	
	for(int i = pos1; i <= pos2; i++){
		printf("%d ", a[i]);
	}
	
	return 0;
}
