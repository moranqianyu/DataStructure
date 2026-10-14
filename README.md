# DataStructure
# 顺序表 ADT 实现
基于C++实现严蔚敏教材顺序表抽象数据类型，拆分为头文件+源文件。

## 文件结构
DataStructure/
├── Chapter01_绪论/
│   ├── notes.md        # 本章知识点笔记
│   ├── example.c       # 课本示例代码
│   └── exercises.c     # 课后习题代码
├── Chapter02_线性表/
├── Chapter03_栈和队列/
├── Chapter04_串数组广义表/
├── Chapter05_树和二叉树/
├── Chapter06_图/
├── Chapter07_查找/
├── Chapter08_排序/
├── common/             # 公共头文件、工具函数
└── README.md           # 仓库介绍、学习进度记录
件

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
