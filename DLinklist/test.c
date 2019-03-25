#define _CRT_SECURE_NO_WARNINGS 1
#include "DList.h"
#include <stdio.h>



int main()
{
	DListNode* list;
	DListInit(&list);
	DListPushBack(list, 1);
	DListPushBack(list, 2);
	DListPushBack(list, 3);
	DListPushBack(list, 4);
	DListPushBack(list, 5);
	//DListPopBack(list);
	//DListPopBack(list);
	//DListPopBack(list);
	//DListPushFront(list, 9);
	//DListPopFront(list);
	//DListInsert(FindPos(list, 3), 12);
	DListErase(FindPos(list, 3));
	/*DListNode* a = DListFind(list, 2);
	if (a == NULL)
		printf("not found!");
	else
		printf("find it");*/
	DListDestroy(&list);


	system("pause");
	return 0;
}
