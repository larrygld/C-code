#include <stdio.h> 


void printarr(int* a, int n){
	
	int* pos = a;   //定义指针用于遍历数组 
	
	for(int i = 0; i < n; i++){
		printf("%d---", *pos);
		printf("%d\n", pos);
		pos++;		//遍历一次指针后移一位 
	}
	
}

 

int main() {
	
	int n, a[21];
	printf("请输入数据个数：\n");
	
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	
	printarr(a, n);

} 

