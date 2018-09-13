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
  
//非递归
int BSTreeInsert(BSTreeNode **pptree,BSTKeyType key,BSTValueType value); //插入
BSTreeNode* BSTreeFind(BSTreeNode** pptree, BSTKeyType key); //查找

//递归
int BSTreeInsertR(BSTreeNode **pptree,BSTKeyType key,BSTValueType value);
BSTreeNode* BSTreeFindR(BSTreeNode** pptree, BSTKeyType key);

void BSTreeInOrder(BSTreeNode** pptree);//中序遍历




void TsetBSTree();