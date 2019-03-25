#define _CRT_SECURE_NO_WARNINGS 1
#include "Bintree.h"
#include <assert.h>
#include <malloc.h>
#include <string.h>
#include <stdio.h>


//队列操作
void QueueInit(Queue* q)
{
	assert(q);
	q->head = NULL;
	q->tail = NULL; 
	q->length = 0;
}
void PushQueue(Queue* q, BTNode* node)
{
	assert(q);
	LinkNode* cur = (LinkNode*)malloc(sizeof(LinkNode));
	if (cur == NULL)
		printf("error");
	cur->data = node;
	cur->_pNext = NULL;
	if (q->length == 0)
	{
		q->head = cur;
		q->tail = q->head;
	}
	else
	{
		q->tail->_pNext = cur;
		q->tail = cur;
	}
	(q->length)++;

}
void PopQueue(Queue* q)
{
	assert(q);
	LinkNode* del = q->head;
	if (q->length == 0)
		printf("cuowu!!");
	else
	{
		q->head = del->_pNext;
		free(del);
		del = NULL;
	}
	(q->length)--;

}
int QueueEmpty(Queue* q)
{
	if (q->length == 0)
		return 1;
	else
		return 0;
}
BTNode* FrontQueue(Queue* q)      //对头元素
{
	assert(q);
	
	BTNode* x;
	if (q->length != 0)
	{
		x = q->head->data;        //队列中的data的结构是   BTNode   类型的
		return x;                 //返回的是一个    BTNode*类型的
	}
}






//栈操作
void StackInit(Stack* s)					 //栈的初始化
{
	assert(s);
	s->_top = 0;
}

void PushStack(Stack* s, BTNode* node)   	 //入栈
{
	assert(s);
	if (s->_top == 10)
	{
		printf("栈已满！！！");
	}
	else
	{
		s->arr[s->_top] = node;
		s->_top++;
	}
}

void PopStack(Stack* s)				 //出栈
{
	assert(s);
	if (s->_top == 0)
	{
		printf("栈已空！！！");
		return;
	}
	else
	{
		s->_top--;
	}
}
int StackEmpty(Stack* s)					 //判断栈是否为空
{
	assert(s);
	if (s->_top == 0)
		return 1;
	else
		return 0;
}

BTNode* TopStack(Stack* s)
{
	assert(s);
	if (s->_top == 0)
	{
		printf("栈已空");
	}
	else
		return s->arr[s->_top-1];
}

int StackSize(Stack* s)
{
	if (s == NULL)
		return;
	else
		return s->_top;
}


//二叉树操作
BTNode* BuyBTNode(DataType data)
{
	BTNode* NewNode = (BTNode*)malloc(sizeof(BTNode));
	if (NULL == NewNode)
	{
		return 0;
	}

	NewNode->_data = data;
	NewNode->_pLeft = NULL;
	NewNode->_pRight = NULL;

	return NewNode;
}

void CreateBinTree(BTNode** pRoot, char* str, int size, int* index)    //创建二叉树
//pRoot 改变，所以传二级指针

//index是用来标记数组走到哪     
//再函数回调时值需要在之前继续++，而不是回调之后值的++，所以源文件需要传址(&index);
{
	assert(pRoot);
	if ((*index) < size && str[*index] != '#')
	{
		*pRoot = BuyBTNode(str[*index]);

		(*index)++;
		CreateBinTree(&(*pRoot)->_pLeft, str, size, index);

		(*index)++;
		CreateBinTree(&(*pRoot)->_pRight, str, size, index);
	}
}


void PreOrder(BTNode* pRoot)        //先序遍历
{
	if (pRoot)
	{
		printf("%c ", pRoot->_data);
		PreOrder(pRoot->_pLeft);
		PreOrder(pRoot->_pRight);
	}
	
}



void InOrder(BTNode* pRoot)         //中序
{
	if (pRoot)
	{
		InOrder(pRoot->_pLeft);
		printf("%c ", pRoot->_data);
		InOrder(pRoot->_pRight);
	}
	
}



void PostOrder(BTNode* pRoot)         //后序
{	
	if (pRoot)
	{
		PostOrder(pRoot->_pLeft);
		PostOrder(pRoot->_pRight);
		printf("%c ", pRoot->_data);
	}
	
}



BTNode* CopyBinTree(BTNode* pRoot)       //拷贝
{
	BTNode* CopyNode = NULL;
	if (pRoot)
	{
		CopyNode = BuyBTNode(pRoot->_data);         //要创建一个节点

		CopyNode->_pLeft = CopyBinTree(pRoot->_pLeft);
		CopyNode->_pRight = CopyBinTree(pRoot->_pRight);
	}

	return CopyNode;
}



void DestroyBinTree(BTNode** pRoot)       //销毁
{
	assert(pRoot);
	if (*pRoot)
	{
		DestroyBinTree(&(*pRoot)->_pLeft);
		DestroyBinTree(&(*pRoot)->_pRight);

		free(*pRoot);          //找到根节点要free啊啊啊，销毁
		*pRoot = NULL;         //还要指向空
	}

}



int GetBinTreeNodeCount(BTNode* pRoot)      //节点个数
{
	if (pRoot==NULL)
		return 0;

	return GetBinTreeNodeCount(pRoot->_pLeft) + GetBinTreeNodeCount(pRoot->_pRight) + 1;

}

int GetLeafNodeCount(BTNode* pRoot)
{
	if (pRoot == NULL)
		return 0;
	if (pRoot->_pLeft == NULL&&pRoot->_pRight == NULL)
		return 1;

	return GetLeafNodeCount(pRoot->_pLeft) + GetLeafNodeCount(pRoot->_pRight);
}

int GetKLevelNodeCount(BTNode* pRoot,int k)
{
	if (pRoot == NULL)
		return 0;
	if (k == 1)
	{
		return 1;
	}
	return GetKLevelNodeCount(pRoot->_pLeft, k - 1) + GetKLevelNodeCount(pRoot->_pRight, k - 1);
}

int Height(BTNode* pRoot)
{
	if (pRoot == NULL)
		return 0;
	if (pRoot->_pLeft == NULL&&pRoot->_pRight == NULL)
		return 1;

	int left = Height(pRoot->_pLeft);
	int right = Height(pRoot->_pRight);

	if (left > right)
		return left+1;
	else
		return right+1;
}
int IsNodeInBinTreeNode(BTNode* pRoot, BTNode* node)           //判断一个节点是否在二叉树中
{
	if (pRoot == NULL)
		return 0;

	if (pRoot->_data == node->_data)
		return 1;
	if (IsNodeInBinTreeNode(pRoot->_pLeft, node) || IsNodeInBinTreeNode(pRoot->_pRight,node))
		return 1;
	
}

BTNode* ParentNode(BTNode* pRoot,BTNode* son)					//获取一个节点的双亲节点
{
	
	BTNode* left;
	BTNode* right;
	if (pRoot == NULL)
		return NULL;
	
	if (pRoot->_pLeft == son || pRoot->_pRight == son)
		return pRoot;
	
	left = ParentNode(pRoot->_pLeft, son);
	right = ParentNode(pRoot->_pRight, son);
	return left != NULL ? left: right;
	
}
BTNode* LeftNode(BTNode* pRoot, BTNode* father)                //获取一个节点的左孩子
{
	if (pRoot == NULL)
		return NULL;
	return father->_pLeft;
}
BTNode* RightNode(BTNode* pRoot, BTNode* father)             //获取一个节点的右孩子
{
	if (pRoot == NULL)
		return NULL;
	return father->_pRight;
}


//void Swap(DataType* left, DataType* right)
//{
//	DataType tmp = 0;
//	tmp = *left;
//	*left = *right;
//	*right = tmp;
//}
void Mirror(BTNode* pRoot)
{
	BTNode* tmp = NULL;
	if (pRoot == NULL)
		return 0;
	
	tmp = pRoot->_pLeft;
	pRoot->_pLeft = pRoot->_pRight;
	pRoot->_pRight = tmp;
	Mirror(pRoot->_pLeft);
	Mirror(pRoot->_pRight);
}

void CengXu(BTNode* pRoot)
{
	Queue q;
	QueueInit(&q);

	if (pRoot != NULL)
		PushQueue(&q, pRoot);
	while (!QueueEmpty(&q))
	{
		BTNode* cur =  FrontQueue(&q);	
	
		printf("%c ", cur->_data);
		
		if (cur->_pLeft != NULL)
			PushQueue(&q, cur->_pLeft);
		if (cur->_pRight != NULL)
			PushQueue(&q, cur->_pRight);
		PopQueue(&q);
	}
}

int IsCompleteBintree(BTNode* pRoot)     //判断是否为完全二叉树
{
	Queue q;
	if (pRoot == NULL)
		return 1;
	
	QueueInit(&q);
	PushQueue(&q, pRoot);
	BTNode* cur = FrontQueue(&q);
	while (cur != NULL)
	{
		PopQueue(&q);
		PushQueue(&q, cur->_pLeft);
		PushQueue(&q, cur->_pRight);
		cur = FrontQueue(&q);
	}
	PopQueue(&q);
	while (QueueEmpty(&q) != 1)
	{
		if (FrontQueue(&q) != NULL)
			return 0;
		PopQueue(&q);
	}
	return 1;

}


void PreOrderNor(BTNode* pRoot)           //先序遍历    非递归
{
	Stack s;
	if (pRoot == NULL)
		return;
	
	StackInit(&s);
	BTNode* cur = pRoot;
	while (StackEmpty(&s) != 1||cur != NULL)
	{
		
		while (cur != NULL)
		{
			PushStack(&s, cur);
			printf("%c ", cur->_data);
			cur = cur->_pLeft;
		}
		BTNode* ret = TopStack(&s);
		cur = ret->_pRight;
		PopStack(&s);
		

	}
}
void InOrderNor(BTNode* pRoot)          //中序        非递归
{
	Stack s;
	if (pRoot == NULL)
		return;
	StackInit(&s);
	
	BTNode* cur = pRoot;
	while (cur != NULL || StackEmpty(&s) != 1)
	{
		while (cur)
		{
			PushStack(&s, cur);
			cur = cur->_pLeft;
		}
		cur = TopStack(&s);
		printf("%c ", cur->_data);
		PopStack(&s);
		cur = cur->_pRight;
	}
}
void PostOrderNor(BTNode* pRoot)         //后序        非递归
{
	Stack s;
	if (pRoot == NULL)
		return;
	StackInit(&s);
	BTNode* cur = pRoot;
	BTNode* prev = NULL;
	while (StackEmpty(&s) != 1||cur)
	{
		while (cur)
		{
			PushStack(&s, cur);
			cur = cur->_pLeft;
		}
		BTNode* top = TopStack(&s);
		if (top->_pRight == NULL || prev == top->_pRight)
		{
			printf("%c ", top->_data);
			prev = top;
			PopStack(&s);
		}
		else
		{
			cur = top->_pRight;	
		}
	}
}
