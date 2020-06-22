/*
 109.滑雪 (10分)
C时间限制：1 毫秒 |  C内存限制：3000 Kb
题目内容：
 Michael喜欢滑雪百这并不奇怪， 因为滑雪的确很刺激。可是为了获得速度，滑的区域必须向下倾斜，而且当你滑到坡底，你不
得不再次走上坡或者等待升降机来载你。Michael想知道载一个区域中最长底滑坡。区域由一个二维数组给出。
数组的每个数字代表点的高度。下面是一个例子 
 1  2  3  4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
一个人可以从某个点滑向上下左右相邻四个点之一，当且仅当高度减小。在上面的例子中，一条可滑行的滑坡为24-17-16-1。当
然25-24-23-...-3-2-1更长。事实上，这是最长的一条。
输入描述
输入的第一行表示区域的行数R和列数C(1<=R,C<=100)。下面是R行，每行有C个整数，代表高度h，0<=h<=10000。
输出描述
输出最长区域的长度。
输入样例
5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
输出样例
25
*/ 

#include <stdio.h>

int m, n, i, j, map[101][101], res[101][101], max = -1;

int mymax(int m, int n){
	if(m > n){
		return m;
	}else{
		return n;
	}
}

int fun(int i, int j){
	// 递归结束的条件 
	if(i >= m || j >= n || i < 0 || j < 0){
		return 0;
	}
	if(res[i][j]){
		return res[i][j];
	}
	//左	
	if(map[i][j-1] < map[i][j]){
		res[i][j] = mymax(fun(i, j-1) + 1, res[i][j]);
	}
	//右 
	if(map[i][j+1] < map[i][j]){
		res[i][j] = mymax(fun(i, j+1) + 1, res[i][j]);
	}
	//下 
	if(map[i+1][j] < map[i][j]){
		res[i][j] = mymax(fun(i+1, j) + 1, res[i][j]);
	}
	//上
	if(map[i-1][j] < map[i][j]){
		res[i][j] = mymax(fun(i-1, j) + 1, res[i][j]);
	}
	
	return res[i][j];
}


int main(){	
	scanf("%d%d", &m, &n);
	for(int i = 0; i < m; i ++){
		for(int j = 0; j < n; j++){
			scanf("%d", &map[i][j]);
		}
	}
	
	for(int i = 0; i < m; i ++){
		for(int j = 0; j < n; j++){
			res[i][j] = mymax(res[i][j], fun(i, j));
		}
	}
	
	for(int i = 0; i < m; i ++){
		for(int j = 0; j < n; j++){
			if(max < res[i][j]){
				max = res[i][j];
			}
		}
	}
	
	printf("%d", max);
} 
