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
	if((fp = fopen("C:\\Users\\larry\\Desktop\\222.txt","r")) == NULL)			// ���ļ�������fpָ�� �ļ� 
	{
		printf("Can not open file\n");
		exit(1);
	}
	
	while(fgets(line[i], 128, fp) != NULL)    /* ÿ����һ�δ� fgets���ͻ��ȡ�ļ�����һ��ר */
    {
    	
        i++;
    }
    
    totalrows = i; //��ǳ���һ���ж����� 
    
    fclose(fp);
    
    i = 0, k = 0;
    char* p = strtok(line[0], " ");//��һ�ε���strtok,�Կո�Ϊ�ָ��� 
    while(p != NULL){//������ֵ��ΪNULLʱ������ѭ��
    		
		str[k++] = p;
		
		i++;
		
        p = strtok(NULL, " ");//��������strtok���ֽ�ʣ�µ��ַ���
    }
    
    strcpy(str[k - 1], "GPA");
    
    total = i + 1; //��������
       
    
	
	if((fp=fopen("C:\\Users\\larry\\Desktop\\222.txt","w")) == NULL)			// ���ļ�������fpָ�� �ļ� 
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
	    char* p = strtok(line[i], " ");			//��һ�ε���strtok,�Կո�Ϊ�ָ��� 
	    while(p != NULL){						//������ֵ��ΪNULLʱ������ѭ��
	    	        
			str[k++] = p;
	        p = strtok(NULL, " ");//��������strtok���ֽ�ʣ�µ��ַ���
	        
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
