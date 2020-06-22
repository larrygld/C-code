#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
#include <string>
#include <string.h>
using namespace std;


void calculateGpa(){
	
	int i = 0, flag = 0, total, totalrows, k;
	char line[100][200];
	char *str[100], *tmp; 
	
	
	
	FILE *fp;
	if((fp = fopen("C:\\Users\\larry\\Desktop\\222.txt","r")) == NULL)			// 打开文件并且让fp指向 文件 
	{
		printf("Can not open file\n");
		exit(1);
	}
	
	while(fgets(line[i], 128, fp) != NULL)    /* 每调用一次答 fgets，就会读取文件的下一行专 */
    {
    	
        i++;
    }
    
    totalrows = i; //标记程序一共有多少行 
    
    fclose(fp);
    
    i = 0, k = 0;
    char* p = strtok(line[0], " ");//第一次调用strtok,以空格为分隔符 
    while(p != NULL){//当返回值不为NULL时，继续循环
    		
		str[k++] = p;
		
		i++;
		
        p = strtok(NULL, " ");//继续调用strtok，分解剩下的字符串
    }
    
    strcpy(str[k - 1], "GPA");
    
    total = i + 1; //所有列数
       
    
	
	if((fp=fopen("C:\\Users\\larry\\Desktop\\222.txt","w")) == NULL)			// 打开文件并且让fp指向 文件 
	{
		printf("Can not open file\n");
		exit(1);
	}

    for(int k = 0; k < total - 1; k++){
    	
		fprintf(fp, "%s ", str[k]);
		
	}
	fprintf(fp, "\n");
 
    for(int i = 1; i < totalrows; i++){	
    
    	int j = 0, k = 0;
	    char* p = strtok(line[i], " ");			//第一次调用strtok,以空格为分隔符 
	    while(p != NULL){						//当返回值不为NULL时，继续循环
	    	        
			str[k++] = p;
	        p = strtok(NULL, " ");//继续调用strtok，分解剩下的字符串
	        
	    }
	    
	    int sum;
	    
	    double times = 0;
	    
	    sum = total - 4;
	    
	    
	    for(int j = 2; j <= total - 3; j++){
	    	
	    	if(strcmp(str[j], "A") == 0){
	    		times += 4;
			}
			
			if(strcmp(str[j], "A-") == 0){
	    		times += 3.67;
			}
			
			if(strcmp(str[j], "B+") == 0){
	    		times += 3.33;
			}
			
			if(strcmp(str[j], "B") == 0){
	    		times += 3;
			}
			
			if(strcmp(str[j], "B-") == 0){
	    		times += 2.67;
			}
			
			if(strcmp(str[j], "C+") == 0){
	    		times += 2.33;
			}
			
			if(strcmp(str[j], "C") == 0){
	    		times += 2;
			}
			
			if(strcmp(str[j], "C-") == 0){
	    		times += 1.67;
			}
			
			if(strcmp(str[j], "D") == 0){
	    		times += 1;
			}
			
			if(strcmp(str[j], "F") == 0){
	    		times += 0;
			}
	    	
	    	
	    	
	    	
		}
		
		_snprintf(str[total - 2], sizeof(str[total - 2]), "%.2lf", times / sum);
//		gcvt(times / sum, 3, str[total - 2]);

		
		
		for(int k = 0; k < total - 1; k++){
			
    	
			fprintf(fp, "%s ", str[k]);
		
		}
		
		fprintf(fp, "\n");
		
	    
	}
	    
	    
	printf("Calculation complete ! \n");

	
}


int main(){
	
	
	
	calculateGpa();
	
	
	return 0;
} 
