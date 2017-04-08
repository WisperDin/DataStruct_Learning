#pragma once
#include "stdafx.h"


typedef struct tn {
	char data;
	struct tn* firstChild;
	struct tn* nextSibling;
}TreeNode;

//初始化root
TreeNode* InitTree();

//从后缀表达式获得树
//TreeNode* InitTreeFromBac(int *src,int length);

//输出树
void ListDir(TreeNode* node, int Depth);

//创建一个树的节点
TreeNode* CreateNode(char key);

//往树节点插入一个儿子
TreeNode* InsertChlidTreeNode(TreeNode* tree, char key);

//往树节点插入一个兄弟
TreeNode* InsertSibTreeNode(TreeNode* tree, char key);

//深度不同的节点输出的缩进不同
void PrintWithDepth(char key, int depth);