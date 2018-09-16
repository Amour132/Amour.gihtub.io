#pragma once

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdlib.h>

typedef int DateType;
typedef struct Node
{
	DateType date;
	struct Node *next;
}Node,*pNode,List,*pList;

void LinkListInit(pList *pplist);  //初始化
pNode BuyNode(DateType d);
void LinkListDestory(pList *pplist);//销毁
void LinkListPushBack(pList *pplist,DateType d); //尾插
void LinkListPopBack(pList *pplist); //尾删
void LinkListPushFront(pList *pplist,DateType d);//头插
void LinkListPopFront(pList *pplist);//头删
pNode Find(pList *pplist,DateType d); //查找

void Insert(pList *pplist,pNode pos,DateType d); //在指定位置之前插入
void Erase(pList *pplist,pNode pos);//指定位置删除
void Remove(pList *pplist,DateType d); //删除指定元素
void RemoveAll(pList *pplist,DateType d);//删除指定所有元素
int GetLength(pList *pplist);

void LinkListPrint(pList *pplist);

void TestLinkList();


//链表面试题
///////////////////////////////////////////////////////////////////////////////////////////////////////////

////1. 比较顺序表和链表的优缺点 

//链表可以频繁插入删除查找效率比顺序表高但是不能随机访问
//顺序表只能尾插不能头插而且增删查的效率很低，但是可以随机访问

void PrintTailToHead(pList *pplist); //2. 从尾到头打印单链表
void EraseNotTail(pNode pos); //3. 删除一个无头单链表的非尾节点 
void InsertNode(pNode pos,DateType d);  //4. 在无头单链表的一个节点前插入一个节点 
pNode JosephCycle(pList * pplist, int num);  //5. 单链表实现约瑟夫环 
void ReverseList(pList* pplist); //6. 逆置反转单链表 
void BubbleSort(pList * pplist); ////7. 单链表排序（冒泡排序） 
pList Merge(pList list1, pList list2);  //8. 合并两个有序链表,合并后依然有序 
pNode FindMidNode(pList *pplist);  //9. 查找单链表的中间节点，要求只能遍历一次链表 
pNode FindLastKNode(pList *pplist, int k); //10. 查找单链表的倒数第k个节点，要求只能遍历一次链表 

void Test();