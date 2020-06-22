#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

struct Infocar
{
	char type[30];		// 	�����ͺ� 
	char industry[30];		// 	���� 
	char rate[30];		// 	���ͼ��� 
	char seats[30];		// 	��λ�� 
	char displacement[20];  // ���� 
	char speedbox[20];   // ������ 
	char color[20];      // ��ɫ
	double price;  // �۸� 
};

int totalcars;  //��¼�������� 
struct Infocar infocar[1001];


void fun01(){
	
	printf("�����ͺ�  ����   ���ͼ���   ��λ��   ����   ������   ������ɫ  �����۸�\n"); 
	for(int i = 0; i < totalcars; i++){
		
		if(infocar[i].price == 0){
			continue;
		} 
		
		printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%.1lf\n", infocar[i].type, infocar[i].industry, infocar[i].rate, infocar[i].seats, infocar[i].displacement, infocar[i].speedbox, infocar[i].color, infocar[i].price);
	}
	
	printf("��������Ϊ�� %d\n", totalcars);
	
}


void fun02(){
	 
	
	
	printf("�������¼�복���ͺţ����̣����ͼ�����λ���������������䣬������ɫ�������۸��Կո���\n");
	
	
	scanf("%s %s %s %s %s %s %s %lf", infocar[totalcars].type, infocar[totalcars].industry, infocar[totalcars].rate, infocar[totalcars].seats, infocar[totalcars].displacement, infocar[totalcars].speedbox, infocar[totalcars].color, &infocar[totalcars].price);
	
	printf("¼��ɹ���¼�복����ϢΪ��\n");
	
	printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%.1lf\n", infocar[totalcars].type, infocar[totalcars].industry, infocar[totalcars].rate, infocar[totalcars].seats, infocar[totalcars].displacement, infocar[totalcars].speedbox, infocar[totalcars].color, infocar[totalcars].price);
	
	 
	totalcars++; 
	
	
	
}


void fun03(){
	
	printf("--1.����--2.��������--3.�����۸�--\n");
	printf("��������(1-3),�����ָ���ֶβ�ѯ��");
	
	
	int pos;
	scanf("%d", &pos);
	
	
	
	char str[100];
	double max, min; //�۸�Χ
	
	
	switch (pos){
        	case 1: {
        		//�������飬��ѯ������Ҫ��ľ���� 
        		printf("�������ֶ�ֵ\n");
        		scanf("%s", str);
        		printf("��ѯ���Ľ��Ϊ��\n");
        		for(int i = 0; i < totalcars; i++){
			       	if(strcmp(str, infocar[i].industry) == 0){
			       		printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%.1lf\n", infocar[i].type, infocar[i].industry, infocar[i].rate, infocar[i].seats, infocar[i].displacement, infocar[i].speedbox, infocar[i].color, infocar[i].price);		
					}
			    }

			}; break;
        	case 2: {
        		
        		//�������飬��ѯ������Ҫ��ľ���� 
        		printf("�������ֶ�ֵ\n");
        		scanf("%s", str);
        		printf("��ѯ���Ľ��Ϊ��\n");
        		for(int i = 0; i < totalcars; i++){
			       	if(strcmp(str, infocar[i].rate) == 0){
			       		printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%.1lf\n", infocar[i].type, infocar[i].industry, infocar[i].rate, infocar[i].seats, infocar[i].displacement, infocar[i].speedbox, infocar[i].color, infocar[i].price);		
					}
			    }
	
			}; break;
        	case 3: {
        		
        		printf("��������С�۸��Լ����۸��Կո�����\n");
        		
        		scanf("%lf %lf", &min, &max); 
        		
        		printf("��ѯ���Ľ��Ϊ��\n");
        		
        		for(int i = 0; i < totalcars; i++){
        			//���ҷ��ϼ۸����䳵�� 
			       	if(infocar[i].price <= max && infocar[i].price >= min){
			       		printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%.1lf\n", infocar[i].type, infocar[i].industry, infocar[i].rate, infocar[i].seats, infocar[i].displacement, infocar[i].speedbox, infocar[i].color, infocar[i].price);		
					}
			    }
			
			}; break;
        	
        	default:printf("error\n");
        		
	} 

	
} 

void fun04(){
	
	int i; 
	
	printf("��������޸ĵĳ����ͺ��Ա��ѯ������Ϣ��\n");
	
	char str01[50];
	scanf("%s", str01); 
	
	
	for(i = 0; i < totalcars; i++){
		if(strcmp(str01, infocar[i].type) == 0){
			
			printf("��ѯ���ĳ���Ϊ��\n");
			
			//�ҵ�����Ҫ��ĳ���ֱ�Ӵ�ӡ���� 
			printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%.1lf\n", infocar[i].type, infocar[i].industry, infocar[i].rate, infocar[i].seats, infocar[i].displacement, infocar[i].speedbox, infocar[i].color, infocar[i].price);		
			
			break; 
		}
	}
	
	
	printf("--1.�����ͺ�--2.����--3.��������--4.��λ��--5.����--6.������--7.��ɫ--8.�����۸�\n");
	printf("��������(1-8),������޸�ָ���ֶΣ�");
	
	
	int pos;
	scanf("%d", &pos);
	
	char str[100];
	double price;
	
	
	switch (pos){
		
		
    	case 1: {

    		printf("�������ֶ�ֵ\n");
    		scanf("%s", str);
    		strcpy(infocar[i].type, str);
    		printf("�޸ĳɹ���\n");	

		}; break;
		
		case 2: {

    		printf("�������ֶ�ֵ\n");
    		scanf("%s", str);
    		strcpy(infocar[i].industry, str);
    		printf("�޸ĳɹ���\n");	

		}; break;
		
		
		case 3: {

    		printf("�������ֶ�ֵ\n");
    		scanf("%s", str);
    		strcpy(infocar[i].rate, str);
    		printf("�޸ĳɹ���\n");	

		}; break;
		
		
		case 4: {

    		printf("�������ֶ�ֵ\n");
    		scanf("%s", str);
    		strcpy(infocar[i].seats, str);
    		printf("�޸ĳɹ���\n");	

		}; break;
		
		
		case 5: {

    		printf("�������ֶ�ֵ\n");
    		scanf("%s", str);
    		strcpy(infocar[i].displacement, str);
    		printf("�޸ĳɹ���\n");	

		}; break;
		
		case 6: {

    		printf("�������ֶ�ֵ\n");
    		scanf("%s", str);
    		strcpy(infocar[i].speedbox, str);
    		printf("�޸ĳɹ���\n");	

		}; break;
		
		
		case 7: {

    		printf("�������ֶ�ֵ\n");
    		scanf("%s", str);
    		strcpy(infocar[i].color, str);
    		printf("�޸ĳɹ���\n");	

		}; break;
		
		
		case 8: {

    		printf("�������޸ĺ�ļ۸�\n");
    		scanf("%lf", &price);
    		infocar[i].price = price;
    		printf("�޸ĳɹ���\n");	

		}; break;
        	
        	
        default:printf("error\n");
        		
	} 
	
}

void fun05(){
	
	
	printf("������Ҫɾ���ĳ����ͺţ�\n");
	char type[20];
	scanf("%s", type);
	
	for(int i = 0; i < totalcars; i++){
		if(strcmp(type, infocar[i].type) == 0){
			
			
			//�鵽�˷���Ҫ��ľ�����ǰ��һλ 
			for(int j = i + 1; j < totalcars; j++){
				infocar[j - 1] = infocar[j];
			}
			totalcars--;
			printf("ɾ���ɹ���\n");
			return ;
			 
		}
	}
	printf("�������󣬳��������ڣ�\n");
	
	
}


void fun06(){
	
	
	printf("--1.�����۸�--2.��λ��--3.����--\n");
	printf("��������(1-3),�����ָ���ֶ�����");
	
	int pos;
	scanf("%d", &pos);
	
	
	Infocar tmp;
	
	switch (pos){
		
		case 1: {
		
		for(int i = 0; i < totalcars; i++){
	       for(int j = 0; j < totalcars - i - 1; j++){
	            if(infocar[j].price > infocar[j + 1].price){
	                tmp = infocar[j+1];//�ṹ���������帳ֵ
	                infocar[j+1] = infocar[j];
	                infocar[j] = tmp;
	            }
	        }
	    }

		fun01();
	}; break;
	
	
	case 2: {
		
		for(int i = 0; i < totalcars; i++){
	       for(int j = 0; j < totalcars - i - 1; j++){
	            if(strcmp(infocar[j].seats, infocar[j+1].seats) < 0){
	                tmp = infocar[j+1];//�ṹ���������帳ֵ
	                infocar[j+1] = infocar[j];
	                infocar[j] = tmp;
	            }
	        }
	    }

		fun01();
	}; break;
	
	
	case 3: {
		
		for(int i = 0; i < totalcars; i++){
	       for(int j = 0; j < totalcars - i - 1; j++){
	            if(strcmp(infocar[j].displacement, infocar[j+1].displacement) < 0){
	                tmp = infocar[j+1];//�ṹ���������帳ֵ
	                infocar[j+1] = infocar[j];
	                infocar[j] = tmp;
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

	fp=fopen("C:\\Users\\larry\\Desktop\\111.txt","w");			/*��ֻ���ļ�ĩβд�ķ�ʽ���ļ�*/
	for(i = 0; i < totalcars; i++)
	{	
		fprintf(fp, "%s %s %s %s %s %s %s %.1lf", infocar[i].type, infocar[i].industry, infocar[i].rate, infocar[i].seats, infocar[i].displacement, infocar[i].speedbox, infocar[i].color, infocar[i].price);
		if(i != totalcars -1){
			fprintf(fp, "\n");
		}
		
	}
	fclose(fp);
	printf("����ɱ��棡\n");
	
	
}

void fun08(){
	int a;
	printf("�����˳�ϵͳ���Ƿ񱣴�(1/0)?\n");
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
	printf("**************������Ϣ����ϵͳ**************\n");
	printf("********************************************\n");
	printf("******1.��¼���*********2.¼�복��*********\n");
	printf("********************************************\n");
	printf("******3.��ѯ����*********4.�޸���Ϣ*********\n");
	printf("********************************************\n");
	printf("******5.ɾ������*********6.��������*********\n");
	printf("********************************************\n");
	printf("******7.�����¼*********0.�˳�ϵͳ*********\n");
	printf("********************************************\n");
	printf("********************************************\n");
	printf("********************************************\n");
	printf("********************************************\n");
	 
	int i = 0, j, flag;
	
	FILE *fp;
	if((fp=fopen("C:\\Users\\larry\\Desktop\\111.txt","r")) == NULL)			// ���ļ�������fpָ�� �ļ� 
	{
		printf("Can not open file\n");
		exit(1);
	}
	
	
	while(!feof(fp))        
	{ 
		fscanf(fp, "%s %s %s %s %s %s %s %lf", infocar[i].type, infocar[i].industry, infocar[i].rate, infocar[i].seats, infocar[i].displacement, infocar[i].speedbox, infocar[i].color, &infocar[i].price);
		i++;
	}          
	totalcars = i;

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
        	case 7: fun07(); break;
        	case 0: fun08(); break;
        	default:printf("error\n");
    }
		
		
	}
			
	return 0;
}
