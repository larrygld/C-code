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
	
	printf("ID号  姓名 基本工资 职务工资 津贴 医疗保险 公积金\n"); 
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
	
	printf("请输入员工ID号，姓名，基本工资，职务工资，津贴，医疗保险，公积金，以空格隔开：\n");
	
	scanf("%s %s %d %d %d %d %d", id, name, &money01, &money02, &money03, &money04, &money05);
	strcpy(workers[totalrecords].id, id);
	strcpy(workers[totalrecords].name, name);
	workers[totalrecords].money01 = money01;
	workers[totalrecords].money02 = money02;
	workers[totalrecords].money03 = money03;
	workers[totalrecords].money04 = money04;
	workers[totalrecords].money05 = money05;
	totalrecords++;
	printf("添加成功！\n");
	
}

void fun03(){
	
	printf("请输入要删员工id：\n");
	char id[10];
	scanf("%s", id);
	
	for(int i = 0; i < totalrecords; i++){
		if(strcmp(id, workers[i].id) == 0){
			
			
			//查到了符合要求的就整体前移一位 
			for(int j = i + 1; j < totalrecords; j++){
				workers[j - 1] = workers[j];
			}
			totalrecords--;
			printf("删除成功！\n");
			return ;
			 
		}
	}
	printf("输入有误，员工不存在！\n");
}

void fun04(){
	
	printf("请输入待修改员工id：\n");
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
			
			
			//查到了符合要求的就修改
			
			printf("请输入修改后的员工ID号，姓名，基本工资，职务工资，津贴，医疗保险，公积金，以空格隔开：\n");
			
			scanf("%s %s %d %d %d %d %d", id, name, &money01, &money02, &money03, &money04, &money05);
			 
			strcpy(workers[i].id, id);
			strcpy(workers[i].name, name);
			workers[i].money01 = money01;
			workers[i].money02 = money02;
			workers[i].money03 = money03;
			workers[i].money04 = money04;
			workers[i].money05 = money05;
			printf("修改成功！\n");
			printf("修改后的结果为：\n");
			
			printf("ID号  姓名 基本工资 职务工资 津贴 医疗保险 公积金\n"); 
			printf("%s\t%s\t%d\t%d\t%d\t%d\t%d\n", workers[i].id, workers[i].name, workers[i].money01, workers[i].money02, workers[i].money03, workers[i].money04, workers[i].money05);
			
		
			return ;
			 
		}
	}
	
	printf("查找失败！请重新输入！\n"); 	
} 


void fun05(){
	
	printf("请输入待查询员工id：\n");
	
	char id01[10];
	scanf("%s", id01);
	
	
	for(int i = 0; i < totalrecords; i++){
		if(strcmp(id01, workers[i].id) == 0){
			
			
			//查到了符合要求的就输出 
			
			printf("查询成功！\n");
			printf("查询后的结果为：\n");
			
			printf("ID号  姓名 基本工资 职务工资 津贴 医疗保险 公积金\n"); 
			printf("%s\t%s\t%d\t%d\t%d\t%d\t%d\n", workers[i].id, workers[i].name, workers[i].money01, workers[i].money02, workers[i].money03, workers[i].money04, workers[i].money05);
			
			return ;
			 
		}
	}
	
	printf("查找失败！请重新输入！\n"); 
	
	
} 


void fun06(){
	
	printf("统计结果为：\n");
	printf("ID号  姓名 基本工资 职务工资 津贴 医疗保险 公积金 总工资\n"); 
	
	int num01 = 0, num02 = 0, num03 = 0; //用来统计各工资段人数
	
	int sum01 = 0, sum02 = 0, sum03 = 0, sum04 = 0, sum05 = 0; //用来记录各项总工资
	
	
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
	
	printf("各项平均工资为：%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\n", (double)sum01 / totalrecords, (double)sum02 / totalrecords, (double)sum03 / totalrecords, (double)sum04 / totalrecords, (double)sum05 / totalrecords);
	
	
	printf("3000元、3000~2000元、2000~1000元工资断人数占比分别为：%.2lf\t%.2lf\t%.2lf\n",  (double)num01 / totalrecords, (double)num02 / totalrecords, (double)num03 / totalrecords);
}


void fun07(){
	
	FILE *fp;		//文件指针
	int i;

	fp=fopen("C:\\Users\\larry\\Desktop\\worker.txt","w");			/*以只在文件末尾写的方式打开文件*/
	fprintf(fp, "ID号  姓名 基本工资 职务工资 津贴 医疗保险 公积金\n");
	for(i = 0; i < totalrecords; i++)
	{	
		fprintf(fp, "%s %s %d %d %d %d %d", workers[i].id, workers[i].name, workers[i].money01, workers[i].money02, workers[i].money03, workers[i].money04, workers[i].money05);
		fprintf(fp, "\n");
	}
	fclose(fp);
	printf("已完成保存！\n");
	
	
}

void fun08(){
	int a;
	printf("即将退出系统，是否保存(1/0)?\n");
	scanf("%d", &a);
	
	if(a == 1){
		fun07();
		printf("欢迎下次使用！\n");
		exit(0);
	}else{
		printf("数据未保存，已成功退出，欢迎下次使用！\n");
		exit(0);
	}	
}




int main(){
	
	cout<<"***********************************************************************"<<endl;
 	cout<<"**------------------------职工工资管理系统---------------------------**"<<endl;
 	cout<<"***********************************************************************"<<endl;
 	cout<<"**                        1. 显示全部职工信息                        **"<<endl;
 	cout<<"**                        2. 添加职工信息                            **"<<endl;
	cout<<"**                        3. 删除职工信息                            **"<<endl;
    cout<<"**                        4. 修改职工信息                            **"<<endl;
    cout<<"**                        5. 查询职工信息                            **"<<endl;
 	cout<<"**                        6. 统计职工信息                            **"<<endl;
 	cout<<"**                        7. 保存文件                                **"<<endl;
 	cout<<"**                        0. 退出系统                                **"<<endl;
 	cout<<"***********************************************************************"<<endl;
 	
 	int flag;
 	
 	while(true){
		
		printf("请输入操作编号,回车键结束：");
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
