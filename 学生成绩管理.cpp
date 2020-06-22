#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
#include <string>
#include <string.h>
using namespace std;


struct Student{
	
	char id[20];	 
	char name[20];		
	double chinese;	
	double math;
	double english;
	double average;		
};

int totalrecords = 0;
struct Student student[1001];


void fun01(){
	
	printf("学号     姓名    语文       数学       英语\n"); 
	
	for(int i = 0; i < totalrecords; i++){
		
		printf("%s\t%s\t%.1lf\t%.1lf\t%.1lf\n", student[i].id, student[i].name, student[i].chinese, student[i].math, student[i].english);
	}
	
} 

void fun02(){
	
	printf("请输入学生学号,姓名,语文成绩,数学成绩,英语成绩，以空格隔开：\n");
	
	char id[20];	 
	char name[20];		
	double chinese;	
	double math;
	double english;
	
	scanf("%s %s %lf %lf %lf", id, name, &chinese, &math, &english);
	
	strcpy(student[totalrecords].id, id);
	strcpy(student[totalrecords].name, name);
	
	student[totalrecords].chinese = chinese;
	student[totalrecords].math = math;
	student[totalrecords].english = english;
	
	totalrecords++;
	
	printf("信息录入成功！\n"); 
	
	
} 


void fun03(){
	
	for(int i = 0; i < totalrecords; i++){
		
		student[i].average = (student[i].chinese + student[i].math + student[i].english) / 3;
	
	}
	
	printf("计算结果为：\n");
	
	printf("学号     姓名    语文       数学       英语    平均成绩\n"); 
	
	for(int i = 0; i < totalrecords; i++){
		
		printf("%s\t%s\t%.1lf\t%.1lf\t%.1lf\t%.1lf\n", student[i].id, student[i].name, student[i].chinese, student[i].math, student[i].english, student[i].average);
	
	
	}
	
} 


void fun04(){
	
	printf("请输入待修改学生学号：\n");
	
	char id01[20];
	
	scanf("%s", id01);
	
	char id[20];	 
	char name[20];		
	double chinese;	
	double math;
	double english;
	
	for(int i = 0; i < totalrecords; i++){
		
		if(strcmp(id01, student[i].id) == 0){
			
			printf("请输入修改后的学生学号,姓名,语文成绩，数学成绩，英语成绩，以空格隔开以空格隔开：\n");
		
			scanf("%s %s %lf %lf %lf", id, name, &chinese, &math, &english);
			
			//赋值给结构体数组 
			strcpy(student[i].id, id);
			strcpy(student[i].name, name);
			
			student[i].chinese = chinese;
			student[i].math = math;
			student[i].english = english;
			
			printf("修改成功！\n");
				
			return ;
		
		}
			
	}
	
	printf("查找失败！请重新输入！\n"); 
	
	
	
}


void fun05(){
	
	printf("--1.学号--2.姓名--\n");
	printf("请输入编号(1-2),按编号指定字段查询：");
	
	
	int pos;
	scanf("%d", &pos);
	
	printf("请输入字段值:\n");
	
	char str[100];
	
	switch (pos){
		
    	case 1: {
    		
    		scanf("%s", str);
    		
    		//遍历数组，查询到符合要求的就输出 
    		
    		printf("查询到的结果为：\n");
    		
    		for(int i = 0; i < totalrecords; i++){
    			
		       	if(strcmp(str, student[i].id) == 0){
		       		
		       		printf("%s\t%s\t%.1lf\t%.1lf\t%.1lf\n", student[i].id, student[i].name, student[i].chinese, student[i].math, student[i].english);		
				}
		    }

		}; break;
		
		
		case 2: {
    		
    		scanf("%s", str);
    		
    		//遍历数组，查询到符合要求的就输出 
    		
    		printf("查询到的结果为：\n");
    		
    		for(int i = 0; i < totalrecords; i++){
    			
		       	if(strcmp(str, student[i].name) == 0){
		       		
		       		printf("%s\t%s\t%.1lf\t%.1lf\t%.1lf\n", student[i].id, student[i].name, student[i].chinese, student[i].math, student[i].english);		
				}
		    }

		}; break;
		
		default:printf("error\n");	
        	
	}
	
}


void fun06(){
	
	//先将平均成绩计算出来 
	
	for(int i = 0; i < totalrecords; i++){
		
		student[i].average = (student[i].chinese + student[i].math + student[i].english) / 3;
	
	}
	
	printf("请输入一个分数，系统将查出所有平均成绩大于此分数的学生信息：\n");
	
	double score;
	
	scanf("%lf", &score); 
	
	for(int i = 0; i < totalrecords; i++){
		
		if(student[i].average > score){
			
			printf("%s\t%s\t%.1lf\t%.1lf\t%.1lf\t%.1lf\n", student[i].id, student[i].name, student[i].chinese, student[i].math, student[i].english, student[i].average);
			
		}
		
	}
	
	
} 


void fun07(){
	
	//先将平均成绩计算出来 
	for(int i = 0; i < totalrecords; i++){
		
		student[i].average = (student[i].chinese + student[i].math + student[i].english) / 3;
	
	}
	
	printf("--1.降序--2.升序--\n");
	printf("请输入编号(1-2),按指定方式排序：");
	
	int pos;
	scanf("%d", &pos);
	
	Student tmp;
	
	
	switch (pos){
		
    	case 1: {
    		
    		for(int i = 0; i < totalrecords; i++){
    			
		       for(int j = 0; j < totalrecords - i - 1; j++){
		       	
		            if(student[j].average < student[j+1].average){
		                tmp = student[j+1];//结构体允许整体赋值
		                student[j+1] = student[j];
		                student[j] = tmp;
		            }
		        }
			}
			
			printf("学号     姓名    语文       数学       英语   平均成绩\n"); 
	
			for(int i = 0; i < totalrecords; i++){
				
				printf("%s\t%s\t%.1lf\t%.1lf\t%.1lf\t%.1lf\n", student[i].id, student[i].name, student[i].chinese, student[i].math, student[i].english, student[i].average);
			}

		}; break;
		
		
		case 2: {
    		
    		for(int i = 0; i < totalrecords; i++){
    			
		       for(int j = 0; j < totalrecords - i - 1; j++){
		       	
		            if(student[j].average > student[j+1].average){
		                tmp = student[j+1];//结构体允许整体赋值
		                student[j+1] = student[j];
		                student[j] = tmp;
		            }
		        }
			}
			
			printf("学号     姓名    语文       数学       英语   平均成绩\n"); 
	
			for(int i = 0; i < totalrecords; i++){
				
				printf("%s\t%s\t%.1lf\t%.1lf\t%.1lf\t%.1lf\n", student[i].id, student[i].name, student[i].chinese, student[i].math, student[i].english, student[i].average);
			}

		}; break;
		
		default:printf("error\n");	
        	
	} 
	
	
	
}


void fun08(){
	
	FILE *fp;		//文件指针
	int i;

	fp=fopen("C:\\Users\\larry\\Desktop\\stu.txt","w");			/*以只在文件末尾写的方式打开文件*/
	for(i = 0; i < totalrecords; i++)
	{	
		fprintf(fp, "%s %s %.1lf %.1lf %.1lf", student[i].id, student[i].name, student[i].chinese, student[i].math, student[i].english);
		fprintf(fp, "\n");
	}
	fclose(fp);
	printf("已完成保存！\n");
	
}

void fun09(){
	
	int a;
	
	printf("即将退出系统，是否保存(1/0)?\n");
	
	scanf("%d", &a);
	
	if(a == 1){
		
		fun08();
		
		printf("欢迎下次使用！\n");
		
		exit(0);
	}else{
		
		printf("数据未保存，已成功退出，欢迎下次使用！\n");
		
		exit(0);
	}	
}


int main(){
	
	char pwd[100];
	
	printf("请输入密码：\n");
	
	scanf("%s", pwd);
	
	if(strcmp(pwd, "0000") == 0){
		
		printf("********************************************\n");	
		printf("********************************************\n");
		printf("**************学生成绩管理系统**************\n");
		printf("********************************************\n");
		printf("******1.所有记录*********2.学生信息录入*****\n");
		printf("********************************************\n");
		printf("******3.平均成绩计算*****4.信息修改*********\n");
		printf("********************************************\n");
		printf("******5.信息查询*********6.成绩统计*********\n");
		printf("********************************************\n");
		printf("******7.成绩排序*********8.信息存盘*********\n");
		printf("********************************************\n");
		printf("***************0.退出系统*******************\n");
		printf("********************************************\n");
		printf("********************************************\n");
		printf("********************************************\n");
		
		
		int flag;
	
		
		while(true){
			
			printf("请输入操作编号,回车键结束：");
			scanf("%d", &flag);
			
			switch (flag){
	        	case 1: fun01(); break;
	        	case 2: fun02(); break;
	        	case 3: fun03(); break;
	        	case 4: fun04(); break;
	        	case 5: fun05(); break;
	        	case 6: fun06(); break;
	        	case 7: fun07(); break;
				case 8: fun08(); break;
				case 0: fun09(); break;
	        	default:printf("error\n");
	    	}
			
			
		}
				
		
		return 0;
		
	
	
	} else{
		printf("密码错误!"); 
	} 
	
	
	return 0;
} 
