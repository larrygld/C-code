#include<stdio.h>

int findmax(int *a, int n){
	
	int max = a[0]; //�ȼ����һ��Ϊ���ֵ 
	
	for(int i = 0; i < n; i++){
		
		if(a[i] > max){
			max = a[i];
		} 
		
	}
	
	return max;
	
}


int findmin(int *a, int n){
	
	int min = a[0]; //�ȼ����һ��Ϊ��Сֵ 
	
	for(int i = 0; i < n; i++){
		
		if(a[i] < min){
			min = a[i];
		} 
		
	}
	
	return min;
	
}

int main(){
	
	int arr[101], n, i = 0, max, min;
	
	scanf("%d", &n);
	
	while(true){
		
		if(n == -1){	//������-1ʱֹͣ�������� 
			break;
		}
		arr[i++] = n;
		scanf("%d", &n);
		
	} 
	
	max = findmax(arr, i);
	min = findmin(arr, i);
	
	printf("Max = %d\n", max);
	printf("Min = %d", min);
	return 0; 
}

