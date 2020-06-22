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
函数功能说明：初始化系统数据 
形参说明：  无 
返回值：    无
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
函数功能说明：打印全部系统数据 
形参说明：  无 
返回值：    无
**************************************/

void fun01(){
	
	printf("雇员编号  姓名 性别 出勤天数\n"); 
	for(int i = 0; i < totalrecords; i++){
		printf("%s\t%s\t%s\t%d\n", employee[i].id, employee[i].name, employee[i].sex, employee[i].days);
	}
	
}


/**************************************
函数功能说明：按id字段进行升降序排序 
形参说明：  无 
返回值：    无
**************************************/

void fun02(){
	
	printf("--1.降序--2.升序--\n");
	printf("请输入编号(1-2),按指定方式排序：");
	
	int pos;
	scanf("%d", &pos);
	
	Employee tmp;
	
	
	switch (pos){
		
    	case 1: {
    		
    		for(int i = 0; i < totalrecords; i++){
    			
		       for(int j = 0; j < totalrecords - i - 1; j++){
		       	
		            if(strcmp(employee[j].id, employee[j + 1].id) < 0){
		                tmp = employee[j+1];//结构体允许整体赋值
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
		                tmp = employee[j+1];//结构体允许整体赋值
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
函数功能说明：按出勤天数字段进行升降序排序 
形参说明：  无 
返回值：    无
**************************************/

void fun03(){
	
	printf("--1.降序--2.升序--\n");
	printf("请输入编号(1-2),按指定方式排序：");
	
	int pos;
	scanf("%d", &pos);
	
	Employee tmp;
	
	
	switch (pos){
		
    	case 1: {
    		
    		for(int i = 0; i < totalrecords; i++){
    			
		       for(int j = 0; j < totalrecords - i - 1; j++){
		       	
		            if(employee[j].days < employee[j + 1].days){
		                tmp = employee[j+1];//结构体允许整体赋值
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
		                tmp = employee[j+1];//结构体允许整体赋值
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
函数功能说明：统计雇员男女比例 
形参说明：  无 
返回值：    无
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

	printf("男生所占比例为： %.2lf\n", (double)m / 7); 
	printf("女生所占比例为： %.2lf\n", (double)f / 7); 
	
	
	
}

/**************************************
函数功能说明：退出系统 
形参说明：  无 
返回值：    无
**************************************/

void fun05(){
	
	printf("欢迎下次使用！"); 
	exit(0);
	
}


int main(){
	
	fun(); 
	
	cout<<"***********************************************************************"<<endl;
 	cout<<"**--------------------------职工管理系统-----------------------------**"<<endl;
 	cout<<"***********************************************************************"<<endl;
 	cout<<"**                        1. 显示全部信息                            **"<<endl;
	cout<<"**                        2. 按id进行排序                            **"<<endl;
    cout<<"**                        3. 按出勤天数进行排序                      **"<<endl;
    cout<<"**                        4. 统计男女比例                            **"<<endl;
 	cout<<"**                        5. 退出系统                                **"<<endl;
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
        	default:printf("error\n");
    	}
    	
	}
	return 0;
} 
