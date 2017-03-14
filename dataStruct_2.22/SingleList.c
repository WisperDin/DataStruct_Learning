#include "stdafx.h"
#include "SingleList.h"


//创建表头，返回指向表头的指针，表头数据为表长
NODE* CreateListHead(){
	int length = 0;
	NODE *head = (NODE*)malloc(sizeof(NODE));
	head->data = length;
	head->next = NULL;//指针指空
	return head;
}

//后插法插入结点,参数为前一个结点与要插入结点的数据，返回值为指向插入结点的指针
NODE* InsertNode(NODE* Head,NODE *pre, int data){
	NODE* tar = (NODE*)malloc(sizeof(NODE));
	tar->data = data;
	tar->next = NULL;

	pre->next = tar;

	Head->data++;//修改表头数据域
	return tar;
}

//头插法
void InsertNodePre(NODE* Head, int data){
	NODE* tar = (NODE*)malloc(sizeof(NODE));
	tar->data = data;
	tar->next = Head->next;
	Head->next = tar;
	Head->data++;//修改表头数据域
}
//生成N的在链表上的结点
void InitList(NODE* head, int n)
{
	if (!head)
	{
		printf("null head");
		return;
	}
	if (n <= 0)
	{
		printf("wrong with n");
		return;
	}
	//尾插
	//NODE* currentNode = head;
	//for (int i = 0; i < n; i++)
	//{
	//	currentNode=InsertNode(currentNode, i);
	//}

	//头插
	for (int i = 0; i < n; i++)
	{
		InsertNodePre(head, i);
	}
}

//找是否存在这个结点数据
NODE* FindNode(NODE* head, int tarData){
	if (!head)
	{
		printf("null head");
		return NULL;
	}
	if (head->data <= 0)
	{
		printf("length = 0");
		return NULL;
	}
	NODE* currentNode = head;
	while (currentNode)
	{
		if (currentNode->data == tarData)
		{
			return currentNode;
		}
		currentNode = currentNode->next;
	}
	return NULL;
}

//输出链表
void PrintList(NODE* head){
	NODE* currentNode = head->next;
	printf("list length:%d\n", head->data);
	while (currentNode != NULL)
	{
		printf("%d", currentNode->data);
		currentNode = currentNode->next;
	}
	printf("\n");
}
void DelList_ALL(NODE* head){
	NODE* currentNode = head->next;
	NODE* nodeToDel = NULL;

	while (currentNode != NULL)
	{
		nodeToDel = currentNode;//记住当前要删除的指针
		currentNode = currentNode->next;//释放这个指针指向的位置
		free(nodeToDel);

	}
	head->data = 0;
	printf("delete comp\n");
}