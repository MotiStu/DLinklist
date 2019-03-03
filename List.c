#define _CRT_SECURE_NO_WARNINGS 1
#include "DList.h"
#include <stdio.h>
#include <assert.h>

DListNode* BuyNode(DataType data)
{
	DListNode* New = (DListNode*)malloc(sizeof(DListNode));
	if (New == NULL)
		return NULL;
	New->_data = data;
	New->_pNext = NULL;
	New->_pPre = NULL;
	return New;
}
void DListInit(DListNode** pHead)						// 初始化 
{
	assert(pHead);
	*pHead = BuyNode(0);
	if (NULL == *pHead)
		return;
	(*pHead)->_pNext = *pHead;
	(*pHead)->_pPre = *pHead;

}



void DListPushBack(DListNode* pHead, DataType data)			// 双向链表的尾插 
{
	
	DListNode* New = NULL;
	DListNode* tail = NULL;
	assert(pHead);
	New = BuyNode(data);
	if (NULL == New)
		return;

	tail = pHead->_pPre;
	tail->_pNext = New;
	New->_pPre = tail;
	New->_pNext = pHead;
	pHead->_pPre = New;

}




void DListPopBack(DListNode* pHead)							// 双向链表的尾删 
{
	DListNode* cur = NULL;
	DListNode* del = NULL;
	assert(pHead);
	del = pHead->_pPre;
	cur = pHead->_pPre->_pPre;
	cur->_pNext = pHead;
	pHead->_pPre = cur;
	free(del);
	del = NULL;

	
}



void DListPushFront(DListNode* pHead, DataType data)		// 双向链表的头插 
{
	DListNode* New = NULL;
	DListNode* cur = NULL;

	assert(pHead);
	cur = pHead->_pNext;
	New = BuyNode(data);

	pHead->_pNext = New;
	New->_pPre = pHead;
	New->_pNext = cur;
	cur->_pPre = New;

	
}




void DListPopFront(DListNode* pHead)						// 双向链表的头删 
{
	assert(pHead);
	DListNode* del = NULL;
	del = pHead->_pNext;
	pHead->_pNext = del->_pNext;
	del->_pNext->_pPre = pHead;

	free(del);
	del = NULL;
}


DListNode* FindPos(DListNode* pHead,int count)
{
	DListNode* cur = pHead;
	while (count != 0)
	{
		if (cur != NULL)
		{
			cur = cur->_pNext;
			count--;
		}
	}
	return cur;
}
void DListInsert(DListNode* pos, DataType data)				// 任意位置插入 
{
	DListNode* New = BuyNode(data);
	DListNode* cur = pos->_pNext;

	pos->_pNext = New;
	New->_pNext = cur;
	New->_pPre = pos;
	cur->_pPre = pos;

}




void DListErase(DListNode* pos)							// 任意位置删除 
{
	pos->_pPre->_pNext = pos->_pNext;
	pos->_pNext->_pPre = pos->_pPre;
	free(pos);
	pos = NULL;
}



DListNode* DListFind(DListNode* pHead, DataType data)		// 查找值为data的结点 
{
	DListNode* cur = pHead->_pNext;
	while (cur->_pNext != pHead)
	{
		if (cur->_data == data)
			return cur;
		else
			cur = cur->_pNext;
	}
	return NULL;
}


void DListDestroy(DListNode** pHead)						// 销毁 
{
	assert(pHead);
	DListNode* del = NULL;
	DListNode* cur = (*pHead)->_pNext;
	
	
	while (cur->_pNext != *pHead)
	{
		del = cur;
		cur = cur->_pNext;
		free(del);
		del = NULL;
	}
	free(*pHead);
	*pHead = NULL;
}
