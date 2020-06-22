#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Student
{
	public:
		char stuid[20];
	    char stuname[20];
	    char grade[10];
	    char major[20];
		
	private:
	    
};

class CourseDesign
{
	public:
		char courseid[30];
	    char coursename[50];
	    char coursetitle[50];
	    char teacher[20];
	    char score[10];
		
	private:
	    
};


class ChooseCourse
{
	public:
		char stuid[20];
	    char stuname[50];
	    char courseid[30];
	    char coursetitle[50];
		
	private:
	    
};

int totalstudents = 0;
int totalcourses = 0;
int totalchoose = 0;
Student student[200];
CourseDesign course[200];
ChooseCourse choose[200];

void fun00(){
	
	int i; 
	
	FILE *fp;
	
	if((fp=fopen("C:\\Users\\larry\\Desktop\\stu.txt","r")) == NULL)			// 打开文件并且让fp指向 文件 
	{
		printf("Can not open file\n");
		exit(1);
	}
	
	
	while(!feof(fp))        
	{ 
		fscanf(fp, "%s %s %s %s", student[i].stuid, student[i].stuname, student[i].grade, student[i].major); // 给对象数组赋值 
		i++;
	} 
	
	totalstudents = i;
	
	fclose(fp);
	
	i = 0;
	
	if((fp=fopen("C:\\Users\\larry\\Desktop\\cou.txt","r")) == NULL)			// 打开文件并且让fp指向 文件 
	{
		printf("Can not open file\n");
		exit(1);
	}
	
	
	while(!feof(fp))        
	{ 
		fscanf(fp, "%s %s %s %s %s", course[i].courseid, course[i].coursename, course[i].coursetitle, course[i].teacher, course[i].score);
		i++;
	}
	
	totalcourses = i;
	
	fclose(fp); //关闭文件 
	
	i = 0;
	
	if((fp=fopen("C:\\Users\\larry\\Desktop\\cho.txt","r")) == NULL)			// 打开文件并且让fp指向 文件 
	{
		printf("Can not open file\n");
		exit(1);
	}
	
	
	while(!feof(fp))        
	{ 
		fscanf(fp, "%s %s %s %s", choose[i].stuid, choose[i].stuname, choose[i].courseid, choose[i].coursetitle);
		i++;
	}
	
	totalchoose = i;
	
	fclose(fp);
}


void fun01(){
	
	printf("课题编号     课程名称    选题题目     指导教师      学分\n"); 
	for(int i = 0; i < totalcourses; i++){
		printf("%s\t%s\t%s\t%s\t%s\n", course[i].courseid, course[i].coursename, course[i].coursetitle, course[i].teacher, course[i].score);
	}
	
}


void fun02(){
	
	printf("学号     姓名    年纪      专业\n"); 
	for(int i = 0; i < totalstudents; i++){
		printf("%s\t%s\t%s\t%s\n", student[i].stuid, student[i].stuname, student[i].grade, student[i].major);
	}
	
}

void fun03(){
	
	printf("学号     姓名    课题编号      课题名称\n"); 
	for(int i = 0; i < totalchoose; i++){
		printf("%s\t%s\t%s\t%s\n", choose[i].stuid, choose[i].stuname, choose[i].courseid, choose[i].coursetitle);
	}
	
}


void fun04(){
	
	printf("请输入课题编号,课程名称,选题题目,指导教师,学分，以空格隔开：\n");
	
	char courseid[30];
    char coursename[50];
    char coursetitle[50];
    char teacher[20];
    char score[10];
    
    scanf("%s %s %s %s %s", courseid, coursename, coursetitle, teacher, score);
	
	strcpy(course[totalcourses].courseid, courseid);
	strcpy(course[totalcourses].coursename, coursename);
	strcpy(course[totalcourses].coursetitle, coursetitle);
	strcpy(course[totalcourses].teacher, teacher);
	strcpy(course[totalcourses].score, score);
	
	totalcourses++;
	
	printf("录入成功！\n");
	
	
} 


void fun05(){
	
	printf("请输入学生学号，姓名，年纪，专业，以空格隔开：\n");
	
	scanf("%s %s %s %s", student[totalstudents].stuid, student[totalstudents].stuname, student[totalstudents].grade, student[totalstudents].major);
	
	totalstudents++;
	
	printf("录入成功！\n");
	
}

void fun06(){
	
	printf("请输入学生学号,姓名,课题编号,课题名称，以空格隔开：\n");
	
	scanf("%s %s %s %s", choose[totalchoose].stuid, choose[totalchoose].stuname, choose[totalchoose].courseid, choose[totalchoose].coursetitle);
	
	totalchoose++;
	
	printf("录入成功！\n");
	
}

void fun07(){
	
	printf("--1.学号--2.姓名--3.课题编号--4.课题名称--\n");
	printf("请输入编号(1-4),按编号指定字段查询：");
	
	int pos;
	scanf("%d", &pos);
	
	printf("请输入字段值\n");
	
	char str[100];
	
	switch (pos){
		
    	case 1: {
    		scanf("%s", str);
    		//遍历数组，查询到符合要求的就输出 
    		printf("查询到的结果为：\n");
    		for(int i = 0; i < totalchoose; i++){
    			
		       	if(strcmp(str, choose[i].stuid) == 0){
		       		printf("%s\t%s\t%s\t%s\n", choose[i].stuid, choose[i].stuname, choose[i].courseid, choose[i].coursetitle);	
				}
			}

		}; break;
		
		case 2: {
    		scanf("%s", str);
    		//遍历数组，查询到符合要求的就输出 
    		printf("查询到的结果为：\n");
    		for(int i = 0; i < totalchoose; i++){
    			
		       	if(strcmp(str, choose[i].stuname) == 0){
		       		printf("%s\t%s\t%s\t%s\n", choose[i].stuid, choose[i].stuname, choose[i].courseid, choose[i].coursetitle);	
				}
			}

		}; break;
		
		case 3: {
    		scanf("%s", str);
    		//遍历数组，查询到符合要求的就输出 
    		printf("查询到的结果为：\n");
    		for(int i = 0; i < totalchoose; i++){
    			
		       	if(strcmp(str, choose[i].courseid) == 0){
		       		printf("%s\t%s\t%s\t%s\n", choose[i].stuid, choose[i].stuname, choose[i].courseid, choose[i].coursetitle);	
				}
			}

		}; break;
		
		case 4: {
    		scanf("%s", str);
    		//遍历数组，查询到符合要求的就输出 
    		printf("查询到的结果为：\n");
    		for(int i = 0; i < totalchoose; i++){
    			
		       	if(strcmp(str, choose[i].coursetitle) == 0){
		       		printf("%s\t%s\t%s\t%s\n", choose[i].stuid, choose[i].stuname, choose[i].courseid, choose[i].coursetitle);	
				}
			}

		}; break;
		
		default:printf("error\n");	
        	
	}
	
}


void fun08(){
	
	printf("请输入要删除记录的学生学号：\n");
	char id[20];
	scanf("%s", id);
	
	for(int i = 0; i < totalchoose; i++){
		if(strcmp(id, choose[i].stuid) == 0){
			
			
			//查到了符合要求的就整体前移一位 
			for(int j = i + 1; j < totalchoose; j++){
				choose[j - 1] = choose[j];
			}
			totalchoose--;
			printf("删除成功！\n");
			return ;
			 
		}
	}
	printf("输入有误，记录不存在！\n");
	
} 

void fun09(){
	int a;
	printf("即将退出系统，是否退出(1/0)?\n");
	scanf("%d", &a);
	
	if(a == 1){
		printf("欢迎下次使用！\n");
		exit(0);
	}else{
		
	}	
}

int main()
{
	
	fun00();
	
	printf("********************************************\n");	
	printf("********************************************\n");
	printf("***************课程设计选题系统*************\n");
	printf("********************************************\n");
	printf("******1.课程信息显示*****2.学生信息显示*****\n");
	printf("********************************************\n");
	printf("******3.选课信息显示*****4.课程信息录入*****\n");
	printf("********************************************\n");
	printf("******5.学生信息录入*****6.选题信息录入*****\n");
	printf("********************************************\n");
	printf("******7.查询选题信息*****8.删除选题信息*****\n");
	printf("********************************************\n");
	printf("*****************0.退出系统*****************\n");
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
		



}

