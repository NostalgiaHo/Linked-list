#include <stdio.h>
#include "LinkedList.h"

int main(void)
{
	LinkedList *list = LinkedList_Create(sizeof(int));

	for (int i = 0; i != 10; ++i)
	{
		LinkedList_Append(list, &i, NULL);
	}

	printf("%d\n", LinkedList_Length(list));

	int num = 9;
	LinkedList_InsertAt(list, 7, &num, NULL);
	LinkedList_Print(list);

	printf("%d\n", LinkedList_Length(list));
	LinkedList_RemoveAt(list, 3);
	
	for (int i = 0; i != LinkedList_Length(list); ++i)
	{
		printf("%d,", (int)(*LinkedList_At(list, i))->value);
	}

	LinkedList_Print(list);

	system("pause");

	return 0;
}