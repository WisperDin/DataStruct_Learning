#include "stdafx.h"
#include "Hashing.h"


//��ʼ��ɢ��
HashTable* InitHashTable(int TableSize){
	HashTable *hashtb;
	//Ϊɢ�з���ռ�
	hashtb = (HashTable*)malloc(sizeof(HashTable));
	hashtb->TableSize = TableSize;
	//Ϊɢ����ָ�����������ָ�����ռ�
	hashtb->theList = (List*)malloc(sizeof(List*)*hashtb->TableSize);
	//Ϊÿ����������һ���ռ���Ϊͷ�ڵ�
	for (size_t i = 0; i < hashtb->TableSize; i++)
	{
		hashtb->theList[i] = (List)malloc(sizeof(List));
		hashtb->theList[i]->data = 0;
		hashtb->theList[i]->next = NULL;
	}
	return hashtb;
}

//����value(�Ȳ���value��ɢ���е�λ�ã����ҵ���λ�����ڸ�λ�õ����������Ƿ���ڴ�value)
List FindHashing(int value, HashTable* hashtb,int *pos){
	//�ҵ���Ӧvalueλ�õ������ͷ������ʹ�ø���pos��
	if (IsPosCorrect(*pos, hashtb->TableSize) != 0)//���pos���Ϸ�����0�������
	{
		*pos = Hash(value, hashtb->TableSize);
	}
	List findList = hashtb->theList[*pos];

	//1.��������ʵ�ֵĲ���
	//NODE* curNode = findList->next;
	////�����������ҵ���Ӧ��value���˳�ѭ��
	//while (curNode != NULL&&curNode->data!=value)
	//{
	//	curNode = curNode->next;
	//}
	//return curNode;

	//2.��Ϊ�Ѿ�ʵ���˵�����Ĳ��ң�����ֱ���ú���
	NODE* curNode = FindNode(findList, value);
	return curNode;
}

//ɢ�к�������ΪԪ�ص��ؼ��ֵ�ת��
int Hash(int value, int TableSize){
	//���ص�ֵ0~TableSize-1
	return value % TableSize;
}

//����value
//��value���ڣ������κ�����
//����,(���Ʋ��ң��Ȳ���value��ɢ���е�λ��(���߸���pos)��ʹ��ǰ�巨���������м���)
void InsertHashing(int value, HashTable* hashtb, int *pos){
	if (FindHashing(value, hashtb, pos) != NULL)//������value�Ѿ�����
	{
		return;
	}
	//�ҵ���Ӧvalueλ�õ������ͷ������ʹ�ø���pos��
	if (IsPosCorrect(*pos,hashtb->TableSize)!=0)//���pos���Ϸ�����0�������
	{
		*pos = Hash(value, hashtb->TableSize);
	}
	List findList = hashtb->theList[*pos];
	//ʹ��ͷ�巨����ڵ�
	InsertNodePre(findList, value);
}

//�ж�ɢ��pos�Ƿ�Ϸ�
//���pos���Ϸ�����0�������
int IsPosCorrect(int pos, int TableSize){
	if (pos<0 || pos >= TableSize)//λ�ò��Ϸ�
	{
		//printf("pos not correct");
		return -1;
	}
	return 0;
}