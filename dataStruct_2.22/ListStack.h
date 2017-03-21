#pragma once
#include "stdafx.h"
//�ṹ���壺
//��ջ,�б�ͷ��ʹ��ͷ�巨���Ԫ�أ�ջ��Ϊ�׽ڵ�

typedef struct LiStack{
	int data;
	struct LiStack* next;
}LiStack;

//��ʼ��ջ
LiStack* InitStack();

//��ջ
void Push(LiStack* s, int data);

//��ջ
int Pop(LiStack* s);

//��ʾջ��Ԫ��
int Top(LiStack* s);

//�ͷ�ջ
void ReleaseStack(LiStack* s);

//��ʾ����ջԪ��(�ݹ�ʵ�֣�Ҫ��������׽ڵ�)
void ShowInStack(LiStack* s);

