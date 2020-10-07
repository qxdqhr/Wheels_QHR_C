//#include "iostream"
//using namespace std;
//void Compare(int arr[], int* max, int* min, int high, int low)
//{
//	if (low == high)
//	{
//		*max = arr[low];
//		*min = arr[high];
//	}
//	else
//	{
//		int mid = (low + high) / 2;
//		int max1 = 1, max2 = 1;
//		int min1 = 1, min2 = 1;
//		Compare(arr,&max1, &min1, mid, low);
//		Compare(arr, &max2, &min2, high, mid+1);
//
//		*max = max1 > max2 ? max1 : max2;
//		*min = min1 < min2 ? min1 : min2;
//
//	}
//}
//int main()
//{
//	int max = 0;
//	int min = 0;
//
//	int arr[] = { 2,5,1 };
//	Compare(arr, &max, &min, sizeof(arr) / sizeof(int)-1, 0);
//	cout << max <<" "<< min;
//}