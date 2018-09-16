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

void LinkListInit(pList *pplist);  //��ʼ��
pNode BuyNode(DateType d);
void LinkListDestory(pList *pplist);//����
void LinkListPushBack(pList *pplist,DateType d); //β��
void LinkListPopBack(pList *pplist); //βɾ
void LinkListPushFront(pList *pplist,DateType d);//ͷ��
void LinkListPopFront(pList *pplist);//ͷɾ
pNode Find(pList *pplist,DateType d); //����

void Insert(pList *pplist,pNode pos,DateType d); //��ָ��λ��֮ǰ����
void Erase(pList *pplist,pNode pos);//ָ��λ��ɾ��
void Remove(pList *pplist,DateType d); //ɾ��ָ��Ԫ��
void RemoveAll(pList *pplist,DateType d);//ɾ��ָ������Ԫ��
int GetLength(pList *pplist);

void LinkListPrint(pList *pplist);

void TestLinkList();


//����������
///////////////////////////////////////////////////////////////////////////////////////////////////////////

////1. �Ƚ�˳�����������ȱ�� 

//�������Ƶ������ɾ������Ч�ʱ�˳���ߵ��ǲ����������
//˳���ֻ��β�岻��ͷ�������ɾ���Ч�ʺܵͣ����ǿ����������

void PrintTailToHead(pList *pplist); //2. ��β��ͷ��ӡ������
void EraseNotTail(pNode pos); //3. ɾ��һ����ͷ������ķ�β�ڵ� 
void InsertNode(pNode pos,DateType d);  //4. ����ͷ�������һ���ڵ�ǰ����һ���ڵ� 
pNode JosephCycle(pList * pplist, int num);  //5. ������ʵ��Լɪ�� 
void ReverseList(pList* pplist); //6. ���÷�ת������ 
void BubbleSort(pList * pplist); ////7. ����������ð������ 
pList Merge(pList list1, pList list2);  //8. �ϲ�������������,�ϲ�����Ȼ���� 
pNode FindMidNode(pList *pplist);  //9. ���ҵ�������м�ڵ㣬Ҫ��ֻ�ܱ���һ������ 
pNode FindLastKNode(pList *pplist, int k); //10. ���ҵ�����ĵ�����k���ڵ㣬Ҫ��ֻ�ܱ���һ������ 

void Test();