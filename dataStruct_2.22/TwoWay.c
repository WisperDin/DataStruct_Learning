#include "stdafx.h"
#include "TwoWay_List.h"



//������ͷ������ָ���ͷ��ָ�룬��ͷ����Ϊ��
TwNODE* CreateTwListHead(){
	int length = 0;
	TwNODE *head = (TwNODE*)malloc(sizeof(TwNODE));
	head->data = length;
	head->next = NULL;//ָ��ָ��
	head->prev = NULL;//ָ��ָ��
	return head;
}

//��巨������,����Ϊǰһ�������Ҫ����������ݣ�����ֵΪָ��������ָ��
TwNODE* InsertTwNODE(TwNODE* Head,TwNODE *pre, int data){
	TwNODE* tar = (TwNODE*)malloc(sizeof(TwNODE));
	tar->data = data;
	tar->next = NULL;

	tar->prev = pre;
	pre->next = tar;

	Head->data++;//�޸ı�ͷ������
	return tar;
}

//ͷ�巨
TwNODE* InsertTwNODEPre(TwNODE* Head, int data){
	TwNODE* tar = (TwNODE*)malloc(sizeof(TwNODE));
	tar->data = data;
	tar->next = Head->next;
	tar->prev = Head;
	if (!(Head->next))//ͷָ���nextΪNULL
	{
		Head->next = tar;
	}
	else
	{
		Head->next->prev = tar;
		Head->next = tar;
	}
	Head->data++;//�޸ı�ͷ������
	return tar;

}

//����N���������ϵĽ��
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
	//β��
	TwNODE* currentNode = head;
	for (int i = 0; i < n; i++)
	{
		currentNode = InsertTwNODE(head,currentNode, i);
	}

	////ͷ��,,ʵ�������ܸ���
	//TwNODE* currentNode = NULL;
	//for (int i = 0; i < n; i++)
	//{
	//	currentNode=InsertTwNODEPre(head, i);
	//}


	//head->data = n;//�޸ı�ͷ������
}

void PrintTwList(TwNODE* head){
	TwNODE* currentNode = head->next;
	printf("list length:%d\n", head->data);

	while (currentNode != NULL)
	{
		printf("%d", currentNode->data);
		if (currentNode->next==NULL)//��ǰ�ڵ�Ϊβ�ڵ�
		{
			break;
		}
		currentNode = currentNode->next;
	}
	printf("\n");
	//�������
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
		nodeToDel = currentNode;//��ס��ǰҪɾ����ָ��
		currentNode = currentNode->next;//�ͷ����ָ��ָ���λ��
		free(nodeToDel);

	}
	head->data = 0;
	printf("delete comp\n");
}