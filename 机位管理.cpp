#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

struct Computer 
{
	int isempty[6];  	
};

struct Computer computer[20];


void fun01(){
	
	printf("����������ʱ��(8:00 ~ 24:00)����ʼ��ѯ�����λ(ʱ����24Сʱ�ƣ�eg: 8:00, 18:00)��\n");
	
	char time[20];
	int flag;
	scanf("%s", time); 
	
	
	if(strcmp(time, "8:00") == 0 || strcmp(time, "9:00") == 0){
		flag = 0;
	}
	else if(strcmp(time, "10:00") == 0 || strcmp(time, "11:00") == 0){
		flag = 1;
	}
	else if(strcmp(time, "12:00") == 0 || strcmp(time, "13:00") == 0){
		flag = 2;
	}
	else if(strcmp(time, "14:00") == 0 || strcmp(time, "15:00") == 0){
		flag = 3;
	}
	else if(strcmp(time, "16:00") == 0 || strcmp(time, "17:00") == 0){
		flag = 4;
	}
	else if(strcmp(time, "18:00") == 0 || strcmp(time, "19:00") == 0){
		flag = 5;
	}else{
		printf("��������\n");
		return ;
	}
	
	printf("�����λΪ��\n");
	
	for(int i = 0; i < 20; i++){
		if(computer[i].isempty[flag] == 0){
			printf("%d ", i);
		}
	}	
	
	printf("\n");
	
	
}

void fun02(){
	
	printf("����������ʱ��(8:00 ~ 24:00)����ʼԤ�������λ(ʱ����24Сʱ�ƣ�eg: 8:00, 18:00)��\n"); 
	
	
	char time[20];
	int flag;
	scanf("%s", time); 
	
	
	if(strcmp(time, "8:00") == 0 || strcmp(time, "9:00") == 0){
		flag = 0;
	}
	else if(strcmp(time, "10:00") == 0 || strcmp(time, "11:00") == 0){
		flag = 1;
	}
	else if(strcmp(time, "12:00") == 0 || strcmp(time, "13:00") == 0){
		flag = 2;
	}
	else if(strcmp(time, "14:00") == 0 || strcmp(time, "15:00") == 0){
		flag = 3;
	}
	else if(strcmp(time, "16:00") == 0 || strcmp(time, "17:00") == 0){
		flag = 4;
	}
	else if(strcmp(time, "18:00") == 0 || strcmp(time, "19:00") == 0){
		flag = 5;
	}else{
		printf("��������\n");
		return ;
	}
	
	for(int i = 0; i < 20; i++){
		if(computer[i].isempty[flag] == 0){
			computer[i].isempty[flag] = 1; 
			printf("Ԥ���ɹ���Ԥ����λΪ��%d\n", i);
			return ;
		}
	}
	
	printf("Ԥ��ʧ�ܣ�����ʱ����޻�λ��");
	
}


void fun03(){
	
	printf("������Ԥ��ʱ��ͻ�λ�ţ��Կո������\n"); 
	
	int id; 
	char time[20];
	int flag;
	scanf("%s %d", time, &id); 
	
	
	if(strcmp(time, "8:00") == 0 || strcmp(time, "9:00") == 0){
		flag = 0;
	}
	else if(strcmp(time, "10:00") == 0 || strcmp(time, "11:00") == 0){
		flag = 1;
	}
	else if(strcmp(time, "12:00") == 0 || strcmp(time, "13:00") == 0){
		flag = 2;
	}
	else if(strcmp(time, "14:00") == 0 || strcmp(time, "15:00") == 0){
		flag = 3;
	}
	else if(strcmp(time, "16:00") == 0 || strcmp(time, "17:00") == 0){
		flag = 4;
	}
	else if(strcmp(time, "18:00") == 0 || strcmp(time, "19:00") == 0){
		flag = 5;
	}else{
		printf("��������\n");
		return ;
	}
	
	if(computer[id].isempty[flag] == 0){
		printf("ȡ��ʧ�ܣ���ǰ��λ��Ԥ����\n"); 
	}else{
		computer[id].isempty[flag] = 0;
		printf("ȡ���ɹ���\n");
	}
	
	 
	
	
}

void fun04(){
	
	int a;
	printf("�����˳�ϵͳ���Ƿ��˳�(1/0)?\n");
	scanf("%d", &a);	
	if(a == 1){
		exit(0);
	}else{
		printf("��ȡ����\n");
	}
}



int main(){
	
	
	
	cout<<"***********************************************************************"<<endl;
 	cout<<"**------------------------������λԤ��ϵͳ---------------------------**"<<endl;
 	cout<<"***********************************************************************"<<endl;
 	cout<<"**                        1. ��ѯ��λ                                **"<<endl;
 	cout<<"**                        2. ��λԤ��                                **"<<endl;
	cout<<"**                        3. ȡ��ԤԼ                                **"<<endl;
 	cout<<"**                        0. �˳�ϵͳ                                **"<<endl;
 	cout<<"***********************************************************************"<<endl;
 	
 	
 	int flag;
	
		
	while(true){
		
		printf("������������,�س���������");
		scanf("%d", &flag);
		
		switch (flag){
        	case 1: fun01(); break;
        	case 2: fun02(); break;
        	case 3: fun03(); break;
        	case 0: fun04(); break;
        	default:printf("error\n");
    	}
		
		
	}
} 
				
		
		
		
