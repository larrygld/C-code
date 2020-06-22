#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

struct Computer 
{
	int isempty[6];  	
};

struct Computer computer[20];


void fun01(){
	
	printf("请输入整点时间(8:00 ~ 24:00)，开始查询空余机位(时间以24小时制，eg: 8:00, 18:00)：\n");
	
	char time[20];
	int flag;
	scanf("%s", time); 
	
	
	if(strcmp(time, "8:00") == 0 || strcmp(time, "9:00") == 0){
		flag = 0;
	}
	else if(strcmp(time, "10:00") == 0 || strcmp(time, "11:00") == 0){
		flag = 1;
	}
	else if(strcmp(time, "12:00") == 0 || strcmp(time, "13:00") == 0){
		flag = 2;
	}
	else if(strcmp(time, "14:00") == 0 || strcmp(time, "15:00") == 0){
		flag = 3;
	}
	else if(strcmp(time, "16:00") == 0 || strcmp(time, "17:00") == 0){
		flag = 4;
	}
	else if(strcmp(time, "18:00") == 0 || strcmp(time, "19:00") == 0){
		flag = 5;
	}else{
		printf("输入有误！\n");
		return ;
	}
	
	printf("空余机位为：\n");
	
	for(int i = 0; i < 20; i++){
		if(computer[i].isempty[flag] == 0){
			printf("%d ", i);
		}
	}	
	
	printf("\n");
	
	
}

void fun02(){
	
	printf("请输入整点时间(8:00 ~ 24:00)，开始预定空余机位(时间以24小时制，eg: 8:00, 18:00)：\n"); 
	
	
	char time[20];
	int flag;
	scanf("%s", time); 
	
	
	if(strcmp(time, "8:00") == 0 || strcmp(time, "9:00") == 0){
		flag = 0;
	}
	else if(strcmp(time, "10:00") == 0 || strcmp(time, "11:00") == 0){
		flag = 1;
	}
	else if(strcmp(time, "12:00") == 0 || strcmp(time, "13:00") == 0){
		flag = 2;
	}
	else if(strcmp(time, "14:00") == 0 || strcmp(time, "15:00") == 0){
		flag = 3;
	}
	else if(strcmp(time, "16:00") == 0 || strcmp(time, "17:00") == 0){
		flag = 4;
	}
	else if(strcmp(time, "18:00") == 0 || strcmp(time, "19:00") == 0){
		flag = 5;
	}else{
		printf("输入有误！\n");
		return ;
	}
	
	for(int i = 0; i < 20; i++){
		if(computer[i].isempty[flag] == 0){
			computer[i].isempty[flag] = 1; 
			printf("预定成功，预定机位为：%d\n", i);
			return ;
		}
	}
	
	printf("预定失败，输入时间段无机位！");
	
}


void fun03(){
	
	printf("请输入预定时间和机位号，以空格隔开：\n"); 
	
	int id; 
	char time[20];
	int flag;
	scanf("%s %d", time, &id); 
	
	
	if(strcmp(time, "8:00") == 0 || strcmp(time, "9:00") == 0){
		flag = 0;
	}
	else if(strcmp(time, "10:00") == 0 || strcmp(time, "11:00") == 0){
		flag = 1;
	}
	else if(strcmp(time, "12:00") == 0 || strcmp(time, "13:00") == 0){
		flag = 2;
	}
	else if(strcmp(time, "14:00") == 0 || strcmp(time, "15:00") == 0){
		flag = 3;
	}
	else if(strcmp(time, "16:00") == 0 || strcmp(time, "17:00") == 0){
		flag = 4;
	}
	else if(strcmp(time, "18:00") == 0 || strcmp(time, "19:00") == 0){
		flag = 5;
	}else{
		printf("输入有误！\n");
		return ;
	}
	
	if(computer[id].isempty[flag] == 0){
		printf("取消失败！当前机位无预定！\n"); 
	}else{
		computer[id].isempty[flag] = 0;
		printf("取消成功！\n");
	}
	
	 
	
	
}

void fun04(){
	
	int a;
	printf("即将退出系统，是否退出(1/0)?\n");
	scanf("%d", &a);	
	if(a == 1){
		exit(0);
	}else{
		printf("已取消！\n");
	}
}



int main(){
	
	
	
	cout<<"***********************************************************************"<<endl;
 	cout<<"**------------------------机房机位预定系统---------------------------**"<<endl;
 	cout<<"***********************************************************************"<<endl;
 	cout<<"**                        1. 查询机位                                **"<<endl;
 	cout<<"**                        2. 机位预定                                **"<<endl;
	cout<<"**                        3. 取消预约                                **"<<endl;
 	cout<<"**                        0. 退出系统                                **"<<endl;
 	cout<<"***********************************************************************"<<endl;
 	
 	
 	int flag;
	
		
	while(true){
		
		printf("请输入操作编号,回车键结束：");
		scanf("%d", &flag);
		
		switch (flag){
        	case 1: fun01(); break;
        	case 2: fun02(); break;
        	case 3: fun03(); break;
        	case 0: fun04(); break;
        	default:printf("error\n");
    	}
		
		
	}
} 
				
		
		
		
