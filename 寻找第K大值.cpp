/*
 97.Ѱ�ҵ�K��ֵ (15��)
Cʱ�����ƣ�3000 ���� |  C�ڴ����ƣ�3000 Kb
��Ŀ���ݣ�
 ��һ�����������У�Ѱ�ҵ�k��ֵ����λ�á�����ÿ����ֵ����һ����Ҫ���㷨ʱ�临����ͨ�������Ϊ���ԡ�
��������
����һ�����鳤��n,һ��k, �Լ������ŵ�n������ֵ������֮���ÿո������
�������
��k��ֵ����λ�ñ�š��涨����ĵ�һ��λ�ñ��Ϊ0.
��������
7 3
1 4 3 9 8 7 2
�������
5

*/


#include <stdio.h>

int m, k, a[101], b[101];

/*
	m: ��¼����Ԫ�ظ���
	k: ��������
	a: ��������
	b: ԭʼ����
	tmp: ������ŵ���㣬�����м�λ�� 
*/

int fun02(int low, int high){
	int tmp = a[low];
	//һֱ�ظ���Ȼ��λ�ã�ֱ����β�����ص� 
	while(low < high){ 
		//���ұ���һ��С�� 
		while (low < high && tmp <= a[high]){
            high--;
        }
        a[low] = a[high];
        //�������һ��С��ģ�ͬʱ���ں����ó���С�ĵ�λ�� 
        while (low < high && tmp >= a[low]) {
            low++;
        }
        a[high] = a[low];
	}
	a[low] = tmp;
	return low;
	
}

void fun01(int low, int high){
	if(low < high){
		int mid = fun02(low, high);
		//����߽�������
		fun01(low, mid - 1);
		//���ұ߽�������
		fun01(mid + 1, high); 
	}
	
} 


int main(){
	
	int res;
	
	scanf("%d%d", &m, &k);
	for(int i = 0; i < m; i++){
		scanf("%d", &a[i]);
	}
	//��ԭʼ�����¼�� 
	for(int i = 0; i < m; i++){
		b[i] = a[i];
	}
	
	fun01(0, m - 1);
	
	for(int i = 0; i < m; i++){
//		printf("%d ", a[i]);
		if(b[i] == a[m - k]){
			printf("%d", i);
			return 0;
		}
	}
	
	return 0;
} 
