#include <stdio.h>

/*
	pos1: 最大字段开始位置
	pos2: 结束位置 
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
		//如果最大字段和更新了，那么我们更新pos2位置 
		if(sum[i] > max){
			max = sum[i];
			pos2 = i;
		}
		//如过最大字段和就等于当前位置，加上前面一截反而变小，那么我们把pos1 pos2都更新。 
		if(max == a[i]){
			pos1 = pos2 = i;
		}
	}
	
	for(int i = pos1; i <= pos2; i++){
		printf("%d ", a[i]);
	}
	
	return 0;
}
