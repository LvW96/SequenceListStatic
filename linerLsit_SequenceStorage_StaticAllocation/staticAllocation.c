// 线性表顺序存储之静态分配
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MaxSize 15
typedef struct{
	int data[MaxSize];
	int length;
}Sqlist;
//初始化线性表
void InitList(Sqlist *L){
	for (int i = 0; i < MaxSize; i++)
	{
		L->data[i] = 0;
	}
	L->length = 10;
}

// 创建线性表
void CreatList(Sqlist *L){
	printf("请输入线性表的长度：");
	scanf("%d", &L->length);
	printf("请向表中输入数据：\n");
	for (int i = 0; i < L->length; i++)
	{
		scanf("%d", &L->data[i]);
	}
	printf("表中的数据为：");
	for (int j = 0; j < L->length; j++)
		printf("%3d", L->data[j]);
	printf("\n");
}
// 插入操作
bool ListInsert(Sqlist *L, int InsertLocation, int InsertData){
	if (InsertLocation < 1 || InsertLocation >L->length + 1)// 插入位置不合法
		return false;
	if (L->length >= MaxSize)// 超过当前的存储空间
		return false;
	for (int i = L->length; i >= InsertLocation; i--)//找到插入位置并将其及其之后数据后移
	{
		L->data[i] = L->data[i - 1];
	}
	L->data[InsertLocation - 1] = InsertData;// 将数据插入该位置
	L->length ++;
	return true;
}
//删除操作
bool DeleteList(Sqlist *L, int DeleteLocation, int *DeleteData){
	if (DeleteLocation < 1 || DeleteLocation > L->length)//判断删除位置是否合法
		return false;
	*DeleteData = L->data[DeleteLocation - 1];
	for (int i = DeleteLocation; i < L->length; i++)// 找到删除位置将其后数据前移
	{
		L->data[i - 1] = L->data[i];
	}
	L->length --;
	return true;
}
// 按值查找，并返回该值在线性表中的位置
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
// 当查找的值不在表中时再次输入值查找
int AgainLocateElem(Sqlist L){
	int LocateValue, ValueLocation;
	printf("请输入要查找的值：");
	scanf("%d", &LocateValue);
	ValueLocation = LocateElem(L, LocateValue);
	if (ValueLocation != 0)
		printf("查找成功，该值在表中的第%d位\n", ValueLocation);
	else{
		printf("该表中不存在该值，请重新输入值！\n");
		AgainLocateElem(L);
	}
	return 0;
}
// 按位置查找，并返回该位置的值
int GetElem(Sqlist L, int LocatePlace){
	if (LocatePlace < 1 || LocatePlace > L.length)
		return -1;
	else
		return L.data[LocatePlace - 1];
}
// 当查找的位置不合法时再次输入查找位置
int AgainGetElem(Sqlist L){
	int LocatePlace, value;
	printf("请输入要查找的位置：");
	scanf("%d", &LocatePlace);
	value = GetElem(L, LocatePlace);
	if (value != -1)
		printf("查找成功，该位置的值为%d\n", value);
	else{
		printf("输入的查找位置有误，请重新输入！\n");
		AgainGetElem(L);
	}
	return 0;
}

//打印线性表数据
void PrintList(Sqlist *L){
	for (int i = 0; i < L->length; i++)
	{
		printf("线性表中的数据为：%d\n", L->data[i]);
	}
	printf("线性表的长度为：%d\n", L->length);
}
int main(){
	Sqlist L;
	int InsertLocation, InsertData, DeleteData, DeleteLoaction, LocateValue, ValueLocation, LocatePlace, value;
	DeleteData = -1;
	InitList(&L);
	// PrintList(&L);
	CreatList(&L);
	// 线性表插入操作
	printf("请输入插入的位置：");
	scanf("%d", &InsertLocation);
	printf("\n");
	printf("请输入要插入的数据：");
	scanf("%d", &InsertData);
	if (ListInsert(&L, InsertLocation, InsertData))
	{
		printf("数据插入成功\n");
		PrintList(&L);
	}
	else
		printf("数据插入失败，检查插入位置是否合法！");
	// 删除操作
	printf("\n");
	printf("请输入要删除的位置：");
	scanf("%d", &DeleteLoaction);
	if (DeleteList(&L,DeleteLoaction,&DeleteData))
	{
		printf("数据删除成功\n");
		printf("删除元素后线性表中的数据为：\n");
		PrintList(&L);
		printf("删除的数据是：%d\n",DeleteData);
		// printf("删除后线性表的长度为：%d\n", L.length);
	}
	else
	{
		printf("删除的位置不合法，请重新输入！");
	}
	printf("\n");
	// 按值查找
	printf("请输入要查找的值：");
	scanf("%d",&LocateValue);
	ValueLocation = LocateElem(L,LocateValue);
	if (ValueLocation != 0)
		printf("查找成功，该值在表中的第%d位\n",ValueLocation);
	else{
		printf("该表中不存在该值，请重新输入值！\n");
		AgainLocateElem(L);
	}
	printf("\n");
	// 按位置查找
	printf("请输入要查找的位置：");
	scanf("%d",&LocatePlace);
	value = GetElem(L, LocatePlace);
	if (value != -1)
		printf("查找成功，该位置的值为%d\n", value);
	else{
		printf("输入的查找位置有误，请重新输入！\n");
		AgainGetElem(L);
	}
	return 0;
}