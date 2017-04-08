#pragma once
#include "stdafx.h"


typedef struct tn {
	char data;
	struct tn* firstChild;
	struct tn* nextSibling;
}TreeNode;

//��ʼ��root
TreeNode* InitTree();

//�Ӻ�׺���ʽ�����
//TreeNode* InitTreeFromBac(int *src,int length);

//�����
void ListDir(TreeNode* node, int Depth);

//����һ�����Ľڵ�
TreeNode* CreateNode(char key);

//�����ڵ����һ������
TreeNode* InsertChlidTreeNode(TreeNode* tree, char key);

//�����ڵ����һ���ֵ�
TreeNode* InsertSibTreeNode(TreeNode* tree, char key);

//��Ȳ�ͬ�Ľڵ������������ͬ
void PrintWithDepth(char key, int depth);