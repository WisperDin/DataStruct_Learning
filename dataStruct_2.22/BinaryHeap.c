#include "stdafx.h"
#include "BinaryHeap.h"

//��С���ݣ����λ�������ڲ���������������������ĸ���ʱ
int minData=-1024;

//��ʼ��
BinaryHeap* InitBinaryHeap(int MaxSize){
	BinaryHeap* bh;
	bh = (BinaryHeap*)malloc(sizeof(BinaryHeap));

	//Ϊ�������ռ�
	bh->group = malloc(sizeof(int)*MaxSize + 1);//����0λ��Ϊ���λ

	bh->Capacity = MaxSize;
	bh->Size = 0;
	bh->group[0] = minData;
	return bh;
}

//����Ԫ��,ʹ�����˷�
void InsertBinaryHeap(int data, BinaryHeap* bh){
	if (IsFull(bh))//����ֱ�ӷ���
		return;
	//bh->Size+1Ϊ��Ѩλ�ã��ӿ�Ѩλ������
	//ÿ������Ѱ�Ҹ���λ��,������׽ڵ���ڲ���Ŀ�����ݣ��򽫸��׽ڵ����¸�ֵ����Ѩ
	//ѭ������ʱi��λ�ü�ΪҪ�������ݵĺ��ʿ�Ѩλ��
	int i;
	for (i = ++bh->Size; bh->group[i/2]>data; i /= 2)
	{
		bh->group[i] = bh->group[i / 2];
	}
	bh->group[i] = data;
}

//ɾ����СԪ,ʹ�����˷�
int DeleteMin(BinaryHeap* bh){
	//�п�
	if (IsEmpty(bh))//���򷵻ر�־λ
	{
		printf("err,BinaryHeap is empty\n");
		return bh->group[0];
	}

	int minData = bh->group[1];//����
	int lastData = bh->group[bh->Size];//���һ��Ԫ�ص�λ��ΪSize,��Ϊ0λ��Ϊ��־λ��Size��¼����Ԫ�ظ���
	bh->Size--;//ɾ����СԪ
	int i,Child;
	for (i = 1; i*2 <= bh->Size; i = Child)//ѭ�������������ʾi�Ѿ�����Ҷ�Ӳ㣬û�ж��ӽڵ�
	{
		Child = i * 2;//iΪ��ǰλ�ã�ChildΪ��ǰλ�õ������
		//ʹ�����˷���Ҫ����С�Ķ������ϸ�ֵ��������Ҫѡ���С����
		//���ߵ�������Ѿ������һ��Ԫ�ص�ʱ������ֱ������С�Ķ����ˣ�����û���Ҷ��ӣ�
		if (Child != bh->Size && bh->group[Child]>bh->group[Child + 1])
			Child++;

		//lastData�����Ҫ���뵽ʣ��һ����Ѩ��Ԫ�أ���Ȼ��Ϊ���Ԫ�صĸ��ڵ㲻�ܱ����Ԫ��Ҫ��
		//������Ҫ���ϸ�ֵ,lastData��ֱ�Ӳ�������ڵ�ĸ��״���for�˳���
		if (lastData>bh->group[Child])
			bh->group[i] = bh->group[Child];
		else
			break;
	}
	bh->group[i] = lastData;
	return minData;

}

//�ж϶�����Ƿ���
int IsFull(BinaryHeap* bh){
	if (bh->Size>=bh->Capacity)
	{
		return 1;
	}
	return 0;
}

//�ж϶�����Ƿ��
int IsEmpty(BinaryHeap* bh){
	if (bh->Size == 0)
	{
		return 1;
	}
	return 0;
}