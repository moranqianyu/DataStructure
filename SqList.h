#pragma once
#ifndef SQLIST_H
#define SQLIST_H

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
#define MAXSIZE 100
typedef int ElemType;

typedef struct {
	ElemType* elem;
	int length;
} SqList;

//º¯ÊýÉùÃ÷
Status InitList(SqList& L);
Status DestroyList(SqList& L);
Status ClearList(SqList& L);
Status ListEmpty(SqList L);
int ListLength(SqList L);
Status GetElem(SqList L, int i, ElemType& e);
int LocateElem(SqList L, ElemType e);
Status PriorElem(SqList L, ElemType cur_e, ElemType& pre_e);
Status NextElem(SqList L, ElemType cur_e, ElemType& next_e);
Status ListInsert(SqList& L, int i, ElemType e);
Status ListDelete(SqList& L, int i, ElemType& e);
void TraverseList(SqList L, void(*visit)(ElemType));

#endif