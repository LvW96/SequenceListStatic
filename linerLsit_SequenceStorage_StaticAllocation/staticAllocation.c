// ���Ա�˳��洢֮��̬����
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MaxSize 15
typedef struct{
	int data[MaxSize];
	int length;
}Sqlist;
//��ʼ�����Ա�
void InitList(Sqlist *L){
	for (int i = 0; i < MaxSize; i++)
	{
		L->data[i] = 0;
	}
	L->length = 10;
}

// �������Ա�
void CreatList(Sqlist *L){
	printf("���������Ա�ĳ��ȣ�");
	scanf("%d", &L->length);
	printf("��������������ݣ�\n");
	for (int i = 0; i < L->length; i++)
	{
		scanf("%d", &L->data[i]);
	}
	printf("���е�����Ϊ��");
	for (int j = 0; j < L->length; j++)
		printf("%3d", L->data[j]);
	printf("\n");
}
// �������
bool ListInsert(Sqlist *L, int InsertLocation, int InsertData){
	if (InsertLocation < 1 || InsertLocation >L->length + 1)// ����λ�ò��Ϸ�
		return false;
	if (L->length >= MaxSize)// ������ǰ�Ĵ洢�ռ�
		return false;
	for (int i = L->length; i >= InsertLocation; i--)//�ҵ�����λ�ò����估��֮�����ݺ���
	{
		L->data[i] = L->data[i - 1];
	}
	L->data[InsertLocation - 1] = InsertData;// �����ݲ����λ��
	L->length ++;
	return true;
}
//ɾ������
bool DeleteList(Sqlist *L, int DeleteLocation, int *DeleteData){
	if (DeleteLocation < 1 || DeleteLocation > L->length)//�ж�ɾ��λ���Ƿ�Ϸ�
		return false;
	*DeleteData = L->data[DeleteLocation - 1];
	for (int i = DeleteLocation; i < L->length; i++)// �ҵ�ɾ��λ�ý��������ǰ��
	{
		L->data[i - 1] = L->data[i];
	}
	L->length --;
	return true;
}
// ��ֵ���ң������ظ�ֵ�����Ա��е�λ��
int LocateElem(Sqlist L, int LocateValue){
	int ValueLocation;
	for (int i = 0; i < L.length; i++)
	{
		if (L.data[i] == LocateValue){
			ValueLocation = i + 1;
			return ValueLocation;
		}
	}
	return 0;
}
// �����ҵ�ֵ���ڱ���ʱ�ٴ�����ֵ����
int AgainLocateElem(Sqlist L){
	int LocateValue, ValueLocation;
	printf("������Ҫ���ҵ�ֵ��");
	scanf("%d", &LocateValue);
	ValueLocation = LocateElem(L, LocateValue);
	if (ValueLocation != 0)
		printf("���ҳɹ�����ֵ�ڱ��еĵ�%dλ\n", ValueLocation);
	else{
		printf("�ñ��в����ڸ�ֵ������������ֵ��\n");
		AgainLocateElem(L);
	}
	return 0;
}
// ��λ�ò��ң������ظ�λ�õ�ֵ
int GetElem(Sqlist L, int LocatePlace){
	if (LocatePlace < 1 || LocatePlace > L.length)
		return -1;
	else
		return L.data[LocatePlace - 1];
}
// �����ҵ�λ�ò��Ϸ�ʱ�ٴ��������λ��
int AgainGetElem(Sqlist L){
	int LocatePlace, value;
	printf("������Ҫ���ҵ�λ�ã�");
	scanf("%d", &LocatePlace);
	value = GetElem(L, LocatePlace);
	if (value != -1)
		printf("���ҳɹ�����λ�õ�ֵΪ%d\n", value);
	else{
		printf("����Ĳ���λ���������������룡\n");
		AgainGetElem(L);
	}
	return 0;
}

//��ӡ���Ա�����
void PrintList(Sqlist *L){
	for (int i = 0; i < L->length; i++)
	{
		printf("���Ա��е�����Ϊ��%d\n", L->data[i]);
	}
	printf("���Ա�ĳ���Ϊ��%d\n", L->length);
}
int main(){
	Sqlist L;
	int InsertLocation, InsertData, DeleteData, DeleteLoaction, LocateValue, ValueLocation, LocatePlace, value;
	DeleteData = -1;
	InitList(&L);
	// PrintList(&L);
	CreatList(&L);
	// ���Ա�������
	printf("����������λ�ã�");
	scanf("%d", &InsertLocation);
	printf("\n");
	printf("������Ҫ��������ݣ�");
	scanf("%d", &InsertData);
	if (ListInsert(&L, InsertLocation, InsertData))
	{
		printf("���ݲ���ɹ�\n");
		PrintList(&L);
	}
	else
		printf("���ݲ���ʧ�ܣ�������λ���Ƿ�Ϸ���");
	// ɾ������
	printf("\n");
	printf("������Ҫɾ����λ�ã�");
	scanf("%d", &DeleteLoaction);
	if (DeleteList(&L,DeleteLoaction,&DeleteData))
	{
		printf("����ɾ���ɹ�\n");
		printf("ɾ��Ԫ�غ����Ա��е�����Ϊ��\n");
		PrintList(&L);
		printf("ɾ���������ǣ�%d\n",DeleteData);
		// printf("ɾ�������Ա�ĳ���Ϊ��%d\n", L.length);
	}
	else
	{
		printf("ɾ����λ�ò��Ϸ������������룡");
	}
	printf("\n");
	// ��ֵ����
	printf("������Ҫ���ҵ�ֵ��");
	scanf("%d",&LocateValue);
	ValueLocation = LocateElem(L,LocateValue);
	if (ValueLocation != 0)
		printf("���ҳɹ�����ֵ�ڱ��еĵ�%dλ\n",ValueLocation);
	else{
		printf("�ñ��в����ڸ�ֵ������������ֵ��\n");
		AgainLocateElem(L);
	}
	printf("\n");
	// ��λ�ò���
	printf("������Ҫ���ҵ�λ�ã�");
	scanf("%d",&LocatePlace);
	value = GetElem(L, LocatePlace);
	if (value != -1)
		printf("���ҳɹ�����λ�õ�ֵΪ%d\n", value);
	else{
		printf("����Ĳ���λ���������������룡\n");
		AgainGetElem(L);
	}
	return 0;
}