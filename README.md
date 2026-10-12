# DataStructure
# 顺序表 ADT 实现
基于C++实现严蔚敏教材顺序表抽象数据类型，拆分为头文件+源文件。

## 文件结构
├── SqList.h      // 头文件：结构体定义、函数声明
├── SqList.cpp    // 顺序表所有操作实现
├── main.cpp      // 测试入口
└── .gitignore    //git 忽略 VS 编译垃圾文件

## 支持操作
- InitList        初始化顺序表
- DestroyList    销毁顺序表
- ClearList      清空顺序表
- ListEmpty      判断是否为空
- ListLength     获取表长度
- GetElem        按位序取值
- LocateElem     按值查找
- PriorElem      获取前驱元素
- NextElem       获取后继元素
- ListInsert     指定位置插入
- ListDelete     指定位置删除
- TraverseList   遍历（函数指针）

## 编译运行
使用Visual Studio，新建空项目，添加3个源码文件，直接编译运行。
