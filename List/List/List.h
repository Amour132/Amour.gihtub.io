#pragma once

#include <stdio.h>
#include <assert.h>
#include <malloc.h>

typedef int LDateType;
typedef struct ListNode
{
	struct ListNode *next;
	struct ListNode *prve;
	LDateType date;
}ListNode;

typedef struct List
{
	ListNode *head;
}List;	

void ListInit(List *lt); //链表初始化
void ListDestory(List *lt); //销毁
void ListPushBack(List *lt,LDateType x);
void ListPopBack(List *lt);
void ListPushFront(List *lt,LDateType x);
void ListPopFront(List *lt);

ListNode *BuyListNode();
ListNode *ListFind(List *lt,LDateType x); //找对应节点
void ListInsert(ListNode *pos,LDateType x); //插入
void ListEarse(ListNode *pos); //删除
int ListEmpty(List *lt);
int ListSize(List *lt);//大小
void ListPrint(List *lt);//打印
void ListClear(List *ls);//清空除头结点外的所有结点

