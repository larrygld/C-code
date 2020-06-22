#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

struct Student{
	
	char id[20];	 
	char name[20];		
	char sex[10];	
	int age;		
	char msg[100];  
};

int totalrecords = 0;
struct Student student[1001];

void fun01(){
	
	printf("学号     姓名    性别       年龄       备注\n"); 
	for(int i = 0; i < totalrecords; i++){
		printf("%s\t%s\t%s\t%d\t%s\n", student[i].id, student[i].name, student[i].sex, student[i].age, student[i].msg);
	}
	
}

void fun02(){
	
	printf("请输入学生学号,姓名,性别,年龄,备注，以空格隔开：\n");
	
	char id[20];	 
	char name[20];		
	char sex[10];	
	int age;		
	char msg[100]; 
		
	scanf("%s %s %s %d %s", id, name, sex, &age, msg);
	
	strcpy(student[totalrecords].id, id);
	strcpy(student[totalrecords].name, name);
	strcpy(student[totalrecords].sex, sex);
	student[totalrecords].age = age;
	strcpy(student[totalrecords].msg, msg);
	
	totalrecords++;
	printf("信息录入成功！\n"); 
	
}


void fun03(){
	
	printf("请输入要删除学生学号：\n");
	char id[20];
	scanf("%s", id);
	
	for(int i = 0; i < totalrecords; i++){
		if(strcmp(id, student[i].id) == 0){
			
			
			//查到了符合要求的就整体前移一位 
			for(int j = i + 1; j < totalrecords; j++){
				student[j - 1] = student[j];
			}
			totalrecords--;
			printf("删除成功！\n");
			return ;
			 
		}
	}
	printf("输入有误，学生不存在！\n");
	
}

void fun04(){
	
	char pwd[100];
	
	printf("请输入密码：\n");
	
	scanf("%s", pwd);
	
	if(strcmp(pwd, "0000") == 0){
		
		printf("请输入待修改学生学号：\n");
		char id01[20];
		scanf("%s", id01);
		
		char id[20];	 
		char name[20];		
		char sex[10];	
		int age;		
		char msg[100]; 
	
	
		for(int i = 0; i < totalrecords; i++){
			if(strcmp(id01, student[i].id) == 0){
				
				
				//查到了符合要求的就修改
				
				printf("请输入修改后的学生学号,姓名,性别,年龄,备注，以空格隔开以空格隔开：\n");
				
				scanf("%s %s %s %d %s", id, name, sex, &age, msg);
				 
				strcpy(student[i].id, id);
				strcpy(student[i].name, name);
				strcpy(student[i].sex, sex);
				student[i].age = age;
				strcpy(student[i].msg, msg);
				printf("修改成功！\n");
				
				return ;
				 
			}
		}
		
		printf("查找失败！请重新输入！\n"); 
	
	
	}else{
		
		printf("密码错误!"); 
	}
	
	
	
}

void fun05(){
	
	printf("--1.学号--2.姓名--3.性别--4.年龄--\n");
	printf("请输入编号(1-4),按编号指定字段查询：");
	
	int pos;
	scanf("%d", &pos);
	
	printf("请输入字段值\n");
	
	char str[100];
	int age; 
	
	
	switch (pos){
        	case 1: {
        		scanf("%s", str);
        		//遍历数组，查询到符合要求的就输出 
        		printf("查询到的结果为：\n");
        		for(int i = 0; i < totalrecords; i++){
			       	if(strcmp(str, student[i].id) == 0){
			       		printf("%s\t%s\t%s\t%d\t%s\n", student[i].id, student[i].name, student[i].sex, student[i].age, student[i].msg);		
					}
			    }

			}; break;
        	case 2: {
        		scanf("%s", str);
        		printf("查询到的结果为：\n");
				for(int i = 0; i < totalrecords; i++){
			       	if(strcmp(str, student[i].name) == 0){
			       		printf("%s\t%s\t%s\t%d\t%s\n", student[i].id, student[i].name, student[i].sex, student[i].age, student[i].msg);			
					}
			    }
	
			}; break;
        	case 3: {
        		scanf("%s", str);
        		printf("查询到的结果为：\n");
				for(int i = 0; i < totalrecords; i++){
			       	if(strcmp(str, student[i].sex) == 0){
			       		printf("%s\t%s\t%s\t%d\t%s\n", student[i].id, student[i].name, student[i].sex, student[i].age, student[i].msg);			
					}
			    }
			
			}; break;
        	case 4: {
        		
        		scanf("%d", &age);
        		printf("查询到的结果为：\n");
				for(int i = 0; i < totalrecords; i++){
			       	if(student[i].age == age){
			       		printf("%s\t%s\t%s\t%d\t%s\n", student[i].id, student[i].name, student[i].sex, student[i].age, student[i].msg);			
					}
			    }
			
			}; break;
        	
        	default:printf("error\n");	
        	
	}
		
}

void fun06(){
	
	FILE *fp;		//文件指针
	int i;

	fp=fopen("C:\\Users\\larry\\Desktop\\student.txt","w");			/*以只在文件末尾写的方式打开文件*/
	
	fprintf(fp, "学号 姓名 性别 年龄 备注\n");
	
	for(i = 0; i < totalrecords; i++)
	{	
		fprintf(fp, "%s %s %s %d %s", student[i].id, student[i].name, student[i].sex, student[i].age, student[i].msg);
		fprintf(fp, "\n");
	}
	fclose(fp);
	printf("已完成保存！\n");
	
}

void fun07(){
	int a;
	printf("即将退出系统，是否保存(1/0)?\n");
	scanf("%d", &a);
	
	if(a == 1){
		fun06();
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
		printf("**************班级档案管理系统**************\n");
		printf("********************************************\n");
		printf("******1.信息显示*********2.信息录入*********\n");
		printf("********************************************\n");
		printf("******3.删除信息*********4.信息修改*********\n");
		printf("********************************************\n");
		printf("******5.信息查询*********6.记录保存*********\n");
		printf("********************************************\n");
		printf("***************0.退出系统*******************\n");
		printf("********************************************\n");
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
	        	case 0: fun07(); break;
	        	default:printf("error\n");
	    	}
			
			
		}
				
		
		
		return 0;
		
	
	
	} else{
		printf("密码错误!"); 
	} 
	
	
	
	
} 
