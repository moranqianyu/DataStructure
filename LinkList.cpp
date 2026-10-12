#include "LinkList.h"

// 函数：初始化带头结点的空单链表
Status InitList(LinkList& L) {
	L = (LinkList)malloc(sizeof(LNode)); // 申请一块结点大小内存，作为头结点
	if (!L) exit(OVERFLOW);              // malloc返回NULL，内存分配失败，程序退出
	L->next = NULL;                      // 头结点后继置空，链表暂无数据结点
	return OK;                           // 初始化成功
}

// 函数：销毁整个链表，释放所有结点（含头结点）
Status DestroyList(LinkList& L) {
	LinkList p;                          // 临时指针保存下一个结点地址
	while (L) {                          // L不为空，还有结点待释放
		p = L->next;                     // 先保存后继，防止free后找不到后续结点
		free(L);                         // 释放当前结点
		L = p;                           // L移动到下一个结点
	}
	return OK;
}

// 函数：清空链表，删除全部数据结点，保留头结点
Status ClearList(LinkList& L) {
	LinkList p, q;                       // p当前结点，q保存后继结点
	p = L->next;                         // p指向第一个数据结点（首元结点）
	while (p) {                          // 还有数据结点
		q = p->next;                     // 暂存下一个结点
		free(p);                         // 释放当前数据结点
		p = q;                           // p移动到暂存的后继结点
	}
	L->next = NULL;                      // 头结点next置空，链表变为空表
	return OK;
}

// 函数：判断链表是否为空表（带头结点）
Status ListEmpty(LinkList L) {
	// 头结点的next为空代表没有数据结点，空表返回OK，否则ERROR
	return L->next == NULL ? OK : ERROR;
}

// 函数：计算链表数据结点的个数，返回长度
int ListLength(LinkList L) {
	int length = 0;                      // 计数器初始化为0
	LinkList p = L->next;                // p指向首元结点
	while (p) {                          // p不为空，结点存在
		length++;                        // 计数+1
		p = p->next;                     // 指针后移
	}
	return length;                       // 返回结点总数
}

// 函数：按位查找，获取第i位元素存入引用e
Status GetElem(LinkList L, int i, ElemType& e) {
	if (i < 1) return ERROR;             // 位序从1开始，i<1位序非法
	LinkList p = L->next;                // p指向第1个数据结点
	int j = 1;                           // j记录当前p对应的位序
	while (p && j < i) {                 // p不为空，且还没走到第i个结点
		p = p->next;                     // p向后移动
		j++;                             // 位序计数+1
	}
	if (!p || j > i) return ERROR;       // p为空/位序超出范围，查找失败
	e = p->data;                         // 将结点数据赋值给e带出函数
	return OK;
}

// 函数：按值查找，找到第一个值等于e的结点，返回结点指针；找不到返回NULL
LNode* LocateElem(LinkList L, ElemType e) {
	LinkList p = L->next;                // 从首元结点开始遍历
	while (p) {                          // p不为空
		if (p->data == e) return p;      // 当前结点数据匹配，返回结点地址
		p = p->next;                     // 不匹配，继续向后遍历
	}
	return NULL;                         // 遍历完未找到，返回空指针
}

// 函数：查找cur_e的前驱元素，前驱存入pre_e
Status PriorElem(LinkList L, ElemType cur_e, ElemType& pre_e) {
	LinkList p = L->next;                // p指向首元结点
	// 链表为空 或者 cur_e是第一个结点（无前驱），直接失败
	if (!p || p->data == cur_e) return ERROR;
	while (p->next) {                    // p的后继结点存在
		if (p->next->data == cur_e) {    // p的后继就是目标cur_e，则p是前驱
			pre_e = p->data;             // 前驱数据存入pre_e
			return OK;
		}
		p = p->next;                     // p后移继续查找
	}
	return ERROR;                        // 遍历结束没找到cur_e
}

// 函数：查找cur_e的后继元素，后继存入next_e
Status NextElem(LinkList L, ElemType cur_e, ElemType& next_e) {
	LinkList p = L->next;                // p指向首元结点
	while (p && p->next) {               // p不为空并且p存在后继
		if (p->data == cur_e) {          // 当前结点是目标cur_e
			next_e = p->next->data;      // 取出后继结点数据
			return OK;
		}
		p = p->next;                     // p后移
	}
	return ERROR;                        // 找不到cur_e / cur_e是最后结点，无后继
}

// 函数：在链表第i个位置插入元素e
Status ListInsert(LinkList& L, int i, ElemType e) {
	if (i < 1) return ERROR;             // 位序不能小于1
	LinkList p = L;                      // p从头结点出发，寻找第i-1号结点（插入前驱）
	int j = 0;                           // j记录p当前位置，头结点j=0
	while (p && j < i - 1) {             // p不为空，还没走到i-1位置
		p = p->next;
		j++;
	}
	if (!p || j > i - 1) return ERROR;   // p为空，i位置不存在，插入失败
	LinkList s = (LinkList)malloc(sizeof(LNode));// 创建新结点s
	if (!s) exit(OVERFLOW);              // 内存分配失败
	s->data = e;                         // 新结点数据域赋值e
	s->next = p->next;                   // 新结点指向p原来的后继
	p->next = s;                         // p指向新结点，完成插入
	return OK;
}

// 函数：删除第i个结点，删除的元素存入e带回
Status ListDelete(LinkList& L, int i, ElemType& e) {
	if (i < 1) return ERROR;             // 位序非法判断
	LinkList p = L;                      // p从头结点出发，寻找i-1号结点
	int j = 0;
	while (p->next && j < i - 1) {       // p存在后继，且未走到i-1
		p = p->next;
		j++;
	}
	if (!p->next || j > i - 1) return ERROR; // 第i个结点不存在，删除失败
	LinkList q = p->next;                // q指向待删除结点
	e = q->data;                         // 取出待删结点的数据
	p->next = q->next;                   // 跳过待删结点，断开链表链接
	free(q);                             // 释放被删结点内存，防止内存泄漏
	return OK;
}

// 函数：遍历链表，visit是回调函数，对每个元素执行visit操作
void TraverseList(LinkList L, void(*visit)(ElemType)) {
	LinkList p = L->next;                // p指向首元结点
	while (p) {                          // p不为空
		visit(p->data);                   // 调用visit处理当前结点数据
		p = p->next;                     // 指针后移
	}
}
