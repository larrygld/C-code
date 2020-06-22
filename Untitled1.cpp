#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
#include <string>
#include <string.h>
using namespace std;


void deleteCourse(){
	
	int i = 0, flag = 0, total, totalrows, k;
	char line[100][200], subject[20];
	char *str[100], *tmp; 
	
	printf("please input the course name you want ti delete:\n");
	scanf("%s", subject);
	
	
	FILE *fp;
	if((fp=fopen("C:\\Users\\larry\\Desktop\\111.txt","r")) == NULL)			// 打开文件并且让fp指向 文件 
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
    
            
        if(strcmp(p, subject) == 0){
        	
        	flag = i;		//flag用来标记待删除列数的位置 
        	
        	i++;
		
        	p = strtok(NULL, " ");
        	
        	continue;
        	
		}
		
		
		str[k++] = p;
		
		i++;
		
        p = strtok(NULL, " ");//继续调用strtok，分解剩下的字符串
    }
    
    total = i; //所有列数
    
    if(flag == 0){  //没有符合条件的 
    	printf("can not find the course name, please try again!\n");
    	return ;
	}else{
		
		if((fp=fopen("C:\\Users\\larry\\Desktop\\111.txt","w")) == NULL)			// 打开文件并且让fp指向 文件 
		{
			printf("Can not open file\n");
			exit(1);
		}
	    
	
	    for(int k = 0; k < total - 1; k++){
	    	
	    	if(k == total - 2) {
				fprintf(fp, "%s", str[k]);
				continue;
			}
			fprintf(fp, "%s ", str[k]);
			
			
		}
	    
	    
	    
	    for(int i = 1; i < totalrows; i++){	
	    
	    	int j = 0, k = 0;
		    char* p = strtok(line[i], " ");			//第一次调用strtok,以空格为分隔符 
		    while(p != NULL){						//当返回值不为NULL时，继续循环
		    	        
		        if(j == flag){
		        	
		        	j++;
		        	p = strtok(NULL, " ");
		        	continue;
		        	
				}
				
				str[k++] = p;
				j++;
		        p = strtok(NULL, " ");//继续调用strtok，分解剩下的字符串
		        
		    }
		    
		    for(int k = 0; k < total - 1; k++){
		    	
		    	if(k == total - 2) {
					fprintf(fp, "%s", str[k]);
					continue;
				}
		    	fprintf(fp, "%s ", str[k]);
			}
		}
	    
	    printf("delete success!");
	    
			
		fclose(fp);    /* 关闭连接到文件的流 */
	
	
	}	
	
}


int main(){
	
	
	
	deleteCourse();
	
	
	return 0;
} 
