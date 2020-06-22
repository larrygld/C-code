#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

struct Infocar
{
	char type[30];		// 	车辆型号 
	char industry[30];		// 	厂商 
	char rate[30];		// 	车型级别 
	char seats[30];		// 	座位数 
	char displacement[20];  // 排量 
	char speedbox[20];   // 变速箱 
	char color[20];      // 颜色
	double price;  // 价格 
};

int totalcars;  //记录车辆总数 
struct Infocar infocar[1001];


void fun01(){
	
	printf("车辆型号  厂商   车型级别   座位数   排量   变速箱   车身颜色  车辆价格\n"); 
	for(int i = 0; i < totalcars; i++){
		
		if(infocar[i].price == 0){
			continue;
		} 
		
		printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%.1lf\n", infocar[i].type, infocar[i].industry, infocar[i].rate, infocar[i].seats, infocar[i].displacement, infocar[i].speedbox, infocar[i].color, infocar[i].price);
	}
	
	printf("车辆总数为： %d\n", totalcars);
	
}


void fun02(){
	 
	
	
	printf("请输入待录入车辆型号，厂商，车型级别，座位数，排量，变速箱，车身颜色，车辆价格，以空格间隔\n");
	
	
	scanf("%s %s %s %s %s %s %s %lf", infocar[totalcars].type, infocar[totalcars].industry, infocar[totalcars].rate, infocar[totalcars].seats, infocar[totalcars].displacement, infocar[totalcars].speedbox, infocar[totalcars].color, &infocar[totalcars].price);
	
	printf("录入成功！录入车辆信息为：\n");
	
	printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%.1lf\n", infocar[totalcars].type, infocar[totalcars].industry, infocar[totalcars].rate, infocar[totalcars].seats, infocar[totalcars].displacement, infocar[totalcars].speedbox, infocar[totalcars].color, infocar[totalcars].price);
	
	 
	totalcars++; 
	
	
	
}


void fun03(){
	
	printf("--1.厂商--2.车辆级别--3.车辆价格--\n");
	printf("请输入编号(1-3),按编号指定字段查询：");
	
	
	int pos;
	scanf("%d", &pos);
	
	
	
	char str[100];
	double max, min; //价格范围
	
	
	switch (pos){
        	case 1: {
        		//遍历数组，查询到符合要求的就输出 
        		printf("请输入字段值\n");
        		scanf("%s", str);
        		printf("查询到的结果为：\n");
        		for(int i = 0; i < totalcars; i++){
			       	if(strcmp(str, infocar[i].industry) == 0){
			       		printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%.1lf\n", infocar[i].type, infocar[i].industry, infocar[i].rate, infocar[i].seats, infocar[i].displacement, infocar[i].speedbox, infocar[i].color, infocar[i].price);		
					}
			    }

			}; break;
        	case 2: {
        		
        		//遍历数组，查询到符合要求的就输出 
        		printf("请输入字段值\n");
        		scanf("%s", str);
        		printf("查询到的结果为：\n");
        		for(int i = 0; i < totalcars; i++){
			       	if(strcmp(str, infocar[i].rate) == 0){
			       		printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%.1lf\n", infocar[i].type, infocar[i].industry, infocar[i].rate, infocar[i].seats, infocar[i].displacement, infocar[i].speedbox, infocar[i].color, infocar[i].price);		
					}
			    }
	
			}; break;
        	case 3: {
        		
        		printf("请输入最小价格以及最大价格，以空格间隔：\n");
        		
        		scanf("%lf %lf", &min, &max); 
        		
        		printf("查询到的结果为：\n");
        		
        		for(int i = 0; i < totalcars; i++){
        			//查找符合价格区间车辆 
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
	
	printf("请输入待修改的车辆型号以便查询车辆信息：\n");
	
	char str01[50];
	scanf("%s", str01); 
	
	
	for(i = 0; i < totalcars; i++){
		if(strcmp(str01, infocar[i].type) == 0){
			
			printf("查询到的车辆为：\n");
			
			//找到符合要求的车辆直接打印出来 
			printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%.1lf\n", infocar[i].type, infocar[i].industry, infocar[i].rate, infocar[i].seats, infocar[i].displacement, infocar[i].speedbox, infocar[i].color, infocar[i].price);		
			
			break; 
		}
	}
	
	
	printf("--1.车辆型号--2.厂商--3.车辆级别--4.座位数--5.排量--6.变速箱--7.颜色--8.车辆价格\n");
	printf("请输入编号(1-8),按编号修改指定字段：");
	
	
	int pos;
	scanf("%d", &pos);
	
	char str[100];
	double price;
	
	
	switch (pos){
		
		
    	case 1: {

    		printf("请输入字段值\n");
    		scanf("%s", str);
    		strcpy(infocar[i].type, str);
    		printf("修改成功！\n");	

		}; break;
		
		case 2: {

    		printf("请输入字段值\n");
    		scanf("%s", str);
    		strcpy(infocar[i].industry, str);
    		printf("修改成功！\n");	

		}; break;
		
		
		case 3: {

    		printf("请输入字段值\n");
    		scanf("%s", str);
    		strcpy(infocar[i].rate, str);
    		printf("修改成功！\n");	

		}; break;
		
		
		case 4: {

    		printf("请输入字段值\n");
    		scanf("%s", str);
    		strcpy(infocar[i].seats, str);
    		printf("修改成功！\n");	

		}; break;
		
		
		case 5: {

    		printf("请输入字段值\n");
    		scanf("%s", str);
    		strcpy(infocar[i].displacement, str);
    		printf("修改成功！\n");	

		}; break;
		
		case 6: {

    		printf("请输入字段值\n");
    		scanf("%s", str);
    		strcpy(infocar[i].speedbox, str);
    		printf("修改成功！\n");	

		}; break;
		
		
		case 7: {

    		printf("请输入字段值\n");
    		scanf("%s", str);
    		strcpy(infocar[i].color, str);
    		printf("修改成功！\n");	

		}; break;
		
		
		case 8: {

    		printf("请输入修改后的价格\n");
    		scanf("%lf", &price);
    		infocar[i].price = price;
    		printf("修改成功！\n");	

		}; break;
        	
        	
        default:printf("error\n");
        		
	} 
	
}

void fun05(){
	
	
	printf("请输入要删除的车辆型号：\n");
	char type[20];
	scanf("%s", type);
	
	for(int i = 0; i < totalcars; i++){
		if(strcmp(type, infocar[i].type) == 0){
			
			
			//查到了符合要求的就整体前移一位 
			for(int j = i + 1; j < totalcars; j++){
				infocar[j - 1] = infocar[j];
			}
			totalcars--;
			printf("删除成功！\n");
			return ;
			 
		}
	}
	printf("输入有误，车辆不存在！\n");
	
	
}


void fun06(){
	
	
	printf("--1.车辆价格--2.座位数--3.排量--\n");
	printf("请输入编号(1-3),按编号指定字段排序：");
	
	int pos;
	scanf("%d", &pos);
	
	
	Infocar tmp;
	
	switch (pos){
		
		case 1: {
		
		for(int i = 0; i < totalcars; i++){
	       for(int j = 0; j < totalcars - i - 1; j++){
	            if(infocar[j].price > infocar[j + 1].price){
	                tmp = infocar[j+1];//结构体允许整体赋值
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
	                tmp = infocar[j+1];//结构体允许整体赋值
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
	                tmp = infocar[j+1];//结构体允许整体赋值
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
	
	FILE *fp;		//文件指针
	int i;

	fp=fopen("C:\\Users\\larry\\Desktop\\111.txt","w");			/*以只在文件末尾写的方式打开文件*/
	for(i = 0; i < totalcars; i++)
	{	
		fprintf(fp, "%s %s %s %s %s %s %s %.1lf", infocar[i].type, infocar[i].industry, infocar[i].rate, infocar[i].seats, infocar[i].displacement, infocar[i].speedbox, infocar[i].color, infocar[i].price);
		if(i != totalcars -1){
			fprintf(fp, "\n");
		}
		
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
	
 
	
	printf("********************************************\n");	
	printf("********************************************\n");
	printf("**************车辆信息管理系统**************\n");
	printf("********************************************\n");
	printf("******1.记录浏览*********2.录入车辆*********\n");
	printf("********************************************\n");
	printf("******3.查询车辆*********4.修改信息*********\n");
	printf("********************************************\n");
	printf("******5.删除车辆*********6.车辆排序*********\n");
	printf("********************************************\n");
	printf("******7.保存记录*********0.退出系统*********\n");
	printf("********************************************\n");
	printf("********************************************\n");
	printf("********************************************\n");
	printf("********************************************\n");
	 
	int i = 0, j, flag;
	
	FILE *fp;
	if((fp=fopen("C:\\Users\\larry\\Desktop\\111.txt","r")) == NULL)			// 打开文件并且让fp指向 文件 
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

	fclose(fp);				//关闭文件； 
	
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
