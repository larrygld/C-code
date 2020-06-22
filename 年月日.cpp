/*
 112.年月日 (5分)
C时间限制：1 毫秒 |  C内存限制：3000 Kb
题目内容：
输入某年某月某日，判断这一天是这一年的第几天？
输入描述
依次输入年月日，中间用空格隔开，如
2012 6 10
输出描述
2012-6-10是这年的第162天
输入样例
2012 6 10
输出样例
162
*/ 

#include <stdio.h>

int year, month, day, a[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int fun(int i){
	int sum = 0;
	for(int j = 0; j < i -1; j++){
		sum += a[j];
//		printf("%d\n", sum);
	}
	return sum;
} 

int main(){
	scanf("%d%d%d", &year, &month, &day);
	if(year % 4 == 0){
		if(year % 100 == 0 && year % 400 != 0){
		}else{
			a[1] = 29;
		}
	}
	
	printf("%d", fun(month) + day);
	return 0;
}
