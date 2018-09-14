#pragma once

#include <stdio.h>
#include <malloc.h>
#include <assert.h>

typedef int HDateType;
typedef struct Heap
{
	HDateType *a;
	int size;
	int capactiy;//����
}Heap;

void HeapInit(Heap *hp,HDateType *arr,int n);//�ѵĳ�ʼ��
void HeapDestory(Heap* hp);//�ѵ�����
void HeapPrint(Heap *hp,int n);
void HeapPush(Heap *hp,HDateType d);
void HeapPop(Heap* hp);
int HeapEmpty(Heap* hp);//�ж϶��Ƿ�Ϊ��
int HeapSize(Heap* hp);

void TestHeap();