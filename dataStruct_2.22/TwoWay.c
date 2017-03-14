#include "stdafx.h"
#include "TwoWay_List.h"



//创建表头，返回指向表头的指针，表头数据为表长
TwNODE* CreateTwListHead(){
	int length = 0;
	TwNODE *head = (TwNODE*)malloc(sizeof(TwNODE));
	head->data = length;
	head->next = NULL;//指针指空
	head->prev = NULL;//指针指空
	return head;
}

//后插法插入结点,参数为前一个结点与要插入结点的数据，返回值为指向插入结点的指针
TwNODE* InsertTwNODE(TwNODE* Head,TwNODE *pre, int data){
	TwNODE* tar = (TwNODE*)malloc(sizeof(TwNODE));
	tar->data = data;
	tar->next = NULL;

	tar->prev = pre;
	pre->next = tar;

	Head->data++;//修改表头数据域
	return tar;
}

//头插法
TwNODE* InsertTwNODEPre(TwNODE* Head, int data){
	TwNODE* tar = (TwNODE*)malloc(sizeof(TwNODE));
	tar->data = data;
	tar->next = Head->next;
	tar->prev = Head;
	if (!(Head->next))//头指针的next为NULL
	{
		Head->next = tar;
	}
	else
	{
		Head->next->prev = tar;
		Head->next = tar;
	}
	Head->data++;//修改表头数据域
	return tar;

}

//生成N的在链表上的结点
void InitTwList(TwNODE* head, int n)
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
	TwNODE* currentNode = head;
	for (int i = 0; i < n; i++)
	{
		currentNode = InsertTwNODE(head,currentNode, i);
	}

	////头插,,实现起来很复杂
	//TwNODE* currentNode = NULL;
	//for (int i = 0; i < n; i++)
	//{
	//	currentNode=InsertTwNODEPre(head, i);
	//}


	//head->data = n;//修改表头数据域
}

void PrintTwList(TwNODE* head){
	TwNODE* currentNode = head->next;
	printf("list length:%d\n", head->data);

	while (currentNode != NULL)
	{
		printf("%d", currentNode->data);
		if (currentNode->next==NULL)//当前节点为尾节点
		{
			break;
		}
		currentNode = currentNode->next;
	}
	printf("\n");
	//倒悬输出
	while (currentNode->prev!=NULL)
	{
		printf("%d", currentNode->data);
		currentNode = currentNode->prev;
	}
	printf("\n");
}

void DelTwList_ALL(TwNODE* head){
	TwNODE* currentNode = head->next;
	TwNODE* nodeToDel = NULL;

	while (currentNode != NULL)
	{
		nodeToDel = currentNode;//记住当前要删除的指针
		currentNode = currentNode->next;//释放这个指针指向的位置
		free(nodeToDel);

	}
	head->data = 0;
	printf("delete comp\n");
}