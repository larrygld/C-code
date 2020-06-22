#include<stdio.h>
#include <malloc.h>
# define MAX 100      //����ʽ�������
typedef struct
{ double coef;      //ϵ��
int exp;           //ָ��
} PolyArray;       //��Ŷ���ʽ����������
typedef struct pnode
{double coef;        //ϵ��
int exp;             //ָ��
struct pnode*next;
} PolyNode;            //��������ʽ������������
void DispPoly(PolyNode * L)           //�������ʽ������
{ 	
	bool first = true;       //firstΪtrue��ʾ�ǵ�һ��
	PolyNode *p = L->next;
	while (p != NULL)
	{
		if (first)
			first = false;
		else if (p->coef > 0)
			printf("+");
		if (p->exp == 0)
			printf("%g", p->coef);
		else if (p->exp == 1)
			printf("%gx", p->coef);
		else
			printf("%gx^%d", p->coef, p->exp);
		p = p->next;
	}
	printf("\n");     
}
void DestroyPoly(PolyNode*&L)    //���ٶ���ʽ������
{
	PolyNode * pre = L, *p= pre->next;
	while (p!= NULL)
	{free(pre);
	pre = p;
	p = pre->next;
	}
       free(pre);
}
void CreatePolyR(PolyNode *&L, double a[], int b[], int n)  //β�巨����
{
	PolyNode *s, *r;int i;  

		L = (PolyNode*)malloc(sizeof(PolyNode));//����ͷ���
		L->next = NULL;
		r = L;                                // r ʼ��ָ��β��㣬��ʼʱָ��ͷ���
		for (i = 0; i < n; i++) 
		  { s = (PolyNode *)malloc(sizeof(PolyNode));//�����½��
			s ->coef= a[i];
			s->exp = b[i];
			r ->next = s;           //�����s���뵽��� r֮��
			r = s;
		}	
	r->next = NULL;              //β���next����ΪNULL
}

void Sort(PolyNode *&L)     // ������ʽ������ָ���ݼ�����
{
	PolyNode *p = L->next, *pre, *q;
	if (p != NULL)   //L��һ�������ϵ����ݽ��
	{ q = p->next;    //q����p���ĺ�̽��
	  p->next = NULL;      //����ֻ��һ�����ݽ��������
	p = q;
	while (p!= NULL)       //ɨ��ԭ�������µ����ݽ��
	{
		q = p->next;              //q����p���ĺ�̽��
		pre = L;
		while(pre->next!= NULL && pre->next->exp > p->exp)
			pre = pre->next;    //����������Ҳ��˽��P��ǰ�����pre
		p->next = pre->next;      //�����p���˵����pre֮��
		pre->next = p;
		p = q;                     //ɨ��ԭ���������µĽ��
	}
}
}

void Mult1(PolyNode *ha, PolyNode*hb, PolyNode *&hc)
{
	PolyNode * pa = ha->next, *pb, *s, *tc;
	hc = (PolyNode *)malloc(sizeof(PolyNode));
	tc = hc;
	while (pa != NULL)
	{pb = hb->next;
	while (pb != NULL)
	{
		s = (PolyNode *)malloc(sizeof(PolyNode));
		s->coef = pa->coef * pb->coef;
		s->exp = pa->exp + pb->exp;
		tc->next = s;
		tc = s;
		pb = pb->next;
	}
	pa = pa -> next;
}
 	tc->next = NULL;
}
void Comb(PolyNode *&L)//�ϲ�ָ����ͬ����
{
	PolyNode *pre = L->next, *p;
	if(pre == NULL) return;
	p = pre->next;
	while (p != NULL)
	{ 
		while (p -> exp == pre -> exp)
		{ 
			pre->coef += p->coef;
			pre->next = p->next;
			free(p);
			p = pre->next;
		}
		pre = p;
		p = p->next;
	
	}
	
}
void DelZero(PolyNode *&L)   //ɾ��ϵ��Ϊ0����
{
	PolyNode *pre = L, *p = pre->next;
	while (p != NULL)
	{  if (p->coef == 0.0)
		{
			pre->next=p->next;
			free(p);
		}
		pre = p;
		p = p->next;
	}
}

void Mult(PolyNode * ha, PolyNode *hb, PolyNode * &hc) //ha ��hb��˵õ����յ�heMult1(ha, hb, hc);
{
	Mult1(ha, hb, hc);
	printf("��˽��:      "); DispPoly(hc);
	Sort(hc);
	printf("��ָ�������:  "); DispPoly(hc);
	Comb(hc);
	printf("�ϲ��ظ�ָ����:"); DispPoly(hc);
	DelZero(hc);
	printf("ɾ������Ϊ0��: "); DispPoly(hc);
}
int main()
{
	PolyNode *Poly1, *Poly2, *Poly3;
	double a[MAX];
	int b[MAX], n;
	// ----������1������ʽ����������
	a[0] = 2; b[0] = 3; a[1] = 1; b[1] = 0; a[2] = 3; b[2] = 1;
	n = 3;
	printf("��1������ʽ:\n");
	CreatePolyR(Poly1, a, b, n);
	printf(" ����ǰ����ʽ1:"); DispPoly(Poly1);
	Sort(Poly1);
	printf(" ��������ʽ1:"); DispPoly(Poly1);
	// ----������2������ʽ���������� 
	printf("��2������ʽ:\n");
	a[0] = 2; b[0] = 3; a[1] = -3; b[1] = 2;
	a[2] = 5; b[2] = 4; a[3] = -3; b[3] = 0;
	n = 4;
	CreatePolyR(Poly2,a,b,n);
	printf(" ����ǰ����ʽ2:"); DispPoly(Poly2);
	Sort(Poly2);
	printf(" ��������ʽ2:"); DispPoly(Poly2);
	Mult(Poly1, Poly2, Poly3);
	printf("��˺����ʽ3��"); DispPoly(Poly3);
	DestroyPoly(Poly1);
	DestroyPoly(Poly2);
	DestroyPoly(Poly3);
	return 1;
}

