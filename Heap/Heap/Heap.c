#include "Heap.h"

void Swap(HDateType *a,HDateType *b)
{
	HDateType temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void AdjustDown(Heap *hp,int n,int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while(child < n)
	{
		if(child+1 <n && hp->a[child+1] > hp->a[child])
		{
			child++;
		}
		if(hp->a[child] > hp->a[parent])
		{
			Swap(&hp->a[child],&hp->a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}


void HeapInit(Heap *hp,HDateType *arr,int n)
{
	int i = 0;
	assert(hp);
	hp->a = (HDateType *)malloc(sizeof(HDateType)*2*n);
	hp->size = n;
	hp->capactiy = 2*n;
	for(i=0; i<n; i++)
	{
		hp->a[i] = arr[i];
	}
	for(i=(n-2)/2; i>=0; i--)
	{
		AdjustDown(hp,n,i);
	}
}

void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->a);
	hp->a = NULL;
	hp->capactiy = hp->size = 0;
}

void HeapPrint(Heap *hp,int n)
{
	int i = 0;
	for(i=0; i<n; i++)
	{
		printf("%d ",hp->a[i]);
	}
	printf("\n");
}



void HeapPop(Heap* hp)
{
	int i = 0;
	assert(hp);
	Swap(&hp->a[0],&hp->a[hp->size-1]);
	hp->size--;
	for(i=(hp->size-2)/2; i>=0; i--)
	{
		AdjustDown(hp,hp->size,i);
	}	
}

void HeapPush(Heap *hp,HDateType d)
{
	int i = 0;
	assert(hp);
	hp->a[hp->size] = d;
	hp->size++;
	for(i=(hp->size-2)/2; i>=0; i--)
	{
		AdjustDown(hp,hp->size,i);
	}	
}

int HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->size == 0 ? 0 : 1;
}

int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->size;
}


void TestHeap()
{
	Heap hp;
	int i = 0;
	int arr[] = {12,56,8,87,98,45,67,82};
	HeapInit(&hp,arr,sizeof(arr)/sizeof(arr[0]));
	HeapPrint(&hp,hp.size);
	HeapPop(&hp);
	HeapPrint(&hp,hp.size);
	HeapPush(&hp,100);
	HeapPush(&hp,5);
	HeapPrint(&hp,hp.size);
	
}

