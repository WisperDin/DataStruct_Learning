#pragma once
#include "stdafx.h"

typedef struct TwNODE
{
	struct TwNODE* prev;
	int data;
	struct TwNODE* next;
}TwNODE;

//������ͷ������ָ���ͷ��ָ�룬��ͷ����Ϊ��
TwNODE* CreateTwListHead();

//��巨������,����Ϊǰһ�������Ҫ����������ݣ�����ֵΪָ��������ָ��
TwNODE* InsertTwNODE(TwNODE* Head,TwNODE *pre, int data);

//ͷ�巨
TwNODE* InsertTwNODEPre(TwNODE* Head, int data);

//����N���������ϵĽ��
void InitTwList(TwNODE* head, int n);

//�������
void PrintTwList(TwNODE* head);

//ɾ������
void DelTwList_ALL(TwNODE* head);