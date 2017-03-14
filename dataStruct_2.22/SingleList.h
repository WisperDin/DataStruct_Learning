#pragma once
#include "stdafx.h"


typedef struct Node
{
	int data;
	struct Node* next;
}NODE;

//创建表头，返回指向表头的指针，表头数据为表长
NODE* CreateListHead();

//后插法插入结点,参数为前一个结点与要插入结点的数据，返回值为指向插入结点的指针
NODE* InsertNode(NODE* Head,NODE *pre, int data);

//头插法
void InsertNodePre(NODE* Head, int data);
//生成N的在链表上的结点
void InitList(NODE* head, int n);

//通过数组生成
void InitListByGroup(NODE* head, int* src, int n);

//找是否存在这个结点数据
NODE* FindNode(NODE* head, int tarData);

//输出链表
void PrintList(NODE* head);

//删除链表
void DelList_ALL(NODE* head);