#pragma once
#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int nVal;
	struct Node* pNext;
}Node;
typedef struct Stack
{
	int nNum;
	Node* pTop;
}Stack;
Stack* CreateStack();

Node* CreateNode_Stack(int i);
void PushNode(Stack** pStack, Node* node);
Node* PullTopNode(Stack** pStack);
void ClearStack(Stack** pstack);
void DestroyStack(Stack** pstack);
void Stack_CTest();