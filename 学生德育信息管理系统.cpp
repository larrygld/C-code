#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
#include <string>
#include <string.h>
using namespace std;


struct Student{
	
	char id[30];
	char name[30];	 
	char class01[30];//所在班级	
	int score01;   	//思想政治学分	
	int score02;	//道德修养学分 
	int score03;	//校规校纪学分 
	int score04;	//寝室纪律学分 
	int score05;	//荣誉奖励学分 
};


int totalrecords;
struct Student student[1001];


void fun01(){
	
	printf("学号    姓名   班级        思想政治学分   道德修养学分   校规校纪学分    寝室纪律学分   荣誉奖励学分\n"); 
	for(int i = 0; i < totalrecords; i++){
		printf("%s\t%s\t%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", student[i].id, student[i].name, student[i].class01, student[i].score01, student[i].score02, student[i].score03, student[i].score04, student[i].score05);
	}
	
}


void fun02(){
	
	printf("请输入学生学号,姓名,班级,思想政治学分,道德修养学分,校规校纪学分,寝室纪律学分,荣誉奖励学分,以空格隔开：\n");
	
	scanf("%s %s %s %d %d %d %d %d", student[totalrecords].id, student[totalrecords].name, student[totalrecords].class01, &student[totalrecords].score01, &student[totalrecords].score02, &student[totalrecords].score03, &student[totalrecords].score04, &student[totalrecords].score05);
	
	printf("添加成功！\n"); 
	
	totalrecords++;
}

void fun03(){
	
	printf("请输入待修改学生学号：\n");
	char id01[20];
	scanf("%s", id01);
	
	for(int i = 0; i < totalrecords; i++){
		if(strcmp(id01, student[i].id) == 0){
			
			
			//查到了符合要求的就修改
			
			printf("请输入修改后的学生学号,姓名,班级,思想政治学分,道德修养学分,校规校纪学分,寝室纪律学分,荣誉奖励学分,以空格隔开：\n");
			
			scanf("%s %s %s %d %d %d %d %d", student[i].id, student[i].name, student[i].class01, &student[i].score01, &student[i].score02, &student[i].score03, &student[i].score04, &student[i].score05);
			printf("修改成功！\n");
			
			return ;
			 
		}
	}
	
	printf("查无此人！\n"); 
	
}

void fun04(){
	
	printf("请输入待查找学生学号：\n");
	char id01[20];
	scanf("%s", id01);
	
	
	for(int i = 0; i < totalrecords; i++){
		if(strcmp(id01, student[i].id) == 0){
			
			
			//查到了符合要求的就输出
			printf("查询到的结果为：\n");
			
			printf("学号    姓名   班级        思想政治学分   道德修养学分   校规校纪学分    寝室纪律学分   荣誉奖励学分\n");
			
			printf("%s\t%s\t%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", student[i].id, student[i].name, student[i].class01, student[i].score01, student[i].score02, student[i].score03, student[i].score04, student[i].score05);
			
			return ;
			
			 
		}
	}
	
	printf("查无此人！\n"); 
		
}

void fun05(){
	
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
	printf("查无此人！\n");
	
} 


void fun06(){
	
	printf("--1.学号--2.姓名--3.班级--\n");
	printf("请输入编号(1-3),按编号指定字段查询：");
	
	int pos;
	scanf("%d", &pos);
	
	
	int k;
	Student tmp;
	
	switch (pos){
        	case 1: {
        		for(int i = 0; i < totalrecords; i++){
			       for(int j = 0; j < totalrecords - i - 1; j++){
			            if(strcmp(student[j].id, student[j+1].id) > 0){
			                tmp = student[j+1];//结构体允许整体赋值
			                student[j+1] = student[j];
			                student[j] = tmp;
			            }
			        }
			    }
	
				fun01();
			}; break;
        	case 2: {
				for(int i = 0; i < totalrecords; i++){
			       for(int j = 0; j < totalrecords - i - 1; j++){
			            if(strcmp(student[j].name, student[j+1].name) > 0){
			                tmp = student[j+1];//结构体允许整体赋值
			                student[j+1] = student[j];
			                student[j] = tmp;
			            }
			        }
			    }
	
				fun01();
	
			}; break;
        	case 3: {
        		
        		for(int i = 0; i < totalrecords; i++){
			       for(int j = 0; j < totalrecords - i - 1; j++){
			            if(strcmp(student[j].class01, student[j+1].class01) > 0){
			                tmp = student[j+1];//结构体允许整体赋值
			                student[j+1] = student[j];
			                student[j] = tmp;
			            }
			        }
			    }
	
				fun01();
			
			}; break;
        	
        	default:printf("error\n");
	}
	

}


void fun07(){
	
	FILE *fp;		//文件指针
	int i;

	fp=fopen("C:\\Users\\larry\\Desktop\\stu.txt","w");			/*以只在文件末尾写的方式打开文件*/
	for(i = 0; i < totalrecords; i++)
	{	
		fprintf(fp, "%s %s %s %d %d %d %d %d", student[i].id, student[i].name, student[i].class01, student[i].score01, student[i].score02, student[i].score03, student[i].score04, student[i].score05);
		fprintf(fp, "\n");
	}
	fclose(fp);
	printf("已完成保存！\n");
	
	
}


void fun08(){
	
	exit(1);
}


int main(){
	
	totalrecords = 0;
	
	printf("********************************************\n");	
	printf("********************************************\n");
	printf("***********学生德育信息管理系统*************\n");
	printf("********************************************\n");
	printf("******1.记录浏览*********2.添加学生*********\n");
	printf("********************************************\n");
	printf("******3.修改学生*********4.查找学生*********\n");
	printf("********************************************\n");
	printf("******5.删除学生*********6.学生排序*********\n");
	printf("********************************************\n");
	printf("******7.保存文件*********8.退出系统*********\n");
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
        	case 7: fun07(); break;
        	case 8: fun08(); break;
        	default:printf("error\n");
    	}
		
		
	}
			
	
	
	return 0;
} 
