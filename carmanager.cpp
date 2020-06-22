#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

struct Infocar
{
	char carnumber[10];		//车牌号 
	char cardtype[20];		//门卡种类 
	char intime[20];		//到达时间 
	char outtime[20];		//离开时间 
	char staffnumber[20];   //员工卡号 
	char lasttime[20];      //到期时间	
};


int totalrecords;
struct Infocar infocar[1001];


//计算时间差 
int GetDifMin(string strTime1, string strTime2)
{
	if (strTime1.length() != 12 || strTime2.length() != 12)
	{
		return -1;
	}
	if (strTime1.compare(strTime2) < 0)
	{
		string linshi = strTime1;
		strTime1 = strTime2;
		strTime2 = linshi;
	}
 
	int iDefDays = 0;
	if (strcmp(strTime1.substr(0, 8).c_str(), strTime2.substr(0, 8).c_str()) > 0)
	{
		int iDaysCount1 = 0;
		int iDaysCount2 = 0;
		int iYear1, iYear2, iMonth1, iMonth2, iDay1, iDay2;
		iYear1 = iYear2 = iMonth1 = iMonth2 = iDay1 = iDay2 = 0;
		iYear1 = atoi(strTime1.substr(0, 4).c_str());
		iYear2 = atoi(strTime2.substr(0, 4).c_str());
		iMonth1 = atoi(strTime1.substr(4, 2).c_str());
		iMonth2 = atoi(strTime2.substr(4, 2).c_str());
		iDay1 = atoi(strTime1.substr(6, 2).c_str());
		iDay2 = atoi(strTime2.substr(6, 2).c_str());
		int DAY[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if ((iYear1 % 4 == 0 || iYear1 % 400 == 0) && (iYear1 % 100 != 0))
		{
			DAY[1] = 29;
		}
		for (int i = 0; i < iMonth1 - 1; i++)
		{
			iDaysCount1 += DAY[i];
		}
		iDaysCount1 += iDay1;
 
		DAY[1] = 28;
		if ((iYear2 % 4 == 0 || iYear2 % 400 == 0) && (iYear2 % 100 != 0))
		{
			DAY[1] = 29;
		}
		for (int i = 0; i < iMonth2 - 1; i++)
		{
			iDaysCount2 += DAY[i];
		}
		iDaysCount2 += iDay2;
 
		if (iYear1 > iYear2)
		{
			for (int i = iYear2; i < iYear1; i++)
			{
				iDaysCount1 += 365;
				if ((i % 4 == 0 || i % 400 == 0) && (i % 100 != 0))
				{
					iDaysCount1++;
				}
			}
		}
		iDefDays = iDaysCount1 - iDaysCount2;
	}
	int ret = iDefDays * 1440;
	string hour1 = strTime1.substr(8, 2);
	string hour2 = strTime2.substr(8, 2);
	ret += (atoi(hour1.c_str()) - atoi(hour2.c_str())) * 60;
	string min1 = strTime1.substr(10, 2);
	string min2 = strTime2.substr(10, 2);
	ret += atoi(min1.c_str()) - atoi(min2.c_str());
	return ret;
}


void fun01(){
	
	printf("车牌号 门卡种类 到达时间        离开时间       员工卡号 到期时间(次数)\n"); 
	for(int i = 0; i < totalrecords; i++){
		printf("%s\t%s\t%s\t%s\t%s\t%s\n", infocar[i].carnumber, infocar[i].cardtype, infocar[i].intime, infocar[i].outtime, infocar[i].staffnumber, infocar[i].lasttime);
	}
	
}

void fun02(){
	
	char carnum[10];
	char carintime[20];
	
	
	printf("请输入车牌号码以及到场时间，以空格隔开：");
	
	scanf("%s%s", carnum, carintime);	
//	printf("%s %s", carnum, carin);

	for(int i = 0; i < totalrecords; i++){
		
		
		if(strcmp(infocar[i].carnumber, carnum) == 0 && strcmp(infocar[i].intime, "null") != 0 && strcmp(infocar[i].outtime, "null") == 0){
				
			printf("车牌已存在，请重新输入！\n");
			fun02(); 
		}
		//年卡 
		if(strcmp(infocar[i].carnumber, carnum) == 0 && strcmp(infocar[i].intime, "null") == 0){
			if(strcmp(infocar[i].intime, "null") == 0 && strcmp(infocar[i].outtime, "null") == 0){
				strcpy(infocar[i].intime, carintime);
				return ;
			}
			
			
		}
		
	}
	
	//临时卡 
	strcpy(infocar[totalrecords].carnumber, carnum);
	strcpy(infocar[totalrecords].cardtype, "临时卡");
	strcpy(infocar[totalrecords].intime, carintime);
	strcpy(infocar[totalrecords].outtime, "null");
	strcpy(infocar[totalrecords].lasttime, "null");
	strcpy(infocar[totalrecords].staffnumber, "null");
	totalrecords++;
	
	
	
}


void fun03(){
	
	
	
	char carnum[10];
	char carouttime[20];
	
	
	printf("请输入车牌号码以及出场时间，以空格隔开：");
	scanf("%s%s", carnum, carouttime);
	
	for(int i = 0; i < totalrecords; i++){
		if(strcmp(infocar[i].carnumber, carnum) == 0 && strcmp(infocar[i].outtime, "null") == 0){
			
//				strcpy(infocar[totalrecords].outtime, carouttime);
			
			//临时车收费 
			if(strcmp(infocar[i].cardtype, "临时卡") == 0){
				int time, hour, money;
				
				string num1 = infocar[i].intime;
				string num2 = carouttime;
				
				
				string year01 = "20";
				string year02 = "20";
				
				
				
				string num01 = year01.append(num1.substr(0, 10));
				string num02 = year02.append(num2.substr(0, 10));
				
//				cout<< num01 << " === " << num02 <<endl;
				
				time = GetDifMin(num01, num02);
				
				hour = time / 60;
				
				if(time != hour * 60){
					hour += 1;
				}
				
				if(hour == 1){
					money = 5;
					
				}else{
					money = 5 + (hour - 1) * 3;
				}
				
				strcpy(infocar[i].outtime, carouttime);
				
				printf("临时车，请交费！%d元\n", money);
				
			
			} else if(strcmp(infocar[i].cardtype, "年卡") == 0){
				
				int flag = 0;
				
				for(int j = 0; j < totalrecords; j++){
					if(strcmp(infocar[j].carnumber, carnum) == 0 && strcmp(infocar[j].outtime, "null") == 0){
						if(strcmp(infocar[i].staffnumber, infocar[j].staffnumber) == 0){
							
							flag++;
						}
					
					}
				}
				
				if(flag > 1 || atoi(infocar[i].lasttime) < atoi(carouttime)){
					
					int time, hour, money;
				
					string num1 = infocar[i].intime;
					string num2 = carouttime;
					
					//切割字符串秒数舍去 
					string year01 = "20";
					string year02 = "20";
					string num01 = year01.append(num1.substr(0, 10));
					string num02 = year02.append(num2.substr(0, 10));
					
	//				cout<< num01 << " === " << num02 <<endl;
					
					time = GetDifMin(num01, num02);
					
					hour = time / 60;
					
					if(time != hour * 60){
						hour += 1;
					}
					
					if(hour == 1){
						money = 5;
						
					}else{
						money = 5 + (hour - 1) * 3;
					}
					
					strcpy(infocar[i].outtime, carouttime);
					printf("停放车辆超过数量限制，请交费%d元！", money);
					
					strcpy(infocar[totalrecords].carnumber, infocar[i].carnumber);
					strcpy(infocar[totalrecords].cardtype, "年卡");
					strcpy(infocar[totalrecords].intime, "null");
					strcpy(infocar[totalrecords].outtime, "null");
					strcpy(infocar[totalrecords].lasttime, infocar[i].lasttime);
					strcpy(infocar[totalrecords].staffnumber, infocar[i].staffnumber);
					totalrecords++;
					return;
					
						
					
				}else if(flag == 1){	
					
					strcpy(infocar[i].outtime, carouttime);				
					printf("年卡用户，欢迎光临，到期时间为：%s\n", infocar[i].lasttime);
					
					strcpy(infocar[totalrecords].carnumber, infocar[i].carnumber);
					strcpy(infocar[totalrecords].cardtype, "年卡");
					strcpy(infocar[totalrecords].intime, "null");
					strcpy(infocar[totalrecords].outtime, "null");
					strcpy(infocar[totalrecords].lasttime, infocar[i].lasttime);
					strcpy(infocar[totalrecords].staffnumber, infocar[i].staffnumber);
					totalrecords++;
					return ;
				} 
				
			}else if(strcmp(infocar[i].cardtype, "次卡") == 0){
				
				int flag = 0;
				
				for(int j = 0; j < totalrecords; j++){
					if(strcmp(infocar[j].carnumber, carnum) == 0 && strcmp(infocar[j].outtime, "null") == 0){
						if(strcmp(infocar[i].staffnumber, infocar[j].staffnumber) == 0){
							
							flag++;
						}
					
					}
				}
				
				if(flag > 1 || atoi(infocar[i].lasttime) <= 0){
					
					int time, hour, money;
				
					string num1 = infocar[i].intime;
					string num2 = carouttime;
					
					
					string year01 = "20";
					string year02 = "20";
					
					string num01 = year01.append(num1.substr(0, 10));
					string num02 = year02.append(num2.substr(0, 10));
					
	//				cout<< num01 << " === " << num02 <<endl;
					
					time = GetDifMin(num01, num02);
					
					hour = time / 60;
					
					if(time != hour * 60){
						hour += 1;
					}
					
					if(hour == 1){
						money = 5;
						
					}else{
						money = 5 + (hour - 1) * 3;
					}
					
					strcpy(infocar[i].outtime, carouttime);
					printf("停放车辆超过数量限制，请交费%d元！\n", money);
					
					strcpy(infocar[totalrecords].carnumber, infocar[i].carnumber);
					strcpy(infocar[totalrecords].cardtype, "年卡");
					strcpy(infocar[totalrecords].intime, "null");
					strcpy(infocar[totalrecords].outtime, "null");
					strcpy(infocar[totalrecords].lasttime, infocar[i].lasttime);
					strcpy(infocar[totalrecords].staffnumber, infocar[i].staffnumber);
					totalrecords++;
					return ;
					
					
					
				}else{	
					
					int times = atoi(infocar[i].lasttime);
					
					times -= 1;
								
					printf("次卡用户，欢迎光临，剩余次数为：%d\n", times);
					
					snprintf(infocar[i].lasttime, sizeof(infocar[i].lasttime), "%d", times);
					
					strcpy(infocar[i].outtime, carouttime);
					
					strcpy(infocar[totalrecords].carnumber, infocar[i].carnumber);
					strcpy(infocar[totalrecords].cardtype, "年卡");
					strcpy(infocar[totalrecords].intime, "null");
					strcpy(infocar[totalrecords].outtime, "null");
					strcpy(infocar[totalrecords].lasttime, infocar[i].lasttime);
					strcpy(infocar[totalrecords].staffnumber, infocar[i].staffnumber);
					totalrecords++;
					return ;
					
				}
				
				
				
			}
					
		} 
	}
	
}


void fun04(){
	
	FILE *fp;		//文件指针
	int i;

	fp=fopen("C:\\Users\\larry\\Desktop\\carmsg.txt","w");			/*以只在文件末尾写的方式打开文件*/
	for(i = 0; i < totalrecords; i++)
	{	
		fprintf(fp, "%s %s %s %s %s %s", infocar[i].carnumber, infocar[i].cardtype, infocar[i].intime, infocar[i].outtime, infocar[i].staffnumber, infocar[i].lasttime);
		fprintf(fp, "\n");
	}
	fclose(fp);
	printf("已完成保存！\n");
	
}


void fun05(){
	
	printf("--1.车牌号--2.年卡类型--3.进场时间--4.出场时间--5.员工卡号--6.到期日期(天数)--\n");
	printf("请输入编号(1-6),按编号指定字段排序：");
	
	int pos;
	scanf("%d", &pos);
	
	
	int k;
	Infocar tmp;
	
	
	switch (pos){
        	case 1: {
        		for(int i = 0; i < totalrecords; i++){
			       for(int j = 0; j < totalrecords - i - 1; j++){
			            if(strcmp(infocar[j].carnumber, infocar[j+1].carnumber) < 0){
			                tmp = infocar[j+1];//结构体允许整体赋值
			                infocar[j+1] = infocar[j];
			                infocar[j] = tmp;
			            }
			        }
			    }
	
				fun01();
			}; break;
        	case 2: {
				for(int i = 0; i < totalrecords; i++){
			       for(int j = 0; j < totalrecords - i - 1; j++){
			            if(strcmp(infocar[j].cardtype, infocar[j+1].cardtype) < 0){
			                tmp = infocar[j+1];//结构体允许整体赋值
			                infocar[j+1] = infocar[j];
			                infocar[j] = tmp;
			            }
			        }
			    }
	
				fun01();
	
			}; break;
        	case 3: {
        		
        		for(int i = 0; i < totalrecords; i++){
			       for(int j = 0; j < totalrecords - i - 1; j++){
			            if(strcmp(infocar[j].intime, infocar[j+1].intime) < 0){
			                tmp = infocar[j+1];//结构体允许整体赋值
			                infocar[j+1] = infocar[j];
			                infocar[j] = tmp;
			            }
			        }
			    }
	
				fun01();
			
			}; break;
        	case 4: {
        		
        		for(int i = 0; i < totalrecords; i++){
			       for(int j = 0; j < totalrecords - i - 1; j++){
			            if(strcmp(infocar[j].outtime, infocar[j+1].outtime) < 0){
			                tmp = infocar[j+1];//结构体允许整体赋值
			                infocar[j+1] = infocar[j];
			                infocar[j] = tmp;
			            }
			        }
			    }
	
				fun01();
			
			}; break;
        	case 5: {
        		
        		for(int i = 0; i < totalrecords; i++){
			       for(int j = 0; j < totalrecords - i - 1; j++){
			            if(strcmp(infocar[j].staffnumber, infocar[j+1].staffnumber) < 0){
			                tmp = infocar[j+1];//结构体允许整体赋值
			                infocar[j+1] = infocar[j];
			                infocar[j] = tmp;
			            }
			        }
			    }
	
				fun01();
			
			}; break;
        	case 6: {
				
				for(int i = 0; i < totalrecords; i++){
			       for(int j = 0; j < totalrecords - i - 1; j++){
			            if(strcmp(infocar[j].lasttime, infocar[j+1].lasttime) < 0){
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
	
//	tmp = infocar[3];
//	infocar[3] = infocar[1];
//	infocar[1] = tmp;
	
} 


void fun06(){
		
	char carnum[10];
	
	
	char carnumber01[10];		//车牌号 
	char cardtype01[20];		//门卡种类 
	char intime01[20];		//到达时间 
	char outtime01[20];		//离开时间 
	char staffnumber01[20];   //员工卡号 
	char lasttime01[20];      //到期时间
	 
	
	
	printf("请输入要修改记录的车牌号："); 
	scanf("%s", carnum);
	
	for(int i = 0; i < totalrecords; i++){
		
		if(strcmp(infocar[i].carnumber, carnum) == 0){
			printf("请输入要修改记录的车牌号：");
			printf("查询到的结果为：\n");
			printf("车牌号 门卡种类 到达时间        离开时间       员工卡号 到期时间(次数)\n"); 
			printf("%s\t%s\t%s\t%s\t%s\t%s\n", infocar[i].carnumber, infocar[i].cardtype, infocar[i].intime, infocar[i].outtime, infocar[i].staffnumber, infocar[i].lasttime);
			
			printf("请输入要修改字段的值，空格间隔，不修改字段以null填充：\n");
			
			scanf("%s%s%s%s%s%s", carnumber01, cardtype01, intime01, outtime01, staffnumber01, lasttime01);
			
			if(strcmp(carnumber01, "null") != 0){
				strcpy(infocar[i].carnumber, carnumber01);
			}
			
			if(strcmp(cardtype01, "null") != 0){
				strcpy(infocar[i].cardtype, cardtype01);
			}
			
			if(strcmp(carnumber01, "null") != 0){
				strcpy(infocar[i].carnumber, carnumber01);
			}
			
			if(strcmp(intime01, "null") != 0){
				strcpy(infocar[i].intime, intime01);
			}
			
			if(strcmp(outtime01, "null") != 0){
				strcpy(infocar[i].outtime, outtime01);
			}
			
			if(strcmp(staffnumber01, "null") != 0){
				strcpy(infocar[i].staffnumber, staffnumber01);
			}
			
			if(strcmp(lasttime01, "null") != 0){
				strcpy(infocar[i].lasttime, lasttime01);
			}
			
			printf("修改成功，结果为：\n");
			printf("车牌号 门卡种类 到达时间        离开时间       员工卡号 到期时间(次数)\n"); 
			printf("%s\t%s\t%s\t%s\t%s\t%s\n", infocar[i].carnumber, infocar[i].cardtype, infocar[i].intime, infocar[i].outtime, infocar[i].staffnumber, infocar[i].lasttime);
			
			return ;
		
		}
		
	}
	
	printf("查询为空！请重新输入！"); 	
}


void fun07(){
	
	char carnum01[20];
	char cartype01[20];
	char staffnumber01[20]; 
	char lasttime01[20];
	
	printf("请输入车牌号,年卡类型,员工号以及到期日期(或次数)，以空格隔开：\n");
	
	scanf("%s%s%s%s", carnum01, cartype01, staffnumber01, lasttime01);
	
	int flag = 0;
	
	for(int j = 0; j < totalrecords; j++){
		
		if(strcmp(infocar[j].staffnumber, staffnumber01) == 0 && strcmp(infocar[j].outtime, "null") == 0){
			
			flag++;
		}
	}
	
	if(flag >= 2){
		printf("名下所属车辆超过两辆，添加失败！\n");
	}else{
		
		strcpy(infocar[totalrecords].carnumber, carnum01);
		strcpy(infocar[totalrecords].cardtype, cartype01);
		strcpy(infocar[totalrecords].intime, "null");
		strcpy(infocar[totalrecords].outtime, "null");
		strcpy(infocar[totalrecords].lasttime, lasttime01);
		strcpy(infocar[totalrecords].staffnumber, staffnumber01);
		totalrecords++;
		
		printf("添加成功!\n"); 
		return;
	}	
}

void fun08(){
	int a;
	printf("即将退出系统，是否保存(1/0)?\n");
	scanf("%d", &a);
	
	if(a == 1){
		fun04();
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
	printf("**************校园车辆管理系统**************\n");
	printf("********************************************\n");
	printf("******1.记录浏览*********2.车辆进场*********\n");
	printf("********************************************\n");
	printf("******3.车辆出场*********4.数据保存*********\n");
	printf("********************************************\n");
	printf("******5.数据排序*********6.修改记录*********\n");
	printf("********************************************\n");
	printf("******7.添加记录*********0.退出系统*********\n");
	printf("********************************************\n");
	printf("********************************************\n");
	printf("********************************************\n");
	printf("********************************************\n");
	 
	int i = 0, j, flag;
	
	FILE *fp;
	if((fp=fopen("C:\\Users\\larry\\Desktop\\carmsg.txt","rb")) == NULL)			// 打开文件并且让fp指向 文件 
	{
		printf("Can not open file\n");
		exit(1);
	}
	
	
	while(!feof(fp))        
	{ 
		fscanf(fp, "%s %s %s %s %s %s", infocar[i].carnumber, infocar[i].cardtype, infocar[i].intime, infocar[i].outtime, infocar[i].staffnumber, infocar[i].lasttime);
		i++;
	}          
	totalrecords = i;

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
