#include "BinarySearchTree.h"

BSTreeNode* BuyBSTreeNode(BSTKeyType key,BSTValueType value)
{
	BSTreeNode *node = (BSTreeNode *)malloc(sizeof(BSTreeNode));
	node->left = NULL;
	node->right = NULL;
	node->value = value;
	node->key = (BSTKeyType)malloc(strlen(key)+1);
	strcpy(node->key,key);
	return node;
}

int BSTreeInsert(BSTreeNode **pptree,BSTKeyType key,BSTValueType value)
{
	BSTreeNode *cur;
	BSTreeNode *parent;
	if(*pptree == NULL)
	{
		*pptree = BuyBSTreeNode(key,value);
		return 1;
	}

	cur = *pptree;
	while(cur)
	{
		if(strcmp(cur->key,key) < 0)
		{
			parent = cur;
			cur = cur->right;
		}
		else if(strcmp(cur->key,key) > 0)
		{
			parent = cur;
			cur = cur->left;
		}
		else
		{
			return 0;
		}
	}
	if(strcmp(parent->key,key) > 0)
	{
		parent->left = BuyBSTreeNode(key,value);
	}
	else
	{
		parent->right = BuyBSTreeNode(key,value);
	}

	return 1;
}

BSTreeNode* BSTreeFind(BSTreeNode** pptree, BSTKeyType key)
{
	BSTreeNode *cur;
	cur = *pptree;
	while(cur)
	{
		if(strcmp(cur->key,key) > 0)
		{
			cur = cur->left;
		}
		else if(strcmp(cur->key,key) < 0)
		{
			cur = cur->right;
		}
		else
		{
			return cur;
		}
	}
	return NULL;
}

void BSTreeInOrder(BSTreeNode** pptree)
{
	if(*pptree == NULL)
	{
		return ;
	}
	BSTreeInOrder(&((*pptree)->left));
	printf("%s:%d\n",(*pptree)->key,(*pptree)->value);
	BSTreeInOrder(&((*pptree)->right));
}

int BSTreeInsertR(BSTreeNode **pptree,BSTKeyType key,BSTValueType value)
{
	BSTreeNode *cur = *pptree;
	if(*pptree == NULL)
	{
		*pptree = BuyBSTreeNode(key,value);
		return 1;
	}
	if(strcmp(cur->key,key) > 0)
	{
		BSTreeInsertR(&(cur->left),key,value);
	}
	else if(strcmp(cur->key,key) < 0)
	{
		BSTreeInsertR(&(cur->right),key,value);
	}
	return 0;
}

BSTreeNode* BSTreeFindR(BSTreeNode** pptree, BSTKeyType key)
{
	BSTreeNode *cur = *pptree;
	if(cur == NULL)
	{
		return NULL;
	}
	else if(strcmp(cur->key,key) > 0)
	{
		BSTreeFindR(&(cur->left),key);
	}
	else if(strcmp(cur->key,key) < 0)
	{
		BSTreeFindR(&(cur->right),key);
	}
	else
	{
		return cur;
	}
	return NULL;
}




void TsetBSTree()
{
	char str[20] = {'0'};
	BSTreeNode *tree = NULL;
	while(1)
	{
		BSTreeNode *node;
		scanf("%s",str);
		if(strcmp(str,"exit") == 0)
		{
			break;
		}
		node = BSTreeFindR(&tree,str);
		if(node)
		{
			node->value++;
		}
		else
		{
			BSTreeInsertR(&tree,str,1);
		}
	}
	BSTreeInOrder(&tree);
}