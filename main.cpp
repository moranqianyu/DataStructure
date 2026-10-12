//#include "SqList.h"
//void print(ElemType x)
//{
//	printf("%d ", x);
//}
//
//int main()
//{
//	SqList L;
//	InitList(L);
//	ListInsert(L, 1, 10);
//	ListInsert(L, 2, 20);
//	printf("顺序表元素：");
//	TraverseList(L, print);
//
//	ElemType e;
//	ListDelete(L, 1, e);
//	printf("\n删除的元素=%d\n", e);
//	printf("删除后：");
//	TraverseList(L, print);
//
//	DestroyList(L);
//	return 0;
//}
#include "LinkList.h"
#include <iostream>

// 打印函数，作为TraverseList的回调visit
void print(ElemType val)
{
	printf("%d ", val);
}

int main()
{
	LinkList L;
	ElemType e;

	//1.初始化链表
	InitList(L);
	printf("初始化完成，链表是否空：%s\n", ListEmpty(L) ? "是" : "否");

	//2.插入元素10,20,30
	ListInsert(L,1,10);
	ListInsert(L,2,20);
	ListInsert(L,3,30);
	printf("插入10,20,30后遍历：");
	TraverseList(L, print);
	printf("\n链表长度=%d\n", ListLength(L));

	//3.按位查找第2个元素
	GetElem(L,2,e);
	printf("第2个元素 = %d\n",e);

	//4.查找20的前驱
	PriorElem(L,20,e);
	printf("20的前驱 = %d\n",e);

	//5.查找20的后继
	NextElem(L,20,e);
	printf("20的后继 = %d\n",e);

	//6.删除第1个元素
	ListDelete(L,1,e);
	printf("删除第1个元素，被删值=%d，遍历：",e);
	TraverseList(L, print);
	printf("\n");

	//7.清空链表
	ClearList(L);
	printf("清空后链表是否空：%s\n", ListEmpty(L) ? "是" : "否");

	//8.销毁链表
	DestroyList(L);
	return 0;
}
