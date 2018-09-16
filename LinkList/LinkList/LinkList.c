#include "LinkList.h"


//链表基本接口
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void LinkListInit(pList *pplist)
{
	assert(*pplist);
	*pplist = NULL;
}

pNode BuyNode(DateType d)
{
	pNode newNode;
	newNode = (Node *)malloc(sizeof(Node));
	if(newNode == NULL)
	{
		perror("fail for malloc\n");
		exit(0);
	}
	newNode->date = d;
	newNode->next = NULL;
	return newNode;
}

void LinkListDestory(pList *pplist)
{
	pNode cur;
	assert(pplist);
	cur = *pplist;
	while(cur)
	{
		pNode del = cur;
		cur = cur->next;
		free(del);
		del = NULL;
	}
}

void LinkListPushBack(pList *pplist,DateType d)
{
	pNode newNode;
	pNode head;
	assert(pplist);
    newNode = BuyNode(d);
	head = *pplist;
	if(head == NULL)
	{
		*pplist = newNode;
		return;
	}
	while(head->next != NULL)
	{
		head = head->next;
	}
	head->next = newNode;
}

void LinkListPrint(pList *pplist)
{
	pNode cur = *pplist;
	while(cur)
	{
		printf("%d->",cur->date);
		cur = cur->next;
	}
	printf("over");
	printf("\n");
}

void LinkListPopBack(pList *pplist)
{
	pNode cur;
	pNode prev;
	assert(pplist);
	cur = *pplist;
	if(cur->next == NULL)
	{
		free(cur);
		cur = NULL;
		return;
	}
	while(cur->next != NULL)
	{
		prev = cur;
		cur = cur->next;
	}
	free(cur);
	cur = NULL;
	prev->next = NULL;
}

void LinkListPushFront(pList *pplist,DateType d)
{
	pNode newNode;
	assert(pplist);
	newNode = BuyNode(d);
	newNode->next = (*pplist);
	(*pplist) = newNode;
}

void LinkListPopFront(pList *pplist)
{
	pNode cur = *pplist;
	assert(pplist);
	*pplist = cur->next;
	free(cur);
	cur = NULL;
}

pNode Find(pList *pplist,DateType d)
{
	pNode cur = *pplist;
	assert(pplist);
	while(cur)
	{
		if(cur->date == d)
		{
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}
	return NULL;
}

void Insert(pList *pplist,pNode pos,DateType d)
{
	pNode cur = *pplist;
	pNode prev = cur;
	pNode newNode;
	assert(pplist);
	if(*pplist == pos)
	{
		LinkListPushFront(&(*pplist),d);
		return;
	}
	newNode = BuyNode(d);
	while(cur)
	{
		if(cur->date == pos->date)
		{
			prev->next = newNode;
			newNode->next = cur;
			return;
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}

//void Erase(pList *pplist,pNode pos)
//{
//	pNode cur = *pplist;
//	pNode prev = cur;
//	assert(pplist);
//	if(pos == (*pplist))
//	{
//		LinkListPopFront(&(*pplist));
//		return;
//	}
//	while(cur)
//	{
//		if(cur->date == pos->date)
//		{
//			prev->next = cur->next;
//			free(cur);
//			cur = NULL;
//			return;
//		}
//		else
//		{
//			prev = cur;
//			cur = cur->next;
//		}
//	}
//}

void Erase(pList *pplist,pNode pos)
{
	pNode del;
	assert(pplist);
	if(pos->next == NULL)
	{
		LinkListPopBack(&(*pplist));
		return;
	}
	del = pos->next;
	pos->date = del->date;
	pos->next = del->next;
	free(del);
	del = NULL;
}

void Remove(pList *pplist,DateType d)
{
	pNode cur;
	pNode del;
	assert(pplist);
	cur = Find(&(*pplist),d);
	if(cur->next == NULL)
	{
		LinkListPopBack(&(*pplist));
		return;
	}
	del = cur->next;
	cur->date = del->date;
	cur->next = del->next;
    free(del);
	del = NULL;
}

void RemoveAll(pList *pplist,DateType d)
{
	pNode cur;
	pNode next;
	assert(pplist);
	while((*pplist)->date == d)
	{
		LinkListPopFront(&(*pplist));
	}
	cur = *pplist;
	next = cur->next;
	while(next!= NULL)
	{
		while(next != NULL && next->date == d)
		{
			cur->next = next->next;
			free(next);
			next = NULL;
			next = cur->next;
		}
		if(next == NULL)
		{
			break;
		}
		cur = cur->next;
		next = cur->next;
	}	
}

int GetLength(pList *pplist)
{
	pNode cur;
	int size = 0;
	assert(pplist);
    cur = *pplist;
	while(cur)
	{
		size++;
		cur = cur->next;
	}
	return size;
}


void TestLinkList()
{
	int i = 0;
	Node *list;
	/*Node *ret;*/
	LinkListInit(&list);
	
	for(i=0; i<10; i++)
	{
		/*LinkListPushBack(&list,i);*/
		LinkListPushFront(&list,i);
	}
	LinkListPrint(&list);
	LinkListPopBack(&list);
	LinkListPopBack(&list);
	LinkListPopBack(&list);
	LinkListPrint(&list);
	LinkListPopFront(&list);
	LinkListPopFront(&list);
	LinkListPopFront(&list);
	LinkListPrint(&list);
	/*ret = Find(&list,5);
	printf("%d ",ret->date);*/
	Insert(&list,Find(&list,5),10);
	Insert(&list,Find(&list,3),7);
	Insert(&list,Find(&list,6),9);
	LinkListPrint(&list);
	Erase(&list,Find(&list,9));
	Erase(&list,Find(&list,10));
	Erase(&list,Find(&list,7));
	LinkListPrint(&list);
	Remove(&list,6);
	Remove(&list,3);
	LinkListPrint(&list);
	printf("%d \n",GetLength(&list));
	LinkListPushFront(&list,1);
	LinkListPushFront(&list,1);
	LinkListPushBack(&list,1);
	LinkListPushBack(&list,1);
	LinkListPrint(&list);
	RemoveAll(&list,1);
	LinkListPrint(&list);

	LinkListDestory(&list);
}


//链表面试题
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PrintTailToHead(pList *pplist) //2. 从尾到头打印单链表
{
	pNode cur = *pplist;
	assert(pplist);
	if(cur == NULL)
	{
		return;
	}
	else
	{
		PrintTailToHead(&cur->next);
		printf("%d->",cur->date);
	}
}

void EraseNotTail(pNode pos)
{
	pNode next;
	assert(pos);
	next = pos->next;
	pos->date = pos->next->date;
	pos->next = pos->next->next;
	free(next);
	next = NULL;
}

void InsertNode(pNode pos,DateType d)
{
	pNode newNode;
	pNode cur;
	int temp = 0;
	if(NULL == pos)
	{
		return;
	}
	newNode = BuyNode(d);
	cur = pos;
	newNode->next = cur->next;
	cur->next = newNode;
    temp = cur->date;
    cur->date = newNode->date;
    newNode->date = temp;
}

pNode JosephCycle(pList * pplist, int num)
{
	int count = num;
	pNode cur = *pplist;
	pNode cur2 = NULL;
	assert(pplist);
	while(cur->next != cur)
	{
		count = num;
		while(count--)
		{
			cur2 = cur;
			cur = cur->next;
		}
		cur2->next = cur->next;
		free(cur);
		cur = cur2->next;
	}
	return cur;
}

void ReverseList(pList* pplist)
{
	pNode cur = NULL; 
    pNode pre = NULL;  
    pNode next = NULL;
	assert(pplist);
    if((*pplist) == NULL)
	{
		return ;
	}
	pre = *pplist;
	cur = (*pplist)->next; 
	while(cur != NULL)
	{
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	(*pplist)->next = NULL;
	(*pplist) = pre;
}

void BubbleSort(pList * pplist)
{
	pNode cur;
	pNode teil = NULL;
	assert(pplist);
	cur = (*pplist);
	while(cur != teil)
	{
		while(cur->next != teil)
		{
			if(cur->date > cur->next ->date )
			{
				int tmp = cur->date ;
				cur->date = cur->next ->date ;
				cur->next ->date = tmp;
			}
			cur = cur->next ;
		}
		teil = cur;
		cur = (*pplist);
	}
}

pNode FindMidNode(pList *pplist)
{
	pNode fast;
	pNode slow;
	assert(pplist);
	fast = *pplist;
	slow = *pplist;
	while(fast)
	{
		if(fast->next)
		{
			fast = fast->next->next;
		}
		else
		{
			break;
		}
		slow = slow->next;
	}
	return slow;
}

pNode FindLastKNode(pList *pplist, int k)
{
	pNode fast;
	pNode slow;
	assert(pplist);
	fast = *pplist;
	slow = *pplist;
	while(k--)
	{
		fast = fast->next;
	}
	while(fast)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}




void Test()
{
	int i = 0;
	Node *list;
	pNode ret;
	LinkListInit(&list);
	for(i=0; i<10; i++)
	{
		LinkListPushBack(&list,i);
	}
	LinkListPrint(&list);
	PrintTailToHead(&list);
	printf("\n");
	EraseNotTail(Find(&list,6));
	LinkListPrint(&list);
	InsertNode(Find(&list,5),10);
	LinkListPrint(&list);
	ReverseList(&list);
	LinkListPrint(&list);
	BubbleSort(&list);
	LinkListPrint(&list);
	ret = FindLastKNode(&list,3);
	printf("%d ",ret->date);


}

