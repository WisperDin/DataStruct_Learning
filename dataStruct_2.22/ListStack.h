#pragma once
#include "stdafx.h"
//结构定义：
//链栈,有表头，使用头插法添加元素，栈顶为首节点

typedef struct LiStack{
	int data;
	struct LiStack* next;
}LiStack;

//初始化栈
LiStack* InitStack();

//入栈
void Push(LiStack* s, int data);

//出栈
int Pop(LiStack* s);

//显示栈顶元素
int Top(LiStack* s);

//释放栈
void ReleaseStack(LiStack* s);

//显示所有栈元素(递归实现，要求传入的是首节点)
void ShowInStack(LiStack* s);

