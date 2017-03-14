#pragma once
#include "stdafx.h"


typedef struct Node
{
	int data;
	struct Node* next;
}NODE;

//������ͷ������ָ���ͷ��ָ�룬��ͷ����Ϊ��
NODE* CreateListHead();

//��巨������,����Ϊǰһ�������Ҫ����������ݣ�����ֵΪָ��������ָ��
NODE* InsertNode(NODE* Head,NODE *pre, int data);

//ͷ�巨
void InsertNodePre(NODE* Head, int data);
//����N���������ϵĽ��
void InitList(NODE* head, int n);

//ͨ����������
void InitListByGroup(NODE* head, int* src, int n);

//���Ƿ��������������
NODE* FindNode(NODE* head, int tarData);

//�������
void PrintList(NODE* head);

//ɾ������
void DelList_ALL(NODE* head);