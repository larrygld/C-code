#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int fun(char *w)
{
        char t, *s1, *s2;
        //获取字符串长度 
        int n = strlen(w);
        //指向头 
        s1 = w;
        //指向尾 
        s2 = w + n - 1;
        //持续将第一位和最后一位，第二位和倒数第二位交换，直到中点位置 
        while(s1 < s2)
        {
                t = *s1;
                *s1 = *s2;
                *s2 = t;
                //交换完毕头指针后移尾指针前移 
                s1++;
                s2--;
        }
}
int main()
{
	char str[100];
	//键入字符串 
    scanf("%s", str); 
    //打印原始字符串 
    printf("%s \n", str);
    //调用函数倒叙字符串 
    fun(str);
    //输出结果字符串 
    printf("%s \n", str);
}
