/*
 110.约瑟夫环 (5分)
C时间限制：1 毫秒 |  C内存限制：3000 Kb
题目内容：
 有n个人围成一圈，顺序排号。从第一个人开始报数（从1到3报数），凡报到3的
人退出圈子，问最后留下的是原来第几号的那位?
输入描述
正整数n
输出描述
直接输出结果
输入样例
10
输出样例
4

*/

#include <stdio.h>

int n, a[101], flag = 0;

/*
	n: 总人数
	a: 辅助数组
	flag：用于计数的标志 
*/

void fun(){
	
	int count = n;
	
	//一直遍历，直至只剩一个人 
	for(int i = 1; ;i++){
		if(i == n + 1){
			i = 1;
		}
		
		//只有等于1才能合法计数 
		if(a[i] == 1){
			flag++;
		}else{
			continue;
		}
		
		//到3减人 
		if(flag % 3 == 0){
			a[i] = 0;
			flag = 0;
			count--;
		}
		
		//只剩最后一个 
		if(count == 1){
			break;
		}
	}
	
} 


int main(){
	
	scanf("%d", &n);
	
	for(int i = 1; i <= n; i++){
		a[i] = 1;
	}
	
	fun();
	
	for(int i = 1; i <= 10; i++){
		if(a[i] == 1){
			printf("%d", i);
		}
	}
	
	return 0;
} 
