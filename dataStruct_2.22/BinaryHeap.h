#pragma once
#include "stdafx.h"
//����Ѷ���
//ͨ����ȫ������������ʵ��ͨ������
//���������⴦��iλ�õ�Ԫ�أ��������λ��2i,�Ҷ���λ��(2i+1),����λ��(i/2)
//ʵ��Ԫ����1��ʼ�洢��0Ϊ���λ��ע��������һ������Ԫ�ص�λ��ΪSize��
typedef struct {
	int Capacity;//�������
	int Size;//��ǰ��С
	int *group;//�����ݵ�����
}BinaryHeap;
//��ʼ��
BinaryHeap* InitBinaryHeap(int MaxSize);

//����Ԫ��,ʹ�����˷�
void InsertBinaryHeap(int data, BinaryHeap* bh);

//ɾ����СԪ,ʹ�����˷�
int DeleteMin(BinaryHeap* bh);

//�ж϶�����Ƿ���
int IsFull(BinaryHeap* bh);

//�ж϶�����Ƿ��
int IsEmpty(BinaryHeap* bh);

//��С���ݣ����λ�������ڲ���������������������ĸ���ʱ
int minData;