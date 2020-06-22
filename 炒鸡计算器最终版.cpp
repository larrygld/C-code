/*��������������ʵ�ִ���*/ 
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
} SepStack1;      //һ������ջһ���ַ���ջ 


int prior(char a)//���ȼ��ж� 
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
	s->top = -1;      //��ɳ�ʼ��ջ���� 
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
}                   //������ջ�������� 



double Pop1(SepStack1* s)
{
	double n =s->elem1[s->top1--];
	return n;
}
void Pop(SepStack* s)
{	
	s->top--;
}                 //��ɵ������ݲ��� 


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
}               //��ջ��Ԫ��
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
}              //�ж��ַ���ջ�Ƿ�Ϊ�� 


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


void Exchange(SepStack* s, char str[], char str2[])//str2ר�����ڴ�ű��ʽ���ڽ���ж������Ƿ�ƥ�� 
{
		int i, k=0, m=0;
		char a;
		scanf("%c", &a);
		str2[m++]=a;
		while(a!='=')
		{
			if(a>='0'&&a<='9'||a=='.')//�������������⿼�� 
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
				else if(prior(a)>prior(GetTop(s)))  //���������������ȼ�����ջ����������ȼ��� 
					Push(s, a);                     //ֱ����ջ 
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
}              //����׺���ʽת���ɺ�׺���ʽ���Ҵ��뵽һ���ַ������� 


double Execute(double a, double b, char ch)//�Զ��� Execute���� �γ����� 
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

double calculation(char a[], SepStack1 &num)// �Զ��庯��ʵ�ֱ��ʽ��ֵ 
{
	int i, j=0;
	double m, n;
	char str1[100];
	for(i=0; a[i]; i++)
	{
		if(a[i]>='0'&&a[i]<='9'||a[i]=='.')
			str1[j++]=a[i];
		if(a[i]==' '&&(a[i-1]>='0'&&a[i-1]<='9'))            //�ո���Ϊ������������ķֽ�� 
		{
			m=atof(str1);
//			printf("%lf\n", m);//���ַ�������ת��Ϊ���������� 
			Push1(&num, m);	
			for(j=0;str1[j];j++) //������ݴ���������ַ������� 
				str1[j]=' ';
				j=0;		
		}
		if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/'||a[i]=='^')
		{
			n=Execute(Pop1(&num), Pop1(&num), a[i]); //ÿ����������������γɼ��� 
			Push1(&num, n);
		}
	}
	printf("                  ");
	printf("%g\n", Pop1(&num));
	
}


void Meau()   // �����û�ʹ�ý��� 
{
	printf("***********************************************\n");
	printf("*******       ��ӭʹ�ó���������        *******\n"); 
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
	printf("***ע������ļ�����ʽ���ԵȺŽ�β��**********\n");
	printf("***********************************************\n");
	printf("��������Ҫ����ı��ʽ��\n"); 

}


int main()
{
	Meau();
	char flag='Y';
	while(flag=='Y'||flag=='y')
	{
		printf("    ");	
		char a[100], b[100];//����a���ڴ��ת����ĺ�׺���ʽ ,b������������ƥ���ж� 
		SepStack s, g;		//ջs���ڸ������ʽ��ֵ��g���ڸ�����������ƥ�� 
		SepStack1 num;		//���ڴ���ַ�������ת����ĸ��������ݣ�����ֱ�Ӽ�����ʽ��ֵ 
		init(&s); 
		init(&g);
		Push(&s, '=');
		init1(&num);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
		Exchange(&s, a, b);
//		puts(a);
		
		
		if(PanIS(b, g))		// ����ƥ���жϣ�ƥ���������һ�����㣬����������������ʽ 
//		if(0)
		{
//			puts("The answer is��");
			calculation(a, num);
			printf("�Ƿ���Ҫ�������㣺Y or N ��\n");    //�����μ����Ҫ�� 
			printf("    ");	 		
			scanf("%c", &flag);
			scanf("%c", &flag);
		}
		else 
		{ 			
			printf("������ʽ��ʽ����������������ʽ��\n");
			flag='y';
		} 

	}
	printf("      ллʹ�� :)");
	return 0;

}
