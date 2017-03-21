#include "stdafx.h"
#include "TwoWay_List.h"
#include "SingleList.h"
#include "ListStack.h"
void MakeTwList(){
	TwNODE *head = CreateTwListHead();
	InitTwList(head, 5);
	PrintTwList(head);
	DelTwList_ALL(head);
}
void MakeSingleList(){
	NODE *head = CreateListHead();
	InitList(head, 5);
	PrintList(head);
	InsertNode(head,FindNode(head, 0), -5);
	PrintList(head);
	DelList_ALL(head);
	//printf("%d", );
}
void MakeListStack(){
	LiStack* head = InitStack();
	/*
	//�����ڿձ��������Ƿ�������
	printf("top:%d\n", Top(head));
	printf("Pop:%d\n", Pop(head));
	ReleaseStack(head);
	*/
	for (size_t i = 0; i < 4; i++)
	{
		Push(head, i);//0,1,2,3˳����ջ
	}
	printf("top:%d\n", Top(head));
	printf("length:%d\n", head->data);
	ShowInStack(head->next);//��ʾ����Ԫ��
	//����Ԫ�س�ջ
	Pop(head);
	Pop(head);
	printf("top:%d\n", Top(head));
	printf("length:%d\n", head->data);
	ShowInStack(head->next);//��ʾ����Ԫ��

	ReleaseStack(head);

}




/////////////////////////////////////////////////////////////////ϰ������
//���ݽṹ��ε��P53 �ڶ���
//��������ת����ѭ������
NODE* FindLastNodeToHead(NODE *head){
	NODE* currentNode = head;
	while (currentNode->next != NULL)
	{
		currentNode = currentNode->next;
	}
	currentNode->next = head;
	return currentNode;
}
//�ҵ�Ŀ�����ǰһ���ڵ�
NODE* FindPrevioudNode(NODE *tar){
	NODE* currentNode = tar;
	while (currentNode->next != NULL&& currentNode->next != tar)
	{
		currentNode = currentNode->next;
	}
	return currentNode;
}
NODE* SolveNode(NODE *head, NODE *currentNode, NODE *tar){
	//�±�ָ��Ŀ��
	currentNode->next = tar;

	//�ҵ�Ŀ��ڵ���ǰ��һ���ڵ㲢���Ǹ��ڵ�ָ��ͷ�ڵ��Ϊѭ���ڵ�
	if (FindPrevioudNode(tar)!=tar)
	{
		tar = FindPrevioudNode(tar);
		tar->next = head;
	}
	//������ڵ�ʱ��������ڵ��ǰһ���ڵ�����Լ��������ֻʣ��һ��Ԫ����...����
	//����ʱ�����Ԫ�ؿ϶�������һ����ʣ�µ�Ԫ��Ҫ��,���Խ����������һ�����Ԫ�ذ�˳��ӽ�ȥ��û����

	//�޸ľɽڵ㳤��
	head->data--;
	//�±�ı�βָ���
	currentNode->next->next = NULL;
	return tar;
}
//���ݽṹ��ε��P53 �ڶ���
void testP53_2(){
	NODE *head1 = CreateListHead();
	int src1[4] = { 3,4, 5, 7 };
	InitListByGroup(head1, src1, 4);
	NODE *last1=FindLastNodeToHead(head1);
	//InitList(head1, 5);
	//PrintList(head1);

	NODE *head2 = CreateListHead();
	int src2[6] = { 2, 5, 6,10,12,13 };
	InitListByGroup(head2, src2, 6);
	NODE *last2 = FindLastNodeToHead(head2);

	NODE *head3,*currentNode;
	head3 = (NODE*)malloc(sizeof(NODE));
	head3->data = 0;
	head3->next = NULL;
	currentNode = head3;
	//����ֻʣ��һ��
	while (head1->data!=0||head2->data!=0)
	{
		if (last1->data>last2->data)
		{
			last1=SolveNode(head1, currentNode, last1);
			//currentNode->next = last1;
			//last1 = FindPrevioudNode(last1);
			//last1->next = head1;
		}
		else
		{
			last2=SolveNode(head2, currentNode, last2);
		}
		head3->data++;
		currentNode = currentNode->next;
	}

	PrintList(head3);
	
}
/////////////////////////////////////////////////////////////////////
//��ȡ�������ʽ�ĺ����ʾ��ʽ
#define N 5
void testP79(int *result){
	char src[N] = { '1', '2', '3', '*', '+' };
	LiStack* head = InitStack();
	for (size_t i = 0; i < N; i++)
	{
		if (src[i]>='0'&&src[i]<='9')//������
		{
			switch (src[i])
			{
			case '1':{
				Push(head, 1);
				break;
				}
			case '2':{
				Push(head, 2);
				break;
			}
			case '3':{
				Push(head, 3);
				break;
			}
			case '4':{
				Push(head, 4);
				break;
			}
			case '5':{
				Push(head, 5);
				break;
			}
			case '6':{
				Push(head, 6);
				break;
			}
			case '7':{
				Push(head, 7);
				break;
			}
			case '8':{
				Push(head, 8);
				break;
			}
			case '9':{
				Push(head, 9);
				break;
			}
			default:
				break;
			}
		}
		else//���ǲ����������ǲ�����
		{
			//��������������,���ӳ�ջ���
			int oper1 = 0, oper2 = 0;
			oper1 = Pop(head);
			oper2 = Pop(head);
			if (oper1 == -1 || oper2 == -1)//��ʵ��-1���쳣��־�����⣬��Ϊ����һЩ����+-*/��ʱ����������������������ʱֻ֧��+��*����ԭʼ����Ϊ������
			{
				//�쳣
				*result = -1;
				return;
			}
			switch (src[i])
			{
			case '+':{
				Push(head,oper1 + oper2);
				break;
			}

			case '*':{
				Push(head, oper1 * oper2);
				break;
			}

			}
		}
	}
	*result = Top(head);
}
void main(){

	//testP53_2();
	//MakeTwList();
	//MakeSingleList();

	//MakeListStack();
	int result = 0;
	testP79(&result);
	printf("result:%d", result);
}