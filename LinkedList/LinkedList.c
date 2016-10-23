#include "LinkedList.h"

LinkedList* LinkedList_Create(const unsigned int dataSize)
{
	LinkedList *linkedList = malloc(sizeof(LinkedList));

	if (linkedList == NULL)
	{
		return NULL;
	}

	linkedList->dataSize = dataSize;
	linkedList->head = NULL;
	return linkedList;
}

int LinkedList_Destroy(LinkedList *linkedList)
{
	if (linkedList == NULL)
	{
		return LINKED_LIST_HAS_NOT_BEEN_INITIALIZED;
	}

	if (linkedList->head != NULL)
	{
		Node *nodePointer = linkedList->head;
		do
		{
			Node *nextPointer = nodePointer->next;

			free(nodePointer->value);
			free(nodePointer);
			nodePointer = nextPointer;
		} while (nodePointer != NULL);
	}

	free(linkedList);
	return 0;
}

int LinkedList_Length(const LinkedList *linkedList)
{
	if (linkedList == NULL)
	{
		return LINKED_LIST_HAS_NOT_BEEN_INITIALIZED;
	}

	unsigned int length = 0;

	Node *node = linkedList->head;

	while (node != NULL)
	{
		length++;
		node = node->next;
	}

	return length;
}

bool LinkedList_IsEmpty(const LinkedList *linkedList)
{
	return ((linkedList == NULL) || (linkedList->head == NULL));
}

void LinkedList_Print(const LinkedList *linkedList)
{
	if (linkedList == NULL)
	{
		return LINKED_LIST_HAS_NOT_BEEN_INITIALIZED;
	}

	Node *node = linkedList->head;

	while (node != NULL)
	{
		printf("%d\n", *((int*) node->value));
		node = node->next;
	}
}

Iterator* LinkedList_At(LinkedList *linkedList, unsigned int index)
{
	if (linkedList == NULL)
	{
		return LINKED_LIST_HAS_NOT_BEEN_INITIALIZED;
	}

	int numElements = LinkedList_Length(linkedList);

	if (numElements > 0)
	{
		if (numElements > index)
		{
			Node *node = linkedList->head;

			for (int i = 1; i <= index; ++i)
			{
				node = node->next;
			}

			return node;
		}
	}

	return NULL;
}

Iterator* LinkedList_Append(LinkedList *linkedList, void *dataPointer, void(*assign)(void*, const void*))
{
	if (linkedList == NULL)
	{
		return LINKED_LIST_HAS_NOT_BEEN_INITIALIZED;
	}

	Node *newNode = malloc(sizeof(Node));
	newNode->value = malloc(sizeof(linkedList->dataSize));
	memcpy(newNode->value, dataPointer, linkedList->dataSize);
	newNode->next = NULL;

	Node *node = linkedList->head;

	while (node != NULL)
	{
		if (node->next != NULL)
		{
			node = node->next;
		} 
		else
		{
			break;
		}
	}

	if (node != NULL)
	{
		node->next = newNode;
		newNode->prev = node;
	}
	else
	{
		linkedList->head = newNode;
	}

	return newNode;
}


Iterator* LinkedList_Insert(LinkedList *linkedList, Iterator* iterator, void *dataPointer, void(*assign)(void*, const void*))
{
	if (linkedList == NULL)
	{
		return LINKED_LIST_HAS_NOT_BEEN_INITIALIZED;
	}

	if (iterator == NULL)
	{
		return ITERATOR_HAS_NOT_BEEN_INITIALIZED;
	}

	Node *newNode = malloc(sizeof(Node));
	newNode->value = malloc(sizeof(linkedList->dataSize));
	memcpy(newNode->value, dataPointer, linkedList->dataSize);

	Node *previousNode = (*iterator)->prev;
	newNode->next = *iterator;
	newNode->prev = previousNode;

	if (previousNode != NULL)
	{
		previousNode->next = newNode;
	}

	(*iterator)->prev = newNode;

	return newNode;	
}

Iterator* LinkedList_InsertAt(LinkedList *linkedList, unsigned int index, void *dataPointer, void(*assign)(void*, const void*))
{
	return LinkedList_Insert(linkedList, LinkedList_At(linkedList, index), dataPointer, NULL);
}

int LinkedList_Remove(LinkedList *linkedList, Iterator* iterator)
{
	if (linkedList == NULL)
	{
		return LINKED_LIST_HAS_NOT_BEEN_INITIALIZED;
	}

	if (iterator == NULL)
	{
		return ITERATOR_HAS_NOT_BEEN_INITIALIZED;
	}

	printf("%d\n", LinkedList_Length(linkedList));
	if ((*iterator)->prev == NULL)
	{
		linkedList->head = (*iterator)->next;

		if ((*iterator)->next != NULL)
		{
			(*iterator)->next->prev = NULL;
		}
	}
	else
	{
		(*iterator)->prev->next = (*iterator)->next;

		if ((*iterator)->next != NULL)
		{
			(*iterator)->next->prev = (*iterator)->prev;
		}
	}

	printf("%d\n", LinkedList_Length(linkedList));

	free((*iterator)->value);
	free(*iterator);

	return 0;
}

int LinkedList_RemoveAt(LinkedList *linkedList, unsigned int index)
{
	return LinkedList_Remove(linkedList, LinkedList_At(linkedList, index));
}



