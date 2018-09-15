#pragma once

#include <stdio.h>
#include <assert.h>
#include <malloc.h>

typedef int HTKeyType; 
typedef int HTValueType; 

typedef enum Status 
{ 
	EMPTY, 
	EXITS, 
	DELETE
}Status; 

typedef struct HashDate
{ 
	HTKeyType key; 
	HTValueType value; 
	Status status; 
}HashDate; 

typedef struct HashTable 
{ 
	HashDate* table; 
	size_t size; 
	size_t len; 
}HashTable; 

void HashTableInit(HashTable *ht,int len); 
void HashTableDestory(HashTable *ht);

int HashTableInsert(HashTable *ht,HTKeyType key,HTValueType value);
HashDate* HashTableFind(HashTable *ht,HTKeyType key);
int HashTableRemove(HashTable *ht,HTKeyType key);

void HashTablePrint(HashTable *ht);
void TestHash();

