#include "stdafx.h"
#include "Tree.h"

//初始化root
TreeNode* InitTree(){
	return CreateNode('r');
}

//从后缀表达式获得树
//TreeNode* InitTreeFromBac(int *src, int length){
//
//
//}

//输出树（递归）
void ListDir(TreeNode* node,int Depth){
	if (node!=NULL)
		PrintWithDepth(node->data, Depth);
	//输出完一个节点下所有的儿子后才开始输出这个节点的兄弟节点

	//纵向步进
	while (node->firstChild != NULL)
	{
		ListDir(node->firstChild, Depth + 1);
		node->firstChild = node->firstChild->firstChild;
	}
	//横向步进
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

//以下两个插入，当已经存在儿子/兄弟时则覆盖

//往树节点插入一个儿子
TreeNode* InsertChlidTreeNode(TreeNode* tree, char key){
	tree->firstChild = CreateNode(key);
	return tree->firstChild;
}

//往树节点插入一个兄弟
TreeNode* InsertSibTreeNode(TreeNode* tree, char key){
	tree->nextSibling = CreateNode(key);
	return tree->nextSibling;
}

//深度不同的节点输出的缩进不同
void PrintWithDepth(char key, int depth){
	for (size_t i = 0; i < depth; i++)
	{
		printf("|--");
	}
	printf("%c",key);
	printf("\n");
}