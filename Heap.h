

#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

//仿函数
template <typename T>
struct Greater
{
	bool operator() (const T & l, const T & r)
	{
		return l > r;
	}
};

template <typename T>
struct Less
{
	bool operator() (const T & l, const T & r)
	{
		return l < r;
	}
};

//模板参数
template <typename T,typename comer=Greater<T> >

class Heap
{
public:
	//无参构造函数
	Heap()
		:_a(NULL)
	{}
	//有参构造函数
	Heap(T * a, size_t size)
	{
		assert(a);
		//先把数据保存在vector中
		for (size_t i = 0; i < size; i++)
		{
			_a.push_back(a[i]);
		}
		//建堆
		for (int j = ((_a.size() - 2) / 2); j >= 0; j--)
		{
			//向下调整算法
			_AdjustDown(j);
		}
	}

	void Push(const T x)//插入元素
	{
		_a.push_back(x);
		_AdjustUp(_a.size() - 1);
	}

	void Pop()//删除元素
	{
		assert(_a.size() > 0);
		swap(_a[0], _a[_a.size() - 1]);
		_a.pop_back();
		_AdjustDown(0);
	}

	size_t Size()
	{
		return _a.size();
	}

	bool Empty()
	{
		return _a.empty();
	}

	void print()
	{
		for (int i = 0; i < _a.size(); i++)
		{
			cout << _a[i] << " ";
		}
		cout << endl;
	}

protected:
	//向下调整算法
	void _AdjustDown(size_t parent)
	{
		size_t child = parent * 2 + 1;
		comer com;
		while (child < _a.size())
		{
			//找出左右孩子中比较大的
			if (child + 1 < _a.size() && com(_a[child + 1] , _a[child]))
			{
				child++;
			}
			//比较父亲和孩子的大小
			if (com (_a[child],_a[parent]))
			{
				swap(_a[child], _a[parent]);
				parent = child;
				child = parent * 2 + 1;
			}
			else
			{
				break;
			}
		}
	}

	//向上调整算法
	void _AdjustUp(size_t child)
	{
		assert(child < _a.size());
		int parent = (child - 1) / 2;
		comer com;
		while (child > 0)
		{
			//只需看父节点<根节点
			if (com(_a[child], _a[parent]))
			{
				swap(_a[child], _a[parent]);
				child = parent;
				parent = (child - 1) / 2;
			}
			else
			{
				break;
			}
		}
	}

private:
	vector <T> _a;
};






