#pragma once
#ifndef SQLIST_H
#define SQLIST_H
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define OK 1          //操作成功
#define ERROR 0       //操作失败
#define OVERFLOW -2   //内存分配溢出

typedef int Status;   //函数返回状态类型
#define MAXSIZE 100   //顺序表最大容量
typedef int ElemType; //存放元素的数据类型

//顺序表结构体定义（动态分配数组的顺序表）
typedef struct {
	ElemType* elem;   //动态数组基指针，指向存放数据的数组空间
	int length;       //当前顺序表中有效元素个数
} SqList;

//函数声明
Status InitList(SqList& L);                     //初始化顺序表，分配数组内存
Status DestroyList(SqList& L);                  //销毁顺序表，释放数组内存
Status ClearList(SqList& L);                    //清空顺序表，元素个数置0，内存保留
Status ListEmpty(SqList L);                     //判断顺序表是否为空
int ListLength(SqList L);                       //获取顺序表当前有效元素个数
Status GetElem(SqList L, int i, ElemType& e);   //按位查找，取第i个元素存入e
int LocateElem(SqList L, ElemType e);           //按值查找，返回元素位序，找不到返回0
Status PriorElem(SqList L, ElemType cur_e, ElemType& pre_e); //查找cur_e的前驱元素
Status NextElem(SqList L, ElemType cur_e, ElemType& next_e); //查找cur_e的后继元素
Status ListInsert(SqList& L, int i, ElemType e);//在第i个位置插入元素e
Status ListDelete(SqList& L, int i, ElemType& e);//删除第i个元素，删除值存入e带回
void TraverseList(SqList L, void(*visit)(ElemType));//遍历顺序表，visit回调处理每个元素

#endif
