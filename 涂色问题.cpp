/*
 99.涂色问题 (15分)
C时间限制：1 毫秒 |  C内存限制：3000 Kb
题目内容：
 有排成一行的ｎ个方格，用红(Red)、粉(Pink)、绿(Green)三色涂每个格子，每格涂一色，要求任何相邻的方格不能同色，且
首尾两格也不同色．求全部的满足要求的涂法。
输入描述
输入正整数n
输出描述
输出结果
输入样例
5
输出样例
30

*/


#include <stdio.h>

/*

	a: 记录格数不同时的涂色总数
	n: 格数 
*/

int a[101], n;

int main(){
	
	scanf("%d", &n);
	
	//初始化前几个的值 
	a[1] = 3;
	a[2] = 6;
	a[3] = 6;
	
	for(int i = 4; i<=n; i++){
		//分两种情况，看倒数第二格和第一个相同与不相同两种情况 
		a[i] = a[i - 1] + 2 * a[i - 2];
	}
	printf("%d", a[n]);
}
