#pragma once

#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>

typedef char* BSTKeyType;
typedef int BSTValueType;

typedef struct BinarySearchTreeNode
{
	struct BinarySearchTreeNode *left;
	struct BinarySearchTreeNode *right;
	BSTKeyType key;
	BSTValueType value;
}BSTreeNode;
  
//�ǵݹ�
int BSTreeInsert(BSTreeNode **pptree,BSTKeyType key,BSTValueType value); //����
BSTreeNode* BSTreeFind(BSTreeNode** pptree, BSTKeyType key); //����

//�ݹ�
int BSTreeInsertR(BSTreeNode **pptree,BSTKeyType key,BSTValueType value);
BSTreeNode* BSTreeFindR(BSTreeNode** pptree, BSTKeyType key);

void BSTreeInOrder(BSTreeNode** pptree);//�������




void TsetBSTree();