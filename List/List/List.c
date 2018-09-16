#include "List.h"

ListNode *BuyListNode()
{
	ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
	if(newNode == NULL)
	{
		perror("fail for mallc\n");
	}
	return newNode;
}

void ListInit(List *lt)
{
	assert(lt);
	lt->head = BuyListNode();
	lt->head->next = lt->head;
	lt->head->prve = lt->head;
}

ListNode *ListFind(List *lt,LDateType x)
{
	ListNode *cur = lt->head->next;
	assert(lt);
	while(cur != lt->head)
	{
		if(cur->date == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void ListEarse(ListNode *pos)
{
	ListNode *prve = pos->prve;
	ListNode *next = pos->next;
	assert(pos);
	free(pos);
	pos = NULL;
	prve->next = next;
	next->prve = prve;
}  

void ListInsert(ListNode *pos,LDateType x)
{
	ListNode* prve = pos->prve;
	ListNode *newNode = BuyListNode();
	assert(pos);
	newNode->date = x;
	prve->next = newNode;
	newNode->prve = prve;
	newNode->next = pos;
	pos->prve = newNode;
}

void ListPushBack(List *lt,LDateType x)
{
	ListInsert(lt->head,x);
}

void ListPopBack(List *lt)
{
	ListEarse(lt->head->prve);
}

void ListPushFront(List *lt,LDateType x)
{
	ListInsert(lt->head->next,x);
}

void ListPopFront(List *lt)
{
	ListEarse(lt->head->next);
}

int ListEmpty(List *lt)
{
	return lt->head == NULL ? 0 : 1;
}

int ListSize(List *lt)
{
	int count = 0;
	ListNode *cur = lt->head->next;
	while(cur != lt->head)
	{
		count++;
		cur = cur->next;
	}
	return count;
}

void ListPrint(List *lt)
{
	ListNode *cur = lt->head->next;
	while(cur != lt->head)
	{
		printf("%d  ",cur->date);
		cur = cur->next;
	}
	printf("\n");
}

void ListClear(List *lt)//先清除头结点外的所有节点
{
	ListNode *cur = lt->head->next;
	ListNode *next;
	assert(lt);
	while(cur != lt->head)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	lt->head->next = lt->head;
	lt->head->prve = lt->head;
}

void ListDestory(List *lt)//清头结点
{
	ListClear(lt);
	free(lt->head);
	lt->head = NULL;
}


