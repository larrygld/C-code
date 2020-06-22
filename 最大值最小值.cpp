#include<stdio.h>

int findmax(int *a, int n){
	
	int max = a[0]; //先假设第一个为最大值 
	
	for(int i = 0; i < n; i++){
		
		if(a[i] > max){
			max = a[i];
		} 
		
	}
	
	return max;
	
}


int findmin(int *a, int n){
	
	int min = a[0]; //先假设第一个为最小值 
	
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
		
		if(n == -1){	//当输入-1时停止接收数据 
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

