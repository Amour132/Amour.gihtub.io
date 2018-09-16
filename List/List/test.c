#include "List.h"

void TestList()
{
	List t;
	ListNode *cur;
	ListInit(&t);
	ListPushFront(&t,2);
	ListPushFront(&t,3);
	ListPushFront(&t,4);
	ListPushFront(&t,5);
	ListPrint(&t);
	ListPushBack(&t,1);
	ListPopBack(&t);
	ListPopFront(&t);
	ListPrint(&t);
	printf("%d \n",ListSize(&t));
	
	cur = ListFind(&t,3);
	printf("%d ",cur->date);
	ListDestory(&t);

}

int main()
{
	TestList();
}
