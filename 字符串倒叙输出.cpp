#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int fun(char *w)
{
        char t, *s1, *s2;
        //��ȡ�ַ������� 
        int n = strlen(w);
        //ָ��ͷ 
        s1 = w;
        //ָ��β 
        s2 = w + n - 1;
        //��������һλ�����һλ���ڶ�λ�͵����ڶ�λ������ֱ���е�λ�� 
        while(s1 < s2)
        {
                t = *s1;
                *s1 = *s2;
                *s2 = t;
                //�������ͷָ�����βָ��ǰ�� 
                s1++;
                s2--;
        }
}
int main()
{
	char str[100];
	//�����ַ��� 
    scanf("%s", str); 
    //��ӡԭʼ�ַ��� 
    printf("%s \n", str);
    //���ú��������ַ��� 
    fun(str);
    //�������ַ��� 
    printf("%s \n", str);
}
