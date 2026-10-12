#pragma once
#ifndef LINKLIST_H
#define LINKLIST_H
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define OK 1          // 操作成功
#define ERROR 0       // 操作失败
#define OVERFLOW -2   // 内存溢出
#define MAXSIZE 100

typedef int Status;   // 函数返回状态类型
typedef int ElemType; // 链表元素数据类型

// 单链表结点结构体定义
typedef struct LNode {
	ElemType data;     // 数据域，存放元素
	struct LNode* next;// 指针域，存下一个结点地址
} LNode, * LinkList;  // LNode结点类型；LinkList为结点指针类型

// 函数声明
Status InitList(LinkList& L);                     // 初始化链表，创建头结点
Status DestroyList(LinkList& L);                  // 销毁链表，释放头结点+所有数据结点
Status ClearList(LinkList& L);                    // 清空链表，只删除数据结点，保留头结点
Status ListEmpty(LinkList L);                     // 判断链表是否为空
int ListLength(LinkList L);                       // 获取链表中数据结点个数
Status GetElem(LinkList L, int i, ElemType& e);   // 按位查找，取出第i个元素存入e
LNode* LocateElem(LinkList L, ElemType e);        // 按值查找，返回值等于e的结点指针
Status PriorElem(LinkList L, ElemType cur_e, ElemType& pre_e); // 查找cur_e的前驱元素
Status NextElem(LinkList L, ElemType cur_e, ElemType& next_e); // 查找cur_e的后继元素
Status ListInsert(LinkList& L, int i, ElemType e);// 在第i个位置插入元素e
Status ListDelete(LinkList& L, int i, ElemType& e);// 删除第i个位置元素，值存入e带回
void TraverseList(LinkList L, void(*visit)(ElemType));// 遍历链表，visit回调处理每个元素

#endif