#include "SqList.h"

Status InitList(SqList& L) {
	L.elem = (ElemType*)malloc(MAXSIZE * sizeof(ElemType));
	if (!L.elem) exit(OVERFLOW);
	L.length = 0;
	return OK;
}
Status DestroyList(SqList& L) {
	free(L.elem);
	L.elem = NULL;
	L.length = 0;
	return OK;
}
Status ClearList(SqList& L) {
	L.length = 0;
	return OK;
}
Status ListEmpty(SqList L) {
	return L.length == 0 ? OK : ERROR;
}
int ListLength(SqList L) {
	return L.length;
}
Status GetElem(SqList L, int i, ElemType& e) {
	if (i < 1 || i > L.length) return ERROR;
	e = L.elem[i - 1];
	return OK;
}
int LocateElem(SqList L, ElemType e) {
	for (int i = 0; i < L.length; i++) {
		if (L.elem[i] == e) return i + 1;
	}
	return 0;
}
Status PriorElem(SqList L, ElemType cur_e, ElemType& pre_e) {
	int pos = LocateElem(L, cur_e);
	if (pos <= 1) return ERROR;
	pre_e = L.elem[pos - 2];
	return OK;
}
Status NextElem(SqList L, ElemType cur_e, ElemType& next_e) {
	int pos = LocateElem(L, cur_e);
	if (pos == 0 || pos >= L.length) return ERROR;
	next_e = L.elem[pos];
	return OK;
}
Status ListInsert(SqList& L, int i, ElemType e) {
	if (i < 1 || i > L.length + 1) return ERROR;
	if (L.length >= MAXSIZE) return ERROR;
	for (int j = L.length - 1; j >= i - 1; j--) {
		L.elem[j + 1] = L.elem[j];
	}
	L.elem[i - 1] = e;
	L.length++;
	return OK;
}
Status ListDelete(SqList& L, int i, ElemType& e) {
	if (i < 1 || i > L.length) return ERROR;
	e = L.elem[i - 1];
	for (int j = i; j < L.length; j++) {
		L.elem[j - 1] = L.elem[j];
	}
	L.length--;
	return OK;
}
void TraverseList(SqList L, void(*visit)(ElemType)) {
	for (int i = 0; i < L.length; i++) {
		visit(L.elem[i]);
	}
}
