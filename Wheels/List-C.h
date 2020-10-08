#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int nVal;
	struct Node* pNext;
}Node;
Node* CreateNode(int i);
void AddNode(Node** phead, Node** pend, Node* node);
void ShowAllNode(Node* phead);
Node* FindNode(Node* phead, int n);
void DeleteNode(Node** phead, Node** pend, int n);
void DeleteAllNode(Node** phead, Node** pend);
void UpdateNode(Node** phead, Node** pend, int n1, int n2);
void List_CTest();