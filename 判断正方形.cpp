/*
 1.2018三大校赛题B-正方形的判断 (10分)
题目内容：
给定四个点的坐标, 问这四个点相连之后是否可以组成正方形.
输入描述：
第一行一个正整数N,表示测试数据组数,N<=500
每组测试数据占一行,给出8个整数x1,y1,x2,y2,x3,y3,x4,y4. -1000000<= x,y <= 1000000
输出描述：
输出一个正整数, 表示N组测试数据中有多少组中的点可以组成正方形.
输入样例：
2
0 1 3 1 0 0 3 0
1 1 -1 1 -1 -1 1 -1
输出样例
1
*/

#include <stdio.h>
#include <math.h>

int main(){
	
	/*
		n: 测试样例数
		x1 ~ y4: 点坐标
		flag1 ~ flag3: 判定结果映射值
		a12 ~ a13: 边长 
	*/
	
	int n;
	
	int x1, y1, x2, y2, x3, y3, x4, y4, flag1, flag2, flag3, a12, a13, a14;
	
	scanf("%d", &n);
	
	while(n--){
		
		scanf("%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
		
		a12 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
		
		a13 = (x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3);
		
		a14 = (x1 - x4) * (x1 - x4) + (y1 - y4) * (y1 - y4);
		
		if(a12 == a13){
			//判定方法：正方形的对角线垂直且相等 
			flag1 = (x1 - x4) * (x2 - x3) + (y1 - y4) * (y2 - y3);
			flag2 = (x1 - x4) * (x1 - x4) + (y1 - y4) * (y1 - y4);
			flag3 = (x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3);
			if(flag1 == 0 && flag2 == flag3){
				printf("perfect\n");
			}else{
//				printf("%d %d %d %d %d %d", flag1, flag2, flag3, a12, a13, a14);
				printf("not perfect\n");
			}
		}else if(a12 == a14){
			flag1 = (x1 - x3) * (x2 - x4) + (y1 - y3) * (y2 - y4);
			flag2 = (x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3);
			flag3 = (x2 - x4) * (x2 - x4) + (y2 - y4) * (y2 - y4);
			if(flag1 == 0 && flag2 == flag3){
				printf("perfect\n");
			}else{
				printf("not perfect\n");
			}
		}else if(a13 == a14){
			flag1 = (x1 - x2) * (x4 - x3) + (y1 - y2) * (y4 - y3);
			flag2 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
			flag3 = (x4 - x3) * (x4 - x3) + (y4 - y3) * (y4 - y3);
			if(flag1 == 0 && flag2 == flag3){
				printf("perfect\n");
			}else{
				printf("not perfect\n");
			}
		}else{
			printf("not perfect\n");
		}
	}
	
	
} 
