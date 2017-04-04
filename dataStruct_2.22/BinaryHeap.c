#include "stdafx.h"
#include "BinaryHeap.h"

//最小数据（标记位），用于插入操作，插入数据在树的根部时
int minData=-1024;

//初始化
BinaryHeap* InitBinaryHeap(int MaxSize){
	BinaryHeap* bh;
	bh = (BinaryHeap*)malloc(sizeof(BinaryHeap));

	//为数组分配空间
	bh->group = malloc(sizeof(int)*MaxSize + 1);//由于0位置为标记位

	bh->Capacity = MaxSize;
	bh->Size = 0;
	bh->group[0] = minData;
	return bh;
}

//插入元素,使用上滤法
void InsertBinaryHeap(int data, BinaryHeap* bh){
	if (IsFull(bh))//满则直接返回
		return;
	//bh->Size+1为空穴位置，从空穴位置上滤
	//每次往上寻找父亲位置,如果父亲节点大于插入目的数据，则将父亲节点往下赋值到空穴
	//循环结束时i的位置即为要插入数据的合适空穴位置
	int i;
	for (i = ++bh->Size; bh->group[i/2]>data; i /= 2)
	{
		bh->group[i] = bh->group[i / 2];
	}
	bh->group[i] = data;
}

//删除最小元,使用下滤法
int DeleteMin(BinaryHeap* bh){
	//判空
	if (IsEmpty(bh))//空则返回标志位
	{
		printf("err,BinaryHeap is empty\n");
		return bh->group[0];
	}

	int minData = bh->group[1];//根部
	int lastData = bh->group[bh->Size];//最后一个元素的位置为Size,因为0位置为标志位，Size记录的是元素个数
	bh->Size--;//删除最小元
	int i,Child;
	for (i = 1; i*2 <= bh->Size; i = Child)//循环正常结束则表示i已经到达叶子层，没有儿子节点
	{
		Child = i * 2;//i为当前位置，Child为当前位置的左儿子
		//使用下滤法需要将较小的儿子往上赋值，所以需要选择出小儿子
		//或者当左儿子已经是最后一个元素的时候，则它直接是最小的儿子了（就是没有右儿子）
		if (Child != bh->Size && bh->group[Child]>bh->group[Child + 1])
			Child++;

		//lastData是最后要插入到剩下一个空穴的元素，当然作为这个元素的父节点不能比这个元素要大
		//否则不需要往上赋值,lastData则直接插入这个节点的父亲处（for退出后）
		if (lastData>bh->group[Child])
			bh->group[i] = bh->group[Child];
		else
			break;
	}
	bh->group[i] = lastData;
	return minData;

}

//判断二叉堆是否满
int IsFull(BinaryHeap* bh){
	if (bh->Size>=bh->Capacity)
	{
		return 1;
	}
	return 0;
}

//判断二叉堆是否空
int IsEmpty(BinaryHeap* bh){
	if (bh->Size == 0)
	{
		return 1;
	}
	return 0;
}