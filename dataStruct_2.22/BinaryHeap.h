#pragma once
#include "stdafx.h"
//二叉堆定义
//通过完全二叉树构建，实现通过数组
//数组上任意处于i位置的元素，其左儿子位于2i,右儿子位于(2i+1),父亲位于(i/2)
//实际元素由1开始存储，0为标记位（注，因此最后一个数组元素的位置为Size）
typedef struct {
	int Capacity;//最大容量
	int Size;//当前大小
	int *group;//存数据的数组
}BinaryHeap;
//初始化
BinaryHeap* InitBinaryHeap(int MaxSize);

//插入元素,使用上滤法
void InsertBinaryHeap(int data, BinaryHeap* bh);

//删除最小元,使用下滤法
int DeleteMin(BinaryHeap* bh);

//判断二叉堆是否满
int IsFull(BinaryHeap* bh);

//判断二叉堆是否空
int IsEmpty(BinaryHeap* bh);

//最小数据（标记位），用于插入操作，插入数据在树的根部时
int minData;