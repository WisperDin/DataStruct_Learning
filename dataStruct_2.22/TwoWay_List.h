#pragma once
#include "stdafx.h"

typedef struct TwNODE
{
	struct TwNODE* prev;
	int data;
	struct TwNODE* next;
}TwNODE;

//创建表头，返回指向表头的指针，表头数据为表长
TwNODE* CreateTwListHead();

//后插法插入结点,参数为前一个结点与要插入结点的数据，返回值为指向插入结点的指针
TwNODE* InsertTwNODE(TwNODE* Head,TwNODE *pre, int data);

//头插法
TwNODE* InsertTwNODEPre(TwNODE* Head, int data);

//生成N的在链表上的结点
void InitTwList(TwNODE* head, int n);

//输出链表
void PrintTwList(TwNODE* head);

//删除链表
void DelTwList_ALL(TwNODE* head);