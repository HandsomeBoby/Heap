

#include <iostream>
#include <assert.h>

using namespace std;
//向下调整
void AdjustDown(int arr[], int n, int parent)
{
	assert(arr);
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n&&arr[child + 1] > arr[child])
		{
			child++;
		}
		if (arr[child]>arr[parent])
		{
			swap(arr[child], arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
//大堆
void HeapSort(int a[], size_t n)
{
	assert(a);
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	//把第一个和最后一个交换，去掉最后一个，找出次大的
	//循环实现
	for (size_t i = 0; i < n - 1; i++)
	{
		swap(a[0], a[n - i - 1]);
		AdjustDown(a, n - i - 1, 0);
	}
	for (size_t i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
