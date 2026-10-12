#include "SqList.h"

//初始化顺序表：分配动态数组空间，初始有效长度置0
Status InitList(SqList& L) {
	//分配MAXSIZE个ElemType大小的内存，强制转为ElemType*赋值给elem
	L.elem = (ElemType*)malloc(MAXSIZE * sizeof(ElemType));
	if (!L.elem) exit(OVERFLOW); //分配失败，退出程序，返回溢出错误
	L.length = 0;                //初始有效元素数量为0，空表
	return OK;
}

//销毁顺序表：释放动态数组内存，清空成员变量
Status DestroyList(SqList& L) {
	free(L.elem);       //释放动态数组开辟的堆内存
	L.elem = NULL;      //指针置空，防止野指针
	L.length = 0;       //有效长度清零
	return OK;
}

//清空顺序表：只把有效元素个数置0，数组内存不释放
Status ClearList(SqList& L) {
	L.length = 0;       //逻辑清空，原数组数据还在，但不再访问
	return OK;
}

//判断顺序表是否为空：有效长度为0则是空表
Status ListEmpty(SqList L) {
	return L.length == 0 ? OK : ERROR;
}

//获取顺序表当前有效元素个数
int ListLength(SqList L) {
	return L.length;
}

//按位查找：获取第i位的元素，存入引用e带出，位序i从1开始
Status GetElem(SqList L, int i, ElemType& e) {
	//判断位序合法性：i不能小于1，不能超过当前表长
	if (i < 1 || i > L.length) return ERROR;
	e = L.elem[i - 1];  //顺序表数组下标从0开始，位序i对应下标i-1
	return OK;
}

//按值查找：找到第一个等于e的元素，返回位序；找不到返回0
int LocateElem(SqList L, ElemType e) {
	//遍历数组下标0~length-1
	for (int i = 0; i < L.length; i++) {
		if (L.elem[i] == e) return i + 1; //下标i对应位序i+1
	}
	return 0; //循环结束没有找到目标元素，返回0
}

//查找cur_e的前驱元素，前驱存入pre_e
Status PriorElem(SqList L, ElemType cur_e, ElemType& pre_e) {
	int pos = LocateElem(L, cur_e); //先查找cur_e的位序pos
	if (pos <= 1) return ERROR;     //pos为0：找不到cur_e；pos=1：第一个元素没有前驱
	pre_e = L.elem[pos - 2];        //pos位元素下标pos-1，前驱下标pos-2
	return OK;
}

//查找cur_e的后继元素，后继存入next_e
Status NextElem(SqList L, ElemType cur_e, ElemType& next_e) {
	int pos = LocateElem(L, cur_e);
	//pos=0找不到cur_e；pos等于表长，是最后一个元素，无后继
	if (pos == 0 || pos >= L.length) return ERROR;
	next_e = L.elem[pos]; //pos位元素下标pos-1，后继下标pos
	return OK;
}

//在第i个位置插入元素e，位序i从1开始
Status ListInsert(SqList& L, int i, ElemType e) {
	//位序合法性判断：i范围 [1, L.length+1]
	if (i < 1 || i > L.length + 1) return ERROR;
	if (L.length >= MAXSIZE) return ERROR; //表已满，无法插入
	//从最后一个有效元素开始，向后挪动，给新元素腾出i-1下标位置
	for (int j = L.length - 1; j >= i - 1; j--) {
		L.elem[j + 1] = L.elem[j];
	}
	L.elem[i - 1] = e; //新元素放入腾出的位置
	L.length++;        //有效元素个数+1
	return OK;
}

//删除第i个位置的元素，被删除的值存入e带回
Status ListDelete(SqList& L, int i, ElemType& e) {
	//位序合法性判断
	if (i < 1 || i > L.length) return ERROR;
	e = L.elem[i - 1]; //取出待删除元素的值
	//待删元素后面所有元素依次向前移动一位，覆盖被删除元素
	for (int j = i; j < L.length; j++) {
		L.elem[j - 1] = L.elem[j];
	}
	L.length--; //有效元素个数-1
	return OK;
}

//遍历顺序表，visit是函数指针，对每个元素执行visit操作
void TraverseList(SqList L, void(*visit)(ElemType)) {
	for (int i = 0; i < L.length; i++) {
		visit(L.elem[i]);
	}
}
