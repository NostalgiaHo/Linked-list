#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "ErrorCode.h"
#include "DataType.h"

LinkedList* LinkedList_Create(const unsigned int dataSize);
int LinkedList_Destroy(LinkedList *linkedList);

int LinkedList_Length(const LinkedList *linkedList);
bool LinkedList_IsEmpty(const LinkedList *linkedList);
void LinkedList_Print(const LinkedList *linkedList);

Iterator* LinkedList_Append(LinkedList *linkedList, void *dataPointer, void(*assign)(void*, const void*));
Iterator* LinkedList_At(LinkedList *linkedList, unsigned int index);

Iterator* LinkedList_Insert(LinkedList *linkedList, Iterator* iterator, void *dataPointer, void(*assign)(void*, const void*));
Iterator* LinkedList_InsertAt(LinkedList *linkedList, unsigned int index, void *dataPointer, void(*assign)(void*, const void*));

int LinkedList_Remove(LinkedList *linkedList, Iterator* iterator);
int LinkedList_RemoveAt(LinkedList *linkedList, unsigned int index);
