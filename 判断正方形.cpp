/*
 1.2018����У����B-�����ε��ж� (10��)
��Ŀ���ݣ�
�����ĸ��������, �����ĸ�������֮���Ƿ�������������.
����������
��һ��һ��������N,��ʾ������������,N<=500
ÿ���������ռһ��,����8������x1,y1,x2,y2,x3,y3,x4,y4. -1000000<= x,y <= 1000000
���������
���һ��������, ��ʾN������������ж������еĵ�������������.
����������
2
0 1 3 1 0 0 3 0
1 1 -1 1 -1 -1 1 -1
�������
1
*/

#include <stdio.h>
#include <math.h>

int main(){
	
	/*
		n: ����������
		x1 ~ y4: ������
		flag1 ~ flag3: �ж����ӳ��ֵ
		a12 ~ a13: �߳� 
	*/
	
	int n;
	
	int x1, y1, x2, y2, x3, y3, x4, y4, flag1, flag2, flag3, a12, a13, a14;
	
	scanf("%d", &n);
	
	while(n--){
		
		scanf("%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
		
		a12 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
		
		a13 = (x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3);
		
		a14 = (x1 - x4) * (x1 - x4) + (y1 - y4) * (y1 - y4);
		
		if(a12 == a13){
			//�ж������������εĶԽ��ߴ�ֱ����� 
			flag1 = (x1 - x4) * (x2 - x3) + (y1 - y4) * (y2 - y3);
			flag2 = (x1 - x4) * (x1 - x4) + (y1 - y4) * (y1 - y4);
			flag3 = (x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3);
			if(flag1 == 0 && flag2 == flag3){
				printf("perfect\n");
			}else{
//				printf("%d %d %d %d %d %d", flag1, flag2, flag3, a12, a13, a14);
				printf("not perfect\n");
			}
		}else if(a12 == a14){
			flag1 = (x1 - x3) * (x2 - x4) + (y1 - y3) * (y2 - y4);
			flag2 = (x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3);
			flag3 = (x2 - x4) * (x2 - x4) + (y2 - y4) * (y2 - y4);
			if(flag1 == 0 && flag2 == flag3){
				printf("perfect\n");
			}else{
				printf("not perfect\n");
			}
		}else if(a13 == a14){
			flag1 = (x1 - x2) * (x4 - x3) + (y1 - y2) * (y4 - y3);
			flag2 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
			flag3 = (x4 - x3) * (x4 - x3) + (y4 - y3) * (y4 - y3);
			if(flag1 == 0 && flag2 == flag3){
				printf("perfect\n");
			}else{
				printf("not perfect\n");
			}
		}else{
			printf("not perfect\n");
		}
	}
	
	
} 
