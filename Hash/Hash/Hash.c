#include "Hash.h"

int HashFun(HashTable *ht,HTKeyType key)
{
	return key % ht->len;
}

void CheckCapacity(HashTable *ht)
{
	if(((ht->size*10) / ht->len) > 7)
	{
		HashTable *newht = NULL;
		size_t i = 0;
		HashTableInit(newht,ht->len*2);
		for(i=0; i<ht->len; i++)
		{
			if(ht->table[i].status == EXITS)
			{
				HashTableInsert(newht,ht->table[i].key,ht->table[i].value);
			}
		}
		HashTableDestory(ht);
		ht->table = newht->table;
		ht->len = newht->len;
		ht->size = newht->size;
	}
}

void HashTableInit(HashTable *ht,int len)
{
	int i = 0;
	assert(len > 0);
	assert(ht);
	ht->table = (HashDate*)malloc(sizeof(HashDate)*len);
	ht->size = 0;
	ht->len = len;
	for(i=0; i<len; i++)
	{
		ht->table[i].status = EMPTY;
	}
}

void HashTableDestory(HashTable *ht)
{
	assert(ht);
	free(ht->table);
	ht->table = NULL;
	ht->size = ht->len = 0;
}

int HashTableInsert(HashTable* ht,HTKeyType key,HTValueType value)
{
	int index = HashFun(ht,key);
	CheckCapacity(ht);
	while(ht->table[index].status == EXITS)
	{
		if(ht->table[index].key == key)
		{
			return 0;
		}
		else
		{
			index++;
		}
	}
	ht->table[index].status = EXITS;
	ht->table[index].key = key;
	ht->table[index].value = value;
	return 1;
}

HashDate* HashTableFind(HashTable *ht,HTKeyType key)
{
	int index = HashFun(ht,key);
	assert(ht);
	while(ht->table[index].status != EMPTY)
	{
		if((ht->table[index].key == key)&&(ht->table[index].status == EXITS))
		{
			return &(ht->table[index]);
		}
		else
		{
			index++;
		}
	}
	return NULL;
}

int HashTableRemove(HashTable *ht,HTKeyType key)
{
	HashDate *date = HashTableFind(ht,key);
	if(date)
	{
		date->status = DELETE;
		ht->size--;
		return 1;
	}
	return 0;
}

void HashTablePrint(HashTable *ht)
{
	size_t i = 0;
	assert(ht);
	for(i=0; i<ht->len; i++)
	{
		if(ht->table[i].status == EXITS)
		{
			printf("%d ",ht->table[i].key);
		}
	}
	printf("\n");
}

void TestHash()
{
	HashTable ht;
	int arr[] = {58,99,67,54,69,14,35,88,89,55,46};
	int i = 0;
	HashTableInit(&ht,16);
	for(i=0; i<sizeof(arr)/sizeof(arr[0]); i++)
	{
		HashTableInsert(&ht,arr[i],1);
	}
	HashTablePrint(&ht);

}

