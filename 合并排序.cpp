/*
 73.合并排序 (10分)
C时间限制：3000 毫秒 |  C内存限制：3000 Kb
题目内容：
使用合并排序算法，对输入的n个数据进行按升序排序。
输入描述
分两行，第一行是整数n,第二行是n个整数，每个整数之间用空格间隔。
输出描述
按升序排序的n个整数
输入样例
8
9 8 7 6 5 4 3 2
输出样例
2 3 4 5 6 7 8 9
*/

#include <stdio.h>
 
int n, a[100];

//合并 
void fun02(int m, int n, int tmp){
	
	/*
		a: 待排序的数组 
		m：左起点
		n: 右终点
		tmp: 中间位置坐标
		b: 临时数组，用来记录排好序的队列	
	*/
	
	int b[100], k = 0, i = m, j = tmp + 1;
	
	//先打擂台，直至一方全军覆没 
	while(i <= tmp && j <= n){
		if(a[i] < a[j]){
			b[k++] = a[i++];
		}else{
			b[k++] = a[j++];
		}
	}
	
	//将剩下的强者全部加入数组 
	while(i <= tmp){
		b[k++] = a[i++];
	}
	
	while(j <= n){
		b[k++] = a[j++];
	}
	
	//将排好序的数组填入初始数组 
	k = 0;
	for(int pos = m; pos <= n; pos++){
		a[pos] = b[k++];
	}
	
	
}


void fun01(int m, int n){
	
	//当只剩下一个数的时候，默认已经排好序 
	if(m >= n){
		return;
	}
	
	//一分为二 
	int tmp = (n + m) / 2;
	//先排左边 
	fun01(m, tmp);
	//再排右边 
	fun01(tmp + 1, n);
	//合并排好序的数组 
	fun02(m, n, tmp);
	
}


int main(){
	
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	
	fun01(0, n - 1);
	
	for(int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
	
	return 0;
}
