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
	
	printf("����     ��ַ        �绰       ��������         email\n"); 
	for(int i = 0; i < totalrecords; i++){
		printf("%s\t%s\t%s\t%s\t%s\n", student[i].name, student[i].location, student[i].phonenumber, student[i].postnum, student[i].email);
	}
	
}

void fun02(){
	
	printf("������ѧ����������ַ���绰���������룬email���Կո������\n");
	char name01[10], location01[100], phonenumber01[20], postnum01[20], email01[20];
	scanf("%s %s %s %s %s", name01, location01, phonenumber01, postnum01, email01);
	
	//����Ϣ����ṹ��
	strcpy(student[totalrecords].name, name01);
	strcpy(student[totalrecords].location, location01);
	strcpy(student[totalrecords].phonenumber, phonenumber01);
	strcpy(student[totalrecords].postnum, postnum01);
	strcpy(student[totalrecords].email, email01);
	
	totalrecords++;
	printf("��Ϣ¼��ɹ���\n"); 
	
} 

void fun03(){
	
	printf("������Ҫɾ��ѧ��������\n");
	char name01[10];
	scanf("%s", name01);
	
	for(int i = 0; i < totalrecords; i++){
		if(strcmp(name01, student[i].name) == 0){
			
			
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
	
	printf("--1.����--2.��ַ--3.�绰--4.��������--5.email--\n");
	printf("��������(1-5),�����ָ���ֶβ�ѯ��");
	
	int pos;
	scanf("%d", &pos);
	
	printf("�������ֶ�ֵ\n");
	
	char str[100];
	scanf("%s", str);

	switch (pos){
        	case 1: {
        		//�������飬��ѯ������Ҫ��ľ���� 
        		printf("��ѯ���Ľ��Ϊ��\n");
        		for(int i = 0; i < totalrecords; i++){
			       	if(strcmp(str, student[i].name) == 0){
			       		printf("%s\t%s\t%s\t%s\t%s\n", student[i].name, student[i].location, student[i].phonenumber, student[i].postnum, student[i].email);		
					}
			    }

			}; break;
        	case 2: {
        		printf("��ѯ���Ľ��Ϊ��\n");
				for(int i = 0; i < totalrecords; i++){
			       	if(strcmp(str, student[i].location) == 0){
			       		printf("%s\t%s\t%s\t%s\t%s\n", student[i].name, student[i].location, student[i].phonenumber, student[i].postnum, student[i].email);		
					}
			    }
	
			}; break;
        	case 3: {
        		printf("��ѯ���Ľ��Ϊ��\n");
        		
        		for(int i = 0; i < totalrecords; i++){
			       	if(strcmp(str, student[i].phonenumber) == 0){
			       		printf("%s\t%s\t%s\t%s\t%s\n", student[i].name, student[i].location, student[i].phonenumber, student[i].postnum, student[i].email);		
					}
			    }
			
			}; break;
        	case 4: {
        		printf("��ѯ���Ľ��Ϊ��\n");
        		
        		for(int i = 0; i < totalrecords; i++){
			       	if(strcmp(str, student[i].postnum) == 0){
			       		printf("%s\t%s\t%s\t%s\t%s\n", student[i].name, student[i].location, student[i].phonenumber, student[i].postnum, student[i].email);		
					}
			    }
			
			}; break;
        	case 5: {
        		printf("��ѯ���Ľ��Ϊ��\n");
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
	
	printf("--1.����--2.��ַ--3.�绰--4.��������--5.email--\n");
	printf("��������(1-5),�����ָ���ֶ�����");
	
	int pos;
	scanf("%d", &pos);
	
	
	int k;
	Student tmp;
	
	switch (pos){
        	case 1: {
        		for(int i = 0; i < totalrecords; i++){
			       for(int j = 0; j < totalrecords - i - 1; j++){
			            if(strcmp(student[j].name, student[j+1].name) < 0){
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
			            if(strcmp(student[j].location, student[j+1].location) < 0){
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
			            if(strcmp(student[j].phonenumber, student[j+1].phonenumber) < 0){
			                tmp = student[j+1];//�ṹ���������帳ֵ
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
			                tmp = student[j+1];//�ṹ���������帳ֵ
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

void fun06(){
	
	FILE *fp;		//�ļ�ָ��
	int i;

	fp=fopen("C:\\Users\\larry\\Desktop\\student.txt","w");			/*��ֻ���ļ�ĩβд�ķ�ʽ���ļ�*/
	for(i = 0; i < totalrecords; i++)
	{	
		fprintf(fp, "%s %s %s %s %s", student[i].name, student[i].location, student[i].phonenumber, student[i].postnum, student[i].email);
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
	
	
	
	printf("********************************************\n");	
	printf("********************************************\n");
	printf("****************ͨѶ¼����ϵͳ**************\n");
	printf("********************************************\n");
	printf("******1.��¼���*********2.��Ӽ�¼*********\n");
	printf("********************************************\n");
	printf("******3.ɾ����¼*********4.��¼����*********\n");
	printf("********************************************\n");
	printf("******5.��¼����*********6.��¼����*********\n");
	printf("********************************************\n");
	printf("***************0.�˳�ϵͳ*******************\n");
	printf("********************************************\n");
	printf("********************************************\n");
	printf("********************************************\n");
	printf("********************************************\n");
	
	
	int i = 0, j, flag;
	
	FILE *fp;
	if((fp=fopen("C:\\Users\\larry\\Desktop\\student.txt","rb")) == NULL)			// ���ļ�������fpָ�� �ļ� 
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

	fclose(fp);				//�ر��ļ��� 
	
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
} 
