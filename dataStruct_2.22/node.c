#include "stdafx.h"
#include "TwoWay_List.h"
#include "SingleList.h"
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
void main(){


	//MakeTwList();
	MakeSingleList();

}