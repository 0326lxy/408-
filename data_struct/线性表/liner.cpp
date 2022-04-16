#include <stdio.h>
#include <stdlib.h>
#define  _CRT_SECURE_NO_WARNINGS
#define MaxSize 50

typedef int ElemType;//顺序表中元素类型
//静态分配
typedef struct {
	ElemType data[MaxSize]; //定义数组
	int length; //定义数组长度
}SqList;


//插入操作
bool listinsert(SqList& L, int i, ElemType e)
{
	//判断位置是否合法
	if (i<1 || i>L.length + 1)
		return false;
	if (L.length >= MaxSize)
		return false;
	//从最后一个位置开始元素挨个后移，直到插入位置元素后移完毕
	for (int j = L.length; j >= i; j--)
	{
		L.data[j] = L.data[j - 1];

	}
	//将值插入该位置
	L.data[i - 1] = e;
	//长度加一
	L.length++;
	return true;
}


//删除操作
bool listdelet(SqList& L, int i, ElemType &e) {

	//判断位置合法
	if (i<1 || i>L.length + 1)
		return false;
	if (L.length == 0) {
		return false;
	}
	
	//将该位置的值返回
	e = L.data[i - 1];

	//从被删除元素后一个元素开始挨个前移，直到最后一个元素为止
	for (int j = i; j < L.length; j++)
	{
		L.data[j - 1] = L.data[j];

	}

	//长度减一
	L.length--;
	return true;

}


//按值查找
int localdata(SqList L, ElemType e)
{
	int i;

	//遍历该顺序表
	for (i = 0; i < L.length; i++) {
		if (L.data[i] == e) {
			return i + 1;//返回位序
		}
	}
	return 0;
}



//打印顺序表
void printlist(SqList& L)
{
	for (int i = 0; i < L.length; i++)
	{
		printf("%3d", L.data[i]);//要求打印到一排
	}
	printf("\n");
}








int main()
{

	SqList L;//顺序表名称
	bool ret;//查看返回值
	ElemType del;//存储需要删除的元素
	L.data[0] = 1;
	L.data[1] = 2;
	L.data[2] = 3;
	L.length = 3;//总计三个元素
	

	//插入操作
	ret = listinsert(L, 2, 60);
	if (ret)
	{
		printf("success\n");
		printlist(L);//打印顺序表
	}
	else {
		printf("failed\n");

	}
	
	
	//删除第一个位置元素并输出
	ret = listdelet(L, 1, del);
	if (ret)
	{
		printf("success\n");
		printf("del=%d\n",del);
		printlist(L);

	}
	else {
		printf("failed\n");
	}
	
	
	//查找某个值且返回位序
	int elem;
	elem = localdata(L,60);
	if (elem) {
		printf("success\n");
		printf("%d\n", ret);
	}

	else {
		printf("failed\n");
	}
	return 0;

	 

}