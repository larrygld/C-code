#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

struct Student{
	
	char id[20];	 
	char name[20];				
	char courseid[100];  
};

struct Course{
	
	char courseid[20];	 
	char coursename[20];				
	char coursetype[100];  
	int coursetime01;
	int coursetime02;
	int coursetime03;
	int coursescore;
	char starttime[50];
};

int totalstudents = 0;
int totalcourses = 0;
struct Student student[1001];
struct Course course[1001];


void fun01(){
	
	printf("课程编号  课程名称  课程性质  学时  授课学时  实验或上机学时  学分  开课学期\n"); 
	for(int i = 0; i < totalcourses; i++){
		printf("%s\t%s\t%s\t%d\t%d\t%d\t%d\t%s\n", course[i].courseid, course[i].coursename, course[i].coursetype, course[i].coursetime01, course[i].coursetime02, course[i].coursetime03, course[i].coursescore, course[i].starttime);
	}
	
} 


void fun02(){
	
	printf("学号   姓名   选课id\n"); 
	for(int i = 0; i < totalstudents; i++){
		printf("%s\t%s\t%s\n", student[i].id, student[i].name, student[i].courseid);
	}
	
} 



void fun03(){
	
	printf("请输入课程编号，课程名称，课程性质，学时，授课学时，实验或上机学时，学分，开课学期，以空格隔开：\n");
	char courseid[20];	 
	char coursename[20];				
	char coursetype[100];  
	int coursetime01;
	int coursetime02;
	int coursetime03;
	int coursescore;
	char starttime[50];
	scanf("%s %s %s %d %d %d %d %s", courseid, coursename, coursetype, &coursetime01, &coursetime02, &coursetime03, &coursescore, starttime);
	
	strcpy(course[totalcourses].courseid, courseid);
	strcpy(course[totalcourses].coursename, coursename);
	strcpy(course[totalcourses].coursetype, coursetype);
	course[totalcourses].coursetime01 = coursetime01;
	course[totalcourses].coursetime02 = coursetime02;
	course[totalcourses].coursetime03 = coursetime03;
	course[totalcourses].coursescore = coursescore;
	strcpy(course[totalcourses].starttime, starttime);
	totalcourses++;
	printf("课程信息录入成功！\n");  

} 


void fun04(){
	
		printf("学生学号，姓名，课程id,以空格间隔：\n");
		
		char id[20];	 
		char name[20];				
		char courseid[100];
		
		scanf("%s %s %s", id, name, courseid);
		
		strcpy(student[totalstudents].id, id);
		strcpy(student[totalstudents].name, name);
		strcpy(student[totalstudents].courseid, courseid);
		
		totalstudents++;
		
		printf("学生选课信息录入成功！\n");  
		
	
} 


void fun05(){
	
	printf("--1.课程id--2.课程名称--3.开课学期--4.课程学分--\n");
	printf("请输入编号(1-4),按编号指定字段查询：");
	 
	int pos;
	scanf("%d", &pos);
	
	printf("请输入字段值\n");
	
	char str[100];
	
	int score;
	
	switch (pos){
        	case 1: {
        		scanf("%s", str);
        		//遍历数组，查询到符合要求的就输出 
        		printf("查询到的结果为：\n");
        		for(int i = 0; i < totalcourses; i++){
			       	if(strcmp(str, course[i].courseid) == 0){
			       		printf("%s\t%s\t%s\t%d\t%d\t%d\t%d\t%s\n", course[i].courseid, course[i].coursename, course[i].coursetype, course[i].coursetime01, course[i].coursetime02, course[i].coursetime03, course[i].coursescore, course[i].starttime);		
					}
			    }

			}; break;
        	case 2: {
        		
        		scanf("%s", str);
        		//遍历数组，查询到符合要求的就输出 
        		printf("查询到的结果为：\n");
        		for(int i = 0; i < totalcourses; i++){
			       	if(strcmp(str, course[i].coursename) == 0){
			       		printf("%s\t%s\t%s\t%d\t%d\t%d\t%d\t%s\n", course[i].courseid, course[i].coursename, course[i].coursetype, course[i].coursetime01, course[i].coursetime02, course[i].coursetime03, course[i].coursescore, course[i].starttime);		
					}
			    }
	
			}; break;
        	case 3: {
        		
        		scanf("%s", str);
        		//遍历数组，查询到符合要求的就输出 
        		printf("查询到的结果为：\n");
        		for(int i = 0; i < totalcourses; i++){
			       	if(strcmp(str, course[i].starttime) == 0){
			       		printf("%s\t%s\t%s\t%d\t%d\t%d\t%d\t%s\n", course[i].courseid, course[i].coursename, course[i].coursetype, course[i].coursetime01, course[i].coursetime02, course[i].coursetime03, course[i].coursescore, course[i].starttime);		
					}
			    }
			
			}; break;
        	case 4: {
        		
        		scanf("%d", &score);
        		printf("查询到的结果为：\n");
				for(int i = 0; i < totalcourses; i++){
			       	if(course[i].coursescore == score){
			       		printf("%s\t%s\t%s\t%d\t%d\t%d\t%d\t%s\n", course[i].courseid, course[i].coursename, course[i].coursetype, course[i].coursetime01, course[i].coursetime02, course[i].coursetime03, course[i].coursescore, course[i].starttime);		
					}
			    }
			
			}; break;
        	
        	default:printf("error\n");	
        	
	}
	
}


void fun06(){
	
	printf("请输入课程id:\n");
	
	char courseid[50];
	scanf("%s", courseid);
	
	printf("选取该门课的学生有：\n");
	
	for(int i = 0; i < totalstudents; i++){
		
		if(strcmp(courseid, student[i].courseid) == 0){
			
			printf("%s\t%s\n", student[i].id, student[i].name);
			
		}
			
	}
		
}


void fun07(){
	
	FILE *fp;		//文件指针
	int i;

	fp=fopen("C:\\Users\\larry\\Desktop\\course.txt","w");			/*以只在文件末尾写的方式打开文件*/
	
	fprintf(fp, "课程编号  课程名称  课程性质  学时  授课学时  实验或上机学时  学分  开课学期\n");
	
	for(i = 0; i < totalcourses; i++)
	{	
		fprintf(fp, "%s %s %s %d %d %d %d %s", course[i].courseid, course[i].coursename, course[i].coursetype, course[i].coursetime01, course[i].coursetime02, course[i].coursetime03, course[i].coursescore, course[i].starttime);
		fprintf(fp, "\n");
	}
	fclose(fp);
	printf("已完成保存！\n");
	
}

void fun08(){
	
	int a;
	printf("即将退出系统，是否保存课程信息(1/0)?\n");
	scanf("%d", &a);
	
	if(a == 1){
		fun07();
		printf("欢迎下次使用！\n");
		exit(0);
	}else{
		printf("数据未保存，已成功退出，欢迎下次使用！\n");
		exit(0);
	}
	
}

int main(){
	
	
	printf("********************************************\n");	
	printf("********************************************\n");
	printf("***************学生选课系统*****************\n");
	printf("********************************************\n");
	printf("******1.课程信息显示*****2.学生选课信息显示*\n");
	printf("********************************************\n");
	printf("******3.课程信息录入*****4.学生选课*********\n");
	printf("********************************************\n");
	printf("******5.课程信息查询*****6.选课信息查询*****\n");
	printf("********************************************\n");
	printf("******7.保存*************0.退出系统*********\n");
	printf("********************************************\n");
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
        	case 0: fun08(); break;
        	default:printf("error\n");
    	}
		
		
	}
			
	
	
	return 0;
	
} 
