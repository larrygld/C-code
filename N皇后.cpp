/*
 104.N皇后 (15分)
C时间限制：3000 毫秒 |  C内存限制：3000 Kb
题目内容：
 国际象棋中的皇后可以沿着水平线，垂直线，或者斜线前进，吃掉遇到的所有棋子，如果棋盘上有八个皇后，
 则这八个皇后如何相安无事的
放置在棋盘上，1970年与1971年， E.W.Dijkstra与N.Wirth曾经用这个问题来讲解程式设计之技巧。
该题要求N皇后的放置结果共有多少种
输入描述
输入一个正整数N（N小于16）
输出描述
输出结果
输入样例
8
输出样例
92
*/

#include <stdio.h>

int N, a[101], cnt = 0, row = 1;

/*
	N：棋盘格及皇后数目
	a: 记录皇后在当前行所在列的位置
	cnt: 记录可行的方式总数
	row: 行的位置 
*/

int fun01(int n){
	for(int i = 1; i < n; i++){
		//判断是否在同一列或者在同一对角线上 
		if(a[i] == a[n] || n - i == a[n] - a[i] || i - n == a[n] - a[i]){
			return false;
		}
	}
	
	return true;
	
}


void fun02(int n){

	for(int i = 1; i <= n; i++){
		a[i] = 0;
	}
	
	//如果倒退到第一列也没有摆放的位置的时候，结束循环 
	while(row >= 1){
		//摆放完成继续试探，往下移一列 
		a[row] = a[row] + 1;
		while(a[row] <= n && !(fun01(row))){
//			printf("----\n");
			//不合适就转下一列 
			a[row] = a[row] + 1;
		}
		
		//最后一个行的皇后摆放完毕，总数加 1 
		if(row == n && a[row] <= n){
			cnt++;
		}
		
		//当前行摆放完毕，转到下一行 
		if(row < n && a[row] <= n){
			row = row + 1;
		}
		
		//当前行没有合适摆放位置，回溯至上一行 
		if(a[row] > n){
			a[row] = 0;
			row = row -1; 
		}
		
	}	
} 

int main(){
	
	scanf("%d", &N);
	fun02(N);
	printf("%d", cnt);
	return 0;
} 
