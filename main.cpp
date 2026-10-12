#include "SqList.h"

void print(ElemType x)
{
	printf("%d ", x);
}

int main()
{
	SqList L;
	InitList(L);
	ListInsert(L, 1, 10);
	ListInsert(L, 2, 20);
	printf("顺序表元素：");
	TraverseList(L, print);

	ElemType e;
	ListDelete(L, 1, e);
	printf("\n删除的元素=%d\n", e);
	printf("删除后：");
	TraverseList(L, print);

	DestroyList(L);
	return 0;
}
