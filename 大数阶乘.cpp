/*
 117.大数相乘 (20分)
C时间限制：3000 毫秒 |  C内存限制：3000 Kb
题目内容：
一个整型变量只能用来存贮较小的n!的值，当 n 较大时，可将阶乘值中的每一个数字放在一个一维数组的一个元素中。
使用这方法，打印n!的值；
输入描述
整数n
输出描述
n!的值
输入样例
18
输出样例
6402373705728000
*/

#include <stdio.h>

/*
	a: 用来存放结果的数组
	tmp: 用来存储进位量
	n: 输入参数 
*/

int a[100], n, tmp = 0;

void fun(){
	//初始化 
	for(int i = 0; i < 100; i++){
		a[i] = 0;
	}
	a[0] = 1;
	
	for(int i = 2; i <= n; i++){
		for(int j = 0; j < 100; j++){
			a[j] = a[j] * i + tmp;
			tmp = 0;
			if(a[j] >= 10){
				tmp = a[j] / 10;
				a[j] = a[j] % 10;
			}
		}
		
	}
}

int main(){
	
	int i;
	scanf("%d", &n);
	fun();
	//从尾向头找，不是0就开始输出结果 
	for(i = 99; a[i] == 0; i--){	
	}
	
	for(int j = i; j >=0; j--){
		printf("%d", a[j]);
	}
	return 0;
} 
