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
	
	printf("�γ̱��  �γ�����  �γ�����  ѧʱ  �ڿ�ѧʱ  ʵ����ϻ�ѧʱ  ѧ��  ����ѧ��\n"); 
	for(int i = 0; i < totalcourses; i++){
		printf("%s\t%s\t%s\t%d\t%d\t%d\t%d\t%s\n", course[i].courseid, course[i].coursename, course[i].coursetype, course[i].coursetime01, course[i].coursetime02, course[i].coursetime03, course[i].coursescore, course[i].starttime);
	}
	
} 


void fun02(){
	
	printf("ѧ��   ����   ѡ��id\n"); 
	for(int i = 0; i < totalstudents; i++){
		printf("%s\t%s\t%s\n", student[i].id, student[i].name, student[i].courseid);
	}
	
} 



void fun03(){
	
	printf("������γ̱�ţ��γ����ƣ��γ����ʣ�ѧʱ���ڿ�ѧʱ��ʵ����ϻ�ѧʱ��ѧ�֣�����ѧ�ڣ��Կո������\n");
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
	printf("�γ���Ϣ¼��ɹ���\n");  

} 


void fun04(){
	
		printf("ѧ��ѧ�ţ��������γ�id,�Կո�����\n");
		
		char id[20];	 
		char name[20];				
		char courseid[100];
		
		scanf("%s %s %s", id, name, courseid);
		
		strcpy(student[totalstudents].id, id);
		strcpy(student[totalstudents].name, name);
		strcpy(student[totalstudents].courseid, courseid);
		
		totalstudents++;
		
		printf("ѧ��ѡ����Ϣ¼��ɹ���\n");  
		
	
} 


void fun05(){
	
	printf("--1.�γ�id--2.�γ�����--3.����ѧ��--4.�γ�ѧ��--\n");
	printf("��������(1-4),�����ָ���ֶβ�ѯ��");
	 
	int pos;
	scanf("%d", &pos);
	
	printf("�������ֶ�ֵ\n");
	
	char str[100];
	
	int score;
	
	switch (pos){
        	case 1: {
        		scanf("%s", str);
        		//�������飬��ѯ������Ҫ��ľ���� 
        		printf("��ѯ���Ľ��Ϊ��\n");
        		for(int i = 0; i < totalcourses; i++){
			       	if(strcmp(str, course[i].courseid) == 0){
			       		printf("%s\t%s\t%s\t%d\t%d\t%d\t%d\t%s\n", course[i].courseid, course[i].coursename, course[i].coursetype, course[i].coursetime01, course[i].coursetime02, course[i].coursetime03, course[i].coursescore, course[i].starttime);		
					}
			    }

			}; break;
        	case 2: {
        		
        		scanf("%s", str);
        		//�������飬��ѯ������Ҫ��ľ���� 
        		printf("��ѯ���Ľ��Ϊ��\n");
        		for(int i = 0; i < totalcourses; i++){
			       	if(strcmp(str, course[i].coursename) == 0){
			       		printf("%s\t%s\t%s\t%d\t%d\t%d\t%d\t%s\n", course[i].courseid, course[i].coursename, course[i].coursetype, course[i].coursetime01, course[i].coursetime02, course[i].coursetime03, course[i].coursescore, course[i].starttime);		
					}
			    }
	
			}; break;
        	case 3: {
        		
        		scanf("%s", str);
        		//�������飬��ѯ������Ҫ��ľ���� 
        		printf("��ѯ���Ľ��Ϊ��\n");
        		for(int i = 0; i < totalcourses; i++){
			       	if(strcmp(str, course[i].starttime) == 0){
			       		printf("%s\t%s\t%s\t%d\t%d\t%d\t%d\t%s\n", course[i].courseid, course[i].coursename, course[i].coursetype, course[i].coursetime01, course[i].coursetime02, course[i].coursetime03, course[i].coursescore, course[i].starttime);		
					}
			    }
			
			}; break;
        	case 4: {
        		
        		scanf("%d", &score);
        		printf("��ѯ���Ľ��Ϊ��\n");
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
	
	printf("������γ�id:\n");
	
	char courseid[50];
	scanf("%s", courseid);
	
	printf("ѡȡ���ſε�ѧ���У�\n");
	
	for(int i = 0; i < totalstudents; i++){
		
		if(strcmp(courseid, student[i].courseid) == 0){
			
			printf("%s\t%s\n", student[i].id, student[i].name);
			
		}
			
	}
		
}


void fun07(){
	
	FILE *fp;		//�ļ�ָ��
	int i;

	fp=fopen("C:\\Users\\larry\\Desktop\\course.txt","w");			/*��ֻ���ļ�ĩβд�ķ�ʽ���ļ�*/
	
	fprintf(fp, "�γ̱��  �γ�����  �γ�����  ѧʱ  �ڿ�ѧʱ  ʵ����ϻ�ѧʱ  ѧ��  ����ѧ��\n");
	
	for(i = 0; i < totalcourses; i++)
	{	
		fprintf(fp, "%s %s %s %d %d %d %d %s", course[i].courseid, course[i].coursename, course[i].coursetype, course[i].coursetime01, course[i].coursetime02, course[i].coursetime03, course[i].coursescore, course[i].starttime);
		fprintf(fp, "\n");
	}
	fclose(fp);
	printf("����ɱ��棡\n");
	
}

void fun08(){
	
	int a;
	printf("�����˳�ϵͳ���Ƿ񱣴�γ���Ϣ(1/0)?\n");
	scanf("%d", &a);
	
	if(a == 1){
		fun07();
		printf("��ӭ�´�ʹ�ã�\n");
		exit(0);
	}else{
		printf("����δ���棬�ѳɹ��˳�����ӭ�´�ʹ�ã�\n");
		exit(0);
	}
	
}

int main(){
	
	
	printf("********************************************\n");	
	printf("********************************************\n");
	printf("***************ѧ��ѡ��ϵͳ*****************\n");
	printf("********************************************\n");
	printf("******1.�γ���Ϣ��ʾ*****2.ѧ��ѡ����Ϣ��ʾ*\n");
	printf("********************************************\n");
	printf("******3.�γ���Ϣ¼��*****4.ѧ��ѡ��*********\n");
	printf("********************************************\n");
	printf("******5.�γ���Ϣ��ѯ*****6.ѡ����Ϣ��ѯ*****\n");
	printf("********************************************\n");
	printf("******7.����*************0.�˳�ϵͳ*********\n");
	printf("********************************************\n");
	printf("********************************************\n");
	printf("********************************************\n");
	printf("********************************************\n");
	printf("********************************************\n");
	
	
	int flag;

	
	while(true){
		
		printf("������������,�س���������");
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
