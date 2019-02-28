#pragma once

typedef int DataType;

typedef struct DListNode
{
	struct DListNode* _pNext;
	struct DListNode* _pPre;
	DataType _data;
}DListNode;

DListNode* BuyNode(DataType data);
void DListInit(DListNode** pHead);							// 初始化 
void DListPushBack(DListNode* pHead, DataType data);			// 双向链表的尾插 
void DListPopBack(DListNode* pHead);							// 双向链表的尾删 
void DListPushFront(DListNode* pHead, DataType data);		// 双向链表的头插 
void DListPopFront(DListNode* pHead);						// 双向链表的头删 
void DListInsert(DListNode* pos, DataType data);				// 任意位置插入 
void DListErase(DListNode* pos);								// 任意位置删除 
DListNode* DListFind(DListNode* pHead, DataType data);		// 查找值为data的结点 
void DListDestroy(DListNode** pHead);						// 销毁 
