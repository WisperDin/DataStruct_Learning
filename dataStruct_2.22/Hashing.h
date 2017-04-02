#pragma once 
#include "stdafx.h"
#include "SingleList.h"
//ɢ�ж���
//���ùؼ���ӳ��Ԫ��
//����ʹ���˷������ӷ���ɢ��
//�����Ԫ��Ϊ���ͣ�����hashӳ��ֱ��ȡmod
typedef NODE* List;
typedef struct 
{
	int TableSize;
	List *theList;
}HashTable;
//ע�⣬theListʵ��Ϊָ��NODE�ṹ��ָ���ָ�룬��typedef��ֹ��ɻ���

//��ʼ��ɢ��
HashTable* InitHashTable(int TableSize);

//����value(�Ȳ���value��ɢ���е�λ�ã����ҵ���λ�����ڸ�λ�õ����������Ƿ���ڴ�value)
//pos����Ϊvalue����ɢ���е�λ��,Ϊ���ò���
List FindHashing(int value, HashTable* hashtb, int *pos);

//ɢ�к�������ΪԪ�ص��ؼ��ֵ�ת��
int Hash(int value, int TableSize);

//����value
//��value���ڣ������κ�����
//����,(���Ʋ��ң��Ȳ���value��ɢ���е�λ��(���߸���pos)��ʹ��ǰ�巨���������м���)
//pos����Ϊvalue����ɢ���е�λ��,Ϊ���ò���
void InsertHashing(int value, HashTable* hashtb,int *pos);//ʹ��posʹ�ü��ټ���hash�Ĵ���

//�ж�ɢ��pos�Ƿ�Ϸ�
//���pos���Ϸ�����0�������
int IsPosCorrect(int pos, int TableSize);


