#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

void fun();


void fun01(){
	
	
	
	while(true){
		
		system("cls");
		
		int a, b , c, max;
	
		printf("�������һ����Ȼ����"); 
		scanf("%d", &a);
		
		printf("������ڶ�����Ȼ����"); 
		scanf("%d", &b);
		
		printf("�������������Ȼ����"); 
		scanf("%d", &c);
		
		if(a > b){
			max = a;
		}else{
			max = b;
		}
		
		if(c > max){
			max = c;
		}
		
		printf("�������ֱ�Ϊ %d %d %d, �������Ϊ %d \n", a, b, c, max);
		
		int flag; 
		
		
		printf("����0�����ϼ��˵������������ַ������˹��ܣ�"); 
		
		scanf("%d", &flag);
		
		if(flag == 0){
			system("cls");
			fun();
			break;
		}
		
	
	}
		
}


void fun02(){
	
	while(true){
		
		system("cls");
		
		int i, sum=0;//����ѭ�������ʹ����͵ı���sum
	
		for(i = 1; i <= 100; i++){
			
			if(i % 2 == 1){
				sum += i;//������ͼ���
			}
			
			
		}
	
		printf("1-100����֮����%d\n", sum);//������
		
		printf("����0�����ϼ��˵������������ַ������˹��ܣ�"); 
		
		int flag; 
		
		scanf("%d", &flag);
		
		if(flag == 0){
			system("cls");
			fun();
			break;
		}		
	
	}	
	
}



void fun03(){
	
	while(true){
		
		system("cls");
		
		char str[201];
		
		int sum;
		
		printf("������һ�����д�д��ĸ���ַ�����"); 
		
		scanf("%s", str);
		
		for(int i = 0; str[i]; i++){
			
			if( str[i] >= 'A' && str[i] <= 'Z'){
				
				sum++;
				
			}
		}
		
		printf("��������ַ���Ϊ��%s  ���д�д��ĸ����Ϊ %d \n", str, sum);
		
		printf("����0�����ϼ��˵������������ַ������˹��ܣ�"); 
		
		int flag; 
		
		scanf("%d", &flag);
		
		if(flag == 0){
			system("cls");
			fun();
			break;
		}		
	
	}	
	
}


void fun(){
	
	printf("2019-2020�ڶ�ѧ��C������ĩ����\n");
	printf("1.�����ֵ\n");
	printf("2.ͳ��������\n");
	printf("3.ͳ�ƴ�д��ĸ����\n");
	
	
	int flag;

	
	while(true){
		
		printf("������������(����0�˳�ϵͳ)��");
		scanf("%d", &flag);
		
		switch (flag){
        	case 1: fun01(); break;
        	case 2: fun02(); break;
        	case 3: fun03(); break;
        	case 0: exit(0); break;
        	default:printf("error\n");
    	}
	
	}
	
}


int main(){
	
	fun();		
	
	return 0;
	
} 
