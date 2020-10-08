#include"List-C.h"

Node* CreateNode(int i)
{
	Node* NewNode;
	NewNode = (Node*)malloc(sizeof(Node));
	NewNode->nVal = i;
	NewNode->pNext = NULL;
	return NewNode;
}
void AddNode(Node** phead, Node** pend, Node*node)
{
	Node* pMark;
	if (*phead == NULL)
	{
		*phead = node;
		*pend = node;
	}
	else
	{
		pMark = *phead;
		while (pMark->pNext!=NULL)
		{
			pMark = pMark->pNext;
		}
		pMark->pNext = node;
		*pend = node;

	}
}
Node* FindNode(Node* phead,int n)
{
	Node* pMark = phead;
	if (pMark == NULL) return NULL;
	while (pMark != NULL)
	{
		if (pMark->nVal == n)
		{
			return pMark;
		}
		pMark = pMark->pNext;
	}

}
void DeleteNode(Node** phead, Node** pend,int n)
{
	Node* pMark = *phead;
	Node* pdel;
	Node* pMark1;
	if (pMark->nVal == n)
	{
		*phead = pMark->pNext;
		free(pMark);
		pMark = NULL;
		return;
	}
	while (pMark->pNext!=NULL)
	{
		if (pMark->pNext->nVal == n)
		{
			pMark1 = pMark;//存储前一节点
			pdel = pMark->pNext;//存储待删除结点
			pMark1->pNext = pdel->pNext;
			if (pdel == *pend)
			{
				*pend = pMark1;
			}
			free(pdel);
			pdel = NULL;
			
		}
		pMark = pMark->pNext;
	}
}
void ShowAllNode(Node* phead)
{
	Node* pmark = phead;
	if (pmark == NULL)
	{
		printf(" No Elements\n");
		return;
	}
	while (pmark)
	{
		printf("%d\t", pmark->nVal);
		pmark = pmark->pNext;
	}
	printf("\n");
}
void DeleteAllNode(Node** phead, Node** pend)
{
	Node* pMark = *phead;
	while (pMark != NULL)
	{
		pMark = *phead;
		*phead = (*phead)->pNext;
		free(pMark);
		pMark = NULL;

	}
	*phead = NULL;
	*pend = NULL;
}
void UpdateNode(Node** phead, Node** pend, int n1,int n2)
{
	Node* pMark = *phead;
	while (pMark->pNext != NULL)
	{
		if (pMark->nVal == n1)
		{
			pMark->nVal = n2;
		}
		pMark = pMark->pNext;
	}
}
void List_CTest()
{
	Node* phead = NULL;
	Node* pend = NULL;
	AddNode(&phead, &pend, CreateNode(1));
	AddNode(&phead, &pend, CreateNode(2));
	AddNode(&phead, &pend, CreateNode(3));
	AddNode(&phead, &pend, CreateNode(4));
	AddNode(&phead, &pend, CreateNode(5));
	AddNode(&phead, &pend, CreateNode(6));
	AddNode(&phead, &pend, CreateNode(7));
	DeleteNode(&phead, &pend, 3);
	ShowAllNode(phead);
	//DeleteAllNode(&phead, &pend);
	UpdateNode(&phead, &pend, 2, 5);
	ShowAllNode(phead);
	//Node*p= FindNode(phead, 3);
	//printf("%d",p->nVal);
}