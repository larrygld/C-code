#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

struct Student{
	
	char name[10];	 
	char location[100];		
	char phonenumber[20];	
	char postnum[20];		
	char email[20];  
};

int totalrecords;
struct Student student[1001];

void fun01(){
	
	printf("姓名     地址        电话       邮政编码         email\n"); 
	for(int i = 0; i < totalrecords; i++){
		printf("%s\t%s\t%s\t%s\t%s\n", student[i].name, student[i].location, student[i].phonenumber, student[i].postnum, student[i].email);
	}
	
}

void fun02(){
	
	printf("请输入学生姓名，地址，电话，邮政编码，email，以空格隔开：\n");
	char name01[10], location01[100], phonenumber01[20], postnum01[20], email01[20];
	scanf("%s %s %s %s %s", name01, location01, phonenumber01, postnum01, email01);
	
	//将信息存入结构体
	strcpy(student[totalrecords].name, name01);
	strcpy(student[totalrecords].location, location01);
	strcpy(student[totalrecords].phonenumber, phonenumber01);
	strcpy(student[totalrecords].postnum, postnum01);
	strcpy(student[totalrecords].email, email01);
	
	totalrecords++;
	printf("信息录入成功！\n"); 
	
} 

void fun03(){
	
	printf("请输入要删除学生姓名：\n");
	char name01[10];
	scanf("%s", name01);
	
	for(int i = 0; i < totalrecords; i++){
		if(strcmp(name01, student[i].name) == 0){
			
			
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
	
	printf("--1.姓名--2.地址--3.电话--4.邮政编码--5.email--\n");
	printf("请输入编号(1-5),按编号指定字段查询：");
	
	int pos;
	scanf("%d", &pos);
	
	printf("请输入字段值\n");
	
	char str[100];
	scanf("%s", str);

	switch (pos){
        	case 1: {
        		//遍历数组，查询到符合要求的就输出 
        		printf("查询到的结果为：\n");
        		for(int i = 0; i < totalrecords; i++){
			       	if(strcmp(str, student[i].name) == 0){
			       		printf("%s\t%s\t%s\t%s\t%s\n", student[i].name, student[i].location, student[i].phonenumber, student[i].postnum, student[i].email);		
					}
			    }

			}; break;
        	case 2: {
        		printf("查询到的结果为：\n");
				for(int i = 0; i < totalrecords; i++){
			       	if(strcmp(str, student[i].location) == 0){
			       		printf("%s\t%s\t%s\t%s\t%s\n", student[i].name, student[i].location, student[i].phonenumber, student[i].postnum, student[i].email);		
					}
			    }
	
			}; break;
        	case 3: {
        		printf("查询到的结果为：\n");
        		
        		for(int i = 0; i < totalrecords; i++){
			       	if(strcmp(str, student[i].phonenumber) == 0){
			       		printf("%s\t%s\t%s\t%s\t%s\n", student[i].name, student[i].location, student[i].phonenumber, student[i].postnum, student[i].email);		
					}
			    }
			
			}; break;
        	case 4: {
        		printf("查询到的结果为：\n");
        		
        		for(int i = 0; i < totalrecords; i++){
			       	if(strcmp(str, student[i].postnum) == 0){
			       		printf("%s\t%s\t%s\t%s\t%s\n", student[i].name, student[i].location, student[i].phonenumber, student[i].postnum, student[i].email);		
					}
			    }
			
			}; break;
        	case 5: {
        		printf("查询到的结果为：\n");
        		for(int i = 0; i < totalrecords; i++){
			       	if(strcmp(str, student[i].email) == 0){
			       		printf("%s\t%s\t%s\t%s\t%s\n", student[i].name, student[i].location, student[i].phonenumber, student[i].postnum, student[i].email);		
					}
			    }
			
			}; break;
        	default:printf("error\n");
        	
        	
	}
	
	
} 

void fun05(){
	
	printf("--1.姓名--2.地址--3.电话--4.邮政编码--5.email--\n");
	printf("请输入编号(1-5),按编号指定字段排序：");
	
	int pos;
	scanf("%d", &pos);
	
	
	int k;
	Student tmp;
	
	switch (pos){
        	case 1: {
        		for(int i = 0; i < totalrecords; i++){
			       for(int j = 0; j < totalrecords - i - 1; j++){
			            if(strcmp(student[j].name, student[j+1].name) < 0){
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
			            if(strcmp(student[j].location, student[j+1].location) < 0){
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
			            if(strcmp(student[j].phonenumber, student[j+1].phonenumber) < 0){
			                tmp = student[j+1];//结构体允许整体赋值
			                student[j+1] = student[j];
			                student[j] = tmp;
			            }
			        }
			    }
	
				fun01();
			
			}; break;
        	case 4: {
        		
        		for(int i = 0; i < totalrecords; i++){
			       for(int j = 0; j < totalrecords - i - 1; j++){
			            if(strcmp(student[j].postnum, student[j+1].postnum) < 0){
			                tmp = student[j+1];//结构体允许整体赋值
			                student[j+1] = student[j];
			                student[j] = tmp;
			            }
			        }
			    }
	
				fun01();
			
			}; break;
        	case 5: {
        		
        		for(int i = 0; i < totalrecords; i++){
			       for(int j = 0; j < totalrecords - i - 1; j++){
			            if(strcmp(student[j].email, student[j+1].email) < 0){
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

void fun06(){
	
	FILE *fp;		//文件指针
	int i;

	fp=fopen("C:\\Users\\larry\\Desktop\\student.txt","w");			/*以只在文件末尾写的方式打开文件*/
	for(i = 0; i < totalrecords; i++)
	{	
		fprintf(fp, "%s %s %s %s %s", student[i].name, student[i].location, student[i].phonenumber, student[i].postnum, student[i].email);
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
	
	
	
	printf("********************************************\n");	
	printf("********************************************\n");
	printf("****************通讯录管理系统**************\n");
	printf("********************************************\n");
	printf("******1.记录浏览*********2.添加记录*********\n");
	printf("********************************************\n");
	printf("******3.删除记录*********4.记录查找*********\n");
	printf("********************************************\n");
	printf("******5.记录排序*********6.记录保存*********\n");
	printf("********************************************\n");
	printf("***************0.退出系统*******************\n");
	printf("********************************************\n");
	printf("********************************************\n");
	printf("********************************************\n");
	printf("********************************************\n");
	
	
	int i = 0, j, flag;
	
	FILE *fp;
	if((fp=fopen("C:\\Users\\larry\\Desktop\\student.txt","rb")) == NULL)			// 打开文件并且让fp指向 文件 
	{
		printf("Can not open file\n");
		exit(1);
	}
	
	
	while(!feof(fp))        
	{ 
		fscanf(fp, "%s %s %s %s %s", student[i].name, student[i].location, student[i].phonenumber, student[i].postnum, student[i].email);
		i++;
	}          
	totalrecords = i;

	fclose(fp);				//关闭文件； 
	
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
} 
