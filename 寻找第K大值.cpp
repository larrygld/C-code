/*
 97.寻找第K大值 (15分)
C时间限制：3000 毫秒 |  C内存限制：3000 Kb
题目内容：
 在一个整数数组中，寻找第k大值所在位置。假设每个数值都不一样。要求算法时间复杂性通常情况下为线性。
输入描述
包括一个数组长度n,一个k, 以及紧接着的n个整数值。整数之间用空格隔开。
输出描述
第k大值所在位置编号。规定数组的第一个位置编号为0.
输入样例
7 3
1 4 3 9 8 7 2
输出样例
5

*/


#include <stdio.h>

int m, k, a[101], b[101];

/*
	m: 记录数组元素个数
	k: 本题主角
	a: 排序数组
	b: 原始数组
	tmp: 定义快排的起点，用作中间位置 
*/

int fun02(int low, int high){
	int tmp = a[low];
	//一直重复找然后换位置，直到首尾坐标重叠 
	while(low < high){ 
		//从右边找一个小的 
		while (low < high && tmp <= a[high]){
            high--;
        }
        a[low] = a[high];
        //从左边找一个小大的，同时放在后面拿出了小的的位置 
        while (low < high && tmp >= a[low]) {
            low++;
        }
        a[high] = a[low];
	}
	a[low] = tmp;
	return low;
	
}

void fun01(int low, int high){
	if(low < high){
		int mid = fun02(low, high);
		//对左边进行排序
		fun01(low, mid - 1);
		//对右边进行排序
		fun01(mid + 1, high); 
	}
	
} 


int main(){
	
	int res;
	
	scanf("%d%d", &m, &k);
	for(int i = 0; i < m; i++){
		scanf("%d", &a[i]);
	}
	//将原始数组记录好 
	for(int i = 0; i < m; i++){
		b[i] = a[i];
	}
	
	fun01(0, m - 1);
	
	for(int i = 0; i < m; i++){
//		printf("%d ", a[i]);
		if(b[i] == a[m - k]){
			printf("%d", i);
			return 0;
		}
	}
	
	return 0;
} 
