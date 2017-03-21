#include "stdafx.h"
#include "ListStack.h"


//初始化栈
LiStack* InitStack(){
	LiStack* head = (LiStack*)malloc(sizeof(LiStack));
	head->data = 0;//存放栈的长度
	head->next = NULL;
	return head;
}

//入栈,使用头插法
void Push(LiStack* s, int data){
	LiStack* tar = (LiStack*)malloc(sizeof(LiStack));
	tar->data = data;
	tar->next = s->next;
	s->next = tar;

	s->data++;//记得修改栈长度
}

//出栈
int Pop(LiStack* s){
	int data = 0;
	LiStack* tmp = s->next;//暂时保存现在的栈顶元素
	if (tmp)//如果tmp为空则空栈
	{
		s->next = tmp->next;//修改当前栈顶元素
		data = tmp->data;//获得删除了的栈顶元素的数据
		free(tmp);//释放空间
		return data;
	}
	return -1;
}

//显示栈顶元素
int Top(LiStack* s){
	if (s->next)//判断是否空栈
	{
		return s->next->data;
	}
	return -1;

}

//释放栈
void ReleaseStack(LiStack* s){
	LiStack* cur = s->next;//节点
	while (cur)
	{
		LiStack* tmp = cur;//记住要删除的节点
		cur = cur->next;//去下一个节点
		free(tmp);
	}

}

//显示所有栈元素(递归实现，要求传入的是首节点)
void ShowInStack(LiStack* s){
	if (s)
	{
		printf("%d ", s->data);
		ShowInStack(s->next);
	}
}

