#include <stdio.h> 


void printarr(int* a, int n){
	
	int* pos = a;   //����ָ�����ڱ������� 
	
	for(int i = 0; i < n; i++){
		printf("%d---", *pos);
		printf("%d\n", pos);
		pos++;		//����һ��ָ�����һλ 
	}
	
}

 

int main() {
	
	int n, a[21];
	printf("���������ݸ�����\n");
	
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	
	printarr(a, n);

} 

