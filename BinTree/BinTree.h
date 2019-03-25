#pragma once
#include <Windows.h>
typedef char DataType;


typedef struct BinTreeNode
{
	struct BinTreeNode* _pLeft;
	struct BinTreeNode* _pRight;
	DataType _data;
}BTNode;


//队列
typedef struct LinkNode
{
	struct LinkNode* _pNext;
	BTNode* data;
}LinkNode;

typedef struct Queue
{
	LinkNode* head;
	LinkNode* tail;
	int length;
}Queue;
void QueueInit(Queue* q);
void PushQueue(Queue* q, BTNode* node);
void PopQueue(Queue* q);
int QueueEmpty(Queue* q);
BTNode* FrontQueue(Queue* q);       //对头元素


//栈
#define MAXSIZE  10

typedef struct Stack
{
	BTNode* arr[MAXSIZE];
	int _top;
}Stack;
void StackInit(Stack* s);					 
void PushStack(Stack* s, DataType data);		 
void PopStack(Stack* s);						 
int StackEmpty(Stack* s);					
int StackSize(Stack* s);
BTNode* TopStack(Stack* s);



//二叉树
BTNode* BuyBTNode(DataType data);          //创建一个根节点
void CreateBinTree(BTNode** pRoot, char* str, int size, int* index);    //创建二叉树
void PreOrder(BTNode* pRoot);         //先序遍历   递归
void InOrder(BTNode* pRoot);         //中序        递归
void PostOrder(BTNode* pRoot);           //后序    递归
BTNode* CopyBinTree(BTNode* pRoot);       //拷贝
void DestroyBinTree(BTNode** pRoot);       //销毁
int GetBinTreeNodeCount(BTNode* pRoot);      //节点个数
int GetLeafNodeCount(BTNode* pRoot);         //叶子节点个数
int GetKLevelNodeCount(BTNode* pRoot,int k);       //K层节点个数
int Height(BTNode* pRoot);                       //高度
int IsNodeInBinTreeNode(BTNode* pRoot, BTNode* node);           //判断一个节点是否在二叉树中
BTNode* ParentNode(BTNode* pRoot, BTNode* son);					//获取一个节点的双亲节点
BTNode* LeftNode(BTNode* pRoot,BTNode* father);                //获取一个节点的左孩子
BTNode* RightNode(BTNode* pRoot,BTNode* father);               //获取一个节点的右孩子
void Mirror(BTNode* pRoot);              //镜像
void CengXu(BTNode* pRoot);              //层序
int IsCompleteBintree(BTNode* pRoot);     //判断是否为完全二叉树

void PreOrderNor(BTNode* pRoot);           //先序遍历    非递归
void InOrderNor(BTNode* pRoot);            //中序        非递归
void PostOrderNor(BTNode* pRoot);          //后序        非递归
