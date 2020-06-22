/*
 119.最短路径 (15分)
C时间限制：3000 毫秒 |  C内存限制：3000 Kb
题目内容：
 有5个城市(A,B,C,D,E),其中每个城市到其他城市的直达距离已知，两个城市之间只有一条公路。计算从城市A到其他任意城市
的最短路径距离。
输入描述
4行数据， 第一行是A到(B,C,D,E)的直达距离，第二行是B到（C,D,E）的直达距离，。。。，第4行是D到E的直达距离。
输出描述
A城市到(B,C,D,E)的最短距离。
输入样例
2 3 4 5  
3 4 2 
4 3   
3
输出样例
2 3 4 4
*/

#include <stdio.h>

#define inf 999999

int a[5][5], dis[5], v[5];

/*
	a: 记录各点之间的距离
	dis: 记录点A到各点的距离
	v: 记录该点是否被访问 
*/ 

void fun(){
	
	int min = inf, k, cnt = 0, pos = 0;
	
	//第一个节点A默认被访问，直连最短的直接为最短 
	v[0] = 1;
	
	//自己到自己初始化值为最小 
	dis[0] = 0;
	
	for(int i = 1; i < 5; i++){
		dis[i] = a[0][i];
	}
	
	
	while(cnt < 3){
		//遍历没有记录的节点且距原点最短的 
		for(int i = 0; i < 5; i++){
			if(!v[i] && a[0][i] < min){
				min = a[0][i];
				k = i; 
			}
		}
		v[k] = 1;
		min = inf;
		
		//如果经过该点距离变短，直接更新 
		for(int i = 0; i < 5; i++){	
			//如果该点没被记录，则尝试更新	
			if(!v[i]){			
				if(a[k][i] + dis[k] < dis[i]){
					dis[i] = a[k][i] + dis[k];
				}
			}
		}
	 	cnt++;		
	}
		
}


int main(){
	
	//输入初始距离数据 
	for(int i = 0; i < 5; i++){
		for(int j = i + 1; j < 5; j++){
			scanf("%d", &a[i][j]);
			a[j][i] = a[i][j];
		}
	}
	
	//打印初始时的各点之间的距离 
//	for(int i = 0; i < 5; i++){
//		for(int j = 0; j < 5; j++){
//			printf("%d ", a[i][j]);
//		}
//		printf("\n"); 
//	}
	
	fun();
	
	for(int i = 1; i < 5; i++){
		printf("%d ", dis[i]);
	}
		
	
	return 0;
}
