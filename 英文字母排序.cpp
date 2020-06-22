/*
 116.英文字母排序 (20分)
C时间限制：3000 毫秒 |  C内存限制：3000 Kb
题目内容：
编写一个程序，当输入英文字符串时，计算机将这个句子中的英文字母按字典字母顺序重新排列，排列后的单词的
长度要与原始句子中的长度相同，并且要求只对Ａ到Ｚ的字母重新排列，其它字符保持原来的状态。
输入描述
一个字符串，包括大写英文字母，以及其他字符
输出描述
字符串的重新排列，只是大写字母按字典顺序，其他字母保持原位
输入样例
ＴＨＥ ＰＲＩＣＥ ＯＦＢＲＥＡＤ ＩＳ ￥１ ２５ ＰＥＲ ＰＯＵＮＤ
输出样例
ＡＢＣ ＤＤＥＥＥ ＥＦＨＩＩＮＯ ＯＰ ￥１ ２５ ＰＰＲ ＲＲＳＴＵ
*/

#include <stdio.h>
/*
	str: 存放原始字符串
	str1: 存放抽取出来的字母 
	len: 待处理字符串长度 
	len1: 抽取出来的字母的长度
	c, tmp, pos: 临时变量 
*/
char c, str[101], str1[101], tmp;
int len = 0, len1 = 0, pos = 0; 


//抽取出字母 
void fun1(){
	for(int i = 0; str[i]; i++){
		if(str[i] >= 'A' && str[i] <= 'Z'){
			str1[len1] = str[i];
			len1++; 
		}
	}
} 

//将抽取出来的字符串排序 
void fun2(){
	//冒泡排序 
	for(int i = 0; str[i]; i++){
		for(int j = 0; j < len1 - 1 - i; j++){
			if(str1[j] > str1[j + 1]){
				tmp = str1[j];
				str1[j] = str1[j + 1];
				str1[j + 1] = tmp;
			}
		}
	} 
} 

//将排序好的字符串填入 
void fun3(){
	for(int i = 0; str[i]; i++){
		if(str[i] >= 'A' && str[i] <= 'Z'){
			str[i] = str1[pos];
			pos++; 
		}
	}
}


int main(){
	scanf("%c", &c);
	while(c != '\n'){
		str[len] = c;
		len++;
		scanf("%c", &c);
	}
	
	
	fun1();
//	printf("%s\n", str);
//	printf("%d\n", len);
//	printf("%s\n", str1);
	fun2();
//	printf("%s\n", str1);
	fun3();
	printf("%s\n", str);
	return 0;
}
