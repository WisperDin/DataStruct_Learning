#include "stdafx.h"
#include "ListStack.h"


//��ʼ��ջ
LiStack* InitStack(){
	LiStack* head = (LiStack*)malloc(sizeof(LiStack));
	head->data = 0;//���ջ�ĳ���
	head->next = NULL;
	return head;
}

//��ջ,ʹ��ͷ�巨
void Push(LiStack* s, int data){
	LiStack* tar = (LiStack*)malloc(sizeof(LiStack));
	tar->data = data;
	tar->next = s->next;
	s->next = tar;

	s->data++;//�ǵ��޸�ջ����
}

//��ջ
int Pop(LiStack* s){
	int data = 0;
	LiStack* tmp = s->next;//��ʱ�������ڵ�ջ��Ԫ��
	if (tmp)//���tmpΪ�����ջ
	{
		s->next = tmp->next;//�޸ĵ�ǰջ��Ԫ��
		data = tmp->data;//���ɾ���˵�ջ��Ԫ�ص�����
		free(tmp);//�ͷſռ�
		return data;
	}
	return -1;
}

//��ʾջ��Ԫ��
int Top(LiStack* s){
	if (s->next)//�ж��Ƿ��ջ
	{
		return s->next->data;
	}
	return -1;

}

//�ͷ�ջ
void ReleaseStack(LiStack* s){
	LiStack* cur = s->next;//�ڵ�
	while (cur)
	{
		LiStack* tmp = cur;//��סҪɾ���Ľڵ�
		cur = cur->next;//ȥ��һ���ڵ�
		free(tmp);
	}

}

//��ʾ����ջԪ��(�ݹ�ʵ�֣�Ҫ��������׽ڵ�)
void ShowInStack(LiStack* s){
	if (s)
	{
		printf("%d ", s->data);
		ShowInStack(s->next);
	}
}

