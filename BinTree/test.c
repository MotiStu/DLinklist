#define _CRT_SECURE_NO_WARNINGS 1
#include "Bintree.h"
#include <string.h>

#include <stdio.h>

void testCheck(BTNode* pRoot)
{

	printf("先序遍历：");
	PreOrder(pRoot);
	printf("\n");

	printf("中序遍历：");
	InOrder(pRoot);
	printf("\n");

	printf("后序遍历：");
	PostOrder(pRoot);
	printf("\n");
}
int main()
{
	system("color 3F");
	system("mode con cols=100 lines=35");
	BTNode* pRoot = NULL;
	char* str = "ABD###CE##F";
	int count = 0;

	CreateBinTree(&pRoot, str, strlen(str), &count);
	//testCheck(pRoot);
	
	//BTNode* copy = NULL;
	//copy = CopyBinTree(pRoot);

	//DestroyBinTree(&pRoot);

	//printf("%d ", GetBinTreeNodeCount(pRoot));
	//printf("%d ", GetLeafNodeCount(pRoot));
	//printf("%d ", GetKLevelNodeCount(pRoot, 2));
	//printf("%d ", Height(pRoot));


	/*BTNode* cur = BuyBTNode('B'); 
	int  i = IsNodeInBinTreeNode(pRoot, cur);
	if (i == 1)
		printf("在二叉树中\n");
	else
		printf("不在二叉树中\n");
*/
	
	/*BTNode* cur = ParentNode(pRoot, pRoot->_pLeft->_pLeft);
	printf("%c ", cur->_data);
	BTNode* left = LeftNode(pRoot, pRoot->_pLeft);
	printf("%c ", left->_data);
	*/
	//printf("%c ", son->_data);
	

	//Mirror(pRoot);
	/*Queue q;
	QueueInit(&q);
	PushQueue(&q, 'A');
	PushQueue(&q, 'B');
	PushQueue(&q, 'C');
	PushQueue(&q, 'D');*/

	//CengXu(pRoot);


	int i = IsCompleteBintree(pRoot);
	printf("%d ", i);
	printf("前序遍历非递归：");
	PreOrderNor(pRoot);
	printf("\n中序遍历非递归：");
	InOrderNor(pRoot);
	printf("\n后序遍历非递归：");
	PostOrderNor(pRoot);
	system("pause");
	return 0;
}
