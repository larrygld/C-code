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
	if((fp=fopen("C:\\Users\\larry\\Desktop\\111.txt","r")) == NULL)			// ���ļ�������fpָ�� �ļ� 
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
    
            
        if(strcmp(p, subject) == 0){
        	
        	flag = i;		//flag������Ǵ�ɾ��������λ�� 
        	
        	i++;
		
        	p = strtok(NULL, " ");
        	
        	continue;
        	
		}
		
		
		str[k++] = p;
		
		i++;
		
        p = strtok(NULL, " ");//��������strtok���ֽ�ʣ�µ��ַ���
    }
    
    total = i; //��������
    
    if(flag == 0){  //û�з��������� 
    	printf("can not find the course name, please try again!\n");
    	return ;
	}else{
		
		if((fp=fopen("C:\\Users\\larry\\Desktop\\111.txt","w")) == NULL)			// ���ļ�������fpָ�� �ļ� 
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
		    char* p = strtok(line[i], " ");			//��һ�ε���strtok,�Կո�Ϊ�ָ��� 
		    while(p != NULL){						//������ֵ��ΪNULLʱ������ѭ��
		    	        
		        if(j == flag){
		        	
		        	j++;
		        	p = strtok(NULL, " ");
		        	continue;
		        	
				}
				
				str[k++] = p;
				j++;
		        p = strtok(NULL, " ");//��������strtok���ֽ�ʣ�µ��ַ���
		        
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
	    
			
		fclose(fp);    /* �ر����ӵ��ļ����� */
	
	
	}	
	
}


int main(){
	
	
	
	deleteCourse();
	
	
	return 0;
} 
