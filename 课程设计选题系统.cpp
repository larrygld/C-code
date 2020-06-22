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
	
	if((fp=fopen("C:\\Users\\larry\\Desktop\\stu.txt","r")) == NULL)			// ���ļ�������fpָ�� �ļ� 
	{
		printf("Can not open file\n");
		exit(1);
	}
	
	
	while(!feof(fp))        
	{ 
		fscanf(fp, "%s %s %s %s", student[i].stuid, student[i].stuname, student[i].grade, student[i].major); // ���������鸳ֵ 
		i++;
	} 
	
	totalstudents = i;
	
	fclose(fp);
	
	i = 0;
	
	if((fp=fopen("C:\\Users\\larry\\Desktop\\cou.txt","r")) == NULL)			// ���ļ�������fpָ�� �ļ� 
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
	
	fclose(fp); //�ر��ļ� 
	
	i = 0;
	
	if((fp=fopen("C:\\Users\\larry\\Desktop\\cho.txt","r")) == NULL)			// ���ļ�������fpָ�� �ļ� 
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
	
	printf("������     �γ�����    ѡ����Ŀ     ָ����ʦ      ѧ��\n"); 
	for(int i = 0; i < totalcourses; i++){
		printf("%s\t%s\t%s\t%s\t%s\n", course[i].courseid, course[i].coursename, course[i].coursetitle, course[i].teacher, course[i].score);
	}
	
}


void fun02(){
	
	printf("ѧ��     ����    ���      רҵ\n"); 
	for(int i = 0; i < totalstudents; i++){
		printf("%s\t%s\t%s\t%s\n", student[i].stuid, student[i].stuname, student[i].grade, student[i].major);
	}
	
}

void fun03(){
	
	printf("ѧ��     ����    ������      ��������\n"); 
	for(int i = 0; i < totalchoose; i++){
		printf("%s\t%s\t%s\t%s\n", choose[i].stuid, choose[i].stuname, choose[i].courseid, choose[i].coursetitle);
	}
	
}


void fun04(){
	
	printf("�����������,�γ�����,ѡ����Ŀ,ָ����ʦ,ѧ�֣��Կո������\n");
	
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
	
	printf("¼��ɹ���\n");
	
	
} 


void fun05(){
	
	printf("������ѧ��ѧ�ţ���������ͣ�רҵ���Կո������\n");
	
	scanf("%s %s %s %s", student[totalstudents].stuid, student[totalstudents].stuname, student[totalstudents].grade, student[totalstudents].major);
	
	totalstudents++;
	
	printf("¼��ɹ���\n");
	
}

void fun06(){
	
	printf("������ѧ��ѧ��,����,������,�������ƣ��Կո������\n");
	
	scanf("%s %s %s %s", choose[totalchoose].stuid, choose[totalchoose].stuname, choose[totalchoose].courseid, choose[totalchoose].coursetitle);
	
	totalchoose++;
	
	printf("¼��ɹ���\n");
	
}

void fun07(){
	
	printf("--1.ѧ��--2.����--3.������--4.��������--\n");
	printf("��������(1-4),�����ָ���ֶβ�ѯ��");
	
	int pos;
	scanf("%d", &pos);
	
	printf("�������ֶ�ֵ\n");
	
	char str[100];
	
	switch (pos){
		
    	case 1: {
    		scanf("%s", str);
    		//�������飬��ѯ������Ҫ��ľ���� 
    		printf("��ѯ���Ľ��Ϊ��\n");
    		for(int i = 0; i < totalchoose; i++){
    			
		       	if(strcmp(str, choose[i].stuid) == 0){
		       		printf("%s\t%s\t%s\t%s\n", choose[i].stuid, choose[i].stuname, choose[i].courseid, choose[i].coursetitle);	
				}
			}

		}; break;
		
		case 2: {
    		scanf("%s", str);
    		//�������飬��ѯ������Ҫ��ľ���� 
    		printf("��ѯ���Ľ��Ϊ��\n");
    		for(int i = 0; i < totalchoose; i++){
    			
		       	if(strcmp(str, choose[i].stuname) == 0){
		       		printf("%s\t%s\t%s\t%s\n", choose[i].stuid, choose[i].stuname, choose[i].courseid, choose[i].coursetitle);	
				}
			}

		}; break;
		
		case 3: {
    		scanf("%s", str);
    		//�������飬��ѯ������Ҫ��ľ���� 
    		printf("��ѯ���Ľ��Ϊ��\n");
    		for(int i = 0; i < totalchoose; i++){
    			
		       	if(strcmp(str, choose[i].courseid) == 0){
		       		printf("%s\t%s\t%s\t%s\n", choose[i].stuid, choose[i].stuname, choose[i].courseid, choose[i].coursetitle);	
				}
			}

		}; break;
		
		case 4: {
    		scanf("%s", str);
    		//�������飬��ѯ������Ҫ��ľ���� 
    		printf("��ѯ���Ľ��Ϊ��\n");
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
	
	printf("������Ҫɾ����¼��ѧ��ѧ�ţ�\n");
	char id[20];
	scanf("%s", id);
	
	for(int i = 0; i < totalchoose; i++){
		if(strcmp(id, choose[i].stuid) == 0){
			
			
			//�鵽�˷���Ҫ��ľ�����ǰ��һλ 
			for(int j = i + 1; j < totalchoose; j++){
				choose[j - 1] = choose[j];
			}
			totalchoose--;
			printf("ɾ���ɹ���\n");
			return ;
			 
		}
	}
	printf("�������󣬼�¼�����ڣ�\n");
	
} 

void fun09(){
	int a;
	printf("�����˳�ϵͳ���Ƿ��˳�(1/0)?\n");
	scanf("%d", &a);
	
	if(a == 1){
		printf("��ӭ�´�ʹ�ã�\n");
		exit(0);
	}else{
		
	}	
}

int main()
{
	
	fun00();
	
	printf("********************************************\n");	
	printf("********************************************\n");
	printf("***************�γ����ѡ��ϵͳ*************\n");
	printf("********************************************\n");
	printf("******1.�γ���Ϣ��ʾ*****2.ѧ����Ϣ��ʾ*****\n");
	printf("********************************************\n");
	printf("******3.ѡ����Ϣ��ʾ*****4.�γ���Ϣ¼��*****\n");
	printf("********************************************\n");
	printf("******5.ѧ����Ϣ¼��*****6.ѡ����Ϣ¼��*****\n");
	printf("********************************************\n");
	printf("******7.��ѯѡ����Ϣ*****8.ɾ��ѡ����Ϣ*****\n");
	printf("********************************************\n");
	printf("*****************0.�˳�ϵͳ*****************\n");
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
			case 8: fun08(); break;
			case 0: fun09(); break;
        	default:printf("error\n");
    	}
		
		
	}
		



}

