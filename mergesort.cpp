#include <iostream>
using namespace std;
#define min(a, b) (a < b) ? a : b
#define M 5
///merge sort
class Merge_Sort
{
	int *data;
	int count;
public:
	Merge_Sort(int N);
	void insert_sort(int low, int high);

	void merge(int first, int middle, int last, int *temp);//自顶向下的归并排序
	void mergesort(int first, int last, int *temp);
	void Mergesort();//建立临时数组，定义程序入口

	void mergesort_btt(int *temp);//自底向上的归并排序
	void Mergesort_btt();


	void swap(int i, int j);

	void issorted();
	void show();
};
Merge_Sort::Merge_Sort(int N)
{
	count = N;
	data = new int[N];
	for (int i = 0; i < N; i++)
	{
		data[i] = (rand() % (100 - 0))+ 0;
	}
};
void Merge_Sort::swap(int i, int j)
{
	int temp = data[i];
	data[i] = data[j];
	data[j] = temp;
}
void Merge_Sort::issorted()
{
	int num = 0;
	for (int i = 0; i < count - 1; i++)
	{
		if (data[i] < data[i + 1])
			num++;
	}
	if (num == count - 1)
		cout<<"数组有序"<<endl;
	else
		cout<<"数组无序"<<endl;
}
void Merge_Sort::show()
{
	for (int i = 0; i < count; i++)
	{
		cout<<data[i]<<" ";
	}
	cout<<endl;
}


void Merge_Sort::merge(int first, int middle, int last, int *temp)
{
	int i = first;
	int m = middle;
	int j = middle + 1;
	int n = last;
	int k = 0;
	while (i <= m && j <= n)
	{
		if (data[i] <= data[j])
			temp[k++] = data[i++];
		else
			temp[k++] = data[j++];
	};
	while (i <= m)
		temp[k++] = data[i++];
	while (j <= n)
		temp[k++] = data[j++];
	for (int i = 0; i < k; i++)
	{
		data[first + i] = temp[i];
	}
}

void Merge_Sort::mergesort(int first, int last, int *temp)
{
	if (first + M >= last)
		insert_sort(first, last);
	else if (first < last)
	{
		int middle = (first + last) / 2;
		mergesort(first, middle, temp);//左边有序
		mergesort(middle + 1, last, temp);//右边有序
		if (data[middle] > data[middle + 1])
			merge(first, middle, last, temp);
	}
	else
		return;
}

void Merge_Sort::Mergesort()
{
	int *temp = new int[count];
	mergesort(0, count - 1, temp);
	delete temp;
}

void Merge_Sort::mergesort_btt(int *temp)
{
	for (int sz = 1; sz < count; sz = sz + sz)
	{
		for (int lo = 0; lo < count - sz; lo += sz + sz)
			merge(lo, lo + sz - 1, min(lo + sz + sz - 1, count - 1), temp);
	}
}
void Merge_Sort::Mergesort_btt()
{
	int *temp = new int[count];
	mergesort_btt(temp);
	delete temp;
}

void Merge_Sort::insert_sort(int low, int high)
{
	for (int i = low + 1; i <= high; i++)
	{
		int j = i;
		int temp = data[i];
		while (j > low && temp < data[j - 1])
		{
			data[j] = data[j - 1];
			j--;
		}
		data[j] = temp;
	}
}
void main()
{
	Merge_Sort s1(10);
	s1.show();
	s1.Mergesort();
	s1.show();
	s1.issorted();
	system("pause");
}

