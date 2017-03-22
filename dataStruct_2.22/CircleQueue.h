#pragma once 
#include "stdafx.h"
#define MAXSIZE 10
//数据结构定义：
//循环队列，头指针指向第一个元素的前一个空间，尾指针指向最后一个元素，
//判空：当头尾指针相等
//判满：当尾指针的后一位=头指针
//特点，少用一个存储空间
typedef struct CircleQueue{
	int data[MAXSIZE];
	int front;//队列头指针
	int rear;//队列尾指针
}CIRQueue;

//初始化队列
CIRQueue* InitQueue();

//进队
void EnQueue(CIRQueue* queue,int tarData);

//出队
int DeQueue(CIRQueue* queue);

//队列判空
int IsQueueEmpty(CIRQueue* queue);

//队列判满
int IsQueueFull(CIRQueue* queue);

//显示队列中所有元素
void ShowQueue(CIRQueue* queue);

//释放队列控件
void FreeQueue(CIRQueue* queue);