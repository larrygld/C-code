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
	
	printf("ѧ��     ����    ����       ��ѧ       Ӣ��\n"); 
	
	for(int i = 0; i < totalrecords; i++){
		
		printf("%s\t%s\t%.1lf\t%.1lf\t%.1lf\n", student[i].id, student[i].name, student[i].chinese, student[i].math, student[i].english);
	}
	
} 

void fun02(){
	
	printf("������ѧ��ѧ��,����,���ĳɼ�,��ѧ�ɼ�,Ӣ��ɼ����Կո������\n");
	
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
	
	printf("��Ϣ¼��ɹ���\n"); 
	
	
} 


void fun03(){
	
	for(int i = 0; i < totalrecords; i++){
		
		student[i].average = (student[i].chinese + student[i].math + student[i].english) / 3;
	
	}
	
	printf("������Ϊ��\n");
	
	printf("ѧ��     ����    ����       ��ѧ       Ӣ��    ƽ���ɼ�\n"); 
	
	for(int i = 0; i < totalrecords; i++){
		
		printf("%s\t%s\t%.1lf\t%.1lf\t%.1lf\t%.1lf\n", student[i].id, student[i].name, student[i].chinese, student[i].math, student[i].english, student[i].average);
	
	
	}
	
} 


void fun04(){
	
	printf("��������޸�ѧ��ѧ�ţ�\n");
	
	char id01[20];
	
	scanf("%s", id01);
	
	char id[20];	 
	char name[20];		
	double chinese;	
	double math;
	double english;
	
	for(int i = 0; i < totalrecords; i++){
		
		if(strcmp(id01, student[i].id) == 0){
			
			printf("�������޸ĺ��ѧ��ѧ��,����,���ĳɼ�����ѧ�ɼ���Ӣ��ɼ����Կո�����Կո������\n");
		
			scanf("%s %s %lf %lf %lf", id, name, &chinese, &math, &english);
			
			//��ֵ���ṹ������ 
			strcpy(student[i].id, id);
			strcpy(student[i].name, name);
			
			student[i].chinese = chinese;
			student[i].math = math;
			student[i].english = english;
			
			printf("�޸ĳɹ���\n");
				
			return ;
		
		}
			
	}
	
	printf("����ʧ�ܣ����������룡\n"); 
	
	
	
}


void fun05(){
	
	printf("--1.ѧ��--2.����--\n");
	printf("��������(1-2),�����ָ���ֶβ�ѯ��");
	
	
	int pos;
	scanf("%d", &pos);
	
	printf("�������ֶ�ֵ:\n");
	
	char str[100];
	
	switch (pos){
		
    	case 1: {
    		
    		scanf("%s", str);
    		
    		//�������飬��ѯ������Ҫ��ľ���� 
    		
    		printf("��ѯ���Ľ��Ϊ��\n");
    		
    		for(int i = 0; i < totalrecords; i++){
    			
		       	if(strcmp(str, student[i].id) == 0){
		       		
		       		printf("%s\t%s\t%.1lf\t%.1lf\t%.1lf\n", student[i].id, student[i].name, student[i].chinese, student[i].math, student[i].english);		
				}
		    }

		}; break;
		
		
		case 2: {
    		
    		scanf("%s", str);
    		
    		//�������飬��ѯ������Ҫ��ľ���� 
    		
    		printf("��ѯ���Ľ��Ϊ��\n");
    		
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
	
	//�Ƚ�ƽ���ɼ�������� 
	
	for(int i = 0; i < totalrecords; i++){
		
		student[i].average = (student[i].chinese + student[i].math + student[i].english) / 3;
	
	}
	
	printf("������һ��������ϵͳ���������ƽ���ɼ����ڴ˷�����ѧ����Ϣ��\n");
	
	double score;
	
	scanf("%lf", &score); 
	
	for(int i = 0; i < totalrecords; i++){
		
		if(student[i].average > score){
			
			printf("%s\t%s\t%.1lf\t%.1lf\t%.1lf\t%.1lf\n", student[i].id, student[i].name, student[i].chinese, student[i].math, student[i].english, student[i].average);
			
		}
		
	}
	
	
} 


void fun07(){
	
	//�Ƚ�ƽ���ɼ�������� 
	for(int i = 0; i < totalrecords; i++){
		
		student[i].average = (student[i].chinese + student[i].math + student[i].english) / 3;
	
	}
	
	printf("--1.����--2.����--\n");
	printf("��������(1-2),��ָ����ʽ����");
	
	int pos;
	scanf("%d", &pos);
	
	Student tmp;
	
	
	switch (pos){
		
    	case 1: {
    		
    		for(int i = 0; i < totalrecords; i++){
    			
		       for(int j = 0; j < totalrecords - i - 1; j++){
		       	
		            if(student[j].average < student[j+1].average){
		                tmp = student[j+1];//�ṹ���������帳ֵ
		                student[j+1] = student[j];
		                student[j] = tmp;
		            }
		        }
			}
			
			printf("ѧ��     ����    ����       ��ѧ       Ӣ��   ƽ���ɼ�\n"); 
	
			for(int i = 0; i < totalrecords; i++){
				
				printf("%s\t%s\t%.1lf\t%.1lf\t%.1lf\t%.1lf\n", student[i].id, student[i].name, student[i].chinese, student[i].math, student[i].english, student[i].average);
			}

		}; break;
		
		
		case 2: {
    		
    		for(int i = 0; i < totalrecords; i++){
    			
		       for(int j = 0; j < totalrecords - i - 1; j++){
		       	
		            if(student[j].average > student[j+1].average){
		                tmp = student[j+1];//�ṹ���������帳ֵ
		                student[j+1] = student[j];
		                student[j] = tmp;
		            }
		        }
			}
			
			printf("ѧ��     ����    ����       ��ѧ       Ӣ��   ƽ���ɼ�\n"); 
	
			for(int i = 0; i < totalrecords; i++){
				
				printf("%s\t%s\t%.1lf\t%.1lf\t%.1lf\t%.1lf\n", student[i].id, student[i].name, student[i].chinese, student[i].math, student[i].english, student[i].average);
			}

		}; break;
		
		default:printf("error\n");	
        	
	} 
	
	
	
}


void fun08(){
	
	FILE *fp;		//�ļ�ָ��
	int i;

	fp=fopen("C:\\Users\\larry\\Desktop\\stu.txt","w");			/*��ֻ���ļ�ĩβд�ķ�ʽ���ļ�*/
	for(i = 0; i < totalrecords; i++)
	{	
		fprintf(fp, "%s %s %.1lf %.1lf %.1lf", student[i].id, student[i].name, student[i].chinese, student[i].math, student[i].english);
		fprintf(fp, "\n");
	}
	fclose(fp);
	printf("����ɱ��棡\n");
	
}

void fun09(){
	
	int a;
	
	printf("�����˳�ϵͳ���Ƿ񱣴�(1/0)?\n");
	
	scanf("%d", &a);
	
	if(a == 1){
		
		fun08();
		
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
		printf("**************ѧ���ɼ�����ϵͳ**************\n");
		printf("********************************************\n");
		printf("******1.���м�¼*********2.ѧ����Ϣ¼��*****\n");
		printf("********************************************\n");
		printf("******3.ƽ���ɼ�����*****4.��Ϣ�޸�*********\n");
		printf("********************************************\n");
		printf("******5.��Ϣ��ѯ*********6.�ɼ�ͳ��*********\n");
		printf("********************************************\n");
		printf("******7.�ɼ�����*********8.��Ϣ����*********\n");
		printf("********************************************\n");
		printf("***************0.�˳�ϵͳ*******************\n");
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
				
		
		return 0;
		
	
	
	} else{
		printf("�������!"); 
	} 
	
	
	return 0;
} 
