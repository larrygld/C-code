/*炒鸡计算器简明实现代码*/ 
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MaxSize 50

typedef struct
{
	char elem[MaxSize];
	int top;	
} SepStack;

typedef struct
{
	double elem1[MaxSize];
	int top1;	
} SepStack1;      //一个数型栈一个字符型栈 


int prior(char a)//优先级判断 
{
	if(a == '^')
		return 4; 
    if(a == '+' || a == '-')
        return 2;
    if(a == '*' || a == '/')
        return 3;
    if(a == '=')
    	return 1;
    if(a == '(')
    	return 0;
}


void init1(SepStack1* s)
{
	s->top1 = -1;
}
void init(SepStack* s)
{
	s->top = -1;      //完成初始化栈工作 
}


void Push1(SepStack1* s, double x)
{
	s->top1++;
	s->elem1[s->top1] = x;
}
void Push(SepStack* s, char x)
{
	s->top++;
	s->elem[s->top] = x;
}                   //数据入栈操作函数 



double Pop1(SepStack1* s)
{
	double n =s->elem1[s->top1--];
	return n;
}
void Pop(SepStack* s)
{	
	s->top--;
}                 //完成弹出数据操作 


double GetTop1(SepStack1* s) 
{
	double x;
	x = s->elem1[s->top1];
	return x;
}
char GetTop(SepStack* s) 
{
	char x;
	x = s->elem[s->top];
	return x;
}               //读栈顶元素
void GetTop2(SepStack* s, char* x)
{
	*x = s->elem[s->top];
}


int IsEmpty(SepStack* s)
{
	if(s->top == -1)
		return 1;
	else
		return 0;
}              //判断字符型栈是否为空 


int Match(char a, char b)
{
	if(a == '(' && b == ')')
		return 1;
		else
		return 0; 
}



int PanIS(char str[], SepStack s)
{
	int i;
	char  x;
	for(i=0; str[i] != '='; i++)
	{
		if(str[i] == '(')
			Push(&s, str[i]);
		else if(str[i] == ')')
		{
			if(IsEmpty(&s))
				break;
			else
			{
				GetTop2(&s, &x);
				if(Match(x, str[i]))
					Pop(&s);
				else
					continue;
			}
		}
		else continue;
	}
	if(IsEmpty(&s))
		return 1;
	else
		return 0;
}


void Exchange(SepStack* s, char str[], char str2[])//str2专门用于存放表达式用于今后判断括号是否匹配 
{
		int i, k=0, m=0;
		char a;
		scanf("%c", &a);
		str2[m++]=a;
		while(a!='=')
		{
			if(a>='0'&&a<='9'||a=='.')//浮点型数据特殊考虑 
			{
				str[k++]=a;
				scanf("%c", &a);
				str2[m++]=a;
				if((a<'0'||a>'9')&&a!='.')
					str[k++]=' ';
			}
			else if(a=='(')
				{
					Push(s, a);
					scanf("%c", &a);
					str2[m++]=a;
				} 
			else
				{
				
				if(a==')')
					{
						while(GetTop(s)!='(')
						{ 
							str[k++]=GetTop(s);
							str[k++]=' ';
							Pop(s);
						}
						Pop(s);
					}
				else if(GetTop(s)=='='||GetTop(s)=='(')
					Push(s, a);
				else if(prior(a)>prior(GetTop(s)))  //如果读入运算符优先级大于栈顶运算符优先级， 
					Push(s, a);                     //直接入栈 
				else 
					{
					while(prior(a)<=prior(GetTop(s))) 
						{
    						str[k++]=GetTop(s);
    						str[k++]=' ';
							Pop(s);
						}
							Push(s, a);			
					}
				scanf("%c", &a);
				str2[m++]=a;
				}
		}
		while(GetTop(s)!='=')
			{ 
				str[k++]=GetTop(s);
				str[k++]=' ';
				Pop(s);
			}
		str[k]=0;
		str2[m]=0; 
}              //将中缀表达式转换成后缀表达式并且存入到一个字符数组中 


double Execute(double a, double b, char ch)//自定义 Execute函数 形成运算 
{
	switch(ch)
	{
		case '+':return a+b;break;
		case '-':return a-b;break;
		case '*':return a*b;break;
		case '/':return a/b;break;
		case '^':return pow(a,b); break;
	}
}

double calculation(char a[], SepStack1 &num)// 自定义函数实现表达式求值 
{
	int i, j=0;
	double m, n;
	char str1[100];
	for(i=0; a[i]; i++)
	{
		if(a[i]>='0'&&a[i]<='9'||a[i]=='.')
			str1[j++]=a[i];
		if(a[i]==' '&&(a[i-1]>='0'&&a[i-1]<='9'))            //空格作为数据与运算符的分界点 
		{
			m=atof(str1);
//			printf("%lf\n", m);//将字符串数据转化为浮点型数据 
			Push1(&num, m);	
			for(j=0;str1[j];j++) //完成数据存入后重置字符串数组 
				str1[j]=' ';
				j=0;		
		}
		if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/'||a[i]=='^')
		{
			n=Execute(Pop1(&num), Pop1(&num), a[i]); //每当遇到运算符，将形成计算 
			Push1(&num, n);
		}
	}
	printf("                  ");
	printf("%g\n", Pop1(&num));
	
}


void Meau()   // 生成用户使用界面 
{
	printf("***********************************************\n");
	printf("*******       欢迎使用炒鸡计算器        *******\n"); 
	printf("***********************************************\n");
	printf("*******   C       /       *     Delete  *******\n");
	printf("*******_________________________________*******\n");
	printf("*******   7       8       9     Minus   *******\n");
	printf("*******_________________________________*******\n");
	printf("*******   4       5       6     Add     *******\n");
	printf("*******_________________________________*******\n");
	printf("*******   1       2       3     Equal   *******\n");
	printf("*******_________________________________*******\n");
	printf("*******   ^       0       .     Space   *******\n");
	printf("*******_________________________________*******\n");		
	printf("***********************************************\n");
	printf("***注：输入的计算表达式请以等号结尾！**********\n");
	printf("***********************************************\n");
	printf("请输入您要计算的表达式：\n"); 

}


int main()
{
	Meau();
	char flag='Y';
	while(flag=='Y'||flag=='y')
	{
		printf("    ");	
		char a[100], b[100];//数组a用于存放转换后的后缀表达式 ,b用于左右括号匹配判断 
		SepStack s, g;		//栈s用于辅助表达式求值，g用于辅助左右括号匹配 
		SepStack1 num;		//用于存放字符型数据转换后的浮点型数据，辅助直接计算表达式的值 
		init(&s); 
		init(&g);
		Push(&s, '=');
		init1(&num);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
		Exchange(&s, a, b);
//		puts(a);
		
		
		if(PanIS(b, g))		// 括号匹配判断，匹配则进行下一步运算，否则请重新输入表达式 
//		if(0)
		{
//			puts("The answer is：");
			calculation(a, num);
			printf("是否需要继续计算：Y or N ？\n");    //满足多次计算的要求 
			printf("    ");	 		
			scanf("%c", &flag);
			scanf("%c", &flag);
		}
		else 
		{ 			
			printf("输入表达式格式有误，请重新输入表达式！\n");
			flag='y';
		} 

	}
	printf("      谢谢使用 :)");
	return 0;

}
