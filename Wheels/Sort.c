#include"C-MergeSort.c"
#include"Sort.h"
void Merge(int* arr, int nLow, int nHigh)
{
	int nBegin1 = 0;
	int nBegin2 = 0;
	int nEnd1 = 0;
	int nEnd2 = 0;

	nBegin1 = nLow;
	nEnd1 = nLow + (nHigh - nLow) / 2;
	nBegin2 = nEnd1 + 1;
	nEnd2 = nHigh;

	int* pTemp = NULL;
	pTemp = (int*)malloc(sizeof(int) * (nHigh - nLow + 1));
	//在堆区申请的额外数组的原因:
	//便于规定额外数组的长度
	//注意:堆区申请的内存需要释放
	int i = 0;
	while (nBegin1 <= nEnd1 && nBegin2 <= nEnd2)
	{
		if (arr[nBegin1] < arr[nBegin2])//左半部分与右半部分进行比较
		{
			pTemp[i] = arr[nBegin1];//较小的元素刷新入额外数组中
			i++;//额外数组向后遍历
			nBegin1++;//左半部分向后遍历
		}
		else
		{
			pTemp[i] = arr[nBegin2];//较小的元素刷新入额外数组中
			i++;//额外数组向后遍历
			nBegin2++;//右半部分向后遍历
		}
	}
	//如果其中某一部分有剩余元素,全部赋入额外数组中
	while (nBegin1 <= nEnd1)
	{
		pTemp[i] = arr[nBegin1];//较小的元素刷新入额外数组中
		i++;//额外数组向后遍历
		nBegin1++;//剩余部分向后遍历
	}
	while (nBegin2 <= nEnd2)
	{
		pTemp[i] = arr[nBegin2];//较小的元素刷新入额外数组中
		i++;//额外数组向后遍历
		nBegin2++;//剩余部分向后遍历
	}
	//将额外数组中所有元素附到原数组中
	for (int i = 0; i < nHigh - nLow + 1; i++)
	{
		arr[nLow+i] = pTemp[i];//nLow+i重要
	}
	//释放额外数组
	free(pTemp);
	pTemp = NULL;
}
void MergeSort(int* arr, int nLow, int nHigh)
{
	if (arr == NULL || nLow >= nHigh) return;
	int nMid = nLow + (nHigh - nLow) / 2;

	MergeSort(arr, nLow, nMid);
	MergeSort(arr, nMid+1, nHigh);

	Merge(arr, nLow, nHigh);
}

void PrintArr(int* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n");
	return;
}
void Sort_test()
{
	int arr[] = { 2,6,3,7,5,9,0,1 };
	MergeSort(arr,0,7);
	PrintArr(arr, 8);
	return ;

}