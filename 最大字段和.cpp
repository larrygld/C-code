/*
 105.最大字段和 (15分)
C时间限制：3000 毫秒 |  C内存限制：3000 Kb
题目内容：
给定长度为n的整数序列，a[1...n], 求[1,n]某个子区间[i , j]使得a[i]+…+a[j]和最大.或者求出最大的这个和.例如(-
2,11,-4,13,-5,2)的最大子段和为20,所求子区间为[2,4].
输入描述
第一行为一个整数n，表示数组有n个数据，第二行依次输入n个整数
输出描述
计算出n个整数中连续k个数的最大和
输入样例
5
1 2 3 4 5
7
6 -5 5 8 -13 5 7
输出样例
15
14
*/

#include <stdio.h>

int n, a[101], sum[101], max = -99999;

/*
	n: 测试组数 
	a: 存储待处理的数据
	sum: 到该点的最大字段和
	max: 最大的字段和 
*/ 

int fun(int m, int n){
	if(m > n){
		return m;
	}else{
		return n;
	}
}

int main(){
	
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}

	//初始化 
	sum[0] = a[0];
	
	for(int i = 1; i < n; i++){
		//关键步骤 
		sum[i] = fun(a[i] + sum[i - 1], a[i]);
		//大于就更新 
		if(sum[i] > max){
			max = sum[i];
		}
	}
	
	printf("%d\n", max);
	
	return 0;
}
