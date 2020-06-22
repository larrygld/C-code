/*
 1550.粉色冒泡 (10分)
C时间限制：1000 毫秒 |  C内存限制：3000 Kb
题目内容：
小C最近有了喜欢的女孩纸，作为程序员的他，想给女孩纸一个与众不同的表白方式！
所以他想到了用代码编写出一个exe文件让心仪的女孩纸一点开就能看到一颗心。
但是他不知道多大的心最好看，所以严谨的他想要打印多个心心进行比较，但是由于小C双十一沉迷于购物食品吃了太多
而忘了怎么打印心形图案了，所以你以帮助他完成这次与众不同的表白吗？
小C已经了解到喜欢的女孩纸HD同学特别喜欢三角形，但是有时候为了爱心的美观只好适当的
放弃三角形的尖尖为了尽量保持心的美丽，所以我们需要限制心的宽度最小不应该小于5，并且样例保证输入均为奇数
输入描述
第一行输入测试用例的个数T(0<T<=10), 接下来是T行测试用例
每行测试用例包括一个数n (5<=n<100,n为奇数)代表心形最大宽度 
输出描述
对于每组输入，打印出一个心形。
注意：每一行输出后面没有多余的空格 
输入样例
3
5
11
13
输出样例
 * *
*****
 ***
  *
  **   **
 **** ****
***********
 *********
  *******
   *****
    ***
     *
   *     *
  ***   ***
 ***** *****
*************
 ***********
  *********
   *******
    *****
     ***
      *
*/ 

#include <stdio.h>

int T, a[11];

/*
	T: 测试样例个数
	a: 存放爱心大小 
	mid: 与上半部分打印行数相关的参数
	space：中间部分打印的空格数 
*/


int fun(int n){
	
	int mid = (n + 1) / 2, m = 0, space = ((mid + 1) / 2 - 2) * 2 + 1, cnt = n;
	
	//分顶部结尾是一个*还是两个*来考虑 
	if(mid % 2 == 0){
		m = 2;
		for(int i = 0; i < (mid - 2) / 2; i++){
			 //先打印上半部分 
			for(int j = 0; j < (mid - 2) / 2 - i; j++){
				printf(" ");
			}
			for(int j = 0; j < m; j++){
				printf("*");
			}
			//后打印下半部分 
			for(int s = 0; s < space; s++){
				printf(" ");
			}
			for(int j = 0; j < m; j++){
				printf("*");
			}
			printf("\n");
			space -= 2;
			m += 2;
		}
		cnt = n;
		for(int x = 0; x < mid; x++){
			for(int y = 0; y < x; y++){
				printf(" ");
			}
			for(int w = 0; w < cnt; w++){
				printf("*");
			}
			printf("\n");
			cnt = cnt - 2;
			
		}
		
		//同上 
	}else{
		m = 1;		
		for(int i = 0; i < (mid - 1) / 2; i++){
			
			for(int j = 0; j < (mid - 1) / 2 - i; j++){
				printf(" ");
			}
			for(int j = 0; j < m; j++){
				printf("*");
			}
			
			for(int s = 0; s < space; s++){
				printf(" ");
			}
			for(int j = 0; j < m; j++){
				printf("*");
			}
			printf("\n");
			space -= 2;
			m += 2;
		}
		cnt = n;
		for(int x = 0; x < mid; x++){
			for(int y = 0; y < x; y++){
				printf(" ");
			}
			for(int w = 0; w < cnt; w++){
				printf("*");
			}
			printf("\n");
			cnt = cnt - 2;	
		}
	}
	
}

int main(){
	
	scanf("%d", &T);
	
	for(int i = 0; i < T; i++){
		scanf("%d", &a[i]);
	}
	
	for(int i = 0; i < T; i++){
		fun(a[i]);
	}

	
	return 0;
}


