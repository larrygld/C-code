#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

void fun();


void fun01(){
	
	
	
	while(true){
		
		system("cls");
		
		int a, b , c, max;
	
		printf("请输入第一个自然数："); 
		scanf("%d", &a);
		
		printf("请输入第二个自然数："); 
		scanf("%d", &b);
		
		printf("请输入第三个自然数："); 
		scanf("%d", &c);
		
		if(a > b){
			max = a;
		}else{
			max = b;
		}
		
		if(c > max){
			max = c;
		}
		
		printf("三个数分别为 %d %d %d, 其中最大为 %d \n", a, b, c, max);
		
		int flag; 
		
		
		printf("输入0返回上级菜单，输入其他字符继续此功能："); 
		
		scanf("%d", &flag);
		
		if(flag == 0){
			system("cls");
			fun();
			break;
		}
		
	
	}
		
}


void fun02(){
	
	while(true){
		
		system("cls");
		
		int i, sum=0;//定义循环变量和存放求和的变量sum
	
		for(i = 1; i <= 100; i++){
			
			if(i % 2 == 1){
				sum += i;//进行求和计算
			}
			
			
		}
	
		printf("1-100奇数之和是%d\n", sum);//输出结果
		
		printf("输入0返回上级菜单，输入其他字符继续此功能："); 
		
		int flag; 
		
		scanf("%d", &flag);
		
		if(flag == 0){
			system("cls");
			fun();
			break;
		}		
	
	}	
	
}



void fun03(){
	
	while(true){
		
		system("cls");
		
		char str[201];
		
		int sum;
		
		printf("请输入一个带有大写字母的字符串："); 
		
		scanf("%s", str);
		
		for(int i = 0; str[i]; i++){
			
			if( str[i] >= 'A' && str[i] <= 'Z'){
				
				sum++;
				
			}
		}
		
		printf("您输入的字符串为：%s  其中大写字母个数为 %d \n", str, sum);
		
		printf("输入0返回上级菜单，输入其他字符继续此功能："); 
		
		int flag; 
		
		scanf("%d", &flag);
		
		if(flag == 0){
			system("cls");
			fun();
			break;
		}		
	
	}	
	
}


void fun(){
	
	printf("2019-2020第二学期C语言期末考试\n");
	printf("1.求最大值\n");
	printf("2.统计奇数和\n");
	printf("3.统计大写字母个数\n");
	
	
	int flag;

	
	while(true){
		
		printf("请输入操作编号(输入0退出系统)：");
		scanf("%d", &flag);
		
		switch (flag){
        	case 1: fun01(); break;
        	case 2: fun02(); break;
        	case 3: fun03(); break;
        	case 0: exit(0); break;
        	default:printf("error\n");
    	}
	
	}
	
}


int main(){
	
	fun();		
	
	return 0;
	
} 
