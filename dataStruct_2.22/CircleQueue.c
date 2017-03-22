#include "stdafx.h"
#include "CircleQueue.h"


//��ʼ������
CIRQueue* InitQueue(){
	CIRQueue* queue = (CIRQueue*)malloc(sizeof(CIRQueue));
	queue->front = queue->rear = 0;
	return queue;
}

//����
void EnQueue(CIRQueue* queue, int tarData){
	//����Ƿ�����
	if (!IsQueueFull(queue))
	{
		//βָ�����Ȼ��д������
		queue->rear = (queue->rear + 1) % MAXSIZE;
		queue->data[queue->rear] = tarData;
	}

}

//����
int DeQueue(CIRQueue* queue){
	//�ж��Ƿ�ն���
	if (!IsQueueEmpty(queue))
	{
		//ͷָ�����Ȼ��������
		queue->front = (queue->front + 1) % MAXSIZE;
		int headData = queue->data[queue->front];
		//��ʵ����Ҫ����ԭ������?
		queue->data[queue->front] = 0;
		return headData;
	}
	return -1;
}

//�����п�
int IsQueueEmpty(CIRQueue* queue){
	//�ж��Ƿ�ն���
	if (queue->front == queue->rear)
		return 1;
	return 0;
}

//��������
int IsQueueFull(CIRQueue* queue){
	//����Ƿ�����
	if (queue->front == (queue->rear + 1) % MAXSIZE)
		return 1;
	return 0;
}

//��ʾ����������Ԫ��
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

//�ͷŶ��пؼ�
void FreeQueue(CIRQueue* queue){
	free(queue);
}