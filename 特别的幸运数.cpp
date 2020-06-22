/*
 81.特别的幸运数 (15分)
C时间限制：3000 毫秒 |  C内存限制：3000 Kb
题目内容：
YF不爱名利，所以他既不喜欢6，也不喜欢8。他的幸运数字是4和7。如果一个数字中只包含4和7，他就认为这个数字是他的幸运数。
现在给你两个正整数a,b，要求返回a,b之间的幸运数的个数，包括a,b本身。
输入描述
第一行输入数目n,表示后面有n组ab
第2行开始，每行一组a b, 空格隔开。
输出描述
每行输出一个数，即a,b之间的幸运数的个数。
输入样例
3
11 20
4 7
1 10
输出样例
0
2
2

*/

#include <stdio.h>

int a, b, n, tmp, cnt = 0;

/*
	a: 左端点
	b: 右端点
	n: 测试组数
	tmp: 临时中间值 
	cnt: 满足题目条件的数目 
*/ 

int fun(int num){
	
	while(num > 10){
		//从后往前一位一位来判断 
		tmp = num % 10;
		if(tmp == 4 || tmp == 7){
			num /= 10;
		}else{
			break;
		}
	}
	
	//只剩一位的时候跳出循环直接判断得出答案 
	if(num == 4 || num == 7){
		return 1;
	}else{
		return 0;
	}
	
}

int main(){
	
	scanf("%d", &n);
	
	while(n--){
		scanf("%d%d", &a, &b);
		cnt = 0;
		for(int i = a; i <= b; i++){
			if(fun(i)){
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}
	
	
	
}
