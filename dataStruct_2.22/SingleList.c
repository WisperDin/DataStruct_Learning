#include "stdafx.h"
#include "SingleList.h"


//������ͷ������ָ���ͷ��ָ�룬��ͷ����Ϊ��
NODE* CreateListHead(){
	int length = 0;
	NODE *head = (NODE*)malloc(sizeof(NODE));
	head->data = length;
	head->next = NULL;//ָ��ָ��
	return head;
}

//��巨������,����Ϊǰһ�������Ҫ����������ݣ�����ֵΪָ��������ָ��
NODE* InsertNode(NODE* Head,NODE *pre, int data){
	NODE* tar = (NODE*)malloc(sizeof(NODE));
	tar->data = data;
	tar->next = NULL;

	pre->next = tar;

	Head->data++;//�޸ı�ͷ������
	return tar;
}

//ͷ�巨
void InsertNodePre(NODE* Head, int data){
	NODE* tar = (NODE*)malloc(sizeof(NODE));
	tar->data = data;
	tar->next = Head->next;
	Head->next = tar;
	Head->data++;//�޸ı�ͷ������
}
//����N���������ϵĽ��
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
	//β��
	//NODE* currentNode = head;
	//for (int i = 0; i < n; i++)
	//{
	//	currentNode=InsertNode(currentNode, i);
	//}

	//ͷ��
	for (int i = 0; i < n; i++)
	{
		InsertNodePre(head, i);
	}
}

//���Ƿ��������������
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

//�������
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
		nodeToDel = currentNode;//��ס��ǰҪɾ����ָ��
		currentNode = currentNode->next;//�ͷ����ָ��ָ���λ��
		free(nodeToDel);

	}
	head->data = 0;
	printf("delete comp\n");
}