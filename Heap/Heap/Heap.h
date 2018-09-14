#pragma once

#include <stdio.h>
#include <malloc.h>
#include <assert.h>

typedef int HDateType;
typedef struct Heap
{
	HDateType *a;
	int size;
	int capactiy;//容量
}Heap;

void HeapInit(Heap *hp,HDateType *arr,int n);//堆的初始化
void HeapDestory(Heap* hp);//堆的销毁
void HeapPrint(Heap *hp,int n);
void HeapPush(Heap *hp,HDateType d);
void HeapPop(Heap* hp);
int HeapEmpty(Heap* hp);//判断堆是否为空
int HeapSize(Heap* hp);

void TestHeap();