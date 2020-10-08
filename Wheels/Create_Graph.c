#pragma once
#include"C-Graph.h"
Graph* CreateGraph();
void PrintGraph(Graph* pGraph);
Graph* CreateGraph()
{
	//确定图中各项属性
	Graph* pGraph = NULL;
	int nV = 0;
	int nE = 0;
	
	int type;
	pGraph = (Graph*)malloc(sizeof(Graph));
	if (pGraph == NULL)
	{
		printf("内存分配失败\n");
		return pGraph;
	}
	printf("请确定要创建的图的类型:\n有向图:1\n无向图:2\n");
	while (1)
	{
		scanf_s("%d",&type);
		if (type == 1)
		{
			pGraph->Graph_Type = _Digraph;
			break;
		}
		else if (type == 2)
		{
			pGraph->Graph_Type = _Undigraph;
			break;
		}
		else
		{
			printf("输入错误,请重新输入\n");
		}

	}


	printf("请输入图中的顶点数和边数,以空格分隔\n");
	scanf_s("%d %d",&nV,&nE);
	pGraph->nVertex = nV;
	pGraph->nEdge = nE;


	//建立矩阵
	pGraph->pMatrix = (int*)malloc(sizeof(int)* pGraph->nVertex * pGraph->nVertex);
	if (pGraph->pMatrix == NULL)
	{
		printf("内存分配失败\n");
		free(pGraph);
		pGraph = NULL;
		return pGraph;
	}
	memset(pGraph->pMatrix,0, sizeof(int) * pGraph->nVertex * pGraph->nVertex);


	//使用循环读入每一条边
	int V1, V2;//确定两个顶点
	for (int i = 0; i < pGraph->nEdge; i++)
	{
		printf("请输入第%d条边",i+1);
		scanf_s("%d %d", &V1, &V2);
		if(pGraph->Graph_Type== _Undigraph )
		{
			//1.对角线无节点
			//2.顶点在范围内
			//3.对应待赋值节点未被赋值
			if (V1 != V2 && \
				V1 <= pGraph->nVertex && \
				V2 <= pGraph->nVertex && \
				pGraph->pMatrix[(V1 - 1) * pGraph->nVertex + (V2 - 1)] == 0\
				)

			{
				pGraph->pMatrix[(V1 - 1) * pGraph->nVertex + (V2 - 1)] = 1;
				pGraph->pMatrix[(V2 - 1) * pGraph->nVertex + (V1 - 1)] = 1;
			}
			else
			{
				printf("此两节点不合法,请重新输入\n");
				i--;
			}
		}
		else if(pGraph->Graph_Type == _Digraph)
		{
			//1.顶点在范围内
			//2.对应待赋值节点未被赋值
			if (V1 <= pGraph->nVertex && \
				V2 <= pGraph->nVertex && \
				pGraph->pMatrix[(V1 - 1) * pGraph->nVertex + (V2 - 1)] == 0\
				)

			{
				pGraph->pMatrix[(V1 - 1) * pGraph->nVertex + (V2 - 1)] = 1;
				pGraph->pMatrix[(V2 - 1) * pGraph->nVertex + (V1 - 1)] = 1;
			}
			else
			{
				printf("此两节点不合法,请重新输入\n");
				i--;
			}
		}		
	}
	return pGraph;
}
void PrintGraph(Graph* pGraph)
{
	if (pGraph == NULL)
	{
		printf("图创建失败\n");
		return;
	}
	else
	{
		printf("图创建成功\n");
		for (int i = 0; i < pGraph->nVertex* pGraph->nVertex; i++)
		{// sizeof(pGraph->pMatrix)/sizeof(int)
			
			if (i%pGraph->nVertex==0)
			{
				printf("\n");
			}
			printf("%d\t", pGraph->pMatrix[i]);
		}
		printf("\n");
	}
}


void DFS(Graph* pGraph, int nBegin);//传入图,传入起始节点
void DFS_Iteration(Graph* pGraph, int Begin, int* pMark);//图,起始节点,标记数组
void CreateGraph_CTest();
void DFS(Graph* pGraph, int nBegin)//传入图,传入起始节点
{
	if (pGraph == NULL)return;
	//申请标记数组
	int* pMark = NULL;
	pMark = (int*)malloc(sizeof(int) * pGraph->nVertex);
	if (pMark == NULL)
	{
		printf("内存申请失败\n");
		return;
	}
	memset(pMark, 0, sizeof(int) * pGraph->nVertex);

	//遍历
	DFS_Iteration(pGraph, nBegin, pMark);
	printf("\n");
	//释放
	free(pMark);
	pMark = NULL;
	return;
}
void DFS_Iteration(Graph* pGraph, int Begin, int* pMark)//图,起始节点,标记数组
{
	//遍历操作(打印)
	printf("%d\t", Begin);
	//标记数组进行标记
	pMark[Begin - 1] = 1;
	//遍历
	int i;
	for (int i = 0; i < pGraph->nVertex; i++)
	{
		//找到有关且未遍历过的节点
		if (pGraph->pMatrix[(Begin - 1) * pGraph->nVertex + i] == 1 && pMark[i] == 0)
		{
			//(节点序号-1)*顶点数:先偏移开始节点序号-1行
			//+i表示再偏移i位表示列
			DFS_Iteration(pGraph, i + 1, pMark);
			//开始遍历矩阵中的下一个元素
		}
	}
}
void CreateGraph_CTest()
{
	Graph* pGraph = NULL;
	pGraph = CreateGraph();
	PrintGraph(pGraph);
	DFS(pGraph, 4);
}