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
	
	printf("ѧ��     ����    �Ա�       ����       ��ע\n"); 
	for(int i = 0; i < totalrecords; i++){
		printf("%s\t%s\t%s\t%d\t%s\n", student[i].id, student[i].name, student[i].sex, student[i].age, student[i].msg);
	}
	
}

void fun02(){
	
	printf("������ѧ��ѧ��,����,�Ա�,����,��ע���Կո������\n");
	
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
	printf("��Ϣ¼��ɹ���\n"); 
	
}


void fun03(){
	
	printf("������Ҫɾ��ѧ��ѧ�ţ�\n");
	char id[20];
	scanf("%s", id);
	
	for(int i = 0; i < totalrecords; i++){
		if(strcmp(id, student[i].id) == 0){
			
			
			//�鵽�˷���Ҫ��ľ�����ǰ��һλ 
			for(int j = i + 1; j < totalrecords; j++){
				student[j - 1] = student[j];
			}
			totalrecords--;
			printf("ɾ���ɹ���\n");
			return ;
			 
		}
	}
	printf("��������ѧ�������ڣ�\n");
	
}

void fun04(){
	
	char pwd[100];
	
	printf("���������룺\n");
	
	scanf("%s", pwd);
	
	if(strcmp(pwd, "0000") == 0){
		
		printf("��������޸�ѧ��ѧ�ţ�\n");
		char id01[20];
		scanf("%s", id01);
		
		char id[20];	 
		char name[20];		
		char sex[10];	
		int age;		
		char msg[100]; 
	
	
		for(int i = 0; i < totalrecords; i++){
			if(strcmp(id01, student[i].id) == 0){
				
				
				//�鵽�˷���Ҫ��ľ��޸�
				
				printf("�������޸ĺ��ѧ��ѧ��,����,�Ա�,����,��ע���Կո�����Կո������\n");
				
				scanf("%s %s %s %d %s", id, name, sex, &age, msg);
				 
				strcpy(student[i].id, id);
				strcpy(student[i].name, name);
				strcpy(student[i].sex, sex);
				student[i].age = age;
				strcpy(student[i].msg, msg);
				printf("�޸ĳɹ���\n");
				
				return ;
				 
			}
		}
		
		printf("����ʧ�ܣ����������룡\n"); 
	
	
	}else{
		
		printf("�������!"); 
	}
	
	
	
}

void fun05(){
	
	printf("--1.ѧ��--2.����--3.�Ա�--4.����--\n");
	printf("��������(1-4),�����ָ���ֶβ�ѯ��");
	
	int pos;
	scanf("%d", &pos);
	
	printf("�������ֶ�ֵ\n");
	
	char str[100];
	int age; 
	
	
	switch (pos){
        	case 1: {
        		scanf("%s", str);
        		//�������飬��ѯ������Ҫ��ľ���� 
        		printf("��ѯ���Ľ��Ϊ��\n");
        		for(int i = 0; i < totalrecords; i++){
			       	if(strcmp(str, student[i].id) == 0){
			       		printf("%s\t%s\t%s\t%d\t%s\n", student[i].id, student[i].name, student[i].sex, student[i].age, student[i].msg);		
					}
			    }

			}; break;
        	case 2: {
        		scanf("%s", str);
        		printf("��ѯ���Ľ��Ϊ��\n");
				for(int i = 0; i < totalrecords; i++){
			       	if(strcmp(str, student[i].name) == 0){
			       		printf("%s\t%s\t%s\t%d\t%s\n", student[i].id, student[i].name, student[i].sex, student[i].age, student[i].msg);			
					}
			    }
	
			}; break;
        	case 3: {
        		scanf("%s", str);
        		printf("��ѯ���Ľ��Ϊ��\n");
				for(int i = 0; i < totalrecords; i++){
			       	if(strcmp(str, student[i].sex) == 0){
			       		printf("%s\t%s\t%s\t%d\t%s\n", student[i].id, student[i].name, student[i].sex, student[i].age, student[i].msg);			
					}
			    }
			
			}; break;
        	case 4: {
        		
        		scanf("%d", &age);
        		printf("��ѯ���Ľ��Ϊ��\n");
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
	
	FILE *fp;		//�ļ�ָ��
	int i;

	fp=fopen("C:\\Users\\larry\\Desktop\\student.txt","w");			/*��ֻ���ļ�ĩβд�ķ�ʽ���ļ�*/
	
	fprintf(fp, "ѧ�� ���� �Ա� ���� ��ע\n");
	
	for(i = 0; i < totalrecords; i++)
	{	
		fprintf(fp, "%s %s %s %d %s", student[i].id, student[i].name, student[i].sex, student[i].age, student[i].msg);
		fprintf(fp, "\n");
	}
	fclose(fp);
	printf("����ɱ��棡\n");
	
}

void fun07(){
	int a;
	printf("�����˳�ϵͳ���Ƿ񱣴�(1/0)?\n");
	scanf("%d", &a);
	
	if(a == 1){
		fun06();
		printf("��ӭ�´�ʹ�ã�\n");
		exit(0);
	}else{
		printf("����δ���棬�ѳɹ��˳�����ӭ�´�ʹ�ã�\n");
		exit(0);
	}	
}


int main(){
	
	char pwd[100];
	
	printf("���������룺\n");
	
	scanf("%s", pwd);
	
	if(strcmp(pwd, "0000") == 0){
		
		printf("********************************************\n");	
		printf("********************************************\n");
		printf("**************�༶��������ϵͳ**************\n");
		printf("********************************************\n");
		printf("******1.��Ϣ��ʾ*********2.��Ϣ¼��*********\n");
		printf("********************************************\n");
		printf("******3.ɾ����Ϣ*********4.��Ϣ�޸�*********\n");
		printf("********************************************\n");
		printf("******5.��Ϣ��ѯ*********6.��¼����*********\n");
		printf("********************************************\n");
		printf("***************0.�˳�ϵͳ*******************\n");
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
	        	case 0: fun07(); break;
	        	default:printf("error\n");
	    	}
			
			
		}
				
		
		
		return 0;
		
	
	
	} else{
		printf("�������!"); 
	} 
	
	
	
	
} 
