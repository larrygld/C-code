#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
#include <string>
#include <string.h>
using namespace std;


struct Student{
	
	char id[30];
	char name[30];	 
	char class01[30];//���ڰ༶	
	int score01;   	//˼������ѧ��	
	int score02;	//��������ѧ�� 
	int score03;	//У��У��ѧ�� 
	int score04;	//���Ҽ���ѧ�� 
	int score05;	//��������ѧ�� 
};


int totalrecords;
struct Student student[1001];


void fun01(){
	
	printf("ѧ��    ����   �༶        ˼������ѧ��   ��������ѧ��   У��У��ѧ��    ���Ҽ���ѧ��   ��������ѧ��\n"); 
	for(int i = 0; i < totalrecords; i++){
		printf("%s\t%s\t%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", student[i].id, student[i].name, student[i].class01, student[i].score01, student[i].score02, student[i].score03, student[i].score04, student[i].score05);
	}
	
}


void fun02(){
	
	printf("������ѧ��ѧ��,����,�༶,˼������ѧ��,��������ѧ��,У��У��ѧ��,���Ҽ���ѧ��,��������ѧ��,�Կո������\n");
	
	scanf("%s %s %s %d %d %d %d %d", student[totalrecords].id, student[totalrecords].name, student[totalrecords].class01, &student[totalrecords].score01, &student[totalrecords].score02, &student[totalrecords].score03, &student[totalrecords].score04, &student[totalrecords].score05);
	
	printf("��ӳɹ���\n"); 
	
	totalrecords++;
}

void fun03(){
	
	printf("��������޸�ѧ��ѧ�ţ�\n");
	char id01[20];
	scanf("%s", id01);
	
	for(int i = 0; i < totalrecords; i++){
		if(strcmp(id01, student[i].id) == 0){
			
			
			//�鵽�˷���Ҫ��ľ��޸�
			
			printf("�������޸ĺ��ѧ��ѧ��,����,�༶,˼������ѧ��,��������ѧ��,У��У��ѧ��,���Ҽ���ѧ��,��������ѧ��,�Կո������\n");
			
			scanf("%s %s %s %d %d %d %d %d", student[i].id, student[i].name, student[i].class01, &student[i].score01, &student[i].score02, &student[i].score03, &student[i].score04, &student[i].score05);
			printf("�޸ĳɹ���\n");
			
			return ;
			 
		}
	}
	
	printf("���޴��ˣ�\n"); 
	
}

void fun04(){
	
	printf("�����������ѧ��ѧ�ţ�\n");
	char id01[20];
	scanf("%s", id01);
	
	
	for(int i = 0; i < totalrecords; i++){
		if(strcmp(id01, student[i].id) == 0){
			
			
			//�鵽�˷���Ҫ��ľ����
			printf("��ѯ���Ľ��Ϊ��\n");
			
			printf("ѧ��    ����   �༶        ˼������ѧ��   ��������ѧ��   У��У��ѧ��    ���Ҽ���ѧ��   ��������ѧ��\n");
			
			printf("%s\t%s\t%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", student[i].id, student[i].name, student[i].class01, student[i].score01, student[i].score02, student[i].score03, student[i].score04, student[i].score05);
			
			return ;
			
			 
		}
	}
	
	printf("���޴��ˣ�\n"); 
		
}

void fun05(){
	
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
	printf("���޴��ˣ�\n");
	
} 


void fun06(){
	
	printf("--1.ѧ��--2.����--3.�༶--\n");
	printf("��������(1-3),�����ָ���ֶβ�ѯ��");
	
	int pos;
	scanf("%d", &pos);
	
	
	int k;
	Student tmp;
	
	switch (pos){
        	case 1: {
        		for(int i = 0; i < totalrecords; i++){
			       for(int j = 0; j < totalrecords - i - 1; j++){
			            if(strcmp(student[j].id, student[j+1].id) > 0){
			                tmp = student[j+1];//�ṹ���������帳ֵ
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
			                tmp = student[j+1];//�ṹ���������帳ֵ
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
			                tmp = student[j+1];//�ṹ���������帳ֵ
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
	
	FILE *fp;		//�ļ�ָ��
	int i;

	fp=fopen("C:\\Users\\larry\\Desktop\\stu.txt","w");			/*��ֻ���ļ�ĩβд�ķ�ʽ���ļ�*/
	for(i = 0; i < totalrecords; i++)
	{	
		fprintf(fp, "%s %s %s %d %d %d %d %d", student[i].id, student[i].name, student[i].class01, student[i].score01, student[i].score02, student[i].score03, student[i].score04, student[i].score05);
		fprintf(fp, "\n");
	}
	fclose(fp);
	printf("����ɱ��棡\n");
	
	
}


void fun08(){
	
	exit(1);
}


int main(){
	
	totalrecords = 0;
	
	printf("********************************************\n");	
	printf("********************************************\n");
	printf("***********ѧ��������Ϣ����ϵͳ*************\n");
	printf("********************************************\n");
	printf("******1.��¼���*********2.���ѧ��*********\n");
	printf("********************************************\n");
	printf("******3.�޸�ѧ��*********4.����ѧ��*********\n");
	printf("********************************************\n");
	printf("******5.ɾ��ѧ��*********6.ѧ������*********\n");
	printf("********************************************\n");
	printf("******7.�����ļ�*********8.�˳�ϵͳ*********\n");
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
        	case 8: fun08(); break;
        	default:printf("error\n");
    	}
		
		
	}
			
	
	
	return 0;
} 
