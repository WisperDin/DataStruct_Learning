#include "stdafx.h"
#include "Tree.h"

//��ʼ��root
TreeNode* InitTree(){
	return CreateNode('r');
}

//�Ӻ�׺���ʽ�����
//TreeNode* InitTreeFromBac(int *src, int length){
//
//
//}

//��������ݹ飩
void ListDir(TreeNode* node,int Depth){
	if (node!=NULL)
		PrintWithDepth(node->data, Depth);
	//�����һ���ڵ������еĶ��Ӻ�ſ�ʼ�������ڵ���ֵܽڵ�

	//���򲽽�
	while (node->firstChild != NULL)
	{
		ListDir(node->firstChild, Depth + 1);
		node->firstChild = node->firstChild->firstChild;
	}
	//���򲽽�
	while (node->nextSibling != NULL)
	{
		ListDir(node->nextSibling, Depth);
		node->nextSibling = node->nextSibling->nextSibling;
	}
}

TreeNode* CreateNode(char key){
	TreeNode* tn;
	tn = (TreeNode*)malloc(sizeof(TreeNode));
	tn->data = key;
	tn->firstChild = NULL;
	tn->nextSibling = NULL;
	return tn;
}

//�����������룬���Ѿ����ڶ���/�ֵ�ʱ�򸲸�

//�����ڵ����һ������
TreeNode* InsertChlidTreeNode(TreeNode* tree, char key){
	tree->firstChild = CreateNode(key);
	return tree->firstChild;
}

//�����ڵ����һ���ֵ�
TreeNode* InsertSibTreeNode(TreeNode* tree, char key){
	tree->nextSibling = CreateNode(key);
	return tree->nextSibling;
}

//��Ȳ�ͬ�Ľڵ������������ͬ
void PrintWithDepth(char key, int depth){
	for (size_t i = 0; i < depth; i++)
	{
		printf("|--");
	}
	printf("%c",key);
	printf("\n");
}