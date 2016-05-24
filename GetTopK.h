

#include <iostream>
#include <assert.h>
#include <time.h>

using namespace std;

const int N = 10000;
const int k = 100;
int Topk[k];

//向下调整算法
void AdjustDown(int Topk[], int n, int parent)
{
	assert(Topk);
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n&&Topk[child + 1] < Topk[child])
		{
			child++;
		}
		if (Topk[child]<Topk[parent])
		{
			swap(Topk[child], Topk[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

//小堆
void GetTopK(int a[])
{
	assert(k < N);
	for (int i = 0; i < k; i++)
	{
		Topk[i] = a[i];
	}
	for (int i = (k - 2) / 2; i >= 0; i--)
	{
		AdjustDown(Topk, k, i);
	}
	//用堆的第一个元素和剩下的一一比较
	for (int i = k; i < N; i++)
	{
		if (a[i] > Topk[0])
		{
			Topk[0] = a[i];
			AdjustDown(Topk, k, 0);
		}
	}
	for (int i = 0; i < k; i++)
	{
		cout << Topk[i] << " ";
	}
	cout << endl;
}
