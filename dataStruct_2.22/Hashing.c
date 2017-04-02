#include "stdafx.h"
#include "Hashing.h"


//初始化散列
HashTable* InitHashTable(int TableSize){
	HashTable *hashtb;
	//为散列分配空间
	hashtb = (HashTable*)malloc(sizeof(HashTable));
	hashtb->TableSize = TableSize;
	//为散列内指向链表的链表指针分配空间
	hashtb->theList = (List*)malloc(sizeof(List*)*hashtb->TableSize);
	//为每个链表申请一个空间作为头节点
	for (size_t i = 0; i < hashtb->TableSize; i++)
	{
		hashtb->theList[i] = (List)malloc(sizeof(List));
		hashtb->theList[i]->data = 0;
		hashtb->theList[i]->next = NULL;
	}
	return hashtb;
}

//查找value(先查找value在散列中的位置，若找到该位置则在该位置的链表中找是否存在此value)
List FindHashing(int value, HashTable* hashtb,int *pos){
	//找到对应value位置的链表表头（或者使用给定pos）
	if (IsPosCorrect(*pos, hashtb->TableSize) != 0)//如果pos不合法返回0以外的数
	{
		*pos = Hash(value, hashtb->TableSize);
	}
	List findList = hashtb->theList[*pos];

	//1.这是重新实现的查找
	//NODE* curNode = findList->next;
	////读到最后或者找到对应的value则退出循环
	//while (curNode != NULL&&curNode->data!=value)
	//{
	//	curNode = curNode->next;
	//}
	//return curNode;

	//2.因为已经实现了单链表的查找，可以直接用函数
	NODE* curNode = FindNode(findList, value);
	return curNode;
}

//散列函数，作为元素到关键字的转换
int Hash(int value, int TableSize){
	//返回的值0~TableSize-1
	return value % TableSize;
}

//插入value
//若value存在，不做任何事情
//否则,(类似查找，先查找value在散列中的位置(或者给定pos)，使用前插法插入链表中即可)
void InsertHashing(int value, HashTable* hashtb, int *pos){
	if (FindHashing(value, hashtb, pos) != NULL)//如果这个value已经存在
	{
		return;
	}
	//找到对应value位置的链表表头（或者使用给定pos）
	if (IsPosCorrect(*pos,hashtb->TableSize)!=0)//如果pos不合法返回0以外的数
	{
		*pos = Hash(value, hashtb->TableSize);
	}
	List findList = hashtb->theList[*pos];
	//使用头插法插入节点
	InsertNodePre(findList, value);
}

//判断散列pos是否合法
//如果pos不合法返回0以外的数
int IsPosCorrect(int pos, int TableSize){
	if (pos<0 || pos >= TableSize)//位置不合法
	{
		//printf("pos not correct");
		return -1;
	}
	return 0;
}