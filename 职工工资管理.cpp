#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
#include <string>
#include <string.h>
using namespace std;




struct InfoWorker 
{
	char id[10];	
	char name[20];	
	int money01;
	int money02;	
	int money03;  
	int money04;  
	int money05; 
	int totalmoney;  	
};

int totalrecords = 0;
struct InfoWorker workers[1001];


void fun01(){
	
	printf("ID��  ���� �������� ְ���� ���� ҽ�Ʊ��� ������\n"); 
	for(int i = 0; i < totalrecords; i++){
		printf("%s\t%s\t%d\t%d\t%d\t%d\t%d\n", workers[i].id, workers[i].name, workers[i].money01, workers[i].money02, workers[i].money03, workers[i].money04, workers[i].money05);
	}
	
} 


void fun02(){
	
	char id[10];	
	char name[20];	
	int money01;
	int money02;	
	int money03;  
	int money04;  
	int money05;
	
	printf("������Ա��ID�ţ��������������ʣ�ְ���ʣ�������ҽ�Ʊ��գ��������Կո������\n");
	
	scanf("%s %s %d %d %d %d %d", id, name, &money01, &money02, &money03, &money04, &money05);
	strcpy(workers[totalrecords].id, id);
	strcpy(workers[totalrecords].name, name);
	workers[totalrecords].money01 = money01;
	workers[totalrecords].money02 = money02;
	workers[totalrecords].money03 = money03;
	workers[totalrecords].money04 = money04;
	workers[totalrecords].money05 = money05;
	totalrecords++;
	printf("��ӳɹ���\n");
	
}

void fun03(){
	
	printf("������ҪɾԱ��id��\n");
	char id[10];
	scanf("%s", id);
	
	for(int i = 0; i < totalrecords; i++){
		if(strcmp(id, workers[i].id) == 0){
			
			
			//�鵽�˷���Ҫ��ľ�����ǰ��һλ 
			for(int j = i + 1; j < totalrecords; j++){
				workers[j - 1] = workers[j];
			}
			totalrecords--;
			printf("ɾ���ɹ���\n");
			return ;
			 
		}
	}
	printf("��������Ա�������ڣ�\n");
}

void fun04(){
	
	printf("��������޸�Ա��id��\n");
	char id01[10];
	scanf("%s", id01);
	
	char id[10];	
	char name[20];	
	int money01;
	int money02;	
	int money03;  
	int money04;  
	int money05;
	
	
	
	for(int i = 0; i < totalrecords; i++){
		if(strcmp(id01, workers[i].id) == 0){
			
			
			//�鵽�˷���Ҫ��ľ��޸�
			
			printf("�������޸ĺ��Ա��ID�ţ��������������ʣ�ְ���ʣ�������ҽ�Ʊ��գ��������Կո������\n");
			
			scanf("%s %s %d %d %d %d %d", id, name, &money01, &money02, &money03, &money04, &money05);
			 
			strcpy(workers[i].id, id);
			strcpy(workers[i].name, name);
			workers[i].money01 = money01;
			workers[i].money02 = money02;
			workers[i].money03 = money03;
			workers[i].money04 = money04;
			workers[i].money05 = money05;
			printf("�޸ĳɹ���\n");
			printf("�޸ĺ�Ľ��Ϊ��\n");
			
			printf("ID��  ���� �������� ְ���� ���� ҽ�Ʊ��� ������\n"); 
			printf("%s\t%s\t%d\t%d\t%d\t%d\t%d\n", workers[i].id, workers[i].name, workers[i].money01, workers[i].money02, workers[i].money03, workers[i].money04, workers[i].money05);
			
		
			return ;
			 
		}
	}
	
	printf("����ʧ�ܣ����������룡\n"); 	
} 


void fun05(){
	
	printf("���������ѯԱ��id��\n");
	
	char id01[10];
	scanf("%s", id01);
	
	
	for(int i = 0; i < totalrecords; i++){
		if(strcmp(id01, workers[i].id) == 0){
			
			
			//�鵽�˷���Ҫ��ľ���� 
			
			printf("��ѯ�ɹ���\n");
			printf("��ѯ��Ľ��Ϊ��\n");
			
			printf("ID��  ���� �������� ְ���� ���� ҽ�Ʊ��� ������\n"); 
			printf("%s\t%s\t%d\t%d\t%d\t%d\t%d\n", workers[i].id, workers[i].name, workers[i].money01, workers[i].money02, workers[i].money03, workers[i].money04, workers[i].money05);
			
			return ;
			 
		}
	}
	
	printf("����ʧ�ܣ����������룡\n"); 
	
	
} 


void fun06(){
	
	printf("ͳ�ƽ��Ϊ��\n");
	printf("ID��  ���� �������� ְ���� ���� ҽ�Ʊ��� ������ �ܹ���\n"); 
	
	int num01 = 0, num02 = 0, num03 = 0; //����ͳ�Ƹ����ʶ�����
	
	int sum01 = 0, sum02 = 0, sum03 = 0, sum04 = 0, sum05 = 0; //������¼�����ܹ���
	
	
	for(int i = 0; i < totalrecords; i++){
		
		
		workers[i].totalmoney = workers[i].money01 + workers[i].money02 + workers[i].money03 - workers[i].money04 - workers[i].money05;
		 
		sum01 += workers[i].money01;
		sum02 += workers[i].money02;
		sum03 += workers[i].money03;
		sum04 += workers[i].money04;
		sum05 += workers[i].money05;
		 
		if(workers[i].money01 + workers[i].money02 + workers[i].money03 > 3000){
			num01++;
		}
		
		if(workers[i].money01 + workers[i].money02 + workers[i].money03 > 2000 && workers[i].money01 + workers[i].money02 + workers[i].money03 <= 3000){
			
			num02++;
		}
		
		if(workers[i].money01 + workers[i].money02 + workers[i].money03 >= 1000 && workers[i].money01 + workers[i].money02 + workers[i].money03 <= 2000){
			
			num03++;
		}
		
		printf("%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n", workers[i].id, workers[i].name, workers[i].money01, workers[i].money02, workers[i].money03, workers[i].money04, workers[i].money05, workers[i].totalmoney);
			
		
	}
	
	printf("����ƽ������Ϊ��%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\n", (double)sum01 / totalrecords, (double)sum02 / totalrecords, (double)sum03 / totalrecords, (double)sum04 / totalrecords, (double)sum05 / totalrecords);
	
	
	printf("3000Ԫ��3000~2000Ԫ��2000~1000Ԫ���ʶ�����ռ�ȷֱ�Ϊ��%.2lf\t%.2lf\t%.2lf\n",  (double)num01 / totalrecords, (double)num02 / totalrecords, (double)num03 / totalrecords);
}


void fun07(){
	
	FILE *fp;		//�ļ�ָ��
	int i;

	fp=fopen("C:\\Users\\larry\\Desktop\\worker.txt","w");			/*��ֻ���ļ�ĩβд�ķ�ʽ���ļ�*/
	fprintf(fp, "ID��  ���� �������� ְ���� ���� ҽ�Ʊ��� ������\n");
	for(i = 0; i < totalrecords; i++)
	{	
		fprintf(fp, "%s %s %d %d %d %d %d", workers[i].id, workers[i].name, workers[i].money01, workers[i].money02, workers[i].money03, workers[i].money04, workers[i].money05);
		fprintf(fp, "\n");
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
	
	cout<<"***********************************************************************"<<endl;
 	cout<<"**------------------------ְ�����ʹ���ϵͳ---------------------------**"<<endl;
 	cout<<"***********************************************************************"<<endl;
 	cout<<"**                        1. ��ʾȫ��ְ����Ϣ                        **"<<endl;
 	cout<<"**                        2. ���ְ����Ϣ                            **"<<endl;
	cout<<"**                        3. ɾ��ְ����Ϣ                            **"<<endl;
    cout<<"**                        4. �޸�ְ����Ϣ                            **"<<endl;
    cout<<"**                        5. ��ѯְ����Ϣ                            **"<<endl;
 	cout<<"**                        6. ͳ��ְ����Ϣ                            **"<<endl;
 	cout<<"**                        7. �����ļ�                                **"<<endl;
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
