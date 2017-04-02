#pragma once 
#include "stdafx.h"
#include "SingleList.h"
//散列定义
//采用关键字映射元素
//这里使用了分离链接法的散列
//保存的元素为整型，所以hash映射直接取mod
typedef NODE* List;
typedef struct 
{
	int TableSize;
	List *theList;
}HashTable;
//注意，theList实质为指向NODE结构的指针的指针，用typedef防止造成混乱

//初始化散列
HashTable* InitHashTable(int TableSize);

//查找value(先查找value在散列中的位置，若找到该位置则在该位置的链表中找是否存在此value)
//pos参数为value所在散列中的位置,为引用参数
List FindHashing(int value, HashTable* hashtb, int *pos);

//散列函数，作为元素到关键字的转换
int Hash(int value, int TableSize);

//插入value
//若value存在，不做任何事情
//否则,(类似查找，先查找value在散列中的位置(或者给定pos)，使用前插法插入链表中即可)
//pos参数为value所在散列中的位置,为引用参数
void InsertHashing(int value, HashTable* hashtb,int *pos);//使用pos使得减少计算hash的次数

//判断散列pos是否合法
//如果pos不合法返回0以外的数
int IsPosCorrect(int pos, int TableSize);


