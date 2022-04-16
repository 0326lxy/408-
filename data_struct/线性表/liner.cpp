#include <stdio.h>
#include <stdlib.h>
#define  _CRT_SECURE_NO_WARNINGS
#define MaxSize 50

typedef int ElemType;//˳�����Ԫ������
//��̬����
typedef struct {
	ElemType data[MaxSize]; //��������
	int length; //�������鳤��
}SqList;


//�������
bool listinsert(SqList& L, int i, ElemType e)
{
	//�ж�λ���Ƿ�Ϸ�
	if (i<1 || i>L.length + 1)
		return false;
	if (L.length >= MaxSize)
		return false;
	//�����һ��λ�ÿ�ʼԪ�ذ������ƣ�ֱ������λ��Ԫ�غ������
	for (int j = L.length; j >= i; j--)
	{
		L.data[j] = L.data[j - 1];

	}
	//��ֵ�����λ��
	L.data[i - 1] = e;
	//���ȼ�һ
	L.length++;
	return true;
}


//ɾ������
bool listdelet(SqList& L, int i, ElemType &e) {

	//�ж�λ�úϷ�
	if (i<1 || i>L.length + 1)
		return false;
	if (L.length == 0) {
		return false;
	}
	
	//����λ�õ�ֵ����
	e = L.data[i - 1];

	//�ӱ�ɾ��Ԫ�غ�һ��Ԫ�ؿ�ʼ����ǰ�ƣ�ֱ�����һ��Ԫ��Ϊֹ
	for (int j = i; j < L.length; j++)
	{
		L.data[j - 1] = L.data[j];

	}

	//���ȼ�һ
	L.length--;
	return true;

}


//��ֵ����
int localdata(SqList L, ElemType e)
{
	int i;

	//������˳���
	for (i = 0; i < L.length; i++) {
		if (L.data[i] == e) {
			return i + 1;//����λ��
		}
	}
	return 0;
}



//��ӡ˳���
void printlist(SqList& L)
{
	for (int i = 0; i < L.length; i++)
	{
		printf("%3d", L.data[i]);//Ҫ���ӡ��һ��
	}
	printf("\n");
}








int main()
{

	SqList L;//˳�������
	bool ret;//�鿴����ֵ
	ElemType del;//�洢��Ҫɾ����Ԫ��
	L.data[0] = 1;
	L.data[1] = 2;
	L.data[2] = 3;
	L.length = 3;//�ܼ�����Ԫ��
	

	//�������
	ret = listinsert(L, 2, 60);
	if (ret)
	{
		printf("success\n");
		printlist(L);//��ӡ˳���
	}
	else {
		printf("failed\n");

	}
	
	
	//ɾ����һ��λ��Ԫ�ز����
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
	
	
	//����ĳ��ֵ�ҷ���λ��
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