#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

struct Employee{
	
	char id[20];	 
	char name[20];		
	char sex[5];	
	int days;		 
};

int totalrecords = 0;
struct Employee employee[1001];


/**************************************
��������˵������ʼ��ϵͳ���� 
�β�˵����  �� 
����ֵ��    ��
**************************************/
 
void fun(){
	
	int i = 0;
	
	strcpy(employee[i].id, "001");
	strcpy(employee[i].name, "Jams");
	strcpy(employee[i].sex, "M");
	employee[i].days = 22;
	i++;
	
	strcpy(employee[i].id, "002");
	strcpy(employee[i].name, "Alice");
	strcpy(employee[i].sex, "F");
	employee[i].days = 15;
	i++;
	
	strcpy(employee[i].id, "003");
	strcpy(employee[i].name, "Tom");
	strcpy(employee[i].sex, "M");
	employee[i].days = 30;
	i++;
	
	strcpy(employee[i].id, "004");
	strcpy(employee[i].name, "Mick");
	strcpy(employee[i].sex, "M");
	employee[i].days = 26;
	i++;
	
	strcpy(employee[i].id, "005");
	strcpy(employee[i].name, "Gates");
	strcpy(employee[i].sex, "M");
	employee[i].days = 19;
	i++;
	
	strcpy(employee[i].id, "006");
	strcpy(employee[i].name, "Robot");
	strcpy(employee[i].sex, "M");
	employee[i].days = 28;
	i++;
	
	strcpy(employee[i].id, "007");
	strcpy(employee[i].name, "Rose");
	strcpy(employee[i].sex, "F");
	employee[i].days = 7;
	i++;
	
	totalrecords = i; 
		
} 


/**************************************
��������˵������ӡȫ��ϵͳ���� 
�β�˵����  �� 
����ֵ��    ��
**************************************/

void fun01(){
	
	printf("��Ա���  ���� �Ա� ��������\n"); 
	for(int i = 0; i < totalrecords; i++){
		printf("%s\t%s\t%s\t%d\n", employee[i].id, employee[i].name, employee[i].sex, employee[i].days);
	}
	
}


/**************************************
��������˵������id�ֶν������������� 
�β�˵����  �� 
����ֵ��    ��
**************************************/

void fun02(){
	
	printf("--1.����--2.����--\n");
	printf("��������(1-2),��ָ����ʽ����");
	
	int pos;
	scanf("%d", &pos);
	
	Employee tmp;
	
	
	switch (pos){
		
    	case 1: {
    		
    		for(int i = 0; i < totalrecords; i++){
    			
		       for(int j = 0; j < totalrecords - i - 1; j++){
		       	
		            if(strcmp(employee[j].id, employee[j + 1].id) < 0){
		                tmp = employee[j+1];//�ṹ���������帳ֵ
		                employee[j+1] = employee[j];
		                employee[j] = tmp;
		            }
		        }
			}	
			fun01();
			
		}; break;
		
		
		case 2: {
    		
    		for(int i = 0; i < totalrecords; i++){
    			
		       for(int j = 0; j < totalrecords - i - 1; j++){
		       	
		            if(strcmp(employee[j].id, employee[j + 1].id) > 0){
		                tmp = employee[j+1];//�ṹ���������帳ֵ
		                employee[j+1] = employee[j];
		                employee[j] = tmp;
		            }
		        }
			}	
			fun01();
			
		}; break;
		
		default:printf("error\n");	
        	
	} 
	
}


/**************************************
��������˵���������������ֶν������������� 
�β�˵����  �� 
����ֵ��    ��
**************************************/

void fun03(){
	
	printf("--1.����--2.����--\n");
	printf("��������(1-2),��ָ����ʽ����");
	
	int pos;
	scanf("%d", &pos);
	
	Employee tmp;
	
	
	switch (pos){
		
    	case 1: {
    		
    		for(int i = 0; i < totalrecords; i++){
    			
		       for(int j = 0; j < totalrecords - i - 1; j++){
		       	
		            if(employee[j].days < employee[j + 1].days){
		                tmp = employee[j+1];//�ṹ���������帳ֵ
		                employee[j+1] = employee[j];
		                employee[j] = tmp;
		            }
		        }
			}	
			fun01();
			
		}; break;
		
		
		case 2: {
    		
    		for(int i = 0; i < totalrecords; i++){
    			
		       for(int j = 0; j < totalrecords - i - 1; j++){
		       	
		            if(employee[j].days > employee[j + 1].days){
		                tmp = employee[j+1];//�ṹ���������帳ֵ
		                employee[j+1] = employee[j];
		                employee[j] = tmp;
		            }
		        }
			}	
			fun01();
			
		}; break;
		
		default:printf("error\n");	
        	
	} 
	
	
	
}

/**************************************
��������˵����ͳ�ƹ�Ա��Ů���� 
�β�˵����  �� 
����ֵ��    ��
**************************************/

void fun04(){
	
	int m = 0, f = 0;
	
	
	for(int i = 0; i < totalrecords; i++){
		if(strcmp(employee[i].sex, "M") == 0){
			m++;
		}else{
			f++;
		}
	}
	
//	printf("m: %d, f: %d", m, f);

	printf("������ռ����Ϊ�� %.2lf\n", (double)m / 7); 
	printf("Ů����ռ����Ϊ�� %.2lf\n", (double)f / 7); 
	
	
	
}

/**************************************
��������˵�����˳�ϵͳ 
�β�˵����  �� 
����ֵ��    ��
**************************************/

void fun05(){
	
	printf("��ӭ�´�ʹ�ã�"); 
	exit(0);
	
}


int main(){
	
	fun(); 
	
	cout<<"***********************************************************************"<<endl;
 	cout<<"**--------------------------ְ������ϵͳ-----------------------------**"<<endl;
 	cout<<"***********************************************************************"<<endl;
 	cout<<"**                        1. ��ʾȫ����Ϣ                            **"<<endl;
	cout<<"**                        2. ��id��������                            **"<<endl;
    cout<<"**                        3. ������������������                      **"<<endl;
    cout<<"**                        4. ͳ����Ů����                            **"<<endl;
 	cout<<"**                        5. �˳�ϵͳ                                **"<<endl;
 	cout<<"***********************************************************************"<<endl;
 	
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
        	default:printf("error\n");
    	}
    	
	}
	return 0;
} 
