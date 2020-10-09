#include"C-Queue.h"
Node* CreateNode_Queue(int nVal)
{
	Node* node = NULL;
	node = (Node*)malloc(sizeof(Node));
	if(node==NULL)return NULL;
	node->nVal = nVal;
	node->pnext=NULL;
	return node;
}
Queue* CreateQueue()
{
	Queue* queue = NULL;
	queue = (Queue*)malloc(sizeof(Queue));
	if (queue == NULL) return NULL;
	queue->Num = 0;
	queue->QueueHead=NULL;
	queue->QueueTail = NULL;
	return queue;

}
void AddQueue(Queue** pQueue, Node* node)
{
	if ((*pQueue) == NULL)return;
	if ((*pQueue)->Num==0)
	{
		(*pQueue)->QueueHead = node;
		(*pQueue)->QueueTail = node;
	}
	(*pQueue)->QueueTail->pnext = node;
	(*pQueue)->QueueTail = node;
	(*pQueue)->Num++;
}
Node* PullQueue(Queue** pQueue)
{
	if ((*pQueue) == NULL)return NULL;
	if ((*pQueue)->Num==0)
	{
		printf("队列内无元素\n");
		return NULL;
	}
	Node* pnode = (*pQueue)->QueueHead; 
	if ((*pQueue)->Num == 1)
	{
		(*pQueue)->QueueHead = NULL;
		(*pQueue)->QueueTail = NULL;
		(*pQueue)->Num--;
		printf("出队成功,出队元素%d\n", pnode->nVal);
		return pnode;
	}
	(*pQueue)->QueueHead = (*pQueue)->QueueHead->pnext;
	(*pQueue)->Num--; 
	pnode->pnext = NULL;
	printf("出队成功,出队元素%d\n", pnode->nVal);
	return pnode;
}
void ClearQueue(Queue** pQueue)
{
	Node* pnode = NULL;
	while ((*pQueue)->Num != 0)
	{
		pnode = PullQueue(pQueue);
		pnode->nVal = 0;
		free(pnode);
		pnode = NULL;
	}
	return	;
}
void DestroyQueue(Queue** pQueue)
{
	ClearQueue(pQueue);
	free(*pQueue);
	(*pQueue) = NULL;
	return;

}

void ArrToQueue(Queue** pQueue,int* arr,int arrlen)
{
	if (*pQueue == NULL)
	{
		(*pQueue) = CreateQueue();
	}
	if (arr == NULL || arrlen == 0)
	{
		printf("请确定要入队的元素个数\n");
		int Num = 0;
		scanf_s("%d", &Num);
		int* arr1 = (int*)malloc(sizeof(int) * Num);
		for (int i = 0; i < Num; i++)
		{
			printf("请输入第%d个元素(下标为%d)", i + 1, i);
			scanf_s("%d", &(arr1[i]));
			AddQueue(pQueue, CreateNode_Queue(arr1[i]));
		}
	}
	else
	{
		for (int i = 0; i < arrlen; i++)
		{
			if (arr == NULL)
			{
				AddQueue(pQueue, CreateNode_Queue(arr[i]));
			}
			
		}                                                     
	}

}
void Queue_CTest()
{
	Queue* pQueue = NULL;
	int arr[] = { 9,8,7,6,5,4,3,2,1 };
	pQueue = CreateQueue();
	ArrToQueue(&pQueue,NULL,0);
	DestroyQueue(&pQueue);
	return;
}
