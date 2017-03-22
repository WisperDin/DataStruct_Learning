#pragma once 
#include "stdafx.h"
#define MAXSIZE 10
//���ݽṹ���壺
//ѭ�����У�ͷָ��ָ���һ��Ԫ�ص�ǰһ���ռ䣬βָ��ָ�����һ��Ԫ�أ�
//�пգ���ͷβָ�����
//��������βָ��ĺ�һλ=ͷָ��
//�ص㣬����һ���洢�ռ�
typedef struct CircleQueue{
	int data[MAXSIZE];
	int front;//����ͷָ��
	int rear;//����βָ��
}CIRQueue;

//��ʼ������
CIRQueue* InitQueue();

//����
void EnQueue(CIRQueue* queue,int tarData);

//����
int DeQueue(CIRQueue* queue);

//�����п�
int IsQueueEmpty(CIRQueue* queue);

//��������
int IsQueueFull(CIRQueue* queue);

//��ʾ����������Ԫ��
void ShowQueue(CIRQueue* queue);

//�ͷŶ��пؼ�
void FreeQueue(CIRQueue* queue);