#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node		//学生信息 
{ 
	char name[20];  //姓名
	double grade;    //分数
	struct node *next;
}node;


//从文件中读取数据存入链表
node *createlink()
{
	node *head, *pre, *p;		//pre保存当前结点的前驱结点，head为头结点
	head = (node *)malloc(sizeof(node));	//创建头结点
	pre = head;		//记录pre为head
	
	char name[20];
	double grade;
	
	FILE *r = fopen("C:\\Users\\larry\\Desktop\\111.txt","r");
	if(r==NULL)
	{
		printf("打开文件失败!");
		return NULL;
	}
	
	while(fscanf(r,"%s %lf", name, &grade) != EOF)
	{
		p = (node *)malloc(sizeof(node));	//新建结点
		p->grade = grade;		//保存数据域 
		strcpy(p->name, name);
		pre->next = p;		//前驱结点的指针域设为当前新建结点的地址
		pre = p;	//把pre设为p，作为下个结点的前驱结点
	}
	pre->next = NULL;
	return head;
}

//按照成绩降序排序 
void sort(node *head)
{
	node *m = head;
	if(head->next==NULL || head->next->next==NULL) //链表中没有元素或者元素个数为1 
	{
		return;
	}
	node *p = head->next;
	node *s = p->next;
	node *k = NULL;        //k始终指向于已经排好序截止的那一位 
	while(k != head->next->next) //如果链表的到第二位已经排好序，那么整体就已经排好序 
	{
		while(s != k)
		{
			if(p->grade < s->grade)
			{
				p->next = s->next;     
				s->next = p;
				m->next = s;
				m = s;
				s = p->next;
			}
			else
			{
				m = p;
				p = s;
				s = s->next;
			}
		}
		k = p;  //k始终指向于已经排好序截止的那一位 
		m = head;
		p = m->next;
		s = p->next;
	}
}



//输出链表到屏幕
void show(node *head)
{
	node *p;
	p = head->next;		//指向第一个有效结点

	while(p)
	{
		//输出链表节点数据到屏幕
		printf("%s %.1lf\n", p->name, p->grade);
		p = p->next;
	}
	return;
}

int main()
{
	node *head;
	head = createlink();
	sort(head);
	show(head);
	return 0;
}


