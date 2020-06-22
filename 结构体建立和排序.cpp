#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node		//ѧ����Ϣ 
{ 
	char name[20];  //����
	double grade;    //����
	struct node *next;
}node;


//���ļ��ж�ȡ���ݴ�������
node *createlink()
{
	node *head, *pre, *p;		//pre���浱ǰ����ǰ����㣬headΪͷ���
	head = (node *)malloc(sizeof(node));	//����ͷ���
	pre = head;		//��¼preΪhead
	
	char name[20];
	double grade;
	
	FILE *r = fopen("C:\\Users\\larry\\Desktop\\111.txt","r");
	if(r==NULL)
	{
		printf("���ļ�ʧ��!");
		return NULL;
	}
	
	while(fscanf(r,"%s %lf", name, &grade) != EOF)
	{
		p = (node *)malloc(sizeof(node));	//�½����
		p->grade = grade;		//���������� 
		strcpy(p->name, name);
		pre->next = p;		//ǰ������ָ������Ϊ��ǰ�½����ĵ�ַ
		pre = p;	//��pre��Ϊp����Ϊ�¸�����ǰ�����
	}
	pre->next = NULL;
	return head;
}

//���ճɼ��������� 
void sort(node *head)
{
	node *m = head;
	if(head->next==NULL || head->next->next==NULL) //������û��Ԫ�ػ���Ԫ�ظ���Ϊ1 
	{
		return;
	}
	node *p = head->next;
	node *s = p->next;
	node *k = NULL;        //kʼ��ָ�����Ѿ��ź����ֹ����һλ 
	while(k != head->next->next) //�������ĵ��ڶ�λ�Ѿ��ź�����ô������Ѿ��ź��� 
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
		k = p;  //kʼ��ָ�����Ѿ��ź����ֹ����һλ 
		m = head;
		p = m->next;
		s = p->next;
	}
}



//���������Ļ
void show(node *head)
{
	node *p;
	p = head->next;		//ָ���һ����Ч���

	while(p)
	{
		//�������ڵ����ݵ���Ļ
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


