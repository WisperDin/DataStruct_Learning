#include "stdafx.h"
#include "CircleQueue.h"


//初始化队列
CIRQueue* InitQueue(){
	CIRQueue* queue = (CIRQueue*)malloc(sizeof(CIRQueue));
	queue->front = queue->rear = 0;
	return queue;
}

//进队
void EnQueue(CIRQueue* queue, int tarData){
	//检查是否满队
	if (!IsQueueFull(queue))
	{
		//尾指针后移然后写入数据
		queue->rear = (queue->rear + 1) % MAXSIZE;
		queue->data[queue->rear] = tarData;
	}

}

//出队
int DeQueue(CIRQueue* queue){
	//判断是否空队列
	if (!IsQueueEmpty(queue))
	{
		//头指针后移然后获得数据
		queue->front = (queue->front + 1) % MAXSIZE;
		int headData = queue->data[queue->front];
		//其实不需要擦除原来数据?
		queue->data[queue->front] = 0;
		return headData;
	}
	return -1;
}

//队列判空
int IsQueueEmpty(CIRQueue* queue){
	//判断是否空队列
	if (queue->front == queue->rear)
		return 1;
	return 0;
}

//队列判满
int IsQueueFull(CIRQueue* queue){
	//检查是否满队
	if (queue->front == (queue->rear + 1) % MAXSIZE)
		return 1;
	return 0;
}

//显示队列中所有元素
void ShowQueue(CIRQueue* queue){
	if (!IsQueueEmpty(queue))
	{
		int p = (queue->front + 1) % MAXSIZE;
		while (p <= queue->rear)
		{
			printf("%d ", queue->data[p]);
			p = (p + 1) % MAXSIZE;
		}
	}
	
}

//释放队列控件
void FreeQueue(CIRQueue* queue){
	free(queue);
}