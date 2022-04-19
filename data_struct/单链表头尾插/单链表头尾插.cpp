#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#define MaxSize 50//这句可以不要

typedef int ElemType;//顺序表中元素类型

typedef struct Lnode
{
	ElemType data; //定义数组
	struct Lnode *next; //定义节点指针
}Lnode, *Linklist;

//单链表头插，带头结点
Linklist  creatList1(Linklist &L) {
	Lnode* s; int x; //定义新节点指针，标准输入数据变量
	L = (Linklist)malloc(sizeof(Lnode));//申请头节点
	L->next = NULL;
	scanf("%d", &x);//读取第一个输入数据

	while (x != 9999) {
		s = (Lnode*)malloc(sizeof(Lnode));//申请新空间存放节点s;
		s->data = x;//把读取到的值给新空间的data
		s->next = L->next;//链接到下一个节点前面
		L->next = s;//链接到前一个节点后面，顺序不能颠倒
		scanf("%d", &x);//读取标准输入
	}
	return L;
}

//单链表尾插，带头结点
Linklist createlist2(Linklist &L) {
	
	L = (Linklist)malloc(sizeof(Lnode));
	Lnode* s, * r = L; int x;//定义新节点指针，表尾指针
	
	scanf("%d", &x);

	while (x != 9999) {
		s = (Lnode*)malloc(sizeof(Lnode));
		s->data = x;
		r->next = s;//接到表尾
		r = s;//重置表尾指针
		scanf("%d", &x);//读取下一个数据


	}
	r->next = NULL;//尾指针如果不赋值NULL会出现堆空间无法访问
	return L;
}

//打印链表
void  printlist(Linklist L) {
	L = L->next;
	while (L != NULL) {
		printf("%3d", L->data);//打印当前节点数据
		L = L->next;
	}
	printf("\n");

 }



int main()
{

	Linklist L;//链表头，是结构体指针类型
	Linklist search;//存储得到的某一个节点
	creatList1(L);//头插法
	printlist(L);
	createlist2(L);//尾插法

	printlist(L);

}

