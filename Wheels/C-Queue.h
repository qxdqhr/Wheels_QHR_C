#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int nVal;
	struct Node* pnext;
}Node;
typedef struct Queue
{
	Node* QueueHead;
	Node* QueueTail;
	int Num;
}Queue;

Node* CreateNode_Queue(int nVal);
Queue* CreateQueue();
void AddQueue(Queue**pQueue,Node*node);
Node* PullQueue(Queue** pQueue);
void ClearQueue(Queue** pQueue);
void DestroyQueue(Queue** pQueue);
void ArrToQueue(Queue** pQueue, int* arr, int arrlen);
void Queue_CTest();
