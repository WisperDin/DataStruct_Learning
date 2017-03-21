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
	//测试在空表的情况下是否会出问题
	printf("top:%d\n", Top(head));
	printf("Pop:%d\n", Pop(head));
	ReleaseStack(head);
	*/
	for (size_t i = 0; i < 4; i++)
	{
		Push(head, i);//0,1,2,3顺序入栈
	}
	printf("top:%d\n", Top(head));
	printf("length:%d\n", head->data);
	ShowInStack(head->next);//显示所有元素
	//两个元素出栈
	Pop(head);
	Pop(head);
	printf("top:%d\n", Top(head));
	printf("length:%d\n", head->data);
	ShowInStack(head->next);//显示所有元素

	ReleaseStack(head);

}




/////////////////////////////////////////////////////////////////习题内容
//数据结构严蔚敏P53 第二题
//将单链表转换成循环链表
NODE* FindLastNodeToHead(NODE *head){
	NODE* currentNode = head;
	while (currentNode->next != NULL)
	{
		currentNode = currentNode->next;
	}
	currentNode->next = head;
	return currentNode;
}
//找到目标结点的前一个节点
NODE* FindPrevioudNode(NODE *tar){
	NODE* currentNode = tar;
	while (currentNode->next != NULL&& currentNode->next != tar)
	{
		currentNode = currentNode->next;
	}
	return currentNode;
}
NODE* SolveNode(NODE *head, NODE *currentNode, NODE *tar){
	//新表指向目标
	currentNode->next = tar;

	//找到目标节点往前的一个节点并将那个节点指向头节点成为循环节点
	if (FindPrevioudNode(tar)!=tar)
	{
		tar = FindPrevioudNode(tar);
		tar->next = head;
	}
	//如果等于的时候则这个节点的前一个节点就是自己（这个表只剩这一个元素了...），
	//那这时候这个元素肯定比另外一个表剩下的元素要大,所以接下来会把另一个表的元素按顺序加进去，没问题

	//修改旧节点长度
	head->data--;
	//新表的表尾指向空
	currentNode->next->next = NULL;
	return tar;
}
//数据结构严蔚敏P53 第二题
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
	//链表不只剩下一个
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
//读取算术表达式的后序表示形式
void testP79(){

}
void main(){

	//testP53_2();
	//MakeTwList();
	//MakeSingleList();

	MakeListStack();
}